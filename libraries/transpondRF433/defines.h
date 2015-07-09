/* ------------------------------------------------------------------ */
/*  ---------   AUTRES   ---------   */

#define DEBUG   true


/* ------------------------------------------------------------------ */
/*  ---------   BROCHES ---------   */

// digital
#define B_RF433_RECEPTION       11
#define B_RF433_EMISSION        12
#define B_BUZZER                13


/* ------------------------------------------------------------------ */
/*  ---------   RF433   ---------   */

// taille tampon max
#define LONGTAMPON              RH_ASK_MAX_MESSAGE_LEN

// position des informations
#define POS_MESSAGE_TYPE        0
#define POS_MESSAGE_SRC         POS_MESSAGE_TYPE + T_MESSAGE_TYPE
#define POS_MESSAGE_DEST        POS_MESSAGE_SRC + T_MESSAGE_SRC
#define POS_MESSAGE_LONG        POS_MESSAGE_DEST + T_MESSAGE_DEST
#define POS_MESSAGE_VAL         POS_MESSAGE_LONG + T_MESSAGE_LONG

// taille des informations
#define T_MESSAGE_TYPE          1
#define T_MESSAGE_SRC           2
#define T_MESSAGE_DEST          2
#define T_MESSAGE_LONG          1
#define T_MESSAGE_VAL           LONGTAMPON - POS_MESSAGE_VAL //  == ce qu'il reste


/* ------------------------------------------------------------------ */
/*  ---------   TYPES MESSAGES   ---------   */

#define MESSAGE_RAW             0
#define MESSAGE_DEBUG           1


/* ------------------------------------------------------------------ */
/*  ---------   FREQUENCES SONORES BUZZER   ---------   */

#define ALARM_ECHEC_INIT        1000
