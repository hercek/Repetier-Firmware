/*
    This file is part of Repetier-Firmware.

    Repetier-Firmware is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Repetier-Firmware is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Repetier-Firmware.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef _EEPROM_H
#define _EEPROM_H

// Id to distinguish version changes
#define EEPROM_PROTOCOL_VERSION 21

/** Where to start with our data block in memory. Can be moved if you
have problems with other modules using the eeprom */

#define EPR_MAGIC_BYTE              0
#define EPR_ACCELERATION_TYPE       1
#define EPR_XAXIS_STEPS_PER_MM      3
#define EPR_YAXIS_STEPS_PER_MM      7
#define EPR_ZAXIS_STEPS_PER_MM     11
#define EPR_X_MAX_FEEDRATE         15
#define EPR_Y_MAX_FEEDRATE         19
#define EPR_Z_MAX_FEEDRATE         23
#define EPR_X_HOMING_FEEDRATE      27
#define EPR_Y_HOMING_FEEDRATE      31
#define EPR_Z_HOMING_FEEDRATE      35
#define EPR_MAX_JERK               39
//#define EPR_OPS_MIN_DISTANCE       43
#define EPR_MAX_ZJERK              47
#define EPR_X_MAX_ACCEL            51
#define EPR_Y_MAX_ACCEL            55
#define EPR_Z_MAX_ACCEL            59
#define EPR_X_MAX_TRAVEL_ACCEL     63
#define EPR_Y_MAX_TRAVEL_ACCEL     67
#define EPR_Z_MAX_TRAVEL_ACCEL     71
#define EPR_BAUDRATE               75
#define EPR_MAX_INACTIVE_TIME      79
#define EPR_STEPPER_INACTIVE_TIME  83
//#define EPR_OPS_RETRACT_DISTANCE   87
//#define EPR_OPS_RETRACT_BACKLASH   91
#define EPR_EXTRUDER_SPEED         95
//#define EPR_OPS_MOVE_AFTER         99
//#define EPR_OPS_MODE              103
#define EPR_INTEGRITY_BYTE        104   // Here the xored sum over eeprom is stored
#define EPR_VERSION               105   // Version id for updates in EEPROM storage
#define EPR_BED_HEAT_MANAGER      106
#define EPR_BED_DRIVE_MAX         107
#define EPR_BED_PID_PGAIN         108
#define EPR_BED_PID_IGAIN         112
#define EPR_BED_PID_DGAIN         116
#define EPR_BED_PID_MAX           120
#define EPR_BED_DRIVE_MIN         124
#define EPR_PRINTING_TIME         125  // Time in seconds printing
#define EPR_PRINTING_DISTANCE     129  // Filament length printed
#define EPR_X_HOME_OFFSET         133
#define EPR_Y_HOME_OFFSET         137
#define EPR_Z_HOME_OFFSET         141
#define EPR_X_LENGTH              145
#define EPR_Y_LENGTH              149
#define EPR_Z_LENGTH              153
#define EPR_BACKLASH_X            157
#define EPR_BACKLASH_Y            161
#define EPR_BACKLASH_Z            165

