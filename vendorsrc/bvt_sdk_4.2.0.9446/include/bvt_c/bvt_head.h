/*
    This file has been generated by bvtidl.pl. DO NOT MODIFY!
*/
#ifndef __BVTHEAD_H__
#define __BVTHEAD_H__

#include <bvt_c/bvt_retval.h>
#include <bvt_c/bvt_ping.h>
#include <bvt_c/bvt_orientation.h>

#ifndef DOXY_IGNORE
#ifdef _WIN32
#	ifdef BUILDING_BVTSDK
#		define BVTSDK_EXPORT __declspec(dllexport)
#	else
#		define BVTSDK_EXPORT __declspec(dllimport)
#	endif
#	if !defined(BVTSDK_NO_DEPRECATE) && _MSC_VER >= 1310
#		define BVTSDK_EXPORT_OBSOLETE BVTSDK_EXPORT __declspec(deprecated("This will be removed in a future version of the BlueView SDK"))
#	else
#		define BVTSDK_EXPORT_OBSOLETE BVTSDK_EXPORT
#	endif
#else
#	if __GNUC__ >= 4
#		define BVTSDK_EXPORT __attribute__ ((visibility ("default")))
#	else
#		define BVTSDK_EXPORT
#	endif
#	if !defined(BVTSDK_NO_DEPRECATE) && ((__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 1)))
#		define BVTSDK_EXPORT_OBSOLETE BVT_EXPORT __attribute__((__deprecated__("This will be removed in a future version of the BlueView SDK")))
#	else
#		define BVTSDK_EXPORT_OBSOLETE BVTSDK_EXPORT
#	endif
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

/** @file
 * @defgroup BVTHead BVTHead
 * @brief
 * A head consists of a group of co-planar transducers which are
 * operated simultaneously to produce (ultimately) a single 2d
 * image.  The Head object provides functions to change the 
 * range window as well as produce pings.
 * @{
*/

/** Opaque type for BVTHead object instances */
typedef struct BVTOpaqueHead* BVTHead;

/** Destroy a BVTHead object
 *  @param obj Object pointer
*/
BVTSDK_EXPORT void BVTHead_Destroy(BVTHead obj);

enum BVTFluidType
{
	BVT_FLUIDTYPE_SALTWATER = 0,
	BVT_FLUIDTYPE_FRESHWATER = 1,
	BVT_FLUIDTYPE_OTHER = 2
};

enum BVTImageRes
{
	BVT_IMAGERES_OFF = 0,
	BVT_IMAGERES_LOW = 1,
	BVT_IMAGERES_MEDIUM = 2,
	BVT_IMAGERES_HIGH = 3,
	BVT_IMAGERES_AUTO = 4
};

enum BVTImageType
{
	BVT_IMAGETYPE_XY = 0,
	BVT_IMAGETYPE_RTHETA = 1
};

enum BVTImageFilterFlags
{
	BVT_IMAGEFILTERFLAGS_NONE = 0,
	BVT_IMAGEFILTERFLAGS_MEAN3X3 = 2,
	BVT_IMAGEFILTERFLAGS_MEAN9X2 = 16
};

enum BVTImageProcessingMethod
{
	BVT_IMAGEPROCESSINGMETHOD_A = 0,
	BVT_IMAGEPROCESSINGMETHOD_B = 1
};

enum BVTMountType
{
	BVT_MOUNTTYPE_UNKNOWN = 0,
	BVT_MOUNTTYPE_POLE = 1,
	BVT_MOUNTTYPE_TRIPOD = 2,
	BVT_MOUNTTYPE_ROV = 3,
	BVT_MOUNTTYPE_UUV = 4,
	BVT_MOUNTTYPE_OTHER = 5
};

enum BVTMountSide
{
	BVT_MOUNTSIDE_UNKNOWN = 0,
	BVT_MOUNTSIDE_PORT = 1,
	BVT_MOUNTSIDE_STARBOARD = 2,
	BVT_MOUNTSIDE_DORSAL = 3,
	BVT_MOUNTSIDE_VENTRAL = 4,
	BVT_MOUNTSIDE_BOW = 5,
	BVT_MOUNTSIDE_STERN = 6,
	BVT_MOUNTSIDE_OTHER = 7
};

