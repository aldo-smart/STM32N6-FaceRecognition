#pragma once

/* Nada disso deve ser visto pelo assembler (.s/.S) */
#ifndef __ASSEMBLER__

#include <math.h>
#include <float.h>

#ifndef INFINITY
#define INFINITY (1.0f/0.0f)
#endif

#ifndef inf
#define inf INFINITY
#endif

#ifndef EpochBlock_Flags_blob_encrypted
#define EpochBlock_Flags_blob_encrypted EpochBlock_Flags_NONE
#endif

#endif /* __ASSEMBLER__ */
