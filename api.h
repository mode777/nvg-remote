void nvgBeginFrame(NVGcontext* ctx, float windowWidth, float windowHeight, float devicePixelRatio);
void nvgCancelFrame(NVGcontext* ctx);
void nvgEndFrame(NVGcontext* ctx);
void nvgGlobalCompositeOperation(NVGcontext* ctx, int op);
void nvgGlobalCompositeBlendFunc(NVGcontext* ctx, int sfactor, int dfactor);
void nvgGlobalCompositeBlendFuncSeparate(NVGcontext* ctx, int srcRGB, int dstRGB, int srcAlpha, int dstAlpha);
void nvgSave(NVGcontext* ctx);
void nvgRestore(NVGcontext* ctx);
void nvgReset(NVGcontext* ctx);
void nvgShapeAntiAlias(NVGcontext* ctx, int enabled);
void nvgStrokeColor(NVGcontext* ctx, NVGcolor color);
void nvgStrokePaint(NVGcontext* ctx, NVGpaint paint);
void nvgFillColor(NVGcontext* ctx, NVGcolor color);
void nvgFillPaint(NVGcontext* ctx, NVGpaint paint);
void nvgMiterLimit(NVGcontext* ctx, float limit);
void nvgStrokeWidth(NVGcontext* ctx, float size);
void nvgLineCap(NVGcontext* ctx, int cap);
void nvgLineJoin(NVGcontext* ctx, int join);
void nvgGlobalAlpha(NVGcontext* ctx, float alpha);
void nvgResetTransform(NVGcontext* ctx);
void nvgTransform(NVGcontext* ctx, float a, float b, float c, float d, float e, float f);
void nvgTranslate(NVGcontext* ctx, float x, float y);
void nvgRotate(NVGcontext* ctx, float angle);
void nvgSkewX(NVGcontext* ctx, float angle);
void nvgSkewY(NVGcontext* ctx, float angle);
void nvgScale(NVGcontext* ctx, float x, float y);
void nvgCurrentTransform(NVGcontext* ctx, float* xform);
void nvgScissor(NVGcontext* ctx, float x, float y, float w, float h);
void nvgIntersectScissor(NVGcontext* ctx, float x, float y, float w, float h);
void nvgResetScissor(NVGcontext* ctx);
void nvgBeginPath(NVGcontext* ctx);
void nvgMoveTo(NVGcontext* ctx, float x, float y);
void nvgLineTo(NVGcontext* ctx, float x, float y);
void nvgBezierTo(NVGcontext* ctx, float c1x, float c1y, float c2x, float c2y, float x, float y);
void nvgQuadTo(NVGcontext* ctx, float cx, float cy, float x, float y);
void nvgArcTo(NVGcontext* ctx, float x1, float y1, float x2, float y2, float radius);
void nvgClosePath(NVGcontext* ctx);
void nvgPathWinding(NVGcontext* ctx, int dir);
void nvgArc(NVGcontext* ctx, float cx, float cy, float r, float a0, float a1, int dir);
void nvgRect(NVGcontext* ctx, float x, float y, float w, float h);
void nvgRoundedRect(NVGcontext* ctx, float x, float y, float w, float h, float r);
void nvgRoundedRectVarying(NVGcontext* ctx, float x, float y, float w, float h, float radTopLeft, float radTopRight, float radBottomRight, float radBottomLeft);
void nvgEllipse(NVGcontext* ctx, float cx, float cy, float rx, float ry);
void nvgCircle(NVGcontext* ctx, float cx, float cy, float r);
void nvgFill(NVGcontext* ctx);
void nvgStroke(NVGcontext* ctx);

// int nvgCreateImage(NVGcontext* ctx, const char* filename, int imageFlags);
// int nvgCreateImageMem(NVGcontext* ctx, int imageFlags, unsigned char* data, int ndata);
// int nvgCreateImageRGBA(NVGcontext* ctx, int w, int h, int imageFlags, const unsigned char* data);
// void nvgUpdateImage(NVGcontext* ctx, int image, const unsigned char* data);
// void nvgImageSize(NVGcontext* ctx, int image, int* w, int* h);
// void nvgDeleteImage(NVGcontext* ctx, int image);
// int nvgCreateFont(NVGcontext* ctx, const char* name, const char* filename);
// int nvgCreateFontAtIndex(NVGcontext* ctx, const char* name, const char* filename, const int fontIndex);
// int nvgCreateFontMem(NVGcontext* ctx, const char* name, unsigned char* data, int ndata, int freeData);
// int nvgCreateFontMemAtIndex(NVGcontext* ctx, const char* name, unsigned char* data, int ndata, int freeData, const int fontIndex);
// int nvgFindFont(NVGcontext* ctx, const char* name);
// int nvgAddFallbackFontId(NVGcontext* ctx, int baseFont, int fallbackFont);
// int nvgAddFallbackFont(NVGcontext* ctx, const char* baseFont, const char* fallbackFont);
// void nvgResetFallbackFontsId(NVGcontext* ctx, int baseFont);
// void nvgResetFallbackFonts(NVGcontext* ctx, const char* baseFont);
// void nvgFontSize(NVGcontext* ctx, float size);
// void nvgFontBlur(NVGcontext* ctx, float blur);
// void nvgTextLetterSpacing(NVGcontext* ctx, float spacing);
// void nvgTextLineHeight(NVGcontext* ctx, float lineHeight);
// void nvgTextAlign(NVGcontext* ctx, int align);
// void nvgFontFaceId(NVGcontext* ctx, int font);
// void nvgFontFace(NVGcontext* ctx, const char* font);
// float nvgText(NVGcontext* ctx, float x, float y, const char* string, const char* end);
// void nvgTextBox(NVGcontext* ctx, float x, float y, float breakRowWidth, const char* string, const char* end);
// float nvgTextBounds(NVGcontext* ctx, float x, float y, const char* string, const char* end, float* bounds);
// void nvgTextBoxBounds(NVGcontext* ctx, float x, float y, float breakRowWidth, const char* string, const char* end, float* bounds);
// int nvgTextGlyphPositions(NVGcontext* ctx, float x, float y, const char* string, const char* end, NVGglyphPosition* positions, int maxPositions);
// void nvgTextMetrics(NVGcontext* ctx, float* ascender, float* descender, float* lineh);
// int nvgTextBreakLines(NVGcontext* ctx, const char* string, const char* end, float breakRowWidth, NVGtextRow* rows, int maxRows);