/** Retrieve the Head's ID.
 * @param self Object pointer
 * @param headId ID for this head
 * @returns headId

 */
BVTSDK_EXPORT RetVal BVTHead_GetHeadID(BVTHead self, int* headId);

/** Retrieves a copy of a the name of the head. The head name is currently
 * set only at the factory, and is simply "Head" on many sonars. Only special
 * order sonars with multiple heads are likely to have a different name.<br>
 * The length of the name has no actual limit, though 80 characters
 * would seem to be more than enough.
 * @param self Object pointer
 * @param buffer buffer to hold the null-terminated string to be passed back 
 * @returns buffer

 * @param buffer_size total number of characters the passed buffer can hold 
 */
BVTSDK_EXPORT RetVal BVTHead_GetHeadName(BVTHead self, char* buffer, int buffer_size);

/** Persistently sets the name of the head. This should not be done frequently due
 * wear on the sonar's onboard storage (Flash memory). The head name is currently
 * set at the factory, and is simply "Head" on many sonars. Only special
 * order sonars with multiple heads are likely to have a different name.
 * @param self Object pointer
 * @param name null-terminated name string. 
 */
BVTSDK_EXPORT RetVal BVTHead_SetHeadName(BVTHead self, const char* name);

/** Set the range to be acquired.
 * @note The start range must be greater than or equal to @ref BVTHead_GetMinimumRange, and the stop range must be less than or equal to @ref BVTHead_GetMaximumRange
 * \warning You may not call this during recording on either the source sonar or the destination file sonar.
 * @param self Object pointer
 * @param start Start range in meters. 
 * @param stop Stop range in meters. 
 */
BVTSDK_EXPORT RetVal BVTHead_SetRange(BVTHead self, float start, float stop);

/** Retrieve the current starting range in meters
 * @param self Object pointer
 * @param start start range in meters
 * @returns start

 */
BVTSDK_EXPORT RetVal BVTHead_GetStartRange(BVTHead self, float* start);

/** Retrieve the current stopping range in meters.
 * @param self Object pointer
 * @param stop stop range in meters
 * @returns stop

 */
BVTSDK_EXPORT RetVal BVTHead_GetStopRange(BVTHead self, float* stop);

/** Return the minimum allowable range for this head.
 * @param self Object pointer
 * @param range minimum range in meters
 * @returns range

 */
BVTSDK_EXPORT RetVal BVTHead_GetMinimumRange(BVTHead self, float* range);

/** Return the maximum allowable range for this head.
 * @param self Object pointer
 * @param range maximum range in meters
 * @returns range

 */
BVTSDK_EXPORT RetVal BVTHead_GetMaximumRange(BVTHead self, float* range);

/** Set the start range of this head in meters.
 * @note The start range must be greater than or equal to @ref BVTHead_GetMinimumRange.
 * @param self Object pointer
 * @param start Start range in meters 
 */
BVTSDK_EXPORT RetVal BVTHead_SetStartRange(BVTHead self, float start);

/** Set the stop range of this head in meters.
 * @note The stop range must be less than or equal to @ref BVTHead_GetMaximumRange
 * @param self Object pointer
 * @param stop Stop range in meters 
 */
BVTSDK_EXPORT RetVal BVTHead_SetStopRange(BVTHead self, float stop);

/** BVTHead_SetClippingThreshold function will set the maximum (+-) raw data 
 * value from the ADC.  If this threshold is reached the entire signal 
 * is zeroed out so that clipping is not propagated through out the 
 * image.  The threshold is an integer ranging from 1 to 4096 (2^12).
 * @param self Object pointer
 * @param threshold The clipping threshold. Allowed values: 1 to 4096 (2^12) 
 * @deprecated This function will be removed in a future version of the SDK

 */
BVTSDK_EXPORT RetVal BVTHead_SetClippingThreshold(BVTHead self, int threshold);

/** [obsolete]
 * BVTHead_GetClippingThreshold returns the integer value of the clipping threshold 
 * @param self Object pointer
 * @param threshold the clipping threshold 
 * @returns threshold

 */
BVTSDK_EXPORT RetVal BVTHead_GetClippingThreshold(BVTHead self, int* threshold);

/** [obsolete]
 * The BVTHead_EnableClippingThreshold needs to be called	first before setting the 
 * clipping threshold.  A value of true  will enable the feature while a value
 * of false will disable it.
 * @param self Object pointer
 * @param enable True if the clipping threshold should be applied. 
 */
