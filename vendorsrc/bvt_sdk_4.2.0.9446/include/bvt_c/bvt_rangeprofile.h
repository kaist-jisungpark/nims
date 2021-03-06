/*
    This file has been generated by bvtidl.pl. DO NOT MODIFY!
*/
#ifndef __BVTRANGEPROFILE_H__
#define __BVTRANGEPROFILE_H__

#include <bvt_c/bvt_retval.h>
#include <bvt_c/bvt_colorimage.h>

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
 * @defgroup BVTRangeProfile BVTRangeProfile
 * @brief
 * @warning RangeProfile functions will fail on a sonar with old firmware, or a file recorded from a sonar with old firmware.
 * The RangeProfile interface provides a 1-D view of a single ping data. It consists of a vector of ranges from the sonar head to the sonic reflection point, indexed along the the bearing (theta) dimension.
 * For each angle, the range and raw intensity of the return beam at that range is stored. There are a number of approaches to choosing the reflection point. This interface provides a settable minimum intensity threshold that must be crossed and a choosable algorithm, returning either the first (nearest) point that exceeds the threshold (THRESHOLD_POLICY_NEAREST) or the distance to sample of greatest intensity (THRESHOLD_POLICY_LARGEST).
 * @{
*/

/** Opaque type for BVTRangeProfile object instances */
typedef struct BVTOpaqueRangeProfile* BVTRangeProfile;

/** Destroy a BVTRangeProfile object
 *  @param obj Object pointer
*/
BVTSDK_EXPORT void BVTRangeProfile_Destroy(BVTRangeProfile obj);

/** Values greater than this indicate no range could be measured. 
 */
#define BVTRANGEPROFILE_MAX_RANGE	(int)(999)

/** Return the largest intensity greater than the threshold found along a beam. 
 */
#define BVTRANGEPROFILE_THRESHOLD_POLICY_LARGEST	(int)(1)

/** Return the nearest intensity greater than the threshold along a beam. 
 */
#define BVTRANGEPROFILE_THRESHOLD_POLICY_NEAREST	(int)(2)

/** Returns the number of range values stored for this ping.
 * @param self Object pointer
 * @param count range data entry count
 * @returns count

 */
BVTSDK_EXPORT RetVal BVTRangeProfile_GetCount(BVTRangeProfile self, int* count);

/** Returns the intensity threshold used to populate this RangeProfile structure. The intensity threshold serves as a noise floor, below which no sample will be considered a candidate for the beam's RangeProfile point. 
 * @param self Object pointer
 * @param threshold raw intensity threshold
 * @returns threshold

 */
BVTSDK_EXPORT RetVal BVTRangeProfile_GetIntensityThreshold(BVTRangeProfile self, unsigned short* threshold);

/** Returns the resolution of the range values, in meters. The RangeProfile range value at a given bearing should be considered approximate to within +- resolution.
 * @param self Object pointer
 * @param resolution range resolution
 * @returns resolution

 */
BVTSDK_EXPORT RetVal BVTRangeProfile_GetRangeResolution(BVTRangeProfile self, double* resolution);

/** Returns the resolution of the bearing (in degrees) of each RangeProfile range value. This is the difference in bearing between adjacent range values in the array.
 * <br>
 * @param self Object pointer
 * @param resolution bearing (angular) resolution
 * @returns resolution

 */
BVTSDK_EXPORT RetVal BVTRangeProfile_GetBearingResolution(BVTRangeProfile self, double* resolution);

/** Return the minimum angle for the sonar's imaging field of view.
 * This is the angle of the first range value, as all
 * angles are "left referenced." The angle is returned in degrees.
 * Note that this may not represent the actual physical field of view
 * of a particular sonar, but does represent the field of view of the
 * data being returned. Some outer angles may have range values
 * indicating they are out of range.
 * @param self Object pointer
 * @param minAngle minimum angle in field-of-view
 * @returns minAngle

 */
BVTSDK_EXPORT RetVal BVTRangeProfile_GetFOVMinAngle(BVTRangeProfile self, float* minAngle);

/** Return the maximum angle for the sonar's imaging field of view.
 * This is the angle of the last range value, as all
 * angles are "left referenced." The angle is returned in degrees.
 * Note that this may not represent the actual physical field of view
 * of a particular sonar, but does represent the field of view of the
 * data being returned. Some outer angles may have range values
 * indicating they are out of range.
 * @param self Object pointer
 * @param maxAngle maximum angle in field-of-view
 * @returns maxAngle

 */
BVTSDK_EXPORT RetVal BVTRangeProfile_GetFOVMaxAngle(BVTRangeProfile self, float* maxAngle);

/** Copies the range values into the user specified buffer. The
 * buffer must hold the entire number of ranges (See BVTRangeProfile_GetCount() above),
 * or an error is returned.
 * @param self Object pointer
 * @param ranges Pointer to a valid buffer of type float.
 * @returns ranges

 * @param number_of_ranges Number of values the buffer can hold.
 */
BVTSDK_EXPORT RetVal BVTRangeProfile_CopyRangeValues(BVTRangeProfile self, float ranges[], int number_of_ranges);

/** Copies the bearing values into the user specified buffer. The
 * buffer must hold the entire number of bearings (See BVTRangeProfile_GetCount() above),
 * or an error is returned.
 * @param self Object pointer
 * @param bearings Pointer to a valid buffer of type float.
 * @returns bearings

 * @param number_of_bearings Number of values the buffer can hold.
 */
BVTSDK_EXPORT RetVal BVTRangeProfile_CopyBearingValues(BVTRangeProfile self, float bearings[], int number_of_bearings);

/** Copies the intensity values into the user specified buffer. The
 * buffer must hold the entire number of intensities (See BVTRangeProfile_GetCount() above),
 * or an error is returned.
 * @param self Object pointer
 * @param intensities Pointer to a valid buffer of type float.
 * @returns intensities

 * @param number_of_intensities Number of values the buffer can hold.
 */
BVTSDK_EXPORT RetVal BVTRangeProfile_CopyIntensityValues(BVTRangeProfile self, unsigned short intensities[], int number_of_intensities);

/** Returns the range from the sonar head, in meters, at a particular
 * index into the array. <br>
 * NOTE: Check all returned values for validity. If range > BVTRANGEPROFILE_MAX_RANGE
 * then the range at the given bearing (index) is not valid.
 * This is the result of either the nearest object at the given bearing was out of view of the sonar, or no return along that beam crossed the specified threshold.
 * @param self Object pointer
 * @param index index into the array of RangeProfile values  
 * @param range range at given index 
 * @returns range

 */
BVTSDK_EXPORT RetVal BVTRangeProfile_GetRangeValue(BVTRangeProfile self, int index, float* range);

/** Returns the intensity value at the specified index into the RangeProfile array. <br>
 * @param self Object pointer
 * @param index index into the array of RangeProfile values  
 * @param intensity raw intensity value 
 * @returns intensity

 */
BVTSDK_EXPORT RetVal BVTRangeProfile_GetIntensityValue(BVTRangeProfile self, int index, unsigned short* intensity);

/** Returns the bearing from the center of the sonar head, in degrees (positive is clockwise as viewed from above) at the given index into the RangeProfile array.
 * @param self Object pointer
 * @param index index into the array of RangeProfile values  
 * @param bearing bearing (angle) at given index 
 * @returns bearing

 */
BVTSDK_EXPORT RetVal BVTRangeProfile_GetBearingValue(BVTRangeProfile self, int index, float* bearing);

/** Returns the X coordinate for the pixel in the passed ColorImage, which
 * maps to the range and bearing at the index passed. This allows placing
 * of the range data on a colorimage, easing analysis of the algorithm
 * used for thresholding.
 * @param self Object pointer
 * @param index index into the array of RangeProfile values  
 * @param image ColorImage object where the pixel coordinate is needed 
 * @param x pixel index in the X axis 
 * @returns x

 */
BVTSDK_EXPORT RetVal BVTRangeProfile_GetColorImagePixelX(BVTRangeProfile self, int index, const BVTColorImage image, int* x);

/** Returns the Y coordinate for the pixel in the passed ColorImage which
 * maps to the range and bearing at the index passed. (see similar function,
 * above, for more details)
 * @param self Object pointer
 * @param index index into the array of RangeProfile values  
 * @param image ColorImage object where the pixel coordinate is needed 
 * @param y pixel index in the Y axis
 * @returns y

 */
BVTSDK_EXPORT RetVal BVTRangeProfile_GetColorImagePixelY(BVTRangeProfile self, int index, const BVTColorImage image, int* y);

/** @}*/

#ifdef __cplusplus
}
#endif

#endif
