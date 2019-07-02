
////////////////////////////////////////////////////////////////////////////
//
// SNORT ALERTER RESOURCE
//
////////////////////////////////////////////////////////////////////////////

#ifndef SNORT_ALERT_H
#define SNORT_ALERT_H

#include <cybermon/resource.h>

#include "delivery.h"

// Specification for a snort alerter.
class snort_alerter_spec : public cybermon::specification {

public:

    // Type is 'snort_alerter'.
    virtual std::string get_type() const { return "snort_alerter"; }

    // Pathname of socket.
    std::string path;

    // Duration for tips to stay active.
    int duration;

    // Constructors.
    snort_alerter_spec() {}

    snort_alerter_spec(const std::string& path, int duration) {
	this->path = path; this->duration = duration;
    }

    // Hash is path:duration
    virtual std::string get_hash() const { 
	std::ostringstream buf;
	buf << path << ":" << duration;
	return buf.str();
    }

};

// Snort alerter, receives snort alerts and enables targeting on alerted
// IP addresses.
class snort_alerter : public cybermon::resource {

private:

    // Specification.
    snort_alerter_spec& spec;

    // True = running.
    bool running;

    // Deliver engine, we mess with the targeting on this.
    delivery& deliv;

    std::thread* thr;

public:

    // Constructor.
    snort_alerter(snort_alerter_spec& spec,
		  delivery& deliv) : spec(spec), deliv(deliv) {
	running = true; 
    }

    // Destructor
    virtual ~snort_alerter() {
	delete thr;
    }

    // Thread body.
    virtual void run();

    // Thread start.
    virtual void start() {

	thr = new std::thread(&snort_alerter::run, this);

	std::cerr << "Start snort alerter on " << spec.path << std::endl;
    }

    // Thread stop.
    virtual void stop() {
	running = false;
	join();
	std::cerr << "Stopped snort alerter." << std::endl;
    }

    virtual void join() {
	thr->join();
    }
    
};

#endif