#define EPR_Z_PROBE_X_OFFSET      800
#define EPR_Z_PROBE_Y_OFFSET      804
#define EPR_Z_PROBE_HEIGHT        808
#define EPR_Z_PROBE_SPEED         812
#define EPR_Z_PROBE_X1            816
#define EPR_Z_PROBE_Y1            820
#define EPR_Z_PROBE_X2            824
#define EPR_Z_PROBE_Y2            828
#define EPR_Z_PROBE_X3            832
#define EPR_Z_PROBE_Y3            836
#define EPR_Z_PROBE_XY_SPEED      840
#define EPR_AUTOLEVEL_MATRIX      844
#define EPR_AUTOLEVEL_ACTIVE      880
// 1 byte padding @ 881
#define EPR_DELTA_SEGMENTS_PER_SECOND_PRINT 882
#define EPR_DELTA_SEGMENTS_PER_SECOND_MOVE  884
// endstop offsets: oas, obs, ocs             //6 bytes
#define EPR_DELTA_TOWERX_OFFSET_STEPS 886
#define EPR_DELTA_TOWERY_OFFSET_STEPS 888
#define EPR_DELTA_TOWERZ_OFFSET_STEPS 890
// tower position:  xa, ya, xc                //12 bytes
#define EPR_DELTA_TOWER_A_XPOS        892
#define EPR_DELTA_TOWER_A_YPOS        896
#define EPR_DELTA_TOWER_C_XPOS        900
// diagonal rods:   ra, rb, rc                //12 bytes
#define EPR_DELTA_DIAGONAL_A          904
#define EPR_DELTA_DIAGONAL_B          908
#define EPR_DELTA_DIAGONAL_C          912
// tower tilts:     dxa,dya, dxb,dyb, dxc,dyc //24 bytes
#define EPR_DELTA_TOWER_A_XTILT       916
#define EPR_DELTA_TOWER_A_YTILT       920
#define EPR_DELTA_TOWER_B_XTILT       924
#define EPR_DELTA_TOWER_B_YTILT       928
#define EPR_DELTA_TOWER_C_XTILT       932
#define EPR_DELTA_TOWER_C_YTILT       936
// max printing radius z-probe return length //6 bytes
#define EPR_DELTA_MAX_RADIUS          940
#define EPR_Z_PROBE_BED_DISTANCE_STEPS 944
#define EPR_TOUCHSCREEN           946 // - 975 = 30 byte for touchscreen calibration data

// Axis compensation
#define EPR_AXISCOMP_TANXY			976
#define EPR_AXISCOMP_TANYZ			980
#define EPR_AXISCOMP_TANXZ			984

#define EPR_DISTORTION_CORRECTION_ENABLED      988
#define EPR_RETRACTION_LENGTH                  992
#define EPR_RETRACTION_LONG_LENGTH             996
#define EPR_RETRACTION_SPEED                  1000
#define EPR_RETRACTION_Z_LIFT                 1004
#define EPR_RETRACTION_UNDO_EXTRA_LENGTH      1008
#define EPR_RETRACTION_UNDO_EXTRA_LONG_LENGTH 1012
#define EPR_RETRACTION_UNDO_SPEED             1016
#define EPR_AUTORETRACT_ENABLED               1020
#define EPR_Z_PROBE_Z_OFFSET			      1024
#define EPR_SELECTED_LANGUAGE                 1028
#define EPR_ACCELERATION_FACTOR_TOP           1032
#define EPR_BENDING_CORRECTION_A              1036
#define EPR_BENDING_CORRECTION_B              1040
#define EPR_BENDING_CORRECTION_C              1044
#define EPR_BED_PREHEAT_TEMP                  1048
#define EPR_X2AXIS_STEPS_PER_MM               1052
#define EPR_PARK_X						      1056
#define EPR_PARK_Y                            1060
#define EPR_PARK_Z                            1064

// Horizontal Scaling
#define EPR_HORIZSCALING_XX			1068
#define EPR_HORIZSCALING_YX			1072
#define EPR_HORIZSCALING_XY			1076
#define EPR_HORIZSCALING_YY			1080


#if EEPROM_MODE != 0
#define EEPROM_FLOAT(x) HAL::eprGetFloat(EPR_##x)
#define EEPROM_INT32(x) HAL::eprGetInt32(EPR_##x)
#define EEPROM_BYTE(x) HAL::eprGetByte(EPR_##x)
#define EEPROM_SET_BYTE(x,val) HAL::eprSetByte(EPR_##x,val)
#else
#define EEPROM_FLOAT(x) (float)(x)
#define EEPROM_INT32(x) (int32_t)(x)
#define EEPROM_BYTE(x) (uint8_t)(x)
#define EEPROM_SET_BYTE(x,val)
#endif

