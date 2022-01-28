#ifndef _ROS_SERVICE_counter_h
#define _ROS_SERVICE_counter_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace counter_node
{

static const char COUNTER[] = "counter_node/counter";

  class counterRequest : public ros::Msg
  {
    public:
      typedef int16_t _req_id_type;
      _req_id_type req_id;

    counterRequest():
      req_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_req_id;
      u_req_id.real = this->req_id;
      *(outbuffer + offset + 0) = (u_req_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_req_id.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->req_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_req_id;
      u_req_id.base = 0;
      u_req_id.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_req_id.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->req_id = u_req_id.real;
      offset += sizeof(this->req_id);
     return offset;
    }

    const char * getType(){ return COUNTER; };
    const char * getMD5(){ return "d67e2fcd47f3255cc3fbcfba8a121186"; };

  };

  class counterResponse : public ros::Msg
  {
    public:
      typedef float _reply_type;
      _reply_type reply;

    counterResponse():
      reply(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_reply;
      u_reply.real = this->reply;
      *(outbuffer + offset + 0) = (u_reply.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reply.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reply.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reply.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reply);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_reply;
      u_reply.base = 0;
      u_reply.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reply.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reply.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reply.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reply = u_reply.real;
      offset += sizeof(this->reply);
     return offset;
    }

    const char * getType(){ return COUNTER; };
    const char * getMD5(){ return "040d3b0e975a8d9d7be9e89146cbb7a9"; };

  };

  class counter {
    public:
    typedef counterRequest Request;
    typedef counterResponse Response;
  };

}
#endif
