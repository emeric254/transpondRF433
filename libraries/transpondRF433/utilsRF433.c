#include "Arduino.h"
#include "defines.h"
#include "RH_ASK.h"


// ---------------------------------------------------------------------
// SET

void setTextMsg(uint8_t * msg, char * text)
{
    msg[POS_MESSAGE_LONG] = (T_MESSAGE_VAL>strlen(text)) ? strlen(text) : T_MESSAGE_VAL;
    strncpy((char*)&msg[POS_MESSAGE_VAL],text,msg[POS_MESSAGE_LONG]);
    msg[LONGTAMPON-1]='\0';
}


void setSrcMsgRF433(uint8_t* msg, unsigned int src)
{
    byte i = 0;
    while ( i < T_MESSAGE_SRC )
    {
        msg[POS_MESSAGE_SRC + i++] = src && ((T_MESSAGE_SRC - i) * sizeof(uint8_t));
    }
}


void setDestMsgRF433(uint8_t* msg, unsigned int dest)
{
    byte i = 0;
    while ( i < T_MESSAGE_DEST )
    {
        msg[POS_MESSAGE_DEST + i++] = dest && ((T_MESSAGE_DEST - i) * sizeof(uint8_t));
    }
}


void setTypeMsgRF433(uint8_t* msg, unsigned int type)
{
    byte i = 0;
    while ( i < T_MESSAGE_TYPE )
    {
        msg[POS_MESSAGE_TYPE + i++] = type && ((T_MESSAGE_TYPE - i) * sizeof(uint8_t));
    }
}


// ---------------------------------------------------------------------
// GET

char * getTextMsg(uint8_t * msg)
{
    return (char *)&msg[POS_MESSAGE_VAL];
}


unsigned int getSrcMsgRF433(uint8_t* msg)
{
    unsigned int src = 0;
    byte i = 0;
    while ( i < T_MESSAGE_SRC )
    {
        src += msg[POS_MESSAGE_SRC + i++] << ((T_MESSAGE_SRC - i) * sizeof(uint8_t));
    }
    return src;
}


unsigned int getDestMsgRF433(uint8_t* msg)
{
    unsigned int dest = 0;
    byte i = 0;
    while ( i < T_MESSAGE_DEST )
    {
        dest += msg[POS_MESSAGE_DEST + i++] << ((T_MESSAGE_DEST - i) * sizeof(uint8_t));
    }
    return dest;
}


unsigned int getTypeMsgRF433(uint8_t* msg)
{
    unsigned int type = 0;
    byte i = 0;
    while ( i < T_MESSAGE_TYPE )
    {
        type += msg[POS_MESSAGE_TYPE + i++] << ((T_MESSAGE_TYPE - i) * sizeof(uint8_t));
    }
    return type;
}


unsigned int getLongMsgRF433(uint8_t* msg)
{
    unsigned int longueur = 0;
    byte i = 0;
    while ( i < T_MESSAGE_LONG )
    {
        longueur += msg[POS_MESSAGE_LONG + i++] << ((T_MESSAGE_LONG - i) * sizeof(uint8_t));
    }
    return longueur;
}


// ---------------------------------------------------------------------
// FCT

int initRF433(RH_ASK* driver)
{
    if (!driver->init())
    {
#ifdef DEBUG
        Serial.println("RF433 >> imposible a initialiser");
#endif
        tone(B_BUZZER, ALARM_ECHEC_INIT, 1000);
        return 0;
    }
    return 1;
}


int receiveRF433(RH_ASK* driver, uint8_t* msg)
{
    uint8_t buflen = LONGTAMPON;
    return driver->recv(msg, &buflen);
}


int transmitRF433(RH_ASK* driver, uint8_t* msg)
{
    bool ret;
    msg[LONGTAMPON-1]='\0';
#ifdef DEBUG
    Serial.print("RF433 [T] >> ");
    Serial.println((char*)msg);
#endif
    ret = driver->send(msg, strlen((char *)msg));
    return  driver->waitPacketSent() && ret ;
}