BVTSDK_EXPORT RetVal BVTHead_EnableClippingThreshold(BVTHead self, int enable);

/** Return the type of water the head is in.  The returned value will correspond to 
 * one of the FLUIDTYPE_* constants.
 * @param self Object pointer
 * @param fluidType fluid type
 * @returns fluidType

 */
BVTSDK_EXPORT RetVal BVTHead_GetFluidType(BVTHead self, int* fluidType);

/** Set the type of water the head is in
 * @param self Object pointer
 * @param fluid The fluid type (one of the FLUIDTYPE_* constants) 
 */
BVTSDK_EXPORT RetVal BVTHead_SetFluidType(BVTHead self, int fluid);

/** Return the current speed of sound in water for this head in meters per second.
 * Note that the returned sound speed is not measured by the sonar, but simply reflects the value currently set.
 * @param self Object pointer
 * @param speed speed of sound 
 * @returns speed

 */
BVTSDK_EXPORT RetVal BVTHead_GetSoundSpeed(BVTHead self, int* speed);

/** Set the current speed of sound in water for this head in meters per second.
 * @param self Object pointer
 * @param speed Sound speed in water, meters per second 
 */
BVTSDK_EXPORT RetVal BVTHead_SetSoundSpeed(BVTHead self, int speed);

/** Return the additional analog gain in dB
 * @param self Object pointer
 * @param gain analog gain
 * @returns gain

 */
BVTSDK_EXPORT RetVal BVTHead_GetGainAdjustment(BVTHead self, float* gain);

/** Set the additional analog gain. 
 * @param self Object pointer
 * @param gain Additional analog gain in dB 
 */
BVTSDK_EXPORT RetVal BVTHead_SetGainAdjustment(BVTHead self, float gain);

/** Return the time variable gain in dB/meter. Note that the parameter is per unit distance, not per unit time. This is a convenience to remove the dependence on the sound speed for clients.
 * @param self Object pointer
 * @param slope slope in dB/meter 
 * @returns slope

 */
BVTSDK_EXPORT RetVal BVTHead_GetTVGSlope(BVTHead self, float* slope);

/** Set the  time variable analog gain. Note that the parameter is per unit distance, not per unit time. This is a convenience to remove the dependence on the sound speed for clients.
 * @param self Object pointer
 * @param tvg Time variable gain in dB/meter 
 */
BVTSDK_EXPORT RetVal BVTHead_SetTVGSlope(BVTHead self, float tvg);

/** Return true if this Head has dynamic power management enabled.
 * @param self Object pointer
 * @param is_enabled True if this Head has dynamic power management enabled. 
 * @returns is_enabled

 */
BVTSDK_EXPORT RetVal BVTHead_GetDynamicPowerManagement(BVTHead self, int* is_enabled);

/** Note: Most BlueView sonars don't support dynamic power managment.
 * @param self Object pointer
 * @param enable If true, enable dynamic power managment. 
 */
BVTSDK_EXPORT RetVal BVTHead_SetDynamicPowerManagement(BVTHead self, int enable);

/** Latest-generation BlueView sonar support two modes of operation,
 * a standard and an alternate mode. The alternate mode provides improved imagery for
 * wide field-of-view sonar (greater than 45 degrees) at the cost of a slower max
 * ping rate, while dual mode maximizes ping rate but reduces image
 * quality. This call provides the user details about whether the alternate
 * ping mode is supported on the given sonar head.
 * @param self Object pointer
 * @param is_supported true (1) if supported, false (0) otherwise
 * @returns is_supported

 */
BVTSDK_EXPORT RetVal BVTHead_SupportsAlternatePingMode(BVTHead self, int* is_supported);

/** Sets the ping mode on sonar head. It is only
 * valid for sonar heads that support alternate ping mode.
 * (see BVTHead_SupportsAlternatePingMode()).
 * @param self Object pointer
 * @param enabled True or false. 
 */
BVTSDK_EXPORT RetVal BVTHead_SetAlternatePingModeEnabled(BVTHead self, int enabled);

/** Obtains the ping mode for the given sonar head.
 * It is only valid for sonar heads that support alternate ping mode
 * selection (see SupportsAlternatePingModemd()).
 * @param self Object pointer
 * @param enabled True or false. 
 * @returns enabled

 */
