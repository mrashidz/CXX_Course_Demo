#include "pcapOpenner.h"
#include <iostream>

pcapOpenner::~pcapOpenner() {
    if(this->inited) pcap_close(this->pcap);
}

bool pcapOpenner::initPCAP(std::string _filePath) {
    this->pcap = pcap_open_offline(_filePath.c_str(), this->errbuff);
    this->inited = true;
    if (this->pcap == nullptr) {
        std::cout << this->errbuff << std::endl;
        this->inited = false;
    }
    return this->inited;
}