#define EEPROM_EXTRUDER_OFFSET 200
// bytes per extruder needed, leave some space for future development
#define EEPROM_EXTRUDER_LENGTH 100
// Extruder positions relative to extruder start
#define EPR_EXTRUDER_STEPS_PER_MM        0
#define EPR_EXTRUDER_MAX_FEEDRATE        4
// Feedrate from halted extruder in mm/s
#define EPR_EXTRUDER_MAX_START_FEEDRATE  8
// Acceleration in mm/s^2
#define EPR_EXTRUDER_MAX_ACCELERATION   12
#define EPR_EXTRUDER_HEAT_MANAGER       16
#define EPR_EXTRUDER_DRIVE_MAX          17
#define EPR_EXTRUDER_PID_PGAIN          18
#define EPR_EXTRUDER_PID_IGAIN          22
#define EPR_EXTRUDER_PID_DGAIN          26
#define EPR_EXTRUDER_DEADTIME EPR_EXTRUDER_PID_PGAIN
#define EPR_EXTRUDER_PID_MAX            30
#define EPR_EXTRUDER_X_OFFSET           31
#define EPR_EXTRUDER_Y_OFFSET           35
#define EPR_EXTRUDER_WATCH_PERIOD       39
#define EPR_EXTRUDER_ADVANCE_K          41
#define EPR_EXTRUDER_DRIVE_MIN          45
#define EPR_EXTRUDER_ADVANCE_L          46
#define EPR_EXTRUDER_WAIT_RETRACT_TEMP 50
#define EPR_EXTRUDER_WAIT_RETRACT_UNITS 52
#define EPR_EXTRUDER_COOLER_SPEED       54
// 55-57 free for byte sized parameter
#define EPR_EXTRUDER_MIXING_RATIOS  58 // 16*2 byte ratios = 32 byte -> end = 89
#define EPR_EXTRUDER_Z_OFFSET            90
#define EPR_EXTRUDER_PREHEAT             94 // maybe better temperature
#ifndef Z_PROBE_BED_DISTANCE
#define Z_PROBE_BED_DISTANCE 5.0
#endif

class EEPROM
{
#if EEPROM_MODE != 0
    static void writeExtruderPrefix(uint pos);
    static void writeFloat(uint pos,PGM_P text,uint8_t digits = 3);
    static void writeLong(uint pos,PGM_P text);
    static void writeInt(uint pos,PGM_P text);
    static void writeByte(uint pos,PGM_P text);
public:
    static uint8_t computeChecksum();
    static void updateChecksum();
#endif
public:

    static void init();
    static void initBaudrate();
    static void storeDataIntoEEPROM(uint8_t corrupted = 0);
    static void readDataFromEEPROM(bool includeExtruder);
    static void restoreEEPROMSettingsFromConfiguration();
    static void writeSettings();
    static void update(GCode *com);
    static void updatePrinterUsage();
    static inline void setVersion(uint8_t v) {
#if EEPROM_MODE != 0
        HAL::eprSetByte(EPR_VERSION,v);
        HAL::eprSetByte(EPR_INTEGRITY_BYTE,computeChecksum());
#endif
    }
    static inline uint8_t getStoredLanguage() {
#if EEPROM_MODE != 0
        return HAL::eprGetByte(EPR_SELECTED_LANGUAGE);
#else
        return 0;
#endif
    }
#if FEATURE_Z_PROBE
static inline void setZProbeHeight(float mm) {
    #if EEPROM_MODE != 0
    HAL::eprSetFloat(EPR_Z_PROBE_HEIGHT, mm);
    Com::printFLN(PSTR("Z-Probe height set to: "),mm,3);
    EEPROM::updateChecksum();
    #endif
}
#endif
    
