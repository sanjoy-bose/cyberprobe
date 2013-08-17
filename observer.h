
#ifndef OBSERVER_H
#define OBSERVER_H

#include "context.h"

namespace analyser {

    // Observer interface.  The observer interface is called when various
    // reportable events occur.
    class observer {
    public:
	
	// Connection-orientated.
	virtual void connection_up(const context_ptr cp) = 0;
	virtual void connection_down(const context_ptr cp) = 0;
	virtual void connection_data(const context_ptr cp,
				     pdu_iter s, pdu_iter e) = 0;

	// Connection-less
	virtual void datagram(const context_ptr cp,
			      pdu_iter s, pdu_iter e) = 0;

	// HTTP
	virtual void http_request(const context_ptr cp,
				  const std::string& method,
				  const std::string& url,
				  const std::map<std::string,std::string>& hdr,
				  pdu_iter body_start,
				  pdu_iter body_end) = 0;

	virtual void trigger_up(const std::string& liid,
				const tcpip::address& trigger_address) = 0;
	virtual void trigger_down(const std::string& liid) = 0;
    };

};

#endif

