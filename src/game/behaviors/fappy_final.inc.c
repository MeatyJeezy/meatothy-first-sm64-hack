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

// static struct ObjectHitbox sFinalFappyHitbox = {
//     /* interactType:      */ INTERACT_DAMAGE,
//     /* downOffset:        */ 0,
//     /* damageOrCoinValue: */ 2,
//     /* health:            */ 0,
//     /* numLootCoins:      */ 0,
//     /* radius:            */ 60,
//     /* height:            */ 60,
//     /* hurtboxRadius:     */ 60,
//     /* hurtboxHeight:     */ 60,
// };

// static u8 sFinalFappyAttackHandlers[] = {
//     /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
//     /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
//     /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_NOP,
//     /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_NOP,
//     /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
//     /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_KNOCKBACK,
// };

// 0 = wait for mario to be in range
// 1 = follow mario from distance
// 2 = prepare to dive at mario, set his position
// 3 = dive and return to following distance (maybe unnecessary?)

// 0x4000 = 90 degrees

static void final_fappy_update_vel_y(f32 offsetY) {
    // In order to encourage oscillation, pass mario by a small margin before
    // accelerating the opposite direction
    // f32 margin;
    // if (o->oVelY < 0.0f) {
    //     margin = -3.0f;
    // } else {
    //     margin = 3.0f;
    // }
    // NEW handle if he is too high or low
    // o->oPosY = gMarioObject->oPosY + offsetY;
    if (o->oPosY > gMarioObject->oPosY + offsetY) {
        o->oPosY = gMarioObject->oPosY + offsetY;
    }
    if (o->oPosY < gMarioObject->oPosY + 500) {
        //o->oPosY = gMarioObject->oPosY - offsetY;
        // if(o->oPosY > gMarioObject->oPosY + 200) {
        //     obj_y_vel_approach(0.0f, 0.8f);
        // }
        obj_y_vel_approach(20.0f, 0.8f);
    } else {
        obj_y_vel_approach(0.0f, 0.8f);
    }
    // if (o->oPosY < gMarioObject->oPosY + offsetY + margin) {
    //     obj_y_vel_approach(8.0f, 0.8f);
    // } else {
    //     obj_y_vel_approach(-8.0f, 0.8f);
    // }
}

/**
 * Control speed based on distance to mario, turn toward mario, and change move
 * angle toward mario.
 */
static void final_fappy_update_speed_and_angle(void) {
    f32 minSpeed;
    s16 turnSpeed;

    f32 distToMario = o->oDistanceToMario;
    if (distToMario > 600.0f) {
        distToMario = 600.0f;
    }

    // Move faster the farther away mario is and the faster mario is moving
    if ((minSpeed = 1.2f * gMarioStates[0].forwardVel) < 8.0f) {
        minSpeed = 8.0f;
    }
    o->oForwardVel = distToMario * 0.04f;
    clamp_f32(&o->oForwardVel, minSpeed, 40.0f);

    // Accelerate toward mario vertically
    final_fappy_update_vel_y(500.0f);

    obj_face_yaw_approach(o->oAngleToMario, 0x200);

    // Change move angle toward mario faster when farther from mario
    turnSpeed = (s16)(distToMario * 2);
    clamp_s16(&turnSpeed, 200, 4000);
    cur_obj_rotate_yaw_toward(o->oAngleToMario, turnSpeed);
}

static void fappy_circle_mario(void) {

    if (o->oTimer++ < 400) {
        final_fappy_update_speed_and_angle();
        //cur_obj_move_standard(78);
    } else {
        o->oAction = 2;
        o->oTimer = 0;
        
    }
}

static void fappy_prepare_dive(void) {
    // Set target
    //o->oFinalFappyTargetX = gMarioState->pos[0];
    //o->oFinalFappyTargetY = gMarioState->pos[1];
    //o->oFinalFappyTargetZ = gMarioState->pos[2];

    // Current location stored for later
    // o->oFinalFappyPrevX = o->oPosX;
    // o->oFinalFappyPrevY = o->oPosY;
    // o->oFinalFappyPrevZ = o->oPosZ;
    f32 distToMario = o->oDistanceToMario;
    // Timer counts for half a sec,
    if (o->oTimer == 0) {
        cur_obj_play_sound_1(SOUND_GENERAL_COIN);
        // Store move yaw in a variable to retrieve later
        o->oFinalFappyCircleRadius = o->oMoveAngleYaw;
        o->oFaceAngleYaw = o->oAngleToMario;
        o->oFaceAnglePitch = obj_turn_pitch_toward_mario(0.0f, 0);

        // I dont understand trig I just copied these from flyguy.inc.c
        //o->oFinalFappyLungeTargetPitch = obj_turn_pitch_toward_mario(-200.0f, 0);

        //o->oForwardVel = 0.5f * (o->oDistanceToMario);//30.0f * coss(o->oFinalFappyLungeTargetPitch);
        //o->oVelY = 30.0f * -sins(o->oFinalFappyLungeTargetPitch);
        //o->oFinalFappyLungeYDecel = -o->oVelY / 30.0f;
        o->oForwardVel = 0;
        o->oVelX = 0;
        o->oVelY = 0;
        o->oVelZ = 0;

        o->oFinalFappySpeed = 0.3f * distToMario;
        o->oMoveAnglePitch = o->oFaceAnglePitch;
        o->oMoveAngleYaw = o->oAngleToMario;
        
    } else if (o->oTimer++ > 30) {
        o->oForwardVel = 15.0f;
        if (o->oPosY > gMarioObject->oPosY) {
            o->oVelY = -40.0f;
        } else {
            o->oVelY = 15.0f;
        }
        o->oTimer = 0;
        o->oAction = 3;
        cur_obj_play_sound_1(SOUND_ACTION_FLYING_FAST);
    }
}

