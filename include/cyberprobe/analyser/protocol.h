
#ifndef CYBERMON_PROTOCOL_H
#define CYBERMON_PROTOCOL_H

#include <cybermon/manager.h>
#include <cybermon/context.h>
#include <cybermon/pdu.h>

namespace cybermon {

    typedef void (*process_fn)(manager&, context_ptr c, const pdu_slice& sl);

};

#endif

