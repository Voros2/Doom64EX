#ifndef _WADGEN_WAD_H_
#define _WADGEN_WAD_H_

#include <string>
#include "sprite.h"
#include "gfx.h"
#include "texture.h"
#include "sound.h"

#define MAX_LUMPS	4096

#pragma pack(push, 1)

typedef struct {
    char id[4];
    int lmpcount;
    int lmpdirpos;
} wadheader_t;

typedef struct {
    int filepos;
    int size;
    char name[8];
} lump_t;

#pragma pack(pop)

typedef struct {
    wadheader_t header;
    lump_t lump[MAX_LUMPS];
    cache lumpcache[MAX_LUMPS];
    uint size;
} wadFile_t;

extern wadFile_t romWadFile;
extern wadFile_t outWadFile;

void Wad_GetIwad(void);
int Wad_GetLumpNum(const std::string &name);
byte*Wad_GetLump(const std::string &name, bool dcmpType);
void Wad_CreateOutput(void);
void Wad_WriteOutput(path outFile);
void Wad_AddOutputSprite(d64ExSpriteLump_t * sprite);
void Wad_AddOutputTexture(d64ExTexture_t * tex);
void Wad_AddOutputGfx(gfxEx_t * gfx);
void Wad_AddOutputHudSprite(d64ExSpriteLump_t * sprite);
void Wad_AddOutputPalette(d64PaletteLump_t * palette);
void Wad_AddOutputMidi(midiheader_t * mthd, int index);
void Wad_AddOutputLump(const char *name, int size, cache data);

#endif
