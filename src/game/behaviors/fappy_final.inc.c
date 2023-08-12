// bullet_bill.inc.c

// void bhv_white_puff_smoke_init(void) {
//     cur_obj_scale(random_float() * 2 + 2.0);
// }

// void bhv_bullet_bill_init(void) {
//     o->oBulletBillInitialMoveYaw = o->oMoveAngleYaw;
// }

// void bullet_bill_act_0(void) {
//     cur_obj_become_tangible();
//     o->oForwardVel = 0.0f;
//     o->oMoveAngleYaw = o->oBulletBillInitialMoveYaw;
//     o->oFaceAnglePitch = 0;
//     o->oFaceAngleRoll = 0;
//     o->oMoveFlags = OBJ_MOVE_NONE;
//     cur_obj_set_pos_to_home();
//     o->oAction = 1;
// }

// void bullet_bill_act_1(void) {
//     s16 sp1E = abs_angle_diff(o->oAngleToMario, o->oMoveAngleYaw);
//     if (sp1E < 0x2000 && 400.0f < o->oDistanceToMario && o->oDistanceToMario < 1500.0f) {
//         o->oAction = 2;
//     }
// }

// void bullet_bill_act_2(void) {
//     if (o->oTimer < 40) {
//         o->oForwardVel = 3.0f;
//     } else if (o->oTimer < 50) {
//         if (o->oTimer % 2) {
//             o->oForwardVel = 3.0f;
//         } else {
//             o->oForwardVel = -3.0f;
//         }
//     } else {
//         if (o->oTimer > 70) {
//             cur_obj_update_floor_and_walls();
//         }

//         spawn_object(o, MODEL_SMOKE, bhvWhitePuffSmoke);
//         o->oForwardVel = 30.0f;

//         if (o->oDistanceToMario > 300.0f) {
//             cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x100);
//         }

//         if (o->oTimer == 50) {
//             cur_obj_play_sound_2(SOUND_OBJ_POUNDING_CANNON);
//             cur_obj_shake_screen(SHAKE_POS_SMALL);
//         }

//         if (o->oTimer > 150 || o->oMoveFlags & OBJ_MOVE_HIT_WALL) {
//             o->oAction = 3;
//             spawn_mist_particles();
//         }
//     }
// }

// void bullet_bill_act_3(void) {
//     o->oAction = 0;
// }

// void bullet_bill_act_4(void) {
//     if (o->oTimer == 0) {
//         o->oForwardVel = -30.0f;
//         cur_obj_become_intangible();
//     }

//     o->oFaceAnglePitch += 0x1000;
//     o->oFaceAngleRoll += 0x1000;
//     o->oPosY += 20.0f;

//     if (o->oTimer > 90) {
//         o->oAction = 0;
//     }
// }

// ObjActionFunc sBulletBillActions[] = {
//     bullet_bill_act_0,
//     bullet_bill_act_1,
//     bullet_bill_act_2,
//     bullet_bill_act_3,
//     bullet_bill_act_4,
// };

// void bhv_bullet_bill_loop(void) {
//     cur_obj_call_action_function(sBulletBillActions);
//     if (cur_obj_check_interacted()) {
//         o->oAction = 4;
//     }
// }

// 0 = wait for mario to be in range
// 1 = follow mario from distance
// 2 = prepare to dive at mario, set his position
// 3 = dive and return to following distance (maybe unnecessary?)

// 0x4000 = 90 degrees

static void final_fappy_update_vel_y(f32 offsetY) {
    // In order to encourage oscillation, pass mario by a small margin before
    // accelerating the opposite direction
    f32 margin;
    if (o->oVelY < 0.0f) {
        margin = -3.0f;
    } else {
        margin = 3.0f;
    }

    if (o->oPosY < gMarioObject->oPosY + offsetY + margin) {
        obj_y_vel_approach(4.0f, 0.4f);
    } else {
        obj_y_vel_approach(-4.0f, 0.4f);
    }
}

/**
 * Control speed based on distance to mario, turn toward mario, and change move
 * angle toward mario.
 */
static void final_fappy_update_speed_and_angle(void) {
    f32 minSpeed;
    s16 turnSpeed;

    f32 distToMario = o->oDistanceToMario;
    if (distToMario > 3000.0f) {
        distToMario = 3000.0f;
    }

    // Move faster the farther away mario is and the faster mario is moving
    if ((minSpeed = 1.2f * gMarioStates[0].forwardVel) < 8.0f) {
        minSpeed = 8.0f;
    }
    o->oForwardVel = distToMario * 0.04f;
    clamp_f32(&o->oForwardVel, minSpeed, 40.0f);

    // Accelerate toward mario vertically
    enemy_lakitu_update_vel_y(400.0f);

    // Turn toward mario except right after throwing a spiny
    // if (o->oEnemyLakituFaceForwardCountdown != 0) {
    //     o->oEnemyLakituFaceForwardCountdown--;
    // } else {
    //     obj_face_yaw_approach(o->oAngleToMario, 0x600);
    // }

    // Change move angle toward mario faster when farther from mario
    turnSpeed = (s16)(distToMario * 2);
    clamp_s16(&turnSpeed, 200, 4000);
    cur_obj_rotate_yaw_toward(o->oAngleToMario, turnSpeed);
}

