#ifndef PCAPOPENNER_H
#define PCAPOPENNER_H
#include <pcap.h>
#include <string>

typedef struct _pcap_packet {
    const struct pcap_pkthdr *pcap_header;
    const u_char *data;
    long long data_len;
    _pcap_packet():pcap_header(nullptr),data(nullptr),data_len(-1){}
    _pcap_packet(const struct pcap_pkthdr *_ph,
                 const u_char *_d, const long long _l):pcap_header(_ph),data(_d),data_len(_l){}
    _pcap_packet(const _pcap_packet&) = default;
    _pcap_packet(_pcap_packet&&) = default;
    _pcap_packet& operator=(const _pcap_packet&) = default;
    _pcap_packet& operator=(_pcap_packet&&) = default;
} Packet_t;

class pcapOpenner {
public:
    pcapOpenner() = default;
    ~pcapOpenner();
    bool initPCAP(std::string _filePath);
    inline Packet_t getPacket() {
        if (this->inited && pcap_next_ex(this->pcap, &this->header, &this->data) >= 0)
            return Packet_t(this->header,this->data,this->header->caplen);
        else
            return Packet_t();
    }

private:
    bool inited = false;    
    pcap_t * pcap;
    const u_char *data;    
    struct pcap_pkthdr *header;
    char errbuff[PCAP_ERRBUF_SIZE];    
};
#endif // PCAPOPENNER_H