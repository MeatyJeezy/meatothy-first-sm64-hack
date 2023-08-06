
/**
 * Behavior for bhvFappy. This includes both the intro lakitu and the
 * lakitu visible in the mirror room.
 * TODO: Processing order relative to bhvCloud
 */

/**
 * Init function for camera lakitu.
 * If this is the intro lakitu, despawn unless this is the start of the game.
 * Spawn cloud if not the intro lakitu.
 */
// NEW enum for fappy bigtop dialogue
enum FappyBigtopDialog {
    FAPPY_BIGTOP_DIALOG_0   = 0x0,
    FAPPY_BIGTOP_DIALOG_1   = 0x1,
    FAPPY_BIGTOP_DIALOG_2   = 0x2,
    FAPPY_BIGTOP_DIALOG_3   = 0x3
};
// Lock Mario in place prepare for cutscene
static void bigtop_act_trigger_cutscene(void) {
    // struct Camera *c = gCurrentArea->camera;
    if (o->oDistanceToMario < 6000.0f) {
        o->oAnimState = FAPPY_ANIM_DEFAULT;
        if (set_mario_npc_dialog(MARIO_DIALOG_LOOK_UP) == MARIO_DIALOG_STATUS_START) { // CHANGED to detect Proximity instead of hard-coded values
            // Move cam up and towards Fappy
            // if (gPlayerCameraState->pos[1] < 3000.0f) {
            //     gPlayerCameraState->pos[1] += 1000.0f;
            //     if (gPlayerCameraState->pos[1] >= 3000.0f) {
            //         gPlayerCameraState->pos[0] -= 1000.0f;
                    o->oAction = BIGTOP_ACT_MOVE_CAMERA;
                //}
            // }
        }
    }
}

static void bigtop_act_move_camera(void) {
    //f32 focusDistance;
    Vec3f focus;
    s16 pitch;
    s16 yaw;
    // struct Camera *c = gCurrentArea->camera;
    //if (set_mario_npc_dialog(MARIO_DIALOG_LOOK_UP) == MARIO_DIALOG_STATUS_START) {
        switch (o->oBehParams2ndByte) {
        case BIGTOP_FIRST_CUTSCENE:
        // Move camera up and towards Fappy
            // while (gPlayerCameraState->pos[1] < 2000.0f) {
            //     gPlayerCameraState->pos[1] += 500.0f;
            //     if (gPlayerCameraState->pos[1] >= 2000.0f) {
            //         gPlayerCameraState->pos[0] -= 1000.0f;
            //     }
            // }
            // set camera focus to Fappy
            //vec3f_set(gCamera->focus, o->oPosX, o->oPosY, o->oPosZ);
            focus[0] = o->oPosX;
            focus[1] = o->oPosY + 400.0f;
            focus[2] = o->oPosZ;
            // focusDistance = calc_abs_dist(gPlayerCameraState->pos, focus);
            
            // get pitch and yaw from camera pos and Fappy focus[] xyz values.
            yaw = calculate_yaw(gPlayerCameraState->pos, focus);
            pitch = calculate_pitch(gPlayerCameraState->pos, focus);
            // vec3f_get_yaw(gPlayerCameraState->pos, focus, &yaw);
            // vec3f_get_pitch(gPlayerCameraState->pos, focus, &pitch);

            approach_vec3f_asymptotic(gPlayerCameraState->pos, focus, 0.9f, 0.9f, 0.9f);

            // approach_f32_asymptotic_bool(f32 *current, f32 target, f32 multiplier)
            gPlayerCameraState->faceAngle[0] = pitch;
            gPlayerCameraState->faceAngle[1] = yaw + 200;

            // Wait x frames before opening dialogue
            if (o->oTimer < 240) {
                o->oTimer++;
            }
            // Once dialog is done, advance action
            else if (cur_obj_update_dialog(MARIO_DIALOG_LOOK_UP,
            DIALOG_FLAG_TEXT_DEFAULT, FAPPY_BIGTOP_DIALOG_0, 0)) {
                o->oAction = BIGTOP_ACT_SHOW_DIALOG;
            }
            
            
            
            // if (c->cutscene == CUTSCENE_NONE) {
            //     c->cutscene = CUTSCENE_BIGTOP_1; // Setting this should play the cutscene I think?
                //start_cutscene(c, CUTSCENE_BIGTOP_1);
            // } 
            break;
        case BIGTOP_SECOND_CUTSCENE:
        break;
        }
    //}
}

