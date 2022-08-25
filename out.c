

void nvgBeginFrame(NVGcontext* ctx, float windowWidth, float windowHeight, float devicePixelRatio){
  unsigned char nvgrOp = nvgrBeginFrame;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&windowWidth, sizeof(float), 1, ctx->file);
  fwrite(&windowHeight, sizeof(float), 1, ctx->file);
  fwrite(&devicePixelRatio, sizeof(float), 1, ctx->file);
}

void nvgCancelFrame(NVGcontext* ctx){
  unsigned char nvgrOp = nvgrCancelFrame;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
}

void nvgEndFrame(NVGcontext* ctx){
  unsigned char nvgrOp = nvgrEndFrame;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
}

void nvgGlobalCompositeOperation(NVGcontext* ctx, int op){
  unsigned char nvgrOp = nvgrGlobalCompositeOperation;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&op, sizeof(int), 1, ctx->file);
}

void nvgGlobalCompositeBlendFunc(NVGcontext* ctx, int sfactor, int dfactor){
  unsigned char nvgrOp = nvgrGlobalCompositeBlendFunc;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&sfactor, sizeof(int), 1, ctx->file);
  fwrite(&dfactor, sizeof(int), 1, ctx->file);
}

void nvgGlobalCompositeBlendFuncSeparate(NVGcontext* ctx, int srcRGB, int dstRGB, int srcAlpha, int dstAlpha){
  unsigned char nvgrOp = nvgrGlobalCompositeBlendFuncSeparate;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&srcRGB, sizeof(int), 1, ctx->file);
  fwrite(&dstRGB, sizeof(int), 1, ctx->file);
  fwrite(&srcAlpha, sizeof(int), 1, ctx->file);
  fwrite(&dstAlpha, sizeof(int), 1, ctx->file);
}

void nvgSave(NVGcontext* ctx){
  unsigned char nvgrOp = nvgrSave;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
}

void nvgRestore(NVGcontext* ctx){
  unsigned char nvgrOp = nvgrRestore;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
}

void nvgReset(NVGcontext* ctx){
  unsigned char nvgrOp = nvgrReset;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
}

void nvgShapeAntiAlias(NVGcontext* ctx, int enabled){
  unsigned char nvgrOp = nvgrShapeAntiAlias;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&enabled, sizeof(int), 1, ctx->file);
}

void nvgStrokeColor(NVGcontext* ctx, NVGcolor color){
  unsigned char nvgrOp = nvgrStrokeColor;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&color, sizeof(NVGcolor), 1, ctx->file);
}

void nvgStrokePaint(NVGcontext* ctx, NVGpaint paint){
  unsigned char nvgrOp = nvgrStrokePaint;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&paint, sizeof(NVGpaint), 1, ctx->file);
}

void nvgFillColor(NVGcontext* ctx, NVGcolor color){
  unsigned char nvgrOp = nvgrFillColor;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&color, sizeof(NVGcolor), 1, ctx->file);
}

void nvgFillPaint(NVGcontext* ctx, NVGpaint paint){
  unsigned char nvgrOp = nvgrFillPaint;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&paint, sizeof(NVGpaint), 1, ctx->file);
}

void nvgMiterLimit(NVGcontext* ctx, float limit){
  unsigned char nvgrOp = nvgrMiterLimit;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&limit, sizeof(float), 1, ctx->file);
}

void nvgStrokeWidth(NVGcontext* ctx, float size){
  unsigned char nvgrOp = nvgrStrokeWidth;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&size, sizeof(float), 1, ctx->file);
}

void nvgLineCap(NVGcontext* ctx, int cap){
  unsigned char nvgrOp = nvgrLineCap;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&cap, sizeof(int), 1, ctx->file);
}

void nvgLineJoin(NVGcontext* ctx, int join){
  unsigned char nvgrOp = nvgrLineJoin;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&join, sizeof(int), 1, ctx->file);
}

void nvgGlobalAlpha(NVGcontext* ctx, float alpha){
  unsigned char nvgrOp = nvgrGlobalAlpha;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&alpha, sizeof(float), 1, ctx->file);
}

