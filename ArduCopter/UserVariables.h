/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

// user defined variables

// example variables used in Wii camera testing - replace with your own
// variables
#ifdef USERHOOK_VARIABLES

// Analog Input
static AP_HAL::AnalogSource *mp;

// DataFlash Writing
# define LOG_ANALOG                    ENABLED

// Analog sensor data packet
struct PACKED log_Analog {
    LOG_PACKET_HEADER;
    float voltage;
};

// Write a analog sensor packet
static void Log_Write_Analog(float voltage)
{
    struct log_Analog pkt = {
        LOG_PACKET_HEADER_INIT(LOG_MODE_MSG),
        voltage            : voltage,
    };
    DataFlash.WriteBlock(&pkt, sizeof(pkt));
}

#if WII_CAMERA == 1
WiiCamera           ircam;
int                 WiiRange=0;
int                 WiiRotation=0;
int                 WiiDisplacementX=0;
int                 WiiDisplacementY=0;
#endif  // WII_CAMERA

#endif  // USERHOOK_VARIABLES


