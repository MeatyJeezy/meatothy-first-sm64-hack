
/**
 * Behavior for bhvCameraLakitu. This includes both the intro lakitu and the
 * lakitu visible in the mirror room.
 * TODO: Processing order relative to bhvCloud
 */

/**
 * Init function for camera lakitu.
 * If this is the intro lakitu, despawn unless this is the start of the game.
 * Spawn cloud if not the intro lakitu.
 */
// NEW enum for fappy dialogue
enum FappyDialog {
    FAPPY_DIALOG_UNUSED,
    FAPPY_DIALOG_1      = 0x1,
    FAPPY_DIALOG_2      = 0x2,
    FAPPY_DIALOG_3      = 0x3
};

void bhv_camera_lakitu_init(void) {
    // Don't show ligma explanation again. JRB_DOOR is set on ligma spawn
    if ((save_file_get_flags() & SAVE_FLAG_UNLOCKED_PSS_DOOR) && (save_file_get_flags() & SAVE_FLAG_UNLOCKED_JRB_DOOR)) {
        obj_mark_for_deletion(o);
    }
    if (o->oBehParams2ndByte != CAMERA_LAKITU_BP_FOLLOW_CAMERA) {
        // Despawn unless this is the very beginning of the game
        cur_obj_hide();
        // if (gNeverEnteredCastle != TRUE) {
        //     obj_mark_for_deletion(o);
        // }
    } else {
        //spawn_object_relative_with_scale(CLOUD_BP_LAKITU_CLOUD, 0, 0, 0, 2.0f, o, MODEL_MIST, bhvCloud);
    }
}
// NEW chooses Dialog constant based on second byte param

/**
 * Wait for mario to stand on the bridge, then interrupt his action and enter
 * the spawn cloud action.
 */
static void camera_lakitu_intro_act_trigger_cutscene(void) {
    //! These bounds are slightly smaller than the actual bridge bounds, allowing
    //  the RTA speedrunning method of lakitu skip
    if (o->oDistanceToMario < 600.0f) {
        if (set_mario_npc_dialog(MARIO_DIALOG_LOOK_UP) == MARIO_DIALOG_STATUS_START) { // CHANGED to detect Lakitu Proximity instead of hard-coded values
            o->oAction = CAMERA_LAKITU_INTRO_ACT_SPAWN_CLOUD;
        }
    }
}

/**
 * Warp up into the air and spawn cloud, then enter the TODO action.
 */
static void camera_lakitu_intro_act_spawn_cloud(void) {
    if (set_mario_npc_dialog(MARIO_DIALOG_LOOK_UP) == MARIO_DIALOG_STATUS_SPEAK) {
        cur_obj_unhide();
        o->oAction = CAMERA_LAKITU_INTRO_ACT_SHOW_DIALOG;

        o->oPosX += 1000.0f; //CHANGED += operator should warp Lakitu straight up?
        o->oPosY += 1600.0f;
        o->oPosZ += 1400.0f;

        o->oMoveAnglePitch = 0x4000;
        o->oCameraLakituSpeed = 60.0f;
        o->oCameraLakituCircleRadius = 1000.0f;

        //spawn_object_relative_with_scale(CLOUD_BP_LAKITU_CLOUD, 0, 0, 0, 2.0f, o, MODEL_MIST, bhvCloud);
    }
}

/**
 * Circle down to mario, show the dialog, then fly away.
 */
