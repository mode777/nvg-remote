const { match } = require("assert/strict");
const fs = require("fs");
const data = fs.readFileSync('api.h', 'utf8')
const re = /^void (nvg[^\(]+)\(([^\)]+)\)/gm;
const result = data.split("\n")
    .map(x => x.trim())
    .map(x => re.lastIndex = 0 || re.exec(x))
    .filter(x => !!x)
    .map(x => ({ 
        matched: x[0],
        name: x[1], 
        args: x[2].split(",")
            .map(x => x.trim().split(' '))
            .map(x => ({ type: x[0], name: x[1] }))
    }));

let i = 1;

// Code Generation
console.log("typedef enum {")
for(f of result){
    console.log(`  ${f.name.replace("nvg","nvgr")} = ${i},`)
    i++;
}
console.log("} nvgrDrawOp;\n")

for(f of result){
    console.log(`${f.matched}{`)
    console.log(`  unsigned char nvgrOp = ${f.name.replace("nvg","nvgr")};`)
    console.log(`  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);`)
    for (let i = 1; i < f.args.length; i++) {
        const arg = f.args[i];
        console.log(`  fwrite(&${arg.name}, sizeof(${arg.type}), 1, ctx->file);`);        
    }
    console.log(`}\n`)
}
console.log("// CLIENT /////\n");

console.log("static void decode(FILE* file){");
console.log("  nvgrDrawOp op;");
console.log("  do {");
console.log("    op = getc(file);");
console.log("    switch(op){");
for(f of result){
    console.log(`      case ${f.name.replace("nvg","nvgr")}:`)
    console.log(`      {`)
    for (let i = 1; i < f.args.length; i++) {
        const arg = f.args[i];
        console.log(`        ${arg.type} ${arg.name};`);        
        console.log(`        fread(&${arg.name}, sizeof(${arg.type}), 1, file);`);        
    }
    console.log(`        ${f.name}(nvg${f.args.length>1?', ':''}${f.args.filter((x,i) => i>0).map(x => x.name).join(', ')});`);        
    console.log(`      }`)
    console.log(`      break;`)
}
console.log(`    }`)
console.log(`  } while(op != nvgrEndFrame);`)
console.log(`}\n`)