static void bigtop_act_show_dialog(void) {
    cur_obj_hide();
}
// void bhv_camera_lakitu_init(void) {
//     if (o->oBehParams2ndByte != CAMERA_LAKITU_BP_FOLLOW_CAMERA) {
//         // Despawn unless this is the very beginning of the game
//         cur_obj_hide();
//         // if (gNeverEnteredCastle != TRUE) {
//         //     obj_mark_for_deletion(o);
//         // }
//     } else {
//         //spawn_object_relative_with_scale(CLOUD_BP_LAKITU_CLOUD, 0, 0, 0, 2.0f, o, MODEL_MIST, bhvCloud);
//     }
// }
// // NEW chooses Dialog constant based on second byte param
// s32 get_dialogue_from_param(void) {
//     u8 param = o->oBehParams2ndByte;
//     switch(param) {
//         case FAPPY_DIALOG_1: return DIALOG_034; break;
//         case FAPPY_DIALOG_2: return DIALOG_035; break;
//         case FAPPY_DIALOG_3: return DIALOG_036; break;
//     }
//     return DIALOG_034;
// }

/**
 * 
 */
// static void camera_lakitu_intro_act_trigger_cutscene(void) {
//     //! These bounds are slightly smaller than the actual bridge bounds, allowing
//     //  the RTA speedrunning method of lakitu skip
//     if (o->oDistanceToMario < 600.0f) {
//         if (set_mario_npc_dialog(MARIO_DIALOG_LOOK_UP) == MARIO_DIALOG_STATUS_START) { // CHANGED to detect Lakitu Proximity instead of hard-coded values
//             o->oAction = CAMERA_LAKITU_INTRO_ACT_SPAWN_CLOUD;
//         }
//     }
//     // if (gMarioObject->oPosX >  -544.0f
//     //     && gMarioObject->oPosX <   545.0f
//     //     && gMarioObject->oPosY >   800.0f
//     //     && gMarioObject->oPosZ > -2000.0f
//     //     && gMarioObject->oPosZ <  -177.0f) {
//     //     if (set_mario_npc_dialog(MARIO_DIALOG_LOOK_UP) == MARIO_DIALOG_STATUS_START) {
//     //         o->oAction = CAMERA_LAKITU_INTRO_ACT_SPAWN_CLOUD;
//     //     }
//     // }
// }

// /**
//  * Warp up into the air and spawn cloud, then enter the TODO action.
//  */
// static void camera_lakitu_intro_act_spawn_cloud(void) {
//     if (set_mario_npc_dialog(MARIO_DIALOG_LOOK_UP) == MARIO_DIALOG_STATUS_SPEAK) {
//         cur_obj_unhide();
//         o->oAction = CAMERA_LAKITU_INTRO_ACT_SHOW_DIALOG;

//         o->oPosX += 1000.0f; //CHANGED += operator should warp Lakitu straight up?
//         o->oPosY += 1600.0f;
//         o->oPosZ += 1400.0f;

//         o->oMoveAnglePitch = 0x4000;
//         o->oFappySpeed = 60.0f;
//         o->oFappyCircleRadius = 1000.0f;

//         //spawn_object_relative_with_scale(CLOUD_BP_LAKITU_CLOUD, 0, 0, 0, 2.0f, o, MODEL_MIST, bhvCloud);
//     }
// }

// /**
//  * Circle down to mario, show the dialog, then fly away.
//  */
// static void camera_lakitu_intro_act_show_dialog(void) {
//     s16 targetMovePitch = 0x0;
//     s16 targetMoveYaw = 0x0;

//     //cur_obj_play_sound_1(SOUND_AIR_LAKITU_FLY); //CHANGED commented out because sound is annoying

//     // Face toward mario
//     o->oFaceAnglePitch = obj_turn_pitch_toward_mario(120.0f, 0);
//     o->oFaceAngleYaw = o->oAngleToMario;

