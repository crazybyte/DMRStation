/*
 * Copyright (C) 2010 mbelib Author
 * GPG Key ID: 0xEA5EFE2C (9E7A 5527 9CDC EBF7 BF1B  D772 4F98 E863 EA5E FE2C)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "fw_mbelib.h"

const int golayGenerator[12] = {
  0x63a, 0x31d, 0x7b4, 0x3da, 0x1ed, 0x6cc, 0x366, 0x1b3, 0x6e3, 0x54b, 0x49f, 0x475
};

const int golayMatrix[2048] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 2084, 0, 0, 0, 769, 0, 1024, 144,
  2, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 72, 0, 72, 72, 72, 0, 0, 0, 16, 0, 1, 1538, 384, 0, 134, 2048, 1056, 288,
  2576, 5, 72, 0, 0, 0, 0, 0, 0, 0, 1280, 0, 0, 0, 4, 0, 546, 144, 2049, 0, 0, 0, 66, 0, 1, 144, 520, 0, 2056, 144,
  1056, 144, 324, 144, 144, 0, 0, 0, 2688, 0, 1, 32, 22, 0, 272, 3, 1056, 3076, 128, 768, 72, 0, 1, 268, 1056, 1, 1, 2112, 1, 576,
  1056, 1056, 1056, 10, 1, 144, 1056, 0, 0, 0, 0, 0, 0, 0, 1280, 0, 0, 0, 160, 0, 21, 2560, 2, 0, 0, 0, 16, 0, 704, 9,
  2, 0, 2056, 1092, 2, 288, 2, 2, 2, 0, 0, 0, 16, 0, 2050, 132, 545, 0, 1536, 3, 2308, 288, 128, 1040, 72, 0, 16, 16, 16, 288,
  1036, 2112, 16, 288, 65, 648, 16, 288, 288, 288, 2, 0, 0, 0, 1280, 0, 1280, 1280, 1280, 0, 2056, 3, 592, 64, 128, 44, 1280, 0, 2056, 544,
  133, 6, 48, 2112, 1280, 2056, 2056, 256, 2056, 1537, 2056, 144, 2, 0, 100, 3, 8, 536, 128, 2112, 1280, 3, 128, 3, 3, 128, 128, 3, 128, 1152,
  770, 2112, 16, 2112, 1, 2112, 2112, 20, 2056, 3, 1056, 288, 128, 2112, 516, 0, 0, 0, 0, 0, 0, 0, 131, 0, 0, 0, 4, 0, 1024, 2560,
  304, 0, 0, 0, 16, 0, 1024, 320, 520, 0, 1024, 42, 2240, 1024, 1024, 5, 1024, 0, 0, 0, 16, 0, 772, 32, 3072, 0, 2081, 1408, 514, 18,
  128, 5, 72, 0, 16, 16, 16, 2184, 98, 5, 16, 576, 264, 5, 16, 5, 1024, 5, 5, 0, 0, 0, 4, 0, 2128, 32, 520, 0, 4, 4,
  4, 265, 128, 1090, 4, 0, 416, 3073, 520, 6, 520, 520, 520, 576, 19, 256, 4, 2080, 1024, 144, 520, 0, 1034, 32, 321, 32, 128, 32, 32, 576,
  128, 2072, 4, 128, 128, 32, 128, 576, 2052, 130, 16, 1296, 1, 32, 520, 576, 576, 576, 1056, 576, 128, 5, 2306, 0, 0, 0, 16, 0, 40, 2560,
  68, 0, 322, 2560, 1033, 2560, 128, 2560, 2560, 0, 16, 16, 16, 6, 2305, 1184, 16, 129, 548, 256, 16, 88, 1024, 2560, 2, 0, 16, 16, 16, 1089,
  128, 266, 16, 12, 128, 96, 16, 128, 128, 2560, 128, 16, 16, 16, 16, 512, 16, 16, 16, 3074, 16, 16, 16, 288, 128, 5, 16, 0, 513, 200,
  2082, 6, 128, 17, 1280, 1072, 128, 256, 4, 128, 128, 2560, 128, 6, 1088, 256, 16, 6, 6, 6, 520, 256, 2056, 256, 256, 6, 128, 256, 97, 2304,
  128, 1540, 16, 128, 128, 32, 128, 128, 128, 3, 128, 128, 128, 128, 128, 41, 16, 16, 16, 6, 128, 2112, 16, 576, 128, 256, 16, 128, 128, 1032,
  128, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0, 160, 0, 1024, 262, 2049, 0, 0, 0, 66, 0, 1024, 9, 384, 0, 1024, 2048, 28, 1024,
  1024, 608, 1024, 0, 0, 0, 1029, 0, 2050, 32, 384, 0, 272, 2048, 514, 641, 36, 1040, 72, 0, 552, 2048, 384, 84, 384, 384, 384, 2048, 65, 2048,
  2048, 10, 1024, 2048, 384, 0, 0, 0, 66, 0, 140, 32, 2049, 0, 272, 1544, 2049, 64, 2049, 2049, 2049, 0, 66, 66, 66, 2816, 48, 1028, 66, 37,
  640, 256, 66, 10, 1024, 144, 2049, 0, 272, 32, 8, 32, 1600, 32, 32, 272, 272, 196, 272, 10, 272, 32, 2049, 1152, 2052, 529, 66, 10, 1, 32,
  384, 10, 272, 2048, 1056, 10, 10, 10, 516, 0, 0, 0, 160, 0, 2050, 9, 68, 0, 160, 160, 160, 64, 776, 1040, 160, 0, 260, 9, 3584, 9,
  48, 9, 9, 530, 65, 256, 160, 2180, 1024, 9, 2, 0, 2050, 832, 8, 2050, 2050, 1040, 2050, 12, 65, 1040, 160, 1040, 2050, 1040, 1040, 1152, 65, 38,
  16, 512, 2050, 9, 384, 65, 65, 2048, 65, 288, 65, 1040, 516, 0, 513, 2068, 8, 64, 48, 642, 1280, 64, 1030, 256, 160, 64, 64, 64, 2049, 1152,
  48, 256, 66, 48, 48, 9, 48, 256, 2056, 256, 256, 64, 48, 256, 516, 1152, 8, 8, 8, 261, 2050, 32, 8, 2592, 272, 3, 8, 64, 128, 1040,
  516, 1152, 1152, 1152, 8, 1152, 48, 2112, 516, 1152, 65, 256, 516, 10, 516, 516, 516, 0, 0, 0, 2312, 0, 1024, 32, 68, 0, 1024, 81, 514, 1024,
  1024, 136, 1024, 0, 1024, 644, 33, 1024, 1024, 2066, 1024, 1024, 1024, 256, 1024, 1024, 1024, 1024, 1024, 0, 192, 32, 514, 32, 25, 32, 32, 12, 514, 514,
  514, 2368, 1024, 32, 514, 259, 2052, 1096, 16, 512, 1024, 32, 384, 176, 1024, 2048, 514, 1024, 1024, 5, 1024, 0, 513, 32, 1168, 32, 258, 32, 32, 2178,
  104, 256, 4, 532, 1024, 32, 2049, 24, 2052, 256, 66, 193, 1024, 32, 520, 256, 1024, 256, 256, 1024, 1024, 256, 1024, 32, 2052, 32, 32, 32, 32, 32,
  32, 1025, 272, 32, 514, 32, 128, 32, 32, 2052, 2052, 32, 2052, 32, 2052, 32, 32, 576, 2052, 256, 137, 10, 1024, 32, 80, 0, 513, 1026, 68, 400,
  68, 68, 68, 12, 2064, 256, 160, 35, 1024, 2560, 68, 2144, 138, 256, 16, 512, 1024, 9, 68, 256, 1024, 256, 256, 1024, 1024, 256, 1024, 12, 1312, 2177,
  16, 512, 2050, 32, 68, 12, 12, 12, 514, 12, 128, 1040, 257, 512, 16, 16, 16, 512, 512, 512, 16, 12, 65, 256, 16, 512, 1024, 194, 2088, 513,
  513, 256, 513, 3080, 513, 32, 68, 256, 513, 256, 256, 64, 128, 256, 26, 256, 513, 256, 256, 6, 48, 256, 2176, 256, 256, 256, 256, 256, 1024, 256,
  256, 82, 513, 32, 8, 32, 128, 32, 32, 12, 128, 256, 3136, 128, 128, 32, 128, 1152, 2052, 256, 16, 512, 328, 32, 1027, 256, 34, 256, 256, 2065,
  128, 256, 516, 0, 0, 0, 0, 0, 0, 0, 528, 0, 0, 0, 4, 0, 2432, 1057, 2, 0, 0, 0, 1160, 0, 1, 320, 2, 0, 112, 2048,
  2, 524, 2, 2, 2, 0, 0, 0, 290, 0, 1, 132, 3072, 0, 1536, 2048, 145, 18, 36, 768, 72, 0, 1, 2048, 580, 1, 1, 56, 1, 2048,
  264, 2048, 2048, 1216, 1, 2048, 2, 0, 0, 0, 4, 0, 1, 2058, 224, 0, 4, 4, 4, 64, 1048, 768, 4, 0, 1, 544, 2320, 1, 1, 1028,
  1, 1282, 640, 73, 4, 2080, 1, 144, 2, 0, 1, 1104, 8, 1, 1, 768, 1, 168, 2114, 768, 4, 768, 1, 768, 768, 1, 1, 130, 1, 1,
  1, 1, 1, 20, 1, 2048, 1056, 1, 1, 768, 1, 0, 0, 0, 2113, 0, 40, 132, 2, 0, 1536, 280, 2, 64, 2, 2, 2, 0, 260, 544,
  2, 3088, 2, 2, 2, 129, 2, 2, 2, 2, 2, 2, 2, 0, 1536, 132, 8, 132, 336, 132, 132, 1536, 1536, 96, 1536, 2057, 1536, 132, 2, 74,
  2208, 1281, 16, 512, 1, 132, 2, 20, 1536, 2048, 2, 288, 2, 2, 2, 0, 146, 544, 8, 64, 2564, 17, 1280, 64, 289, 3200, 4, 64, 64, 64,
  2, 544, 1088, 544, 544, 392, 1, 544, 2, 20, 2056, 544, 2, 64, 2, 2, 2, 2304, 8, 8, 8, 1058, 1, 132, 8, 20, 1536, 3, 8, 64,
  128, 768, 2096, 20, 1, 544, 8, 1, 1, 2112, 1, 20, 20, 20, 448, 20, 1, 1032, 2, 0, 0, 0, 4, 0, 40, 320, 3072, 0, 4, 4,
  4, 18, 577, 136, 4, 0, 2562, 320, 33, 320, 148, 320, 320, 129, 264, 1552, 4, 2080, 1024, 320, 2, 0, 192, 521, 3072, 18, 3072, 3072, 3072, 18,
  264, 96, 4, 18, 18, 18, 3072, 1060, 264, 130, 16, 512, 1, 320, 3072, 264, 264, 2048, 264, 18, 264, 5, 672, 0, 4, 4, 4, 1664, 258, 17,
  4, 4, 4, 4, 4, 2080, 4, 4, 4, 24, 1088, 130, 4, 2080, 1, 320, 520, 2080, 4, 4, 4, 2080, 2080, 2080, 4, 2304, 560, 130, 4, 76,
  1, 32, 3072, 1025, 4, 4, 4, 18, 128, 768, 4, 130, 1, 130, 130, 1, 1, 130, 1, 576, 264, 130, 4, 2080, 1, 1032, 80, 0, 40, 1026,
  896, 40, 40, 17, 40, 129, 2064, 96, 4, 1284, 40, 2560, 2, 129, 1088, 2060, 16, 512, 40, 320, 2, 129, 129, 129, 2, 129, 2, 2, 2, 2304,
  7, 96, 16, 512, 40, 132, 3072, 96, 1536, 96, 96, 18, 128, 96, 257, 512, 16, 16, 16, 512, 512, 512, 16, 129, 264, 96, 16, 512, 2116, 1032,
  2, 2304, 1088, 17, 4, 17, 40, 17, 17, 522, 4, 4, 4, 64, 128, 17, 4, 1088, 1088, 544, 1088, 6, 1088, 17, 2176, 129, 1088, 256, 4, 2080,
  784, 1032, 2, 2304, 2304, 2304, 8, 2304, 128, 17, 578, 2304, 128, 96, 4, 128, 128, 1032, 128, 2304, 1088, 130, 16, 512, 1, 1032, 292, 20, 34, 1032,
  2561, 1032, 128, 1032, 1032, 0, 0, 0, 528, 0, 528, 528, 528, 0, 11, 2048, 1344, 64, 36, 136, 528, 0, 260, 2048, 33, 162, 2120, 1028, 528, 2048,
  640, 2048, 2048, 273, 1024, 2048, 2, 0, 192, 2048, 8, 1288, 36, 67, 528, 2048, 36, 2048, 2048, 36, 36, 2048, 36, 2048, 1042, 2048, 2048, 512, 1, 2048,
  384, 2048, 2048, 2048, 2048, 2048, 36, 2048, 2048, 0, 3104, 385, 8, 64, 258, 1028, 528, 64, 640, 50, 4, 64, 64, 64, 2049, 24, 640, 1028, 66, 1028,
  1, 1028, 1028, 640, 640, 2048, 640, 64, 640, 1028, 296, 518, 8, 8, 8, 2192, 1, 32, 8, 1025, 272, 2048, 8, 64, 36, 768, 1154, 352, 1, 2048,
  8, 1, 1, 1028, 1, 2048, 640, 2048, 2048, 10, 1, 2048, 80, 0, 260, 1026, 8, 64, 1153, 2336, 528, 64, 2064, 517, 160, 64, 64, 64, 2, 260,
  260, 208, 260, 512, 260, 9, 2, 1064, 260, 2048, 2, 64, 2, 2, 2, 49, 8, 8, 8, 512, 2050, 132, 8, 386, 1536, 2048, 8, 64, 36, 1040,
  257, 512, 260, 2048, 8, 512, 512, 512, 1120, 2048, 65, 2048, 2048, 512, 152, 2048, 2, 64, 8, 8, 8, 64, 64, 64, 8, 64, 64, 64, 8, 64,
  64, 64, 64, 2051, 260, 544, 8, 64, 48, 1028, 2176, 64, 640, 256, 1041, 64, 64, 64, 2, 8, 8, 8, 8, 64, 8, 8, 8, 64, 8, 8,
  8, 64, 64, 64, 8, 1152, 8, 8, 8, 512, 1, 274, 8, 20, 34, 2048, 8, 64, 3328, 161, 516, 0, 192, 1026, 33, 2053, 258, 136, 528, 800,
  2064, 136, 4, 136, 1024, 136, 136, 24, 33, 33, 33, 512, 1024, 320, 33, 70, 1024, 2048, 33, 1024, 1024, 136, 1024, 192, 192, 276, 192, 512, 192, 32,
  3072, 1025, 192, 2048, 514, 18, 36, 136, 257, 512, 192, 2048, 33, 512, 512, 512, 14, 2048, 264, 2048, 2048, 512, 1024, 2048, 80, 24, 258, 2624, 4, 258,
  258, 32, 258, 1025, 4, 4, 4, 64, 258, 136, 4, 24, 24, 24, 33, 24, 258, 1028, 2176, 24, 640, 256, 4, 2080, 1024, 515, 80, 1025, 192, 32,
  8, 32, 258, 32, 32, 1025, 1025, 1025, 4, 1025, 2568, 32, 80, 24, 2052, 130, 1792, 512, 1, 32, 80, 1025, 34, 2048, 80, 388, 80, 80, 80, 1026,
  2064, 1026, 1026, 512, 40, 1026, 68, 2064, 2064, 1026, 2064, 64, 2064, 136, 257, 512, 260, 1026, 33, 512, 512, 512, 2176, 129, 2064, 256, 584, 512, 1024, 52,
  2, 512, 192, 1026, 8, 512, 512, 512, 257, 12, 2064, 96, 257, 512, 257, 257, 257, 512, 512, 512, 16, 512, 512, 512, 512, 512, 34, 2048, 1156, 512,
  512, 512, 257, 164, 513, 1026, 8, 64, 258, 17, 2176, 64, 2064, 256, 4, 64, 64, 64, 1568, 24, 1088, 256, 2176, 512, 2176, 2176, 2176, 256, 34, 256,
  256, 64, 13, 256, 2176, 2304, 8, 8, 8, 512, 1044, 32, 8, 1025, 34, 656, 8, 64, 128, 2054, 257, 512, 34, 69, 8, 512, 512, 512, 2176, 34,
  34, 256, 34, 512, 34, 1032, 80
};

/*
 * DMR AMBE interleave schedule
 */