void nvgResetTransform(NVGcontext* ctx){
  unsigned char nvgrOp = nvgrResetTransform;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
}

void nvgTransform(NVGcontext* ctx, float a, float b, float c, float d, float e, float f){
  unsigned char nvgrOp = nvgrTransform;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&a, sizeof(float), 1, ctx->file);
  fwrite(&b, sizeof(float), 1, ctx->file);
  fwrite(&c, sizeof(float), 1, ctx->file);
  fwrite(&d, sizeof(float), 1, ctx->file);
  fwrite(&e, sizeof(float), 1, ctx->file);
  fwrite(&f, sizeof(float), 1, ctx->file);
}

void nvgTranslate(NVGcontext* ctx, float x, float y){
  unsigned char nvgrOp = nvgrTranslate;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&x, sizeof(float), 1, ctx->file);
  fwrite(&y, sizeof(float), 1, ctx->file);
}

void nvgRotate(NVGcontext* ctx, float angle){
  unsigned char nvgrOp = nvgrRotate;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&angle, sizeof(float), 1, ctx->file);
}

void nvgSkewX(NVGcontext* ctx, float angle){
  unsigned char nvgrOp = nvgrSkewX;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&angle, sizeof(float), 1, ctx->file);
}

void nvgSkewY(NVGcontext* ctx, float angle){
  unsigned char nvgrOp = nvgrSkewY;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&angle, sizeof(float), 1, ctx->file);
}

void nvgScale(NVGcontext* ctx, float x, float y){
  unsigned char nvgrOp = nvgrScale;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&x, sizeof(float), 1, ctx->file);
  fwrite(&y, sizeof(float), 1, ctx->file);
}

void nvgCurrentTransform(NVGcontext* ctx, float* xform){
  unsigned char nvgrOp = nvgrCurrentTransform;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&xform, sizeof(float*), 1, ctx->file);
}

void nvgScissor(NVGcontext* ctx, float x, float y, float w, float h){
  unsigned char nvgrOp = nvgrScissor;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&x, sizeof(float), 1, ctx->file);
  fwrite(&y, sizeof(float), 1, ctx->file);
  fwrite(&w, sizeof(float), 1, ctx->file);
  fwrite(&h, sizeof(float), 1, ctx->file);
}

void nvgIntersectScissor(NVGcontext* ctx, float x, float y, float w, float h){
  unsigned char nvgrOp = nvgrIntersectScissor;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&x, sizeof(float), 1, ctx->file);
  fwrite(&y, sizeof(float), 1, ctx->file);
  fwrite(&w, sizeof(float), 1, ctx->file);
  fwrite(&h, sizeof(float), 1, ctx->file);
}

void nvgResetScissor(NVGcontext* ctx){
  unsigned char nvgrOp = nvgrResetScissor;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
}

void nvgBeginPath(NVGcontext* ctx){
  unsigned char nvgrOp = nvgrBeginPath;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
}

void nvgMoveTo(NVGcontext* ctx, float x, float y){
  unsigned char nvgrOp = nvgrMoveTo;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&x, sizeof(float), 1, ctx->file);
  fwrite(&y, sizeof(float), 1, ctx->file);
}

void nvgLineTo(NVGcontext* ctx, float x, float y){
  unsigned char nvgrOp = nvgrLineTo;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&x, sizeof(float), 1, ctx->file);
  fwrite(&y, sizeof(float), 1, ctx->file);
}

void nvgBezierTo(NVGcontext* ctx, float c1x, float c1y, float c2x, float c2y, float x, float y){
  unsigned char nvgrOp = nvgrBezierTo;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&c1x, sizeof(float), 1, ctx->file);
  fwrite(&c1y, sizeof(float), 1, ctx->file);
  fwrite(&c2x, sizeof(float), 1, ctx->file);
  fwrite(&c2y, sizeof(float), 1, ctx->file);
  fwrite(&x, sizeof(float), 1, ctx->file);
  fwrite(&y, sizeof(float), 1, ctx->file);
}

