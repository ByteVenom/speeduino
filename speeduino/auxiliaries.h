#ifndef AUX_H
#define AUX_H

#include BOARD_H //Note that this is not a real file, it is defined in globals.h. 

void initialiseAuxPWM();
void boostControl();
void boostDisable();
void idleControl();
void vvtControl();
void initialiseFan();
void initialiseMainRelay();
void nitrousControl();
void fanControl();

#define BOOST_PIN_LOW()  *boost_pin_port &= ~(boost_pin_mask)
#define BOOST_PIN_HIGH() *boost_pin_port |= (boost_pin_mask)
#define VVT_PIN_LOW()    *vvt_pin_port &= ~(vvt_pin_mask)
#define VVT_PIN_HIGH()   *vvt_pin_port |= (vvt_pin_mask)
#define FAN_PIN_LOW()    *fan_pin_port &= ~(fan_pin_mask)
#define FAN_PIN_HIGH()   *fan_pin_port |= (fan_pin_mask)
#define SEC_FAN_PIN_LOW()    *sec_fan_pin_port &= ~(sec_fan_pin_mask)
#define SEC_FAN_PIN_HIGH()   *sec_fan_pin_port |= (sec_fan_pin_mask)
#define MAIN_RELAY_PIN_LOW()    *main_relay_pin_port &= ~(main_relay_pin_mask)
#define MAIN_RELAY_PIN_HIGH()   *main_relay_pin_port |= (main_relay_pin_mask)

#define N2O_STAGE1_PIN_LOW()  *n2o_stage1_pin_port &= ~(n2o_stage1_pin_mask)
#define N2O_STAGE1_PIN_HIGH() *n2o_stage1_pin_port |= (n2o_stage1_pin_mask)
#define N2O_STAGE2_PIN_LOW()  *n2o_stage2_pin_port &= ~(n2o_stage2_pin_mask)
#define N2O_STAGE2_PIN_HIGH() *n2o_stage2_pin_port |= (n2o_stage2_pin_mask)
#define READ_N2O_ARM_PIN()    ((*n2o_arming_pin_port & n2o_arming_pin_mask) ? true : false)

volatile PORT_TYPE *boost_pin_port;
volatile byte boost_pin_mask;
volatile PORT_TYPE *vvt_pin_port;
volatile byte vvt_pin_mask;
volatile PORT_TYPE *fan_pin_port;
volatile byte fan_pin_mask;
volatile byte *main_relay_pin_port;
volatile byte main_relay_pin_mask;
volatile byte *n2o_stage1_pin_port;
volatile byte n2o_stage1_pin_mask;
volatile PORT_TYPE *n2o_stage2_pin_port;
volatile byte n2o_stage2_pin_mask;
volatile PORT_TYPE *n2o_arming_pin_port;
volatile byte n2o_arming_pin_mask;

volatile bool boost_pwm_state;
unsigned int boost_pwm_max_count; //Used for variable PWM frequency
volatile unsigned int boost_pwm_cur_value;
long boost_pwm_target_value;
long boost_cl_target_boost;
byte boostCounter;

byte fanHIGH = HIGH;             // Used to invert the cooling fan output
byte fanLOW = LOW;               // Used to invert the cooling fan output

byte mainRelayHIGH = HIGH;
byte mainRelayLOW = LOW;

volatile bool vvt_pwm_state;
unsigned int vvt_pwm_max_count; //Used for variable PWM frequency
volatile unsigned int vvt_pwm_cur_value;
long vvt_pwm_target_value;
static inline void boostInterrupt();
static inline void vvtInterrupt();


#endif
