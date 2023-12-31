#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "geo_commands.h"

#include "make_const_nonconst.h"

// Note: This bin does not use bin IDs, unlike the other segmented bins.
#include "mario/model.inc.c"

#include "bubble/model.inc.c"

#include "walk_smoke/model.inc.c"

#include "burn_smoke/model.inc.c"

#include "small_water_splash/model.inc.c"

#include "water_wave/model.inc.c"

#include "sparkle/model.inc.c"

#include "water_splash/model.inc.c"

#include "white_particle_small/model.inc.c"

#include "sparkle_animation/model.inc.c"

#ifdef S2DEX_TEXT_ENGINE
#include "src/s2d_engine/config.h"
#include FONT_C_FILE
#endif

#include "mario/anims/data.inc.c"
#include "mario/anims/table.inc.c"
#include "lakitu_cameraman/model.inc.c"
#include "lakitu_cameraman/anims/data.inc.c"
#include "lakitu_cameraman/anims/table.inc.c"
#include "CustomBob/model.inc.c"
#include "HighStrikerBell/model.inc.c"
#include "HighStrikerBell/anims/data.inc.c"
#include "HighStrikerBell/anims/table.inc.c"
#include "HighStrikerRinger/model.inc.c"
#include "HighStrikerRinger/anims/data.inc.c"
#include "HighStrikerRinger/anims/table.inc.c"
#include "HighStrikerCarnie/model.inc.c"
#include "HighStrikerCarnie/anims/data.inc.c"
#include "HighStrikerCarnie/anims/table.inc.c"
#include "warp_pipe_blue/model.inc.c"
#include "warp_pipe_yellow/model.inc.c"
#include "warp_pipe_red/model.inc.c"
#include "Goombaplatform/model.inc.c"
#include "Goombaplatform/anims/data.inc.c"
#include "Goombaplatform/anims/table.inc.c"
#include "Whompplatform/model.inc.c"
#include "CowboyToad/model.inc.c"
#include "SpelunkerToad/model.inc.c"
#include "CarnieToad/model.inc.c"
#include "BossFappy/model.inc.c"
#include "BossFappy/anims/data.inc.c"
#include "BossFappy/anims/table.inc.c"
#include "ferrisplatform/model.inc.c"