static void camera_lakitu_intro_act_show_dialog(void) {
    s16 targetMovePitch = 0x0;
    s16 targetMoveYaw = 0x0;

    //cur_obj_play_sound_1(SOUND_AIR_LAKITU_FLY); //CHANGED commented out because sound is annoying

    // Face toward mario
    o->oFaceAnglePitch = obj_turn_pitch_toward_mario(120.0f, 0);
    o->oFaceAngleYaw = o->oAngleToMario;

    // After finishing dialog, fly away and despawn
    if (o->oCameraLakituFinishedDialog) {
        approach_f32_ptr(&o->oCameraLakituSpeed, 60.0f, 3.0f);
        if (o->oDistanceToMario > 6000.0f) {
            cur_obj_hide();
            // set the flag if the player understood the tutorial.
            // If a ligma has spawned:
            if (cur_obj_nearest_object_with_behavior(bhvLigma) != NULL) {
                o->oCameraLakituLigmaExists = TRUE;
            }
            // If there was a ligma, but now there isn't, set the flag to never have the ligma tutorial again.
            else if (cur_obj_nearest_object_with_behavior(bhvLigma) == NULL && o->oCameraLakituLigmaExists) {
                save_file_set_flags(SAVE_FLAG_UNLOCKED_PSS_DOOR);
            }
            // No ligma nearby, safe to delete.
            if (cur_obj_nearest_object_with_behavior(bhvLigma) == NULL) {
                obj_mark_for_deletion(o);
            }
            
        }

        targetMovePitch = -0x3000;
        targetMoveYaw = -0x6000;
    } else {
        if (o->oCameraLakituSpeed != 0.0f) {
            if (o->oDistanceToMario > 5000.0f) {
                targetMovePitch = o->oMoveAnglePitch;
                targetMoveYaw = o->oAngleToMario;
            } else {
                // Stay moving in a circle around mario
                s16 turnAmount = 0x4000
                                 - atan2s(o->oCameraLakituCircleRadius,
                                          o->oDistanceToMario - o->oCameraLakituCircleRadius);
                if ((s16)(o->oMoveAngleYaw - o->oAngleToMario) < 0) {
                    turnAmount = -turnAmount;
                }

                targetMoveYaw = o->oAngleToMario + turnAmount;
                targetMovePitch = o->oFaceAnglePitch;

                approach_f32_ptr(&o->oCameraLakituCircleRadius, 200.0f, 50.0f);
                if (o->oDistanceToMario < 1000.0f) {
#ifndef VERSION_JP
                    if (!o->oCameraLakituIntroMusicPlayed) {
                        //play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(15, SEQ_EVENT_CUTSCENE_LAKITU), 0); //CHANGED don't want music interrupted.
                        cur_obj_play_sound_1(SOUND_ACTION_FLYING_FAST);
                        o->oCameraLakituIntroMusicPlayed = TRUE;
                    }
#endif
                    // Once within 1000 units, slow down
                    approach_f32_ptr(&o->oCameraLakituSpeed, 20.0f, 1.0f);
                    if (o->oDistanceToMario < 600.0f // CHANGED 500 to 600
                        && abs_angle_diff(gMarioObject->oFaceAngleYaw, o->oFaceAngleYaw) > 0x7000) {
                        // Once within 500 units and facing toward mario, come to a stop
                        approach_f32_ptr(&o->oCameraLakituSpeed, 0.0f, 5.0f);
                    }
                }
            }
        } else if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP,
            DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, o->oBehParams2ndByte)) {
            o->oCameraLakituFinishedDialog = TRUE;
            //  Ligma dialog, spawn the object.
            if (o->oBehParams2ndByte == 0xBA) {
                spawn_object_relative(o->oBehParams2ndByte, 0, 0, 0, o, MODEL_NONE, bhvLigma);
            }
        }
    }

    o->oCameraLakituPitchVel = approach_s16_symmetric(o->oCameraLakituPitchVel, 2000, 400);
    obj_move_pitch_approach(targetMovePitch, o->oCameraLakituPitchVel);

    o->oCameraLakituYawVel = approach_s16_symmetric(o->oCameraLakituYawVel, 2000, 100);
    cur_obj_rotate_yaw_toward(targetMoveYaw, o->oCameraLakituYawVel);

    // vel y is explicitly computed, so gravity doesn't apply
    obj_compute_vel_from_move_pitch(o->oCameraLakituSpeed);
    cur_obj_move_using_fvel_and_gravity();
}

/**
 * Update function for camera lakitu.
 */
void bhv_camera_lakitu_update(void) {
    if (!(o->activeFlags & ACTIVE_FLAG_IN_DIFFERENT_ROOM)) {
        if (o->oBehParams2ndByte == 0xBA) { // DIALOG_186 is the ligma shield explanation. Only play if flag is set
            if (save_file_get_flags() & SAVE_FLAG_UNLOCKED_JRB_DOOR) {
                o->oCameraLakituCanInteract = TRUE;
                // Flag to never show this again
                // save_file_set_flags(SAVE_FLAG_UNLOCKED_PSS_DOOR);
            }
        } else {
            o->oCameraLakituCanInteract = TRUE;
        }
        obj_update_blinking(&o->oCameraLakituBlinkTimer, 20, 40, 4);

        if (o->oBehParams2ndByte != CAMERA_LAKITU_BP_FOLLOW_CAMERA && o->oCameraLakituCanInteract) {
            switch (o->oAction) {
                case CAMERA_LAKITU_INTRO_ACT_TRIGGER_CUTSCENE:
                    camera_lakitu_intro_act_trigger_cutscene();
                    break;
                case CAMERA_LAKITU_INTRO_ACT_SPAWN_CLOUD:
                    camera_lakitu_intro_act_spawn_cloud();
                    break;
                case CAMERA_LAKITU_INTRO_ACT_SHOW_DIALOG:
                    camera_lakitu_intro_act_show_dialog();
                    break;
            }
        } else {
            f32 mirroredX = CASTLE_MIRROR_X - gLakituState.curPos[0];

            if (gLakituState.curPos[0] < 1700.0f || mirroredX < 0.0f) {
                cur_obj_hide();
            } else {
                cur_obj_unhide();
                vec3f_copy(&o->oPosVec, gLakituState.curPos);

                o->oHomeX = gLakituState.curFocus[0];
                o->oHomeZ = gLakituState.curFocus[2];

                o->oFaceAngleYaw = -cur_obj_angle_to_home();
                o->oFaceAnglePitch = atan2s(cur_obj_lateral_dist_to_home(),
                                            o->oPosY - gLakituState.curFocus[1]);

                o->oPosX = CASTLE_MIRROR_X + mirroredX;
            }
        }
    }
}
