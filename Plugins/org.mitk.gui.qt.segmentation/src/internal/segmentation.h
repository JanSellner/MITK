/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/

#ifndef _QEMBED_1804289383
#define _QEMBED_1804289383
#include <qimage.h>
#include <qdict.h>
static const QRgb segmentation_data[] = {
    0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
    0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
    0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
    0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1000000,
    0x3000000,0x3000000,0x3000000,0x2000000,0x1000000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
    0x0,0x0,0x0,0x1000000,0x36000000,0x84000000,0xa3000000,0xff000000,0xff000000,0xff000000,0xb4000000,0x93000000,0x54000000,0x1a000000,
    0x2000000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xa000000,0x9b000000,0xee4b4b4a,0xffb4b2b1,0xffdfdedd,
    0xffe4e3e0,0xffe3e1dd,0xffc2beb5,0xffc1bdb4,0xffbab5ab,0xffd1cdc7,0xff919191,0xbc292929,0x69000000,0x11000000,0x1000000,0x0,0x0,0x0,
    0x0,0x1000000,0x29000000,0xff414140,0xffd9d9d7,0xfff0efef,0xffc8c7c5,0xff6d6b6a,0xff494947,0xff2b2b2b,0xff161616,0xff262522,0xff3e3d39,0xff56534e,
    0xff87837d,0xffd0ceca,0xff6f6e6d,0x71000000,0x9000000,0x1000000,0x0,0x0,0x3000000,0x18000000,0xff474544,0xffe3e2e1,0xffb9b9b8,0xe8242424,
    0xbb0a0a0a,0x76000000,0x60000000,0x50000000,0x49000000,0x6b000000,0x51000000,0x79000000,0xca000000,0xff343230,0xffb7b4ad,0xbe000000,0x1b000000,0x6000000,
    0x0,0x0,0xd000000,0xff494947,0xffd1d1d0,0xff656564,0x9a000000,0x55000000,0x36000000,0x29000000,0x20000000,0x1c000000,0x1c000000,0x1c000000,
    0x1c000000,0x1c000000,0x67000000,0xeb333333,0xffc1bfbc,0xff000000,0x2f000000,0xe000000,0x0,0x0,0xb4000000,0xffd5d5d2,0xff747371,0x7f000000,
    0x42000000,0x26000000,0x14000000,0xb000000,0x6000000,0x4000000,0x4000000,0x4000000,0x29000000,0x8b131313,0xdb6a6a6a,0xffd7d6d4,0xff969692,0xcb000000,
    0x39000000,0x14000000,0x0,0x2000000,0xff000000,0xffd8d6d2,0xff000000,0x4e000000,0x2b000000,0xe000000,0x4000000,0x1000000,0x0,0x1000000,
    0x5e000000,0xbe3d3d3d,0xe26c6c6c,0xf8d6d6d4,0xffe0dfde,0xff787774,0xff22211f,0x66000000,0x2f000000,0xe000000,0x0,0x2000000,0x91000000,0xff8b8881,
    0xff262422,0xe8201f1e,0xac000000,0x12000000,0x8000000,0x59000000,0xa2202020,0xdf727272,0xffa3a3a2,0xffe4e2df,0xffe7e5e3,0xff71706c,0xff262624,0xff000000,
    0x61000000,0x3e000000,0x1b000000,0x6000000,0x0,0x2000000,0x3b000000,0xff000000,0xffd7d7d3,0xffe2e0dc,0xffe2dfdc,0xff0b0b0b,0xff484846,0xff939291,
    0xffc4c1be,0xffd6d4ce,0xffa7a49e,0xff383735,0xf0090908,0xcc000000,0x53000000,0x48000000,0x3c000000,0x21000000,0xa000000,0x1000000,0x0,0x1000000,
    0xe5000000,0xffe0dedd,0xffcfcbc4,0xff63605c,0xffb8b5b0,0xffb2b1ad,0xff5c5b57,0xff837f79,0xff3c3a36,0xea000000,0xde000000,0x54000000,0x46000000,0x3c000000,
    0x2f000000,0x22000000,0x16000000,0x9000000,0x2000000,0x0,0x0,0x2000000,0xb7000000,0xffd0cdc6,0xff999692,0xff66645d,0xff151515,0xffa6a5a1,
    0xff000000,0xd8000000,0x60000000,0x46000000,0x3a000000,0x2f000000,0x21000000,0x16000000,0xe000000,0x7000000,0x3000000,0x1000000,0x0,0x0,
    0x0,0x2000000,0xf000000,0xff363636,0xff817f7b,0xff393633,0xff8c8884,0xff0b0b0b,0x7a000000,0x4a000000,0x34000000,0x21000000,0x16000000,0xe000000,
    0x7000000,0x3000000,0x2000000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7000000,0x1d000000,0xc2000000,0xff000000,
    0xffafaca6,0xd8000000,0x4c000000,0x2a000000,0x12000000,0x7000000,0x3000000,0x2000000,0x0,0x0,0x0,0x0,0x0,0x0,
    0x0,0x0,0x0,0x0,0x2000000,0xa000000,0x1f000000,0xdc6c6965,0xffdbdad5,0xd5000000,0x3c000000,0x17000000,0x4000000,0x0,
    0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x2000000,
    0xd40c0c0c,0xffdad7d2,0xf4212121,0x9b000000,0x2e000000,0xe000000,0x2000000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
    0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1000000,0xc000000,0xd0000000,0x71000000,0x37000000,0x1a000000,0x6000000,
    0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
    0x0,0x0,0x6000000,0x17000000,0x24000000,0x1a000000,0x9000000,0x1000000,0x0,0x0,0x0,0x0,0x0,0x0,
    0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1000000,0x6000000,0xa000000,0x6000000,
    0x1000000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
    0x0,0x0,0x0,0x0,0x0,0x0,0x1000000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
    0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0
};

/* Generated by qembed */
static struct EmbedImage {
    int width, height, depth;
    const unsigned char *data;
    int numColors;
    const QRgb *colorTable;
    bool alpha;
    const char *name;
} embed_image_vec[] = {
    { 22, 22, 32, (const unsigned char*)segmentation_data, 0, 0, TRUE, "segmentation" },
    { 0, 0, 0, 0, 0, 0, 0, 0 }
};

static const QImage& qembed_findImage( const QString& name )
{
    static QDict<QImage> dict;
    QImage* img = dict.find( name );
    if ( !img ) {
  for ( int i = 0; embed_image_vec[i].data; i++ ) {
      if ( strcmp(embed_image_vec[i].name, name.latin1()) == 0 ) {
    img = new QImage((uchar*)embed_image_vec[i].data,
          embed_image_vec[i].width,
          embed_image_vec[i].height,
          embed_image_vec[i].depth,
          (QRgb*)embed_image_vec[i].colorTable,
          embed_image_vec[i].numColors,
          QImage::BigEndian );
    if ( embed_image_vec[i].alpha )
        img->setAlphaBuffer( TRUE );
    dict.insert( name, img );
    break;
      }
  }
  if ( !img ) {
      static QImage dummy;
      return dummy;
  }
    }
    return *img;
}

#endif