void nvgQuadTo(NVGcontext* ctx, float cx, float cy, float x, float y){
  unsigned char nvgrOp = nvgrQuadTo;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&cx, sizeof(float), 1, ctx->file);
  fwrite(&cy, sizeof(float), 1, ctx->file);
  fwrite(&x, sizeof(float), 1, ctx->file);
  fwrite(&y, sizeof(float), 1, ctx->file);
}

void nvgArcTo(NVGcontext* ctx, float x1, float y1, float x2, float y2, float radius){
  unsigned char nvgrOp = nvgrArcTo;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&x1, sizeof(float), 1, ctx->file);
  fwrite(&y1, sizeof(float), 1, ctx->file);
  fwrite(&x2, sizeof(float), 1, ctx->file);
  fwrite(&y2, sizeof(float), 1, ctx->file);
  fwrite(&radius, sizeof(float), 1, ctx->file);
}

void nvgClosePath(NVGcontext* ctx){
  unsigned char nvgrOp = nvgrClosePath;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
}

void nvgPathWinding(NVGcontext* ctx, int dir){
  unsigned char nvgrOp = nvgrPathWinding;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&dir, sizeof(int), 1, ctx->file);
}

void nvgArc(NVGcontext* ctx, float cx, float cy, float r, float a0, float a1, int dir){
  unsigned char nvgrOp = nvgrArc;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&cx, sizeof(float), 1, ctx->file);
  fwrite(&cy, sizeof(float), 1, ctx->file);
  fwrite(&r, sizeof(float), 1, ctx->file);
  fwrite(&a0, sizeof(float), 1, ctx->file);
  fwrite(&a1, sizeof(float), 1, ctx->file);
  fwrite(&dir, sizeof(int), 1, ctx->file);
}

void nvgRect(NVGcontext* ctx, float x, float y, float w, float h){
  unsigned char nvgrOp = nvgrRect;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&x, sizeof(float), 1, ctx->file);
  fwrite(&y, sizeof(float), 1, ctx->file);
  fwrite(&w, sizeof(float), 1, ctx->file);
  fwrite(&h, sizeof(float), 1, ctx->file);
}

void nvgRoundedRect(NVGcontext* ctx, float x, float y, float w, float h, float r){
  unsigned char nvgrOp = nvgrRoundedRect;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&x, sizeof(float), 1, ctx->file);
  fwrite(&y, sizeof(float), 1, ctx->file);
  fwrite(&w, sizeof(float), 1, ctx->file);
  fwrite(&h, sizeof(float), 1, ctx->file);
  fwrite(&r, sizeof(float), 1, ctx->file);
}

void nvgRoundedRectVarying(NVGcontext* ctx, float x, float y, float w, float h, float radTopLeft, float radTopRight, float radBottomRight, float radBottomLeft){
  unsigned char nvgrOp = nvgrRoundedRectVarying;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&x, sizeof(float), 1, ctx->file);
  fwrite(&y, sizeof(float), 1, ctx->file);
  fwrite(&w, sizeof(float), 1, ctx->file);
  fwrite(&h, sizeof(float), 1, ctx->file);
  fwrite(&radTopLeft, sizeof(float), 1, ctx->file);
  fwrite(&radTopRight, sizeof(float), 1, ctx->file);
  fwrite(&radBottomRight, sizeof(float), 1, ctx->file);
  fwrite(&radBottomLeft, sizeof(float), 1, ctx->file);
}

void nvgEllipse(NVGcontext* ctx, float cx, float cy, float rx, float ry){
  unsigned char nvgrOp = nvgrEllipse;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&cx, sizeof(float), 1, ctx->file);
  fwrite(&cy, sizeof(float), 1, ctx->file);
  fwrite(&rx, sizeof(float), 1, ctx->file);
  fwrite(&ry, sizeof(float), 1, ctx->file);
}

void nvgCircle(NVGcontext* ctx, float cx, float cy, float r){
  unsigned char nvgrOp = nvgrCircle;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
  fwrite(&cx, sizeof(float), 1, ctx->file);
  fwrite(&cy, sizeof(float), 1, ctx->file);
  fwrite(&r, sizeof(float), 1, ctx->file);
}