    static inline float zProbeZOffset() {
#if EEPROM_MODE != 0
	    return HAL::eprGetFloat(EPR_Z_PROBE_Z_OFFSET);
#else
	    return Z_PROBE_Z_OFFSET;
#endif
    }
    static inline float zProbeSpeed() {
#if EEPROM_MODE != 0
        return HAL::eprGetFloat(EPR_Z_PROBE_SPEED);
#else
        return Z_PROBE_SPEED;
#endif
    }
    static inline float zProbeXYSpeed() {
#if EEPROM_MODE != 0
        return HAL::eprGetFloat(EPR_Z_PROBE_XY_SPEED);
#else
        return Z_PROBE_XY_SPEED;
#endif
    }
    static inline float zProbeXOffset() {
#if EEPROM_MODE != 0
        return HAL::eprGetFloat(EPR_Z_PROBE_X_OFFSET);
#else
        return Z_PROBE_X_OFFSET;
#endif
    }
    static inline float zProbeYOffset() {
#if EEPROM_MODE != 0
        return HAL::eprGetFloat(EPR_Z_PROBE_Y_OFFSET);
#else
        return Z_PROBE_Y_OFFSET;
#endif
    }
    static inline float zProbeHeight() {
#if EEPROM_MODE != 0
        return HAL::eprGetFloat(EPR_Z_PROBE_HEIGHT);
#else
        return Z_PROBE_HEIGHT;
#endif
    }
    static inline float zProbeX1() {
#if EEPROM_MODE != 0
        return HAL::eprGetFloat(EPR_Z_PROBE_X1);
#else
        return Z_PROBE_X1;
#endif
    }
    static inline float zProbeY1() {
#if EEPROM_MODE != 0
        return HAL::eprGetFloat(EPR_Z_PROBE_Y1);
#else
        return Z_PROBE_Y1;
#endif
    }
    static inline float zProbeX2() {
#if EEPROM_MODE != 0
        return HAL::eprGetFloat(EPR_Z_PROBE_X2);
#else
        return Z_PROBE_X2;
#endif
    }
    static inline float zProbeY2() {
#if EEPROM_MODE != 0
        return HAL::eprGetFloat(EPR_Z_PROBE_Y2);
#else
        return Z_PROBE_Y2;
#endif
    }
    static inline float zProbeX3() {
#if EEPROM_MODE != 0
        return HAL::eprGetFloat(EPR_Z_PROBE_X3);
#else
        return Z_PROBE_X3;
#endif
    }
    static inline float zProbeY3() {
#if EEPROM_MODE != 0
        return HAL::eprGetFloat(EPR_Z_PROBE_Y3);
#else
        return Z_PROBE_Y3;
#endif
    }
    static inline float zProbeBedDistance() {
#if EEPROM_MODE != 0
        return HAL::eprGetInt16(EPR_Z_PROBE_BED_DISTANCE_STEPS) / HAL::eprGetFloat(EPR_ZAXIS_STEPS_PER_MM);
#else
        return Z_PROBE_BED_DISTANCE;
#endif
    }

    static inline float axisCompTanXY() {
#if EEPROM_MODE != 0
        return HAL::eprGetFloat(EPR_AXISCOMP_TANXY);
#else
        return AXISCOMP_TANXY;
#endif
    }
    static inline float axisCompTanYZ() {
#if EEPROM_MODE != 0
        return HAL::eprGetFloat(EPR_AXISCOMP_TANYZ);
#else
        return AXISCOMP_TANYZ;
#endif
    }
    static inline float axisCompTanXZ() {
#if EEPROM_MODE != 0
        return HAL::eprGetFloat(EPR_AXISCOMP_TANXZ);
#else
        return AXISCOMP_TANXZ;
#endif
    }

    static inline float horizScalingXX() {
#if EEPROM_MODE != 0
        return HAL::eprGetFloat(EPR_HORIZSCALING_XX);
#else
        return HORIZSCALING_XX;
#endif
    }
    static inline float horizScalingYX() {
#if EEPROM_MODE != 0
        return HAL::eprGetFloat(EPR_HORIZSCALING_YX);
#else
        return HORIZSCALING_YX;
#endif
    }
    static inline float horizScalingXY() {
#if EEPROM_MODE != 0
        return HAL::eprGetFloat(EPR_HORIZSCALING_XY);
#else
        return HORIZSCALING_XY;
#endif
    }
    static inline float horizScalingYY() {
#if EEPROM_MODE != 0
        return HAL::eprGetFloat(EPR_HORIZSCALING_YY);
#else
        return HORIZSCALING_YY;
#endif
    }

#if NONLINEAR_SYSTEM
    static inline int16_t deltaSegmentsPerSecondMove() {
#if EEPROM_MODE != 0
        return HAL::eprGetInt16(EPR_DELTA_SEGMENTS_PER_SECOND_MOVE);
#else
        return DELTA_SEGMENTS_PER_SECOND_MOVE;
#endif
    }
   static inline int16_t deltaSegmentsPerSecondPrint() {
#if EEPROM_MODE != 0
        return HAL::eprGetInt16(EPR_DELTA_SEGMENTS_PER_SECOND_PRINT);
#else
        return DELTA_SEGMENTS_PER_SECOND_PRINT;
#endif
    }
#endif
#if DRIVE_SYSTEM == DELTA
    static inline int16_t deltaTowerXOffsetSteps() {
#if EEPROM_MODE != 0
        return HAL::eprGetInt16(EPR_DELTA_TOWERX_OFFSET_STEPS);
#else
        return DELTA_X_ENDSTOP_OFFSET_STEPS;
#endif
    }
    static inline int16_t deltaTowerYOffsetSteps() {
#if EEPROM_MODE != 0
        return HAL::eprGetInt16(EPR_DELTA_TOWERY_OFFSET_STEPS);
#else
        return DELTA_Y_ENDSTOP_OFFSET_STEPS;
#endif
    }
    static inline int16_t deltaTowerZOffsetSteps() {
#if EEPROM_MODE != 0
        return HAL::eprGetInt16(EPR_DELTA_TOWERZ_OFFSET_STEPS);
#else
        return DELTA_Z_ENDSTOP_OFFSET_STEPS;
#endif
    }

