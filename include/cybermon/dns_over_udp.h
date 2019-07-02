
////////////////////////////////////////////////////////////////////////////
//
// DNS over UDP processing
//
////////////////////////////////////////////////////////////////////////////

#ifndef CYBERMON_DNS_OVER_UDP_H
#define CYBERMON_DNS_OVER_UDP_H


#include "cybermon/context.h"
#include "cybermon/manager.h"
#include "cybermon/pdu.h"


namespace cybermon
{

    class dns_over_udp
    {
    public:

        // DNS over UDP processing function.
        static void process(manager&, context_ptr c, const pdu_slice& s);
    };

}; // End namespace

#endif

