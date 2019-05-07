
#ifndef TLS_HANDSHAKE_H
#define TLS_HANDSHAKE_H

#include <cybermon/context.h>
#include <cybermon/manager.h>
#include <cybermon/tls.h>



namespace cybermon {


class tls_handshake {
public:
  static void process(manager& mgr, tls_context::ptr ctx, const pdu_slice& pduSlice, const tls::header* hdr);
private:
  static void processMessage(manager& mgr, tls_context::ptr ctx, const pdu_slice& pduSlice, uint8_t type);
  static void clientHello(manager& mgr, tls_context::ptr ctx, const pdu_slice& pduSlice, uint16_t length);
  static void processExtensions(const pdu_slice& pduSlice, uint16_t length, std::vector<tls_handshake_protocol::extension>& exts);

  struct client_hello {
    uint8_t majVersion;
    uint8_t minVersion;
    uint16_t date1; // split due to padding
    uint16_t date2;
    uint8_t random[28];
  };
};


} // cybermon


#endif