    static inline void adjustRodRadius(float factor) {
#if DRIVE_SYSTEM == DELTA
      Printer::deltaAPosXSteps = floor(0.5+Printer::deltaAPosXSteps*factor);
      Printer::deltaAPosYSteps = floor(0.5+Printer::deltaAPosYSteps*factor);
      Printer::deltaBPosXSteps = floor(0.5+Printer::deltaBPosXSteps*factor);
      Printer::deltaBPosYSteps = floor(0.5+Printer::deltaBPosYSteps*factor);
      Printer::deltaCPosXSteps = floor(0.5+Printer::deltaCPosXSteps*factor);
      Printer::deltaCPosYSteps = floor(0.5+Printer::deltaCPosYSteps*factor);
#if EEPROM_MODE != 0
      HAL::eprSetFloat(EPR_DELTA_TOWER_A_XPOS, EEPROM::deltaTowerA_xPos()*factor);
      HAL::eprSetFloat(EPR_DELTA_TOWER_A_YPOS, EEPROM::deltaTowerA_yPos()*factor);
      HAL::eprSetFloat(EPR_DELTA_TOWER_C_XPOS, EEPROM::deltaTowerC_xPos()*factor);
      EEPROM::updateChecksum();
#endif
#endif
    }
    static inline void setTowerXFloor(float newZ) {
#if DRIVE_SYSTEM == DELTA
      Printer::xMin = newZ;
      Printer::updateDerivedParameter();
      Com::printFLN(PSTR("X (A) tower floor set to: "),Printer::xMin,3);
#if EEPROM_MODE != 0
        HAL::eprSetFloat(EPR_X_HOME_OFFSET,Printer::xMin);
        EEPROM::updateChecksum();
#endif
#endif
    }
static inline void setTowerYFloor(float newZ) {
#if DRIVE_SYSTEM == DELTA
      Printer::yMin = newZ;
      Printer::updateDerivedParameter();
      Com::printFLN(PSTR("Y (B) tower floor set to: "), Printer::yMin, 3);
#if EEPROM_MODE != 0

        HAL::eprSetFloat(EPR_Y_HOME_OFFSET,Printer::yMin);
        EEPROM::updateChecksum();
#endif
#endif
}
static inline void setTowerZFloor(float newZ) {
#if DRIVE_SYSTEM == DELTA
      Printer::zMin = newZ;
      Printer::updateDerivedParameter();
      Com::printFLN(PSTR("Z (C) tower floor set to: "), Printer::zMin, 3);
#if EEPROM_MODE != 0
      HAL::eprSetFloat(EPR_Z_HOME_OFFSET,Printer::zMin);
        EEPROM::updateChecksum();
#endif
#endif
    }
    static inline void setDeltaTowerXOffsetSteps(int16_t steps) {
#if EEPROM_MODE != 0
        HAL::eprSetInt16(EPR_DELTA_TOWERX_OFFSET_STEPS,steps);
        EEPROM::updateChecksum();
#endif
    }
    static inline void setDeltaTowerYOffsetSteps(int16_t steps) {
#if EEPROM_MODE != 0
        HAL::eprSetInt16(EPR_DELTA_TOWERY_OFFSET_STEPS,steps);
        EEPROM::updateChecksum();
#endif
    }
    static inline void setDeltaTowerZOffsetSteps(int16_t steps) {
#if EEPROM_MODE != 0
        HAL::eprSetInt16(EPR_DELTA_TOWERZ_OFFSET_STEPS,steps);
        EEPROM::updateChecksum();
#endif
    }
    static inline float deltaTowerA_xPos() {
      return EEPROM_FLOAT(DELTA_TOWER_A_XPOS);
    }
    static inline float deltaTowerA_yPos() {
      return EEPROM_FLOAT(DELTA_TOWER_A_YPOS);
    }
    static inline float deltaTowerC_xPos() {
      return EEPROM_FLOAT(DELTA_TOWER_C_XPOS);
    }
    static inline float deltaDiagonalRodA() {
      return EEPROM_FLOAT(DELTA_DIAGONAL_A);
    }
    static inline float deltaDiagonalRodB() {
      return EEPROM_FLOAT(DELTA_DIAGONAL_B);
    }
    static inline float deltaDiagonalRodC() {
      return EEPROM_FLOAT(DELTA_DIAGONAL_C);
    }
    static inline float deltaTowerA_xTilt() {
      return EEPROM_FLOAT(DELTA_TOWER_A_XTILT);
    }
    static inline float deltaTowerA_yTilt() {
      return EEPROM_FLOAT(DELTA_TOWER_A_YTILT);
    }
    static inline float deltaTowerB_xTilt() {
      return EEPROM_FLOAT(DELTA_TOWER_B_XTILT);
    }
    static inline float deltaTowerB_yTilt() {
      return EEPROM_FLOAT(DELTA_TOWER_B_YTILT);
    }
    static inline float deltaTowerC_xTilt() {
      return EEPROM_FLOAT(DELTA_TOWER_C_XTILT);
    }
    static inline float deltaTowerC_yTilt() {
      return EEPROM_FLOAT(DELTA_TOWER_C_YTILT);
    }
    static inline float deltaMaxRadius() {
      return EEPROM_FLOAT(DELTA_MAX_RADIUS);
    }

#endif
    static void initalizeUncached();
#if MIXING_EXTRUDER
    static void storeMixingRatios(bool updateChecksums = true);
    static void readMixingRatios();
    static void restoreMixingRatios();
#endif