BVTSDK_EXPORT RetVal BVTHead_GetAlternatePingModeEnabled(BVTHead self, int* enabled);

/** Return the center frequency(in Hz) of this head.
 * @param self Object pointer
 * @param frequency center frequency 
 * @returns frequency

 */
BVTSDK_EXPORT RetVal BVTHead_GetCenterFreq(BVTHead self, int* frequency);

/** Return the number of pings 'in' this head
 * A head attached to a file might have more than one ping recorded.  However, a networked sonar will only have a single ping.
 * @param self Object pointer
 * @param count ping count 
 * @returns count

 */
BVTSDK_EXPORT RetVal BVTHead_GetPingCount(BVTHead self, int* count);

/** Retrieve a Ping from the Head
 * If ping_num is less than 0, return the next ping in the file. Otherwise, load the specified ping.  
 * If the Head is attached to a 'live' sonar (network), then BVTHead_GetPing always acquires a new ping.
 * @param self Object pointer
 * @param ping_num The ping number to return 
 * @param ping The returned Ping object
 * @returns ping

 */
BVTSDK_EXPORT RetVal BVTHead_GetPing(BVTHead self, int ping_num, BVTPing* ping);

/** \note This Head must be attached to a 'file' sonar.
 * Retrieve a Ping's metadata from the Head, skipping its signal data.
 * \warning You cannot create imagery from the ping returned by this function.
 * \warning Do not store the returned ping to another file unless you intend to never create imagery.
 * If ping_num is less than 0, return the next ping in the file. Otherwise, load the specified ping.
 * @param self Object pointer
 * @param ping_num The ping number to return 
 * @param ping The returned Ping object
 * @returns ping

 */
BVTSDK_EXPORT RetVal BVTHead_GetPingMetadataOnly(BVTHead self, int ping_num, BVTPing* ping);

/** Retrieve a Ping from a networked Head.
 * The Head must be attached to a 'live' sonar (network) which supports multicast pings.
 * @param self Object pointer
 * @param ping_num The ping number to return, currently unused 
 * @param ping The returned Ping object
 * @returns ping

 */
BVTSDK_EXPORT RetVal BVTHead_GetPingMulticast(BVTHead self, int ping_num, BVTPing* ping);

/** Retrieve a multicast Ping from a networked Head, but do not ask the Head to emit a ping.
 * The Head must be attached to a 'live' sonar (network) which supports multicast pings.
 * See also: Sonar_SupportsMulticast
 * @param self Object pointer
 * @param ping The returned Ping object 
 * @returns ping

 */
BVTSDK_EXPORT RetVal BVTHead_ListenForPingMulticast(BVTHead self, BVTPing* ping);

/** Write a ping to a file.
 * \warning The source_ping's Head must match this Head.
 * @param self Object pointer
 * @param source_ping The ping to write out 
 */
BVTSDK_EXPORT RetVal BVTHead_PutPing(BVTHead self, const BVTPing source_ping);

/** Setting this to a non-zero number will cause a multicast ping to be emitted every N milliseconds.
 * This is only supported on sonar with newer firmware, and support can be checked with @ref BVTSonar_SupportsMulticast.
 * @param self Object pointer
 * @param milliseconds The number of milliseconds between each ping acquisition on the remote Head. 
 */
BVTSDK_EXPORT RetVal BVTHead_SetPingInterval(BVTHead self, int milliseconds);

/** 
 * @param self Object pointer
 * @param milliseconds The number of milliseconds between each ping acquisition on the remote Head. 
 * @returns milliseconds

 */
BVTSDK_EXPORT RetVal BVTHead_GetPingInterval(BVTHead self, int* milliseconds);

/** Set the image processing resolution. The RES_AUTO setting is highly
 * recommended, as it adapts via a formula according to the stop range,
 * whereas the other ranges are fixed values, and should only be used
 * in specialized cases, such as requesting high resolution for longer
 * distances (which will increase the processing time required to 
 * create the image). R-Theta images may use either this function or
 * BVTHead_SetRangeResolution(), depending on the degree of control required.
 * @param self Object pointer
 * @param res Resolution constant (IMAGERES_*)
 * @deprecated This function will be removed in a future version of the SDK

 */