//     // After finishing dialog, fly away and despawn
//     if (o->oFappyFinishedDialog) {
//         approach_f32_ptr(&o->oFappySpeed, 60.0f, 3.0f);
//         if (o->oDistanceToMario > 6000.0f) {
//             obj_mark_for_deletion(o);
//         }

//         targetMovePitch = -0x3000;
//         targetMoveYaw = -0x6000;
//     } else {
//         if (o->oFappySpeed != 0.0f) {
//             if (o->oDistanceToMario > 5000.0f) {
//                 targetMovePitch = o->oMoveAnglePitch;
//                 targetMoveYaw = o->oAngleToMario;
//             } else {
//                 // Stay moving in a circle around mario
//                 s16 turnAmount = 0x4000
//                                  - atan2s(o->oFappyCircleRadius,
//                                           o->oDistanceToMario - o->oFappyCircleRadius);
//                 if ((s16)(o->oMoveAngleYaw - o->oAngleToMario) < 0) {
//                     turnAmount = -turnAmount;
//                 }

//                 targetMoveYaw = o->oAngleToMario + turnAmount;
//                 targetMovePitch = o->oFaceAnglePitch;

//                 approach_f32_ptr(&o->oFappyCircleRadius, 200.0f, 50.0f);
//                 if (o->oDistanceToMario < 1000.0f) {
// #ifndef VERSION_JP
//                     if (!o->oFappyIntroMusicPlayed) {
//                         //play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(15, SEQ_EVENT_CUTSCENE_LAKITU), 0); //CHANGED don't want music interrupted.
//                         cur_obj_play_sound_1(SOUND_ACTION_FLYING_FAST);
//                         o->oFappyIntroMusicPlayed = TRUE;
//                     }
// #endif
//                     // Once within 1000 units, slow down
//                     approach_f32_ptr(&o->oFappySpeed, 20.0f, 1.0f);
//                     if (o->oDistanceToMario < 600.0f // CHANGED 500 to 600
//                         && abs_angle_diff(gMarioObject->oFaceAngleYaw, o->oFaceAngleYaw) > 0x7000) {
//                         // Once within 500 units and facing toward mario, come to a stop
//                         approach_f32_ptr(&o->oFappySpeed, 0.0f, 5.0f);
//                     }
//                 }
//             }
//         } else if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP,
//             DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, get_dialogue_from_param())) {
//             o->oFappyFinishedDialog = TRUE;
//         }
//     }

//     o->oFappyPitchVel = approach_s16_symmetric(o->oFappyPitchVel, 2000, 400);
//     obj_move_pitch_approach(targetMovePitch, o->oFappyPitchVel);

//     o->oFappyYawVel = approach_s16_symmetric(o->oFappyYawVel, 2000, 100);
//     cur_obj_rotate_yaw_toward(targetMoveYaw, o->oFappyYawVel);

//     // vel y is explicitly computed, so gravity doesn't apply
//     obj_compute_vel_from_move_pitch(o->oFappySpeed);
//     cur_obj_move_using_fvel_and_gravity();
// }

/**
 * Update function for bigtop cutscene.
 */
void bhv_bigtop_cutscene_loop(void) {
    cur_obj_unhide();
            switch (o->oAction) {
                case BIGTOP_ACT_TRIGGER_CUTSCENE:
                    bigtop_act_trigger_cutscene();
                    break;
                case BIGTOP_ACT_MOVE_CAMERA:
                    bigtop_act_move_camera();
                    break;
                case BIGTOP_ACT_SHOW_DIALOG:
                    bigtop_act_show_dialog();
                    break;
            }
    //             vec3f_copy(&o->oPosVec, gLakituState.curPos);

    //             o->oHomeX = gLakituState.curFocus[0];
    //             o->oHomeZ = gLakituState.curFocus[2];

    //             o->oFaceAngleYaw = -cur_obj_angle_to_home();
    //             o->oFaceAnglePitch = atan2s(cur_obj_lateral_dist_to_home(),
    //                                         o->oPosY - gLakituState.curFocus[1]);

    //             o->oPosX = CASTLE_MIRROR_X + mirroredX;
    //         }
    //     }
    // }
}
