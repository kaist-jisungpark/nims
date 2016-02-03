/* 	AUTOMATICALLY GENERATED  -- DO NOT EDIT -- */

#ifndef __ERROR_CODES_H__90352305613045
#define __ERROR_CODES_H__90352305613045

namespace BVTSDK
{
	namespace ReturnCode
	{
		const RetVal INVALID_ERROR = -1;
		const RetVal SUCCESS = 0;
		const RetVal FAILED = 1;
		const RetVal MEMORY_ALLOC = 2;
		const RetVal FILE_OPEN = 3;
		const RetVal FILE_READ = 4;
		const RetVal FILE_WRITE = 5;
		const RetVal BAD_PARAMETER = 6;
		const RetVal INVALID_PTR = 7;
		const RetVal FILE_CREATE = 8;
		const RetVal FILE_SEEK = 9;
		const RetVal FILE_NOTOPEN = 10;
		const RetVal FILE_EXISTS = 11;
		const RetVal FILE_STAT = 12;
		const RetVal NOT_IMPLEMENTED = 13;
		const RetVal MKDIR_FAILED = 14;
		const RetVal BAD_CMDLINE = 15;
		const RetVal SUCCESS_EXIT = 16;
		const RetVal USER_ABORT = 17;
		const RetVal TIMEOUT = 18;
		const RetVal BUFFER_TOO_SMALL = 19;
		const RetVal SDK_EXPIRED = 20;
		const RetVal BAD_OFFSET = 1000;
		const RetVal BUFFER_TOO_SHORT = 1001;
		const RetVal FILE_HEADER_SHORT = 1002;
		const RetVal FILE_HEADER_BAD = 1003;
		const RetVal FILE_TOO_NEW = 1004;
		const RetVal BLOCK_ALLOC = 1005;
		const RetVal MAX_BLOCKCOUNT = 1006;
		const RetVal WRITE_TOO_BIG = 1007;
		const RetVal INVALID_BLOCKSIZE = 1008;
		const RetVal INVALID_MAXBLOCKCOUNT = 1009;
		const RetVal ZLIB_COMPRESS = 1010;
		const RetVal ZLIB_UNCOMPRESS = 1011;
		const RetVal CANT_LOCK = 1012;
		const RetVal SOCKET_CREATE = 1013;
		const RetVal LOOKUP_HOST = 1014;
		const RetVal CONNECTION_TIMEDOUT = 1015;
		const RetVal SOCKET_BIND = 1016;
		const RetVal SOCKET_READ_TIMEOUT = 1017;
		const RetVal SOCKET_WRITE_TIMEOUT = 1018;
		const RetVal BAD_SOCKET = 1019;
		const RetVal SOCKET_CLOSED = 1020;
		const RetVal SOCKET_WRITE = 1021;
		const RetVal SOCKET_READ = 1022;
		const RetVal SOCKET_SETSOCKOPT = 1023;
		const RetVal LOGGER_CREATE = 1024;
		const RetVal THREAD_START = 1025;
		const RetVal ALARM_EXIST = 1026;
		const RetVal BAD_UNITS = 1027;
		const RetVal INVALID_DIMENSION = 1028;
		const RetVal BAD_DATATYPE = 1029;
		const RetVal SER_EMPTY_QUEUE = 1030;
		const RetVal SER_FULL_QUEUE = 1031;
		const RetVal SER_BAD_PORT = 1032;
		const RetVal SER_SETUP_COMM = 1033;
		const RetVal SER_PURGE_COMM = 1034;
		const RetVal SER_COMM_TIMEOUTS = 1035;
		const RetVal SER_COMM_STATE = 1036;
		const RetVal SER_WIN32_POLL = 1037;
		const RetVal SER_READ = 1038;
		const RetVal SER_WRITE = 1039;
		const RetVal SER_INV_FLOW = 1040;
		const RetVal SER_INV_DATA = 1041;
		const RetVal SER_INV_PAR = 1042;
		const RetVal SER_INV_STOP = 1043;
		const RetVal SER_INV_BAUD = 1044;
		const RetVal SER_INV_CONFIG = 1045;
		const RetVal SOCKET_LISTEN = 1046;
		const RetVal SER_NOTOPEN = 1047;
		const RetVal BAD_UNITTYPE = 1048;
		const RetVal WRONG_PROTOCOL = 1049;
		const RetVal EMPTY = 1059;
		const RetVal SHUTDOWN = 1060;
		const RetVal ALREADY_STARTED = 1061;
		const RetVal QUEUE_FULL = 1062;
		const RetVal QUEUE_EMPTY = 1063;
		const RetVal INDEX_OUTOFBOUNDS = 1064;
		const RetVal SOCKET_NOT_CONNECTED = 1065;
		const RetVal SOCKET_WOULD_BLOCK = 1066;
		const RetVal STRING_TOO_LONG = 1067;
		const RetVal PULSE_SIGNATURE_BAD = 2000;
		const RetVal PULSE_BAD_COMPTYPE = 2001;
		const RetVal BAD_SONAR_TYPE = 2002;
		const RetVal BAD_PARENT = 2003;
		const RetVal BAD_IMAGE_BUILDER = 2004;
		const RetVal LISTENER_NOT_FOUND = 2005;
		const RetVal SON_XML_PARSE = 2006;
		const RetVal BAD_TRANSDUCER = 2007;
		const RetVal NO_TEMP = 2008;
		const RetVal NO_TILT = 2009;
		const RetVal NO_HEAD = 2010;
		const RetVal NO_TRANSDUCER = 2011;
		const RetVal BAD_BEAM_FORMER = 2012;
		const RetVal BAD_SONAR = 2013;
		const RetVal MATCH_FILTER_FAILURE = 2014;
		const RetVal INVALID_NORMALIZATION = 2015;
		const RetVal INVALID_SIGNAL_LENGTH = 2016;
		const RetVal V1_SIGNATURE_BAD = 4001;
		const RetVal PING_NUM_TOO_LARGE = 4002;
		const RetVal PING_NUM_TOO_SMALL = 4003;
		const RetVal WRONG_RECORD_TYPE = 4004;
		const RetVal NO_SETTINGS_RECORD = 4005;
		const RetVal NO_HEAD_RECORD = 4006;
		const RetVal V2_BAD_INDEX = 4007;
		const RetVal NOT_DIR = 4008;
		const RetVal BAD_RANGE = 4009;
		const RetVal UNKNOWN_RECORD_TYPE = 4010;
		const RetVal NO_PING_SIGNAL = 4011;
		const RetVal READONLY_FILE = 4012;
		const RetVal V2_BAD_COMPRESSION = 4013;
		const RetVal NO_VIDEO_FRAME = 4014;
		const RetVal INVALID_VIDEO_FORMAT = 4015;
		const RetVal NO_STORED_PROFILES = 4016;
		const RetVal INVALID_HEAD_COUNT = 4017;
		const RetVal INVALID_HEAD = 4018;
		const RetVal MISMATCHED_HEAD_PAIR = 4019;
		const RetVal BAD_MAP = 5000;
		const RetVal BAD_PING = 5001;
		const RetVal BAD_COLOR_MAP = 5002;
		const RetVal BAD_HEAD = 5003;
		const RetVal BAD_IMAGE_TYPE = 5004;
		const RetVal IMG_NO_TRANSDUCERS = 5005;
		const RetVal BAD_RANGE_POLICY = 5006;
		const RetVal INACCURATE_TRANSDUCERS = 5007;
		const RetVal INVALID_IMG_SIZE = 5008;
		const RetVal INVALID_TXDR_COUNT = 5009;
		const RetVal INVALID_RESOLUTION = 5010;
		const RetVal MEDIAN_FILTER_BIG = 7000;
		const RetVal NOT_ENOUGH_DATA = 7001;
		const RetVal PV_NO_SONAR = 9000;
		const RetVal PV_LOAD_COLORMAP = 9001;
		const RetVal PV_LOAD_FILE = 9002;
		const RetVal PT_BAD_SPEED = 10000;
		const RetVal PT_BAD_BRAKE = 10001;
		const RetVal PT_BAD_ANGLE = 10002;
		const RetVal PT_NODE_EXISTS = 10003;
		const RetVal PT_NODE_NOT_FOUND = 10004;
		const RetVal PT_INVALID_NODE = 10005;
		const RetVal PT_WRONG_NODE = 10006;
		const RetVal PT_WRONG_LEN = 10007;
		const RetVal PT_BUS_COL = 10008;
		const RetVal PT_HORIZ_AXIS_FAIL = 10009;
		const RetVal PT_VERT_AXIS_FAIL = 10010;
		const RetVal PT_NO_HORIZ = 10011;
		const RetVal PT_NO_VERT = 10012;
		const RetVal PT_DUP_NODES = 10013;
		const RetVal PT_OLD_FIRMWARE = 10014;
		const RetVal PT_ECHO_FAILURE = 10015;
		const RetVal PT_INV_RESPONSE_FORMAT = 10016;
		const RetVal PT_CMD_IN_PROGRESS = 10017;
		const RetVal PT_NOT_CONNECTED = 10018;
		const RetVal ST_INVALID_SETTING = 11000;
		const RetVal ST_INVALID_ORIENTATION = 11001;
		const RetVal ST_BAD_SONAR_NUM = 11002;
		const RetVal AVI_CREATE_FILE = 12000;
		const RetVal AVI_ALREADY_COMP = 12001;
		const RetVal AVI_CREATE_STREAM = 12002;
		const RetVal AVI_SET_FORMAT = 12003;
		const RetVal AVI_WRITE_FRAME = 12004;
		const RetVal AVI_CREATE_DIB = 12005;
		const RetVal V_OLE_FAILURE = 13000;
		const RetVal V_DSHOW_ERROR = 13001;
		const RetVal V_NO_VIDEO_CAPTURE = 13002;
		const RetVal V_CANT_USE_VIDEO = 13003;
		const RetVal V_DSHOW_NOPLAY = 13004;
		const RetVal V_VID_FORMAT = 13005;
		const RetVal NET_BAD_PACKET_SIZE = 14000;
		const RetVal NET_BAD_PACKET_TYPE = 14001;
		const RetVal NET_XML_PARSE = 14002;
		const RetVal NET_NOT_CONNECTED = 14003;
		const RetVal NET_BAD_PACKET_VER = 14004;
		const RetVal NET_BAD_NETSETTINGS = 14005;
		const RetVal NDAQ_NOT_OPEN = 15000;
		const RetVal NDAQ_SET_REG = 15001;
		const RetVal NDAQ_GET_REG = 15002;
		const RetVal NDAQ_MEM_WRITE = 15003;
		const RetVal NDAQ_MEM_READ = 15004;
		const RetVal NDAQ_MEM_ALLOC = 15005;
		const RetVal NDAQ_MEM_TEST = 15006;
		const RetVal NDAQ_BAD_ID = 15007;
		const RetVal NDAQ_MMAP = 15008;
		const RetVal NDAQ_CFG_TOO_LARGE = 15009;
		const RetVal NDAQ_CFG_ERASE = 15010;
		const RetVal NDAQ_HOLDOFF_TIMEOUT = 15011;
		const RetVal NDAQ_BAD_BASE_TXDR = 15012;
		const RetVal NDAQ_MASTER_PORT_ERR = 15013;
		const RetVal NAV_NO_DATA = 16000;
		const RetVal NMEA_INPUT_DISABLED = 17000;
		const RetVal NMEA_OUTUT_DISABLED = 17001;
		const RetVal NMEA_SRV_UNINIT = 17002;
		const RetVal NMEA_INVALID = 17003;
		const RetVal NMEA_ID_UNKNOWN = 17004;
		const RetVal TRIGGER_NOT_PRESENT = 18000;
		const RetVal TRIG_OPTIONS_INVALID = 18001;
		const RetVal TRIGGER_IS_INPUT = 18002;
		const RetVal TRIGGER_IS_OUTPUT = 18003;
		const RetVal PV_IF_UNINIT = 19000;
		const RetVal PV_IF_BAD_MSG = 19001;
		const RetVal FEAT_BAD_CFG = 20000;
		const RetVal FEAT_EXPORT_FAILURE = 20001;
		const RetVal FEAT_INVALID_NODE = 20002;
	}
}

#endif