    static void setZCorrection(int32_t c,int index);
    static inline int32_t getZCorrection(int index) {
        return HAL::eprGetInt32(2048 + (index << 2));
    }
    static inline void setZCorrectionEnabled(int8_t on) {
#if EEPROM_MODE != 0
        if(isZCorrectionEnabled() == on) return;
        HAL::eprSetInt16(EPR_DISTORTION_CORRECTION_ENABLED, on);
        EEPROM::updateChecksum();
#endif
    }
    static inline int8_t isZCorrectionEnabled() {
#if EEPROM_MODE != 0
        return HAL::eprGetByte(EPR_DISTORTION_CORRECTION_ENABLED);
#else
        return 0;
#endif
    }
    static inline float bendingCorrectionA() {
#if EEPROM_MODE != 0
        return HAL::eprGetFloat(EPR_BENDING_CORRECTION_A);
#else
        return BENDING_CORRECTION_A;
#endif
    }
    static inline float bendingCorrectionB() {
#if EEPROM_MODE != 0
        return HAL::eprGetFloat(EPR_BENDING_CORRECTION_B);
#else
        return BENDING_CORRECTION_B;
#endif
    }
    static inline float bendingCorrectionC() {
#if EEPROM_MODE != 0
        return HAL::eprGetFloat(EPR_BENDING_CORRECTION_C);
#else
        return BENDING_CORRECTION_C;
#endif
    }
    static inline float accelarationFactorTop() {
#if EEPROM_MODE != 0
        return HAL::eprGetFloat(EPR_ACCELERATION_FACTOR_TOP);
#else
        return ACCELERATION_FACTOR_TOP;
#endif
    }
    static inline float parkX() {
	    #if EEPROM_MODE != 0
	    return HAL::eprGetFloat(EPR_PARK_X);
	    #else
	    return PARK_POSITION_X;
	    #endif
    }
    static inline float parkY() {
	    #if EEPROM_MODE != 0
	    return HAL::eprGetFloat(EPR_PARK_Y);
	    #else
	    return PARK_POSITION_Y;
	    #endif
    }
    static inline float parkZ() {
	    #if EEPROM_MODE != 0
	    return HAL::eprGetFloat(EPR_PARK_Z);
	    #else
	    return PARK_POSITION_Z_RAISE;
	    #endif
    }

};
#endif