BVTSDK_EXPORT RetVal BVTHead_SetImageRes(BVTHead self, int res);

/** Requests a range resolution for R-Theta images. Also affects the
 * range resolution for RangeProfile. Note that the exact range resolution
 * may not be available, and the closest resolution will be set. The
 * actual resolution can be obtained by querying the returned image
 * or RangeProfile object.
 * @param self Object pointer
 * @param resolution_in_meters Range resolution, in meters 
 * @deprecated This function will be removed in a future version of the SDK

 */
BVTSDK_EXPORT RetVal BVTHead_SetRangeResolution(BVTHead self, float resolution_in_meters);

/** Set the requested out image size
 * The processing code will attempt to process images at the specified size.
 * However, it doesn't guarantee that the final output will match this size.
 * NOTE: For R-Theta images, only the width is used, and the image will
 * be created with that exact width. Height will depend on the range,
 * and the resolution set. (See BVTHead_SetImageRes() and BVTHead_SetRangeResolution())
 * @param self Object pointer
 * @param height The requested height 
 * @param width The requested width 
 * @deprecated This function will be removed in a future version of the SDK

 */
BVTSDK_EXPORT RetVal BVTHead_SetImageReqSize(BVTHead self, int height, int width);

/** Return the XY dimensions
 * @param self Object pointer
 * @param height height in pixels 
 * @returns height

 * @param width width in pixels 
 * @returns width

 * @deprecated This function will be removed in a future version of the SDK

 */
BVTSDK_EXPORT RetVal BVTHead_GetXYImageSizeRequested(BVTHead self, int* height, int* width);

/** Set the XY image size
 * This is a helper function to accompany the Ping's GetImageXY() function.
 * @param self Object pointer
 * @param width The requested width 
 * @param height The requested height 
 * @deprecated This function will be removed in a future version of the SDK

 */
BVTSDK_EXPORT RetVal BVTHead_SetXYImageSize(BVTHead self, int width, int height);

/** Set the RTheta image width
 * This is a helper function to accompany the Ping's GetImageRTheta() function.
 * @param self Object pointer
 * @param width The requested width 
 * @deprecated This function will be removed in a future version of the SDK

 */
BVTSDK_EXPORT RetVal BVTHead_SetRThetaImageWidth(BVTHead self, int width);

/** Set the type of image created by the BVTPing_GetImage() function.
 * NOTE: See BVTHead_SetImageReqSize() for important issues regarding image size.
 * If images are requested with the BVTPing_GetXYImage() or 
 * BVTPing_GetRThetaImage(), then this function is not needed.
 * @param self Object pointer
 * @param type Image type constant (IMAGETYPE_*) 
 * @deprecated This function will be removed in a future version of the SDK

 */
BVTSDK_EXPORT RetVal BVTHead_SetImageType(BVTHead self, int type);

/** Return the filter flags.  As of this version, if more than one flag is set, only the lowest-valued flag is used.
 * @param self Object pointer
 * @param flags The image filter flags in effect. 
 * @returns flags

 * @deprecated This function will be removed in a future version of the SDK

 */
BVTSDK_EXPORT RetVal BVTHead_GetImageFilterFlags(BVTHead self, int* flags);

/** Set the filter flags. As of this version, if more than one flag is set, only the lowest-valued flag is used.
 * @param self Object pointer
 * @param flags The image filter flags to set (bit field). 
 * @deprecated This function will be removed in a future version of the SDK

 */
BVTSDK_EXPORT RetVal BVTHead_SetImageFilterFlags(BVTHead self, int flags);

/** Inform the user about which type of image processing algorithm is being used.
 * The returned value will correspond to one of the IMAGE_PROCESSING_METHOD_* constants.
 * @param self Object pointer
 * @param method The image processing method used by this Head. 
 * @returns method

 * @deprecated This function will be removed in a future version of the SDK

 */
BVTSDK_EXPORT RetVal BVTHead_GetImageProcessingMethod(BVTHead self, int* method);

/** Return the current image calibration value A.
 * @param self Object pointer
 * @param cal_value_a Undocumented. 
 * @returns cal_value_a

 * @deprecated This function will be removed in a future version of the SDK

 */
BVTSDK_EXPORT RetVal BVTHead_GetImageCalibrationA(BVTHead self, int* cal_value_a);

