#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <math.h>

#include "nvgr_server.h"
#include "nvgr_common.h"

struct NVGcontext {
    FILE* file;
};

NVGcontext* nvgCreateRemote(FILE* f){
    NVGcontext* ctx = calloc(1, sizeof(struct NVGcontext));
    ctx->file = f;
    return ctx;
}

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

// Implemented functions
void nvgTransformIdentity(float* t)
{
	t[0] = 1.0f; t[1] = 0.0f;
	t[2] = 0.0f; t[3] = 1.0f;
	t[4] = 0.0f; t[5] = 0.0f;
}


static float nvg__clampf(float a, float mn, float mx) { return a < mn ? mn : (a > mx ? mx : a); }
static float nvg__modf(float a, float b) { return fmodf(a, b); }
static float nvg__maxf(float a, float b) { return a > b ? a : b; }

static float nvg__hue(float h, float m1, float m2)
{
	if (h < 0) h += 1;
	if (h > 1) h -= 1;
	if (h < 1.0f/6.0f)
		return m1 + (m2 - m1) * h * 6.0f;
	else if (h < 3.0f/6.0f)
		return m2;
	else if (h < 4.0f/6.0f)
		return m1 + (m2 - m1) * (2.0f/3.0f - h) * 6.0f;
	return m1;
}

NVGcolor nvgHSLA(float h, float s, float l, unsigned char a)
{
	float m1, m2;
	NVGcolor col;
	h = nvg__modf(h, 1.0f);
	if (h < 0.0f) h += 1.0f;
	s = nvg__clampf(s, 0.0f, 1.0f);
	l = nvg__clampf(l, 0.0f, 1.0f);
	m2 = l <= 0.5f ? (l * (1 + s)) : (l + s - l * s);
	m1 = 2 * l - m2;
	col.r = nvg__clampf(nvg__hue(h + 1.0f/3.0f, m1, m2), 0.0f, 1.0f);
	col.g = nvg__clampf(nvg__hue(h, m1, m2), 0.0f, 1.0f);
	col.b = nvg__clampf(nvg__hue(h - 1.0f/3.0f, m1, m2), 0.0f, 1.0f);
	col.a = a/255.0f;
	return col;
}

NVGcolor nvgRGB(unsigned char r, unsigned char g, unsigned char b)
{
	return nvgRGBA(r,g,b,255);
}

NVGcolor nvgRGBf(float r, float g, float b)
{
	return nvgRGBAf(r,g,b,1.0f);
}

NVGcolor nvgRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	NVGcolor color;
	// Use longer initialization to suppress warning.
	color.r = r / 255.0f;
	color.g = g / 255.0f;
	color.b = b / 255.0f;
	color.a = a / 255.0f;
	return color;
}

NVGcolor nvgRGBAf(float r, float g, float b, float a)
{
	NVGcolor color;
	// Use longer initialization to suppress warning.
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return color;
}

NVGcolor nvgTransRGBA(NVGcolor c, unsigned char a)
{
	c.a = a / 255.0f;
	return c;
}

NVGcolor nvgTransRGBAf(NVGcolor c, float a)
{
	c.a = a;
	return c;
}

NVGcolor nvgLerpRGBA(NVGcolor c0, NVGcolor c1, float u)
{
	int i;
	float oneminu;
	NVGcolor cint = {{{0}}};

	u = nvg__clampf(u, 0.0f, 1.0f);
	oneminu = 1.0f - u;
	for( i = 0; i <4; i++ )
	{
		cint.rgba[i] = c0.rgba[i] * oneminu + c1.rgba[i] * u;
	}

	return cint;
}

NVGcolor nvgHSL(float h, float s, float l)
{
	return nvgHSLA(h,s,l,255);
}

NVGpaint nvgLinearGradient(NVGcontext* ctx,
								  float sx, float sy, float ex, float ey,
								  NVGcolor icol, NVGcolor ocol)
{
	NVGpaint p;
	float dx, dy, d;
	const float large = 1e5;
	NVG_NOTUSED(ctx);
	memset(&p, 0, sizeof(p));

	// Calculate transform aligned to the line
	dx = ex - sx;
	dy = ey - sy;
	d = sqrtf(dx*dx + dy*dy);
	if (d > 0.0001f) {
		dx /= d;
		dy /= d;
	} else {
		dx = 0;
		dy = 1;
	}

	p.xform[0] = dy; p.xform[1] = -dx;
	p.xform[2] = dx; p.xform[3] = dy;
	p.xform[4] = sx - dx*large; p.xform[5] = sy - dy*large;

	p.extent[0] = large;
	p.extent[1] = large + d*0.5f;

	p.radius = 0.0f;

	p.feather = nvg__maxf(1.0f, d);

	p.innerColor = icol;
	p.outerColor = ocol;

	return p;
}

NVGpaint nvgRadialGradient(NVGcontext* ctx,
								  float cx, float cy, float inr, float outr,
								  NVGcolor icol, NVGcolor ocol)
{
	NVGpaint p;
	float r = (inr+outr)*0.5f;
	float f = (outr-inr);
	NVG_NOTUSED(ctx);
	memset(&p, 0, sizeof(p));

	nvgTransformIdentity(p.xform);
	p.xform[4] = cx;
	p.xform[5] = cy;

	p.extent[0] = r;
	p.extent[1] = r;

	p.radius = r;

	p.feather = nvg__maxf(1.0f, f);

	p.innerColor = icol;
	p.outerColor = ocol;

	return p;
}

NVGpaint nvgBoxGradient(NVGcontext* ctx,
							   float x, float y, float w, float h, float r, float f,
							   NVGcolor icol, NVGcolor ocol)
{
	NVGpaint p;
	NVG_NOTUSED(ctx);
	memset(&p, 0, sizeof(p));

	nvgTransformIdentity(p.xform);
	p.xform[4] = x+w*0.5f;
	p.xform[5] = y+h*0.5f;

	p.extent[0] = w*0.5f;
	p.extent[1] = h*0.5f;

	p.radius = r;

	p.feather = nvg__maxf(1.0f, f);

	p.innerColor = icol;
	p.outerColor = ocol;

	return p;
}