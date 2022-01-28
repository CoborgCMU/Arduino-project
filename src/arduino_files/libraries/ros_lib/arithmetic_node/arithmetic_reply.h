#ifndef _ROS_arithmetic_node_arithmetic_reply_h
#define _ROS_arithmetic_node_arithmetic_reply_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace arithmetic_node
{

  class arithmetic_reply : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _oper_type_type;
      _oper_type_type oper_type;
      typedef float _answer_type;
      _answer_type answer;
      typedef float _time_received_type;
      _time_received_type time_received;
      typedef float _time_answered_type;
      _time_answered_type time_answered;
      typedef float _process_time_type;
      _process_time_type process_time;

    arithmetic_reply():
      header(),
      oper_type(""),
      answer(0),
      time_received(0),
      time_answered(0),
      process_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_oper_type = strlen(this->oper_type);
      varToArr(outbuffer + offset, length_oper_type);
      offset += 4;
      memcpy(outbuffer + offset, this->oper_type, length_oper_type);
      offset += length_oper_type;
      union {
        float real;
        uint32_t base;
      } u_answer;
      u_answer.real = this->answer;
      *(outbuffer + offset + 0) = (u_answer.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_answer.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_answer.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_answer.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->answer);
      offset += serializeAvrFloat64(outbuffer + offset, this->time_received);
      offset += serializeAvrFloat64(outbuffer + offset, this->time_answered);
      offset += serializeAvrFloat64(outbuffer + offset, this->process_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_oper_type;
      arrToVar(length_oper_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_oper_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_oper_type-1]=0;
      this->oper_type = (char *)(inbuffer + offset-1);
      offset += length_oper_type;
      union {
        float real;
        uint32_t base;
      } u_answer;
      u_answer.base = 0;
      u_answer.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_answer.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_answer.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_answer.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->answer = u_answer.real;
      offset += sizeof(this->answer);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->time_received));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->time_answered));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->process_time));
     return offset;
    }

    const char * getType(){ return "arithmetic_node/arithmetic_reply"; };
    const char * getMD5(){ return "cff965eb480643e73d2e8348f0d32d0e"; };

  };

}
#endif
