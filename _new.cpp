/*
 *  Nekton Interaction Monitoring System (NIMS)
 *
 *  filename.cpp
 *  
 *  Created by Firstname Lastname on mm/dd/yyyy.
 *  Copyright 2015 Pacific Northwest National Laboratory. All rights reserved.
 *
 */
#include <iostream> // cout, cin, cerr
//#include <fstream>  // ifstream, ofstream
#include <string>   // for strings

//#include <opencv2/opencv.hpp>

//#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>

using namespace std;
//using namespace cv;
using namespace boost;
namespace po = boost::program_options;
//namespace fs = boost::filesystem;


int main (int argc, char * const argv[]) {
	//--------------------------------------------------------------------------
    // PARSE COMMAND LINE
	//
	po::options_description desc;
	desc.add_options()
	("help",                                                    "print help message")
	("foo,f", po::value<string>()->default_value( "" ),         "a string value")
	("bar,b",   po::value<unsigned int>()->default_value( 101 ),"an integer value")
	;
	po::variables_map options;
    try
    {
        po::store( po::parse_command_line( argc, argv, desc ), options );
    }
    catch( const std::exception& e )
    {
        cerr << "Sorry, couldn't parse that: " << e.what() << endl;
        cerr << desc << endl;
        return -1;
    }
	
	po::notify( options );
	
    if( options.count( "help" ) > 0 )
    {
        cerr << desc << endl;
        return 0;
    }
	
    string foo = options["foo"].as<string>();
	unsigned int bar = options["bar"].as<unsigned int>();
    
	//--------------------------------------------------------------------------
	// DO STUFF
	cout << endl << "Starting " << argv[0] << endl;
	
	   
	cout << endl << "Ending " << argv[0] << endl << endl;
    return 0;
}
