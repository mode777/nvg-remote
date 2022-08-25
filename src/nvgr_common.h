#ifndef NVGR_COMMON_H
#define NVGR_COMMON_H

typedef enum {
  nvgrBeginFrame = 1,
  nvgrCancelFrame = 2,
  nvgrEndFrame = 3,
  nvgrGlobalCompositeOperation = 4,
  nvgrGlobalCompositeBlendFunc = 5,
  nvgrGlobalCompositeBlendFuncSeparate = 6,
  nvgrSave = 7,
  nvgrRestore = 8,
  nvgrReset = 9,
  nvgrShapeAntiAlias = 10,
  nvgrStrokeColor = 11,
  nvgrStrokePaint = 12,
  nvgrFillColor = 13,
  nvgrFillPaint = 14,
  nvgrMiterLimit = 15,
  nvgrStrokeWidth = 16,
  nvgrLineCap = 17,
  nvgrLineJoin = 18,
  nvgrGlobalAlpha = 19,
  nvgrResetTransform = 20,
  nvgrTransform = 21,
  nvgrTranslate = 22,
  nvgrRotate = 23,
  nvgrSkewX = 24,
  nvgrSkewY = 25,
  nvgrScale = 26,
  nvgrCurrentTransform = 27,
  nvgrScissor = 28,
  nvgrIntersectScissor = 29,
  nvgrResetScissor = 30,
  nvgrBeginPath = 31,
  nvgrMoveTo = 32,
  nvgrLineTo = 33,
  nvgrBezierTo = 34,
  nvgrQuadTo = 35,
  nvgrArcTo = 36,
  nvgrClosePath = 37,
  nvgrPathWinding = 38,
  nvgrArc = 39,
  nvgrRect = 40,
  nvgrRoundedRect = 41,
  nvgrRoundedRectVarying = 42,
  nvgrEllipse = 43,
  nvgrCircle = 44,
  nvgrFill = 45,
  nvgrStroke = 46,
} nvgrDrawOp;

#endif