static void fappy_circle_mario(void) {
    o->oTimer++;

    if (o->oTimer++ < 360) {
        final_fappy_update_speed_and_angle();
    } else {
        o->oAction = 2;
    }
}


// static void fappy_circle_mario(void) {
//     // s16 targetMovePitch = 0x0;
//     // s16 targetMoveYaw = 0x0;

//     o->oTimer++;

//     // Face toward mario
//     // o->oFaceAnglePitch = obj_turn_pitch_toward_mario(120.0f, 0);
//     // o->oFaceAngleYaw = o->oAngleToMario;

//     // Every 360 frames, try the dive again
//     // if (oTimer < 360) {
//     //     s16 turnAmount = 0x4000 - atan2s(o->oFinalFappyCircleRadius, o->oDistanceToMario - o->oFinalFappyCircleRadius);
//     //     if ((s16)(o->oMoveAngleYaw - o->oAngleToMario) < 0) {
//     //         turnAmount = -turnAmount;
//     //     }
//     //     targetMoveYaw = o->oAngleToMario + turnAmount;
//     //     targetMovePitch = o->oFaceAnglePitch;

//     //     approach_f32_ptr(&o->oFinalFappyCircleRadius, 200.0f, 50.0f);
//     } else {
//         o->oAction = 2;
//     }

// }

static void fappy_prepare_dive(void) {
    // Set target
    o->oFinalFappyTargetX = gMarioState->pos[0];
    o->oFinalFappyTargetY = gMarioState->pos[1];
    o->oFinalFappyTargetZ = gMarioState->pos[2];

    // Current location stored for later
    o->oFinalFappyPrevX = o->oPosX;
    o->oFinalFappyPrevY = o->oPosY;
    o->oFinalFappyPrevZ = o->oPosZ;

    o->oFaceAngleYaw = o->oAngleToMario;
    //o->oFaceAnglePitch = obj_turn_pitch_toward_mario(120.0f, 0);

    // I dont understand trig I just copied these from flyguy.inc.c
    o->oFinalFappyLungeTargetPitch = obj_turn_pitch_toward_mario(-200.0f, 0);
    o->oForwardVel = 25.0f * coss(o->oFinalFappyLungeTargetPitch);
    o->oVelY = 25.0f * -sins(o->oFinalFappyLungeTargetPitch);
    o->oFinalFappyLungeYDecel = -o->oVelY / 30.0f;

    o->oTimer = 1;
    o->oAction = 3;
}

// lunge to mario's old position
static void fappy_to_mario(void) {
    //
}

static void fappy_return_to_orbit(void) {

}

static void fappy_dive_at_mario(void) {

    if (o->oVelY < 0.0f) {
        // Lunge downward

        o->oVelY += o->oFinalFappyLungeYDecel;

        cur_obj_rotate_yaw_toward(o->oFaceAngleYaw, 0x800);
        obj_face_pitch_approach(o->oFinalFappyLungeTargetPitch, 0x400);

        // Possible values: {-0x1000, 0x0000, 0x1000}
        o->oFinalFappyTargetRoll = 0x1000 * (s16)(random_float() * 3.0f) - 0x1000;
        o->oTimer = 0;
    } else {
        // Twirl back upward

        obj_face_pitch_approach(0, 0x100);
        obj_face_roll_approach(o->oFinalFappyTargetRoll, 300);

        // Twirl in a spiral with curvature proportional to oFaceAngleRoll
        o->oMoveAngleYaw -= o->oFaceAngleRoll / 4;
        obj_face_yaw_approach(o->oMoveAngleYaw, 0x800);

        // Continue moving upward until at least 200 units above mario
        if (o->oPosY < gMarioObject->oPosY + 200.0f) {
            obj_y_vel_approach(20.0f, 0.5f);
        } else if (obj_y_vel_approach(0.0f, 0.5f)) {
            // Wait until roll is zero
            if (o->oFaceAngleRoll == 0) {
                o->oAction = FLY_GUY_ACT_APPROACH_MARIO;
            }

            o->oFinalFappyTargetRoll = 0;
        }
    }
    
    // Finished returning from dive

    o->oTimer = 0;
    o->oAction = 1;
}

void bhv_final_fappy_init(void) {
    o->oAction = 0;
    o->oTimer = 0;

    o->oFinalFappySpeed = 40.0f;
    o->oFinalFappyCircleRadius = 3000.0f;
}

void bhv_final_fappy_loop(void) {
    if (o->oDistanceToMario < 9000 && o->oAction == 0) {
        o->oAction = 1;
    }

    switch (o->oAction) {
        case 1:
            treat_far_home_as_mario(3000.0f);
            fappy_circle_mario();
        break;
        case 2:
            fappy_prepare_dive();
        break;
        case 3:
            fappy_dive_at_mario();
        break;
    }
}