const int rW[36] = {
  0, 1, 0, 1, 0, 1,
  0, 1, 0, 1, 0, 1,
  0, 1, 0, 1, 0, 1,
  0, 1, 0, 1, 0, 2,
  0, 2, 0, 2, 0, 2,
  0, 2, 0, 2, 0, 2
};

const int rX[36] = {
  23, 10, 22, 9, 21, 8,
  20, 7, 19, 6, 18, 5,
  17, 4, 16, 3, 15, 2,
  14, 1, 13, 0, 12, 10,
  11, 9, 10, 8, 9, 7,
  8, 6, 7, 5, 6, 4
};

const int rY[36] = {
  0, 2, 0, 2, 0, 2,
  0, 2, 0, 3, 0, 3,
  1, 3, 1, 3, 1, 3,
  1, 3, 1, 3, 1, 3,
  1, 3, 1, 3, 1, 3,
  1, 3, 1, 3, 1, 3
};

const int rZ[36] = {
  5, 3, 4, 2, 3, 1,
  2, 0, 1, 13, 0, 12,
  22, 11, 21, 10, 20, 9,
  19, 8, 18, 7, 17, 6,
  16, 5, 15, 4, 14, 3,
  13, 2, 12, 1, 11, 0
};


void mbe_checkGolayBlock (long int *block)
{
  static int i, syndrome, eccexpected, eccbits, databits;
  long int mask, block_l;

  block_l = *block;

  mask = 0x400000l;
  eccexpected = 0;
  for (i = 0; i < 12; i++)
    {
      if ((block_l & mask) != 0l)
        {
          eccexpected ^= golayGenerator[i];
        }
      mask = mask >> 1;
    }
  eccbits = (int) (block_l & 0x7ffl);
  syndrome = eccexpected ^ eccbits;

  databits = (int) (block_l >> 11);
  databits = databits ^ golayMatrix[syndrome];

  *block = (long) databits;
}