void nvgFill(NVGcontext* ctx){
  unsigned char nvgrOp = nvgrFill;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
}

void nvgStroke(NVGcontext* ctx){
  unsigned char nvgrOp = nvgrStroke;
  fwrite(&nvgrOp, sizeof(unsigned char), 1, ctx->file);
}

// CLIENT /////

static void decode(FILE* file){
  nvgrDrawOp op;
  do {
    op = getc(file);
    switch(op){
      case nvgrBeginFrame:
      {
        float windowWidth;
        fread(&windowWidth, sizeof(float), 1, file);
        float windowHeight;
        fread(&windowHeight, sizeof(float), 1, file);
        float devicePixelRatio;
        fread(&devicePixelRatio, sizeof(float), 1, file);
        nvgBeginFrame(nvg, windowWidth, windowHeight, devicePixelRatio);
      }
      break;
      case nvgrCancelFrame:
      {
        nvgCancelFrame(nvg);
      }
      break;
      case nvgrEndFrame:
      {
        nvgEndFrame(nvg);
      }
      break;
      case nvgrGlobalCompositeOperation:
      {
        int op;
        fread(&op, sizeof(int), 1, file);
        nvgGlobalCompositeOperation(nvg, op);
      }
      break;
      case nvgrGlobalCompositeBlendFunc:
      {
        int sfactor;
        fread(&sfactor, sizeof(int), 1, file);
        int dfactor;
        fread(&dfactor, sizeof(int), 1, file);
        nvgGlobalCompositeBlendFunc(nvg, sfactor, dfactor);
      }
      break;
      case nvgrGlobalCompositeBlendFuncSeparate:
      {
        int srcRGB;
        fread(&srcRGB, sizeof(int), 1, file);
        int dstRGB;
        fread(&dstRGB, sizeof(int), 1, file);
        int srcAlpha;
        fread(&srcAlpha, sizeof(int), 1, file);
        int dstAlpha;
        fread(&dstAlpha, sizeof(int), 1, file);
        nvgGlobalCompositeBlendFuncSeparate(nvg, srcRGB, dstRGB, srcAlpha, dstAlpha);
      }
      break;
      case nvgrSave:
      {
        nvgSave(nvg);
      }
      break;
      case nvgrRestore:
      {
        nvgRestore(nvg);
      }
      break;
      case nvgrReset:
      {
        nvgReset(nvg);
      }
      break;
      case nvgrShapeAntiAlias:
      {
        int enabled;
        fread(&enabled, sizeof(int), 1, file);
        nvgShapeAntiAlias(nvg, enabled);
      }
      break;
      case nvgrStrokeColor:
      {
        NVGcolor color;
        fread(&color, sizeof(NVGcolor), 1, file);
        nvgStrokeColor(nvg, color);
      }
      break;
      case nvgrStrokePaint:
      {
        NVGpaint paint;
        fread(&paint, sizeof(NVGpaint), 1, file);
        nvgStrokePaint(nvg, paint);
      }
      break;
      case nvgrFillColor:
      {
        NVGcolor color;
        fread(&color, sizeof(NVGcolor), 1, file);
        nvgFillColor(nvg, color);
      }
      break;
      case nvgrFillPaint:
      {
        NVGpaint paint;
        fread(&paint, sizeof(NVGpaint), 1, file);
        nvgFillPaint(nvg, paint);
      }
      break;
      case nvgrMiterLimit:
      {
        float limit;
        fread(&limit, sizeof(float), 1, file);
        nvgMiterLimit(nvg, limit);
      }
      break;
      case nvgrStrokeWidth:
      {
        float size;
        fread(&size, sizeof(float), 1, file);
        nvgStrokeWidth(nvg, size);
      }
      break;
      case nvgrLineCap:
      {
        int cap;
        fread(&cap, sizeof(int), 1, file);
        nvgLineCap(nvg, cap);
      }
      break;
      case nvgrLineJoin:
      {
        int join;
        fread(&join, sizeof(int), 1, file);
        nvgLineJoin(nvg, join);
      }
      break;
      case nvgrGlobalAlpha:
      {
        float alpha;
        fread(&alpha, sizeof(float), 1, file);
        nvgGlobalAlpha(nvg, alpha);
      }
      break;
      case nvgrResetTransform:
      {
        nvgResetTransform(nvg);
      }
      break;
      case nvgrTransform:
      {
        float a;
        fread(&a, sizeof(float), 1, file);
        float b;
        fread(&b, sizeof(float), 1, file);
        float c;
        fread(&c, sizeof(float), 1, file);
        float d;
        fread(&d, sizeof(float), 1, file);
        float e;
        fread(&e, sizeof(float), 1, file);
        float f;
        fread(&f, sizeof(float), 1, file);
        nvgTransform(nvg, a, b, c, d, e, f);
      }
      break;
      case nvgrTranslate:
      {
        float x;
        fread(&x, sizeof(float), 1, file);
        float y;
        fread(&y, sizeof(float), 1, file);
        nvgTranslate(nvg, x, y);
      }
      break;
      case nvgrRotate:
      {
        float angle;
        fread(&angle, sizeof(float), 1, file);
        nvgRotate(nvg, angle);
      }
      break;
      case nvgrSkewX:
      {
        float angle;
        fread(&angle, sizeof(float), 1, file);
        nvgSkewX(nvg, angle);
      }
      break;
      case nvgrSkewY:
      {
        float angle;
        fread(&angle, sizeof(float), 1, file);
        nvgSkewY(nvg, angle);
      }
      break;
      case nvgrScale:
      {
        float x;
        fread(&x, sizeof(float), 1, file);
        float y;
        fread(&y, sizeof(float), 1, file);
        nvgScale(nvg, x, y);
      }
      break;
      case nvgrCurrentTransform:
      {
        float* xform;
        fread(&xform, sizeof(float*), 1, file);
        nvgCurrentTransform(nvg, xform);
      }
      break;
      case nvgrScissor:
      {
        float x;
        fread(&x, sizeof(float), 1, file);
        float y;
        fread(&y, sizeof(float), 1, file);
        float w;
        fread(&w, sizeof(float), 1, file);
        float h;
        fread(&h, sizeof(float), 1, file);
        nvgScissor(nvg, x, y, w, h);
      }
      break;
      case nvgrIntersectScissor:
      {
        float x;
        fread(&x, sizeof(float), 1, file);
        float y;
        fread(&y, sizeof(float), 1, file);
        float w;
        fread(&w, sizeof(float), 1, file);
        float h;
        fread(&h, sizeof(float), 1, file);
        nvgIntersectScissor(nvg, x, y, w, h);
      }
      break;
      case nvgrResetScissor:
      {
        nvgResetScissor(nvg);
      }
      break;
      case nvgrBeginPath:
      {
        nvgBeginPath(nvg);
      }
      break;
      case nvgrMoveTo:
      {
        float x;
        fread(&x, sizeof(float), 1, file);
        float y;
        fread(&y, sizeof(float), 1, file);
        nvgMoveTo(nvg, x, y);
      }
      break;
      case nvgrLineTo:
      {
        float x;
        fread(&x, sizeof(float), 1, file);
        float y;
        fread(&y, sizeof(float), 1, file);
        nvgLineTo(nvg, x, y);
      }
      break;
      case nvgrBezierTo:
      {
        float c1x;
        fread(&c1x, sizeof(float), 1, file);
        float c1y;
        fread(&c1y, sizeof(float), 1, file);
        float c2x;
        fread(&c2x, sizeof(float), 1, file);
        float c2y;
        fread(&c2y, sizeof(float), 1, file);
        float x;
        fread(&x, sizeof(float), 1, file);
        float y;
        fread(&y, sizeof(float), 1, file);
        nvgBezierTo(nvg, c1x, c1y, c2x, c2y, x, y);
      }
      break;
      case nvgrQuadTo:
      {
        float cx;
        fread(&cx, sizeof(float), 1, file);
        float cy;
        fread(&cy, sizeof(float), 1, file);
        float x;
        fread(&x, sizeof(float), 1, file);
        float y;
        fread(&y, sizeof(float), 1, file);
        nvgQuadTo(nvg, cx, cy, x, y);
      }
      break;
      case nvgrArcTo:
      {
        float x1;
        fread(&x1, sizeof(float), 1, file);
        float y1;
        fread(&y1, sizeof(float), 1, file);
        float x2;
        fread(&x2, sizeof(float), 1, file);
        float y2;
        fread(&y2, sizeof(float), 1, file);
        float radius;
        fread(&radius, sizeof(float), 1, file);
        nvgArcTo(nvg, x1, y1, x2, y2, radius);
      }
      break;
      case nvgrClosePath:
      {
        nvgClosePath(nvg);
      }
      break;
      case nvgrPathWinding:
      {
        int dir;
        fread(&dir, sizeof(int), 1, file);
        nvgPathWinding(nvg, dir);
      }
      break;
      case nvgrArc:
      {
        float cx;
        fread(&cx, sizeof(float), 1, file);
        float cy;
        fread(&cy, sizeof(float), 1, file);
        float r;
        fread(&r, sizeof(float), 1, file);
        float a0;
        fread(&a0, sizeof(float), 1, file);
        float a1;
        fread(&a1, sizeof(float), 1, file);
        int dir;
        fread(&dir, sizeof(int), 1, file);
        nvgArc(nvg, cx, cy, r, a0, a1, dir);
      }
      break;
      case nvgrRect:
      {
        float x;
        fread(&x, sizeof(float), 1, file);
        float y;
        fread(&y, sizeof(float), 1, file);
        float w;
        fread(&w, sizeof(float), 1, file);
        float h;
        fread(&h, sizeof(float), 1, file);
        nvgRect(nvg, x, y, w, h);
      }
      break;
      case nvgrRoundedRect:
      {
        float x;
        fread(&x, sizeof(float), 1, file);
        float y;
        fread(&y, sizeof(float), 1, file);
        float w;
        fread(&w, sizeof(float), 1, file);
        float h;
        fread(&h, sizeof(float), 1, file);
        float r;
        fread(&r, sizeof(float), 1, file);
        nvgRoundedRect(nvg, x, y, w, h, r);
      }
      break;
      case nvgrRoundedRectVarying:
      {
        float x;
        fread(&x, sizeof(float), 1, file);
        float y;
        fread(&y, sizeof(float), 1, file);
        float w;
        fread(&w, sizeof(float), 1, file);
        float h;
        fread(&h, sizeof(float), 1, file);
        float radTopLeft;
        fread(&radTopLeft, sizeof(float), 1, file);
        float radTopRight;
        fread(&radTopRight, sizeof(float), 1, file);
        float radBottomRight;
        fread(&radBottomRight, sizeof(float), 1, file);
        float radBottomLeft;
        fread(&radBottomLeft, sizeof(float), 1, file);
        nvgRoundedRectVarying(nvg, x, y, w, h, radTopLeft, radTopRight, radBottomRight, radBottomLeft);
      }
      break;
      case nvgrEllipse:
      {
        float cx;
        fread(&cx, sizeof(float), 1, file);
        float cy;
        fread(&cy, sizeof(float), 1, file);
        float rx;
        fread(&rx, sizeof(float), 1, file);
        float ry;
        fread(&ry, sizeof(float), 1, file);
        nvgEllipse(nvg, cx, cy, rx, ry);
      }
      break;
      case nvgrCircle:
      {
        float cx;
        fread(&cx, sizeof(float), 1, file);
        float cy;
        fread(&cy, sizeof(float), 1, file);
        float r;
        fread(&r, sizeof(float), 1, file);
        nvgCircle(nvg, cx, cy, r);
      }
      break;
      case nvgrFill:
      {
        nvgFill(nvg);
      }
      break;
      case nvgrStroke:
      {
        nvgStroke(nvg);
      }
      break;
    }
  } while(op != nvgrEndFrame);
}