// lunge to mario's old position
static void fappy_lunge(void) {
    // target - old position
    // Lunge downward
    // f32 xDist = (o->oFinalFappyTargetX - o->oFinalFappyPrevX);
    // f32 yDist = (o->oFinalFappyTargetY - o->oFinalFappyPrevY);
    // f32 zDist = (o->oFinalFappyTargetZ - o->oFinalFappyPrevZ);
    s32 time = 90;
    if (lateral_dist_between_objects(o, gMarioObject) > 0.0f) {
        obj_forward_vel_approach(60.0f, 0.5);
    } else {
        obj_forward_vel_approach(0.0f, 0.5);
    }
    // cur_obj_forward_vel_approach_upward(80.0f, 80.0f/time);
    // obj_forward_vel_approach(f32 target, f32 delta);
    if (o->oPosY < gMarioObject->oPosY + 100) {
        obj_y_vel_approach(10.0f, 0.5f);
    } else { 
        obj_y_vel_approach(-55.0f, 0.5f);
    }
    //obj_y_vel_approach(f32 target, f32 delta);
    //o->oForwardVel = o->oFinalFappySpeed;
    //obj_compute_vel_from_move_pitch(o->oFinalFappySpeed);
    //cur_obj_move_using_fvel_and_gravity();

    // o->oPosX += xDist/time;
    // o->oPosY += yDist/time;
    // o->oPosX += zDist/time;
    // if (o->oVelY < 0.0f) {
    //     o->oVelY += o->oFinalFappyLungeYDecel;

    //     cur_obj_rotate_yaw_toward(o->oFaceAngleYaw, 0x800);
    //     obj_face_pitch_approach(o->oFinalFappyLungeTargetPitch, 0x400);

    //     // Possible values: {-0x1000, 0x0000, 0x1000}
    //     //o->oFinalFappyTargetRoll = 0x1000 * (s16)(random_float() * 3.0f) - 0x1000;

    //     // Timer is up or he reaches his target
    // }
    if (o->oTimer++ > time /*|| (o->oPosX == o->oFinalFappyTargetX && o->oPosY == o->oFinalFappyTargetY && o->oPosZ == o->oFinalFappyTargetZ)*/) {
        // reset timer and move on to returning to orbit phase.
        o->oFinalFappyInRange = TRUE;
        o->oTimer = 0;
    }
}

static void fappy_return_to_orbit(void) {

    // prevX is the new target, go the opposite of it to sort of mirror the movement of attacking mario
    //f32 xDist = (o->oFinalFappyPrevX - o->oFinalFappyTargetX);
    // s16 yDist = (o->oFinalFappyPrevY - o->oFinalFappyTargetY);
    //f32 zDist = (o->oFinalFappyPrevZ - o->oFinalFappyTargetZ);
    s32 time = 90;
    obj_face_pitch_approach(0, 0x100);
    //obj_face_roll_approach(o->oFinalFappyTargetRoll, 300);
    //o->oPosX -= xDist/time;
    // o->oPosY -= yDist/time;
    //o->oPosX -= zDist/time;

    //o->oMoveAngleYaw -= o->oFaceAngleRoll / 4;
    //obj_face_yaw_approach(o->oMoveAngleYaw, 0x800);
    final_fappy_update_vel_y(500.0f);

    // Once Fappy is high enough and the timer hits time, return to the circle action
    // OR if he reaches X and Z
    if (o->oTimer++ > time /*|| (o->oPosX == o->oFinalFappyTargetX - xDist && o->oPosZ == o->oFinalFappyTargetZ - zDist)*/) {
        o->oFinalFappyInRange = FALSE;
        o->oTimer = 0;
        o->oAction = 1;
        o->oMoveAngleYaw = o->oFinalFappyCircleRadius;
    }
}

static void fappy_dive_at_mario(void) {

    if (o->oFinalFappyInRange) {
        fappy_lunge();
    } else {
        // Returning from dive
        fappy_return_to_orbit();
        //cur_obj_move_standard(78);
    }
    
    
}

void bhv_final_fappy_init(void) {
    cur_obj_hide();
    o->oPosY = gMarioObject->oPosY + 500;
    o->oAction = 0;
    o->oTimer = 0;
}

void bhv_final_fappy_loop(void) {
    if (o->oDistanceToMario < 9000 && o->oAction == 0 && cur_obj_nearest_object_with_behavior(bhvCameraLakitu) == NULL) {
        o->oAction = 1;
        cur_obj_unhide();
    }
    treat_far_home_as_mario(25000.0f);

    switch (o->oAction) {
        case 1:
            fappy_circle_mario();
            //cur_obj_move_standard(78);
        break;
        case 2:
            fappy_prepare_dive();
        break;
        case 3:
            fappy_dive_at_mario();
        break;
    }
    cur_obj_move_standard(78);
    // ?? idk
    // obj_check_attacks(&sFinalFappyHitbox, o->oAction);
}

// void bhv_overhead_cam(void) {}