int mbe_golay2312 (char *in, char *out)
{

  int i, errs;
  long block;

  block = 0;
  for (i = 22; i >= 0; i--)
    {
      block = block << 1;
      block = block + in[i];
    }

  mbe_checkGolayBlock (&block);

  for (i = 22; i >= 11; i--)
    {
      out[i] = (block & 2048) >> 11;
      block = block << 1;
    }
  for (i = 10; i >= 0; i--)
    {
      out[i] = in[i];
    }

  errs = 0;
  for (i = 22; i >= 11; i--)
    {
      if (out[i] != in[i])
        {
          errs++;
        }
    }
  return (errs);
}


int mbe_eccAmbe3600x2450C0 (char ambe_fr[4][24])
{

  int j, errs;
  char in[23], out[23];

  for (j = 0; j < 23; j++)
    {
      in[j] = ambe_fr[0][j + 1];
    }
  errs = mbe_golay2312 (in, out);
  // ambe_fr[0][0] should be the C0 golay24 parity bit.
  // TODO: actually test that here...
  for (j = 0; j < 23; j++)
    {
      ambe_fr[0][j + 1] = out[j];
    }

  return (errs);
}

int mbe_eccAmbe3600x2450Data (char ambe_fr[4][24], char *ambe_d)
{

  int j, errs;
  char *ambe, gin[24], gout[24];

  ambe = ambe_d;
  // just copy C0
  for (j = 23; j > 11; j--)
    {
      *ambe = ambe_fr[0][j];
      ambe++;
    }

  // ecc and copy C1
  for (j = 0; j < 23; j++)
    {
      gin[j] = ambe_fr[1][j];
    }
  errs = mbe_golay2312 (gin, gout);
  for (j = 22; j > 10; j--)
    {
      *ambe = gout[j];
      ambe++;
    }

  // just copy C2
  for (j = 10; j >= 0; j--)
    {
      *ambe = ambe_fr[2][j];
      ambe++;
    }

  // just copy C3
  for (j = 13; j >= 0; j--)
    {
      *ambe = ambe_fr[3][j];
      ambe++;
    }

  return (errs);
}

