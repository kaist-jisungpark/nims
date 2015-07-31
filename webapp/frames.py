#!/usr/bin/python

# Python modules
import sys
import time
from struct import *
import mmap

# 3rd party modules
import posix_ipc


class frame_buffer:

    def __init__(self, buff):
        self.valid = self.parse_buffer(buff)

    def unpacker(self, fmt, buff):
        size = calcsize(fmt)
        return unpack(fmt, buff[:size]), buff[size:]

    def parse_buffer(self, buff):
        print "At parse buffer"
        try:
            self.device, buff = self.unpacker('c' * 64, buff)
            dev = ""
            for x in self.device:
                if x == '\x00':
                    break
                dev = dev + x
            self.device = dev
            self.version, buff = self.unpacker('I', buff)
            self.ping_num, buff = self.unpacker('I', buff)
            self.ping_sec, buff = self.unpacker('I', buff)
            self.ping_millisec, buff = self.unpacker('I', buff)
            self.soundspeed_mps, buff = self.unpacker('f', buff)
            self.num_samples, buff = self.unpacker('I', buff)
            self.range_min_m, buff = self.unpacker('f', buff)
            self.range_max_m, buff = self.unpacker('f', buff)
            self.winstart_sec, buff = self.unpacker('f', buff)
            self.winlen_sec, buff = self.unpacker('f', buff)
            self.num_beams, buff = self.unpacker('I', buff)
            self.beam_angles_deg, buff = self.unpacker('f' * self.num_beams[0], buff)
            self.freq_hz, buff = self.unpacker('I', buff)
            self.pulselen_microsec, buff = self.unpacker('I', buff)
            self.pulserep_hz, buff = self.unpacker('f', buff)
            print "Parsed buffer.."
            return True
        except:
            print "Failed to parse buff:", sys.exc_info()
            return False

    def print_field(self, field, v):
        if v == None:
            return
        v = v[0]
        spaces= 14 - len(field)

        print ""*spaces-1, field,":",v[0] 
    def print_header(self):
        #self.print_field("version", self.version)

        #print "device: ", self.device
        #print "version:", self.version
        #return

        #print "          device:", self.device[0]
        print "         version:", self.version[0]
        print "     ping number:", self.ping_num[0]
        print "        ping sec:", self.ping_sec[0]
        print "         ping ms:", self.ping_millisec[0]
        print "soundspeed (mps):", self.soundspeed_mps[0]
        print "     num_samples:", self.num_samples[0]
        print "   range min (m):", self.range_min_m[0]
        print "   range max (m):", self.range_max_m[0]
        print "    window start:", self.winstart_sec[0]
        print "   window length:",  self.winlen_sec[0]
        print "       num beams:", self.num_beams[0]
        print "     beam angles:", self.beam_angles_deg
        print "       freq (hz):", self.freq_hz[0]
        print "  pulse len (ms):", self.pulselen_microsec[0]
        print "  pulse rep (hz):", self.pulserep_hz[0]


class frame_message:
    def __init__(self, message):
        self.valid = self.parse_message(message)

    def unpacker(self, fmt, buff):
        s = calcsize(fmt)
        return unpack(fmt, buff[:s]), buff[s:]

    def parse_message(self, message):
        try:
            self.frame_number, message = self.unpacker('q', message)
            self.frame_length, message = self.unpacker('Q', message)
            self.shm_location, message = self.unpacker('s'*64, message)

            self.frame_number = self.frame_number[0]
            self.frame_length = self.frame_length[0]
            shm = ""
            for x in self.shm_location:
                if x == '\x00':
                    break
                shm = shm + x
            self.shm_location = shm
            return True
        except:
            print "Failed to parse buff:", sys.exc_info()
            return False

    def print_message(self):
        print "frame number:", self.frame_number
        print "frame length:", self.frame_length
        print "shm location:", self.shm_location