/** Set the image calibration value for A.
 * This function should only be used for older sonars.  Before using this function,
 * call @ref BVTHead_GetImageProcessingMethod and test the return value.  If the return
 * value is IMAGE_PROCESSING_METHOD_A (0), then this function may be used, otherwise, do not
 * use this function.
 * NOTE: These values will be permanently saved on the sonar,
 * and the sonar's FLASH memory has limited write cycles available,
 * so this function should not be called often.
 * @param self Object pointer
 * @param cal_value_a Undocumented. 
 * @deprecated This function will be removed in a future version of the SDK

 */
BVTSDK_EXPORT RetVal BVTHead_SetImageCalibrationA(BVTHead self, int cal_value_a);

/** Return the current image calibration value B.
 * @param self Object pointer
 * @param cal_value_b Undocumented. 
 * @returns cal_value_b

 * @deprecated This function will be removed in a future version of the SDK

 */
BVTSDK_EXPORT RetVal BVTHead_GetImageCalibrationB(BVTHead self, int* cal_value_b);

/** Set the image calibration value for B.
 * This function should only be used for older sonars.  Before using this function,
 * call  @ref BVTHead_GetImageProcessingMethod() and test the return value.  If the return
 * value is IMAGE_PROCESSING_METHOD_A (0), then this function may be used, otherwise, do not
 * use this function.
 * NOTE: These values will be permanently saved on the sonar,
 * and the sonar's FLASH memory has limited write cycles available,
 * so this function should not be called often.
 * @param self Object pointer
 * @param cal_value_b Undocumented. 
 * @deprecated This function will be removed in a future version of the SDK

 */
BVTSDK_EXPORT RetVal BVTHead_SetImageCalibrationB(BVTHead self, int cal_value_b);

/** By default, the sonar transmits pings.  This function allows the user to 
 * disable transmit.  This can be useful to get background noise measurements.
 * Note that this is not implemented on all sonars.
 * @param self Object pointer
 * @param enableTx If 0, disable the sonar transmission of pings.
 */
BVTSDK_EXPORT RetVal BVTHead_SetTxEnable(BVTHead self, int enableTx);

/** Stores a copy of the Orientation data with the in the head's MountingOrientation object, so the data
 * will be saved if the head is saved to a file.
 * @param self Object pointer
 * @param orient Orientation data object to copy from 
 */
BVTSDK_EXPORT RetVal BVTHead_SetMountingOrientation(BVTHead self, const BVTOrientation orient);

/** Retrieves a copy of the MountingOrientation object stored with this head. Note
 * that the data is copied out of the head into the local Orientation object,
 * a pointer to internal data is not returned. Thus, the Orientation object
 * may be used after the head is destroyed.
 * @param self Object pointer
 * @param orient Orientation data object to copy the existing Orientation data to 
 * @returns orient

 */
BVTSDK_EXPORT RetVal BVTHead_GetMountingOrientationCopy(BVTHead self, BVTOrientation* orient);

/** Stores a copy of the Orientation data with the in the head's MountingOrientation object, so the data
 * will be saved if the head is saved to a file.
 * This second (auxillary) Orientation object is optional. 
 * @param self Object pointer
 * @param orient Orientation data object to copy from 
 */
BVTSDK_EXPORT RetVal BVTHead_SetAuxMountingOrientation(BVTHead self, const BVTOrientation orient);

/** Retrieves a copy of the MountingOrientation object stored with this head. Note
 * that the data is copied out of the head into the local Orientation object,
 * a pointer to internal data is not returned. Thus, the Orientation object
 * may be used after the head is destroyed.
 * This second (auxillary) Orientation object is optional.  Calling this function on an unused auxillary Orientation will return all zeros. 
 * @param self Object pointer
 * @param orient Orientation data object to copy the existing Orientation data to 
 * @returns orient

 */
BVTSDK_EXPORT RetVal BVTHead_GetAuxMountingOrientationCopy(BVTHead self, BVTOrientation* orient);

/** Return the number of transducers for this head
 * @param self Object pointer
 * @param count number of trandsucers
 * @returns count

 */
BVTSDK_EXPORT RetVal BVTHead_GetTransducerCount(BVTHead self, int* count);