void mbe_demodulateAmbe3600x2450Data (char ambe_fr[4][24])
{
  int i, j, k;
  unsigned short pr[115];
  unsigned short foo = 0;

  // create pseudo-random modulator
  for (i = 23; i >= 12; i--)
    {
      foo <<= 1;
      foo |= ambe_fr[0][i];
    }
  pr[0] = (16 * foo);
  for (i = 1; i < 24; i++)
    {
      pr[i] = (173 * pr[i - 1]) + 13849 - (65536 * (((173 * pr[i - 1]) + 13849) / 65536));
    }
  for (i = 1; i < 24; i++)
    {
      pr[i] = pr[i] / 32768;
    }

  // demodulate ambe_fr with pr
  k = 1;
  for (j = 22; j >= 0; j--)
    {
      ambe_fr[1][j] = ((ambe_fr[1][j]) ^ pr[k]);
      k++;
    }
}

void prepare_framedata(uint8_t *indata, char *ambe_d, int *errs, int *errs2)
{
	char ambe_fr[4][24];
	int *w, *x, *y, *z;
	uint8_t rampos = 0;

	w = (int*)rW;
	x = (int*)rX;
	y = (int*)rY;
	z = (int*)rZ;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ambe_fr[*w][*x] = (indata[rampos]>>(7-(2*j))) & 1;
			ambe_fr[*y][*z] = (indata[rampos]>>(7-(2*j+1))) & 1;
			w++;
			x++;
			y++;
			z++;
		}
		rampos++;
	}

    *errs = 0;
    *errs2 = 0;
    *errs = mbe_eccAmbe3600x2450C0 (ambe_fr);
    mbe_demodulateAmbe3600x2450Data (ambe_fr);
    *errs2 = *errs;
    *errs2 += mbe_eccAmbe3600x2450Data (ambe_fr, ambe_d);
}



