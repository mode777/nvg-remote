#include <GLES2/gl2.h>
#include "nanovg.h"
#define NANOVG_GLES2_IMPLEMENTATION
#include "nanovg_gl.h"

#include "nvgr_client.h"
#include "nvgr_common.h"

static NVGcontext* nvg;

static bool decode(FILE* file){
  nvgrDrawOp op;
  do {
    op = getc(file);
    if(op == 0) return false;
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
  return true;
}

void nvgr_client_init() {
  nvg = nvgCreateGLES2(NVG_ANTIALIAS | NVG_STENCIL_STROKES);
}

bool nvgr_client_draw_next(FILE* f) {
    return decode(f);
}