/** Get the transducer orientation for the specified transducer index.
 * @param self Object pointer
 * @param transducer_index The zero-based index of the transducer
 * @param orient The orientation of the transducer. 
 * @returns orient

 */
BVTSDK_EXPORT RetVal BVTHead_GetTransducerOrientationCopy(BVTHead self, int transducer_index, BVTOrientation* orient);

/** Identifies the general configuration of how this data was collected.
 * @param self Object pointer
 * @param type One of the MOUNTTYPE_* constants 
 */
BVTSDK_EXPORT RetVal BVTHead_SetMountType(BVTHead self, int type);

/** Returns the mount type.  The returned value will correspond to
 * one of the MOUNTTYPE_* constants.
 * @param self Object pointer
 * @param type mount type
 * @returns type

 */
BVTSDK_EXPORT RetVal BVTHead_GetMountType(BVTHead self, int* type);

/** Specifiy where the sonar was mounted when this data was collected.
 * @param self Object pointer
 * @param side One of the MOUNTSIDE_* constants 
 */
BVTSDK_EXPORT RetVal BVTHead_SetMountSide(BVTHead self, int side);

/** Return where the sonar was mounted when this data was collected.
 * The returned value will correspond to one of the SIDE_* constants.
 * @param self Object pointer
 * @param side One of the MOUNTSIDE_* constants 
 * @returns side

 */
BVTSDK_EXPORT RetVal BVTHead_GetMountSide(BVTHead self, int* side);

/** This offset is calculated as MRU time - Sonar time;
 * @param self Object pointer
 * @param milliseconds Offset in milliseconds between the MRU's time reading and the Sonar's time reading. 
 */
BVTSDK_EXPORT RetVal BVTHead_SetMRUTimeOffset(BVTHead self, int milliseconds);

/** This offset is calculated as MRU time - Sonar time;
 * @param self Object pointer
 * @param milliseconds Offset in milliseconds between the MRU's time reading and the Sonar's time reading. 
 * @returns milliseconds

 */
BVTSDK_EXPORT RetVal BVTHead_GetMRUTimeOffset(BVTHead self, int* milliseconds);

/** 
 * @param self Object pointer
 * @param bearing Bearing in degrees from pole mount to GPS antenna. 
 * @param distance Distance in meters from pole mount to GPS antenna. 
 */
BVTSDK_EXPORT RetVal BVTHead_SetPoleGPSBearing(BVTHead self, float bearing, float distance);

/** 
 * @param self Object pointer
 * @param bearing Bearing in degrees from pole mount to GPS antenna. 
 * @returns bearing

 * @param distance Distance in meters from pole mount to GPS antenna. 
 * @returns distance

 */
BVTSDK_EXPORT RetVal BVTHead_GetPoleGPSBearing(BVTHead self, float* bearing, float* distance);

/** 
 * @param self Object pointer
 * @param bearing Bearing in degrees from pole mount to landmark. 
 */
BVTSDK_EXPORT RetVal BVTHead_SetPoleLandmarkBearing(BVTHead self, float bearing);

/** Returns bearing in degrees from pole mount to landmark. 
 * @param self Object pointer
 */
BVTSDK_EXPORT float BVTHead_GetPoleLandmarkBearing(BVTHead self);

/** This is used in tripod mount situations where the default/baseline/normal/center
 * position of the Head is not aligned with the tripod-mounted compass's
 * North direction.
 * This offset is calculated as MRU time - Sonar time;			
 * @param self Object pointer
 * @param offset Offset in degrees from compass North. 
 */
BVTSDK_EXPORT RetVal BVTHead_SetHeadingOffset(BVTHead self, float offset);

/** Returns offset in degrees from compass North. 
 * This is used in tripod mount situations where the default/baseline/normal/center
 * position of the Head is not aligned with the tripod-mounted compass's
 * North direction.
 * @param self Object pointer
 * @param offset heading offset
 * @returns offset

 */
BVTSDK_EXPORT RetVal BVTHead_GetHeadingOffset(BVTHead self, float* offset);

/** This is used to compute x,y,z offsets driven by the tilt position.
 * The manufacturer and model strings are limited to a maximum of 79 characters, not counting the terminating null characters.
 * @param self Object pointer
 * @param manufacturer Manufacturer of pan/tilt unit e.g. ROS 
 * @param model pan/tilt model  
 * @param elbowOffset offset from tilt motor axis to center of sonar 
 */
BVTSDK_EXPORT RetVal BVTHead_SetPanTiltAttributes(BVTHead self, const char* manufacturer, const char* model, float elbowOffset);

/** Returns the name of the Pan-Tilt manufacturer as a string.
 * @param self Object pointer
 * @param manufacturer The buffer to hold the returned manufacturer name string. 
 * @returns manufacturer

 * @param buffer_length The size in chararacters of the buffer to hold the returned manufacturer string. 
 */
BVTSDK_EXPORT RetVal BVTHead_GetPanTiltManufacturer(BVTHead self, char* manufacturer, int buffer_length);

/** Returns the length of the name of the Pan-Tilt manufacturer as a string.
 * @param self Object pointer
 * @param buffer_length The size in characters of the manufacturer name string. 
 * @returns buffer_length

 */
BVTSDK_EXPORT RetVal BVTHead_GetPanTiltManufacturerLength(BVTHead self, int* buffer_length);

/** Returns the model name.
 * @param self Object pointer
 * @param model The string to hold the returned model name. 
 * @returns model

 * @param buffer_length The size in bytes of the buffer 'model' 
 */
BVTSDK_EXPORT RetVal BVTHead_GetPanTiltModel(BVTHead self, char* model, int buffer_length);

/** Returns the length of the model name.
 * @param self Object pointer
 * @param buffer_length The string length of the model name. 
 * @returns buffer_length

 */
BVTSDK_EXPORT RetVal BVTHead_GetPanTiltModelLength(BVTHead self, int* buffer_length);

/** This is used to compute x,y,z offsets driven by the tilt position. Elbow offset specified in meters
 * @param self Object pointer
 * @param offset offset to P/T elbow 
 * @returns offset

 */
BVTSDK_EXPORT RetVal BVTHead_GetPanTiltElbowOffset(BVTHead self, float* offset);

/** Helper function to retrieve the pan/tilt mount offsets.  
 * The panRotationOffset and tiltRotationOffset values should be subtracted 
 * from the X_axis_degrees (pan) and Y_axis_degrees (tilt) parameters 
 * of the BVTPing_GetPositionerRotations() function to obtain 
 * the same pan & tilt values displayed during data collection.
 * If verticalInverted is false(0), then the tilt value obtained in the 
 * step above must be multiplied by -1.0 to represent real-world tilt values.
 * @param self Object pointer
 * @param tiltElbowVerticalOffset in meters 
 * @returns tiltElbowVerticalOffset

 * @param tiltElbowHorizontalOffset in meters 
 * @returns tiltElbowHorizontalOffset

 * @param panRotationOffset offset to "home" position 
 * @returns panRotationOffset

 * @param tiltRotationOffset offset to "home" position 
 * @returns tiltRotationOffset

 * @param verticalInverted either 1 or 0, to indicate true or false, respectively 
 * @returns verticalInverted

 */
BVTSDK_EXPORT RetVal BVTHead_GetPanTiltMountOffsets(BVTHead self, float* tiltElbowVerticalOffset, float* tiltElbowHorizontalOffset, float* panRotationOffset, float* tiltRotationOffset, int* verticalInverted);

/** Helper function to set the pan/tilt mount offsets.  
 * The panRotationOffset and tiltRotationOffset values should be subtracted 
 * from the X_axis_degrees (pan) and Y_axis_degrees (tilt) parameters 
 * of the BVTPing_GetPositionerRotations() function to obtain 
 * the same pan & tilt values displayed during data collection.
 * verticalInverted is set to false(0) if the pan/tilt device has been mounted in an inverted fashion.
 * @param self Object pointer
 * @param tiltElbowVerticalOffset in meters 
 * @param tiltElbowHorizontalOffset in meters 
 * @param panRotationOffset offset to "home" position 
 * @param tiltRotationOffset offset to "home" position 
 * @param verticalInverted either 1 or 0, to indicate true or false, respectively 
 */
BVTSDK_EXPORT RetVal BVTHead_SetPanTiltMountOffsets(BVTHead self, float tiltElbowVerticalOffset, float tiltElbowHorizontalOffset, float panRotationOffset, float tiltRotationOffset, int verticalInverted);

/** @}*/

#ifdef __cplusplus
}
#endif

#endif