void interleave(uint8_t *ambe_fr, uint8_t *dataOut)
{
	int bitIndex = 0;
	int	w = 0;
	int x = 0;
	int	y = 0;
	int z = 0;
	uint8_t bit0;
	uint8_t bit1;

	for (int i = 0; i<36; i++)
	{
		bit1 = ambe_fr[rW[w] * 24 + rX[x]]; // bit 1
		bit0 = ambe_fr[rY[y] * 24 + rZ[z]]; // bit 0

		dataOut[bitIndex >> 3] = ((dataOut[bitIndex >> 3] << 1) & 0xfe) | bit1;
		bitIndex ++;

		dataOut[bitIndex >> 3] = ((dataOut[bitIndex >> 3] << 1) & 0xfe) | bit0;
		bitIndex++;

		w++;
		x++;
		y++;
		z++;
	}
}

/**
* This function checks the overall parity of codeword cw.
* If parity is even, 0 is returned, else 1.
**/

int parity(int cw) {
    /* XOR the bytes of the codeword */
    int p = cw & 0xff;
    p = p ^ ((cw >> 8) & 0xff);
    p = p ^ ((cw >> 16) & 0xff);

    /* XOR the halves of the intermediate result */
    p = p ^ (p >> 4);
    p = p ^ (p >> 2);
    p = p ^ (p >> 1);

    /* return the parity result */
    return(p & 1);
}

/**
* This function calculates [23,12] Golay codewords.
* The format of the returned longint is [checkbits(11),data(12)].
**/
int golay2312word(int cw) {
    int POLY = 0xAE3;            /* or use the other polynomial, 0xC75 */
    cw = cw & 0x0fff;             // Strip off check bits and only use data
    int c = cw;                      /* save original codeword */
    for (int i = 1; i<13; i++) {
                               /* examine each data bit */
        if (cw & 1) {            /* test data bit */
            cw = cw ^ POLY;      /* XOR polynomial */
        }
        cw = cw >> 1;            /* shift intermediate result */
    }
    return((cw << 12) | c);      /* assemble codeword */
}

void convert49BitAmbeTo72BitFrames(uint8_t *inAmbe49bits, uint8_t *ambe_frOut)
{
	//Place bits into the 4x24 frames.  [bit0...bit23]
	//fr0: [P e10 e9 e8 e7 e6 e5 e4 e3 e2 e1 e0 11 10 9 8 7 6 5 4 3 2 1 0]
	//fr1: [e10 e9 e8 e7 e6 e5 e4 e3 e2 e1 e0 23 22 21 20 19 18 17 16 15 14 13 12 xx]
	//fr2: [34 33 32 31 30 29 28 27 26 25 24 x x x x x x x x x x x x x]
	//fr3: [48 47 46 45 44 43 42 41 40 39 38 37 36 35 x x x x x x x x x x]

	// ecc and copy C0: 12bits + 11ecc + 1 parity
	// First get the 12 bits that actually exist
	// Then calculate the golay codeword
	// And then add the parity bit to get the final 24 bit pattern

	int tmp = 0;

	//grab the 12 MSB
	for (int i = 11; i>-1; i--) {
		tmp = (tmp << 1) | (inAmbe49bits[i] ? 1 : 0);
	}

	tmp = golay2312word(tmp);               //Generate the 23 bit result
	int parityBit = parity(tmp);
	tmp = tmp | (parityBit << 23);           //And create a full 24 bit value

	for (int i = 23; i>-1; i--) {
		ambe_frOut[i] = (tmp & 1);
		tmp = tmp >> 1;
	}

	// C1: 12 bits + 11ecc (no parity)
	tmp = 0;
	//grab the next 12 bits
	for (int i = 23; i>11; i--) {
		tmp = (tmp << 1) | (inAmbe49bits[i] ? 1 : 0);
	}

	tmp = golay2312word(tmp);                    //Generate the 23 bit result

	for (int j = 22; j>-1; j--) {
		ambe_frOut[1*24 + j] =  tmp & 1;
		tmp = tmp >> 1;
	}

	//C2: 11 bits (no ecc)
	for (int j = 10; j>-1; j--) {
		ambe_frOut[2*24 + j] = inAmbe49bits[34 - j];
	}

	//C3: 14 bits (no ecc)
	for (int j = 13; j>-1; j--) {
		ambe_frOut[3*24 + j] = inAmbe49bits[48 - j];
	}

}
