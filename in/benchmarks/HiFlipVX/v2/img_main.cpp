#define _USE_MATH_DEFINES
#define HALF_ENABLE_CPP11_CMATH 0

#ifdef __clang__
class type_info;
#endif

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include <cmath>
#include <limits>
#include <iostream>
#ifndef __XILINX__
#include <algorithm>
#endif

using namespace std;

/*!
 * \file vx_types.h
 * \brief The type definitions required by OpenVX Library.
 */

/*********************************************************************************************************************/
/* OpenVX Macros */
/*********************************************************************************************************************/

/*! \def VX_DF_IMAGE
 * \brief Converts a set of four chars into a \c uint32_t container of a VX_DF_IMAGE code.
 * \note Use a <tt>\ref vx_df_image</tt> variable to hold the value.
 * \ingroup group_basic_features
 */
#define VX_DF_IMAGE(a, b, c, d) ((a) | (b << 8) | (c << 16) | (d << 24))

/*! \def VX_ATTRIBUTE_BASE
 * \brief Defines the manner in which to combine the Vendor and Object IDs to get
 * the base value of the enumeration.
 * \ingroup group_basic_features
 */
#define VX_ATTRIBUTE_BASE(vendor, object) (((vendor) << 20) | (object << 8))

/*! \def VX_ENUM_BASE
 * \brief Defines the manner in which to combine the Vendor and Object IDs to get
 * the base value of the enumeration.
 * \details From any enumerated value (with exceptions), the vendor, and enumeration
 * type should be extractable. Those types that are exceptions are
 * <tt>\ref vx_vendor_id_e</tt>, <tt>\ref vx_type_e</tt>, <tt>\ref vx_enum_e</tt>, <tt>\ref vx_df_image_e</tt>, and \c vx_bool.
 * \ingroup group_basic_features
 */
#define VX_ENUM_BASE(vendor, id) (((vendor) << 20) | (id << 12))

/*********************************************************************************************************************/
/* OpenVX typedefs */
/*********************************************************************************************************************/

/*! \brief An 8 bit ASCII character.
 * \ingroup group_basic_features
 */
typedef char vx_char;

/*! \brief An 8-bit unsigned value.
 * \ingroup group_basic_features
 */
typedef uint8_t vx_uint8;

/*! \brief A 16-bit unsigned value.
 * \ingroup group_basic_features
 */
typedef uint16_t vx_uint16;

/*! \brief A 32-bit unsigned value.
 * \ingroup group_basic_features
 */
typedef uint32_t vx_uint32;

/*! \brief A 64-bit unsigned value.
 * \ingroup group_basic_features
 */
typedef uint64_t vx_uint64;

/*! \brief An 8-bit signed value.
 * \ingroup group_basic_features
 */
typedef int8_t vx_int8;

/*! \brief A 16-bit signed value.
 * \ingroup group_basic_features
 */
typedef int16_t vx_int16;

/*! \brief A 32-bit signed value.
 * \ingroup group_basic_features
 */
typedef int32_t vx_int32;

/*! \brief A 64-bit signed value.
 * \ingroup group_basic_features
 */
typedef int64_t vx_int64;

/*! \brief A 32-bit float value.
 * \ingroup group_basic_features
 */
typedef float vx_float32;

/*! \brief A 64-bit float value (aka double).
 * \ingroup group_basic_features
 */
typedef double vx_float64;

/*! \brief Sets the standard enumeration type size to be a fixed quantity.
 * \details All enumerable fields must use this type as the container to
 * enforce enumeration ranges and sizeof() operations.
 * \ingroup group_basic_features
 */
typedef int32_t vx_enum;

/*! \brief A wrapper of <tt>size_t</tt> to keep the naming convention uniform.
 * \ingroup group_basic_features
 */
typedef size_t vx_size;

/*! \brief Used to hold a VX_DF_IMAGE code to describe the pixel format and color space.
 * \ingroup group_basic_features
 */
typedef uint32_t vx_df_image;

/*! \brief A Boolean value.
 * This allows 0 to be FALSE, as it is in C, and any non-zero to be TRUE.
 * \code
 * vx_bool ret = vx_true_e;
 * if (ret) printf("true!\n");
 * ret = vx_false_e;
 * if (!ret) printf("false!\n");
 * \endcode
 * This would print both strings.
 * \ingroup group_basic_features
 */
typedef enum _vx_bool_e
{
	/*! \brief The "false" value. */
	vx_false_e = 0,
	/*! \brief The "true" value. */
	vx_true_e,
} vx_bool;

/*! \brief The type enumeration lists all the known types in OpenVX.
 * \ingroup group_basic_features
 */
enum vx_type_e
{
	VX_TYPE_INVALID = 0x000,  /*!< \brief An invalid type value. When passed an error must be returned. */
	VX_TYPE_CHAR = 0x001,	  /*!< \brief A <tt>\ref vx_char</tt>. */
	VX_TYPE_INT8 = 0x002,	  /*!< \brief A <tt>\ref vx_int8</tt>. */
	VX_TYPE_UINT8 = 0x003,	  /*!< \brief A <tt>\ref vx_uint8</tt>. */
	VX_TYPE_INT16 = 0x004,	  /*!< \brief A <tt>\ref vx_int16</tt>. */
	VX_TYPE_UINT16 = 0x005,	  /*!< \brief A <tt>\ref vx_uint16</tt>. */
	VX_TYPE_INT32 = 0x006,	  /*!< \brief A <tt>\ref vx_int32</tt>. */
	VX_TYPE_UINT32 = 0x007,	  /*!< \brief A <tt>\ref vx_uint32</tt>. */
	VX_TYPE_INT64 = 0x008,	  /*!< \brief A <tt>\ref vx_int64</tt>. */
	VX_TYPE_UINT64 = 0x009,	  /*!< \brief A <tt>\ref vx_uint64</tt>. */
	VX_TYPE_FLOAT32 = 0x00A,  /*!< \brief A <tt>\ref vx_float32</tt>. */
	VX_TYPE_FLOAT64 = 0x00B,  /*!< \brief A <tt>\ref vx_float64</tt>. */
	VX_TYPE_ENUM = 0x00C,	  /*!< \brief A <tt>\ref vx_enum</tt>. Equivalent in size to a <tt>\ref vx_int32</tt>. */
	VX_TYPE_SIZE = 0x00D,	  /*!< \brief A <tt>\ref vx_size</tt>. */
	VX_TYPE_DF_IMAGE = 0x00E, /*!< \brief A <tt>\ref vx_df_image</tt>. */
	VX_TYPE_BOOL = 0x010,	  /*!< \brief A <tt>\ref vx_bool</tt>. */
};

/*********************************************************************************************************************/
/* OpenVX enums (TODO: Change Vendor ID) */
/*********************************************************************************************************************/

/*! \brief The Vendor ID of the Implementation. As new vendors submit their
 * implementations, this enumeration will grow.
 * \ingroup group_basic_features
 */
enum vx_vendor_id_e
{
	VX_ID_KHRONOS = 0x000, /*!< \brief The Khronos Group */
};

/*! \brief The set of supported enumerations in OpenVX.
 * \details These can be extracted from enumerated values using <tt>\ref VX_ENUM_TYPE</tt>.
 * \ingroup group_basic_features
 */
enum vx_enum_e
{
	VX_ENUM_INTERPOLATION = 0x04,  /*!< \brief Interpolation Types. */
	VX_ENUM_CONVERT_POLICY = 0x0A, /*!< \brief Convert Policy. */
	VX_ENUM_THRESHOLD_TYPE = 0x0B, /*!< \brief Threshold Type List. */
	VX_ENUM_BORDER = 0x0C,		   /*!< \brief Border Mode List. */
	VX_ENUM_ROUND_POLICY = 0x12,   /*!< \brief Rounding Policy. */
	VX_ENUM_SCALAR_OPERATION = 0x20,
};

/*! \brief The Conversion Policy Enumeration.
 * \ingroup group_basic_features
 */
enum vx_convert_policy_e
{
	/*! \brief Results are the least significant bits of the output operand, as if
	 * stored in two's complement binary format in the size of its bit-depth.
	 */
	VX_CONVERT_POLICY_WRAP = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_CONVERT_POLICY) + 0x0,
	/*! \brief Results are saturated to the bit depth of the output operand. */
	VX_CONVERT_POLICY_SATURATE = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_CONVERT_POLICY) + 0x1,
};

/*! \brief Based on the VX_DF_IMAGE definition.
 * \note Use <tt>\ref vx_df_image</tt> to contain these values.
 * \ingroup group_basic_features
 */
enum vx_df_image_e
{
	/*! \brief A single plane of 24-bit pixel as 3 interleaved 8-bit units of
	 * R then G then B data. This uses the BT709 full range by default.
	 */
	VX_DF_IMAGE_RGB = VX_DF_IMAGE('R', 'G', 'B', '2'),
	/*! \brief A single plane of 32-bit pixel as 4 interleaved 8-bit units of
	 * R then G then B data, then a <i>don't care</i> byte.
	 * This uses the BT709 full range by default.
	 */
	VX_DF_IMAGE_RGBX = VX_DF_IMAGE('R', 'G', 'B', 'A'),
	/*! \brief A single plane of unsigned 8-bit data.
	 * The range of data is not specified, as it may be extracted from a YUV or
	 * generated.
	 */
	VX_DF_IMAGE_U8 = VX_DF_IMAGE('U', '0', '0', '8'),
	/*! \brief A single plane of unsigned 8-bit data.
	 * The range of data is not specified, as it may be extracted from a YUV or
	 * generated.
	 */
	VX_DF_IMAGE_S8 = VX_DF_IMAGE('S', '0', '0', '8'),
	/*! \brief A single plane of signed 16-bit data.
	 * The range of data is not specified, as it may be extracted from a YUV or
	 * generated.
	 */
	VX_DF_IMAGE_U16 = VX_DF_IMAGE('U', '0', '1', '6'),
	/*! \brief A single plane of signed 16-bit data.
	 * The range of data is not specified, as it may be extracted from a YUV or
	 * generated.
	 */
	VX_DF_IMAGE_S16 = VX_DF_IMAGE('S', '0', '1', '6'),
	/*! \brief A single plane of unsigned 32-bit data.
	 * The range of data is not specified, as it may be extracted from a YUV or
	 * generated.
	 */
	VX_DF_IMAGE_U32 = VX_DF_IMAGE('U', '0', '3', '2'),
	/*! \brief A single plane of unsigned 32-bit data.
	 * The range of data is not specified, as it may be extracted from a YUV or
	 * generated.
	 */
	VX_DF_IMAGE_S32 = VX_DF_IMAGE('S', '0', '3', '2'),
};

/*! \brief The Threshold types.
 * \ingroup group_threshold
 */
enum vx_threshold_type_e
{
	/*! \brief A threshold with only 1 value. */
	VX_THRESHOLD_TYPE_BINARY = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_THRESHOLD_TYPE) + 0x0,
	/*! \brief A threshold with 2 values (upper/lower). Use with Canny Edge Detection. */
	VX_THRESHOLD_TYPE_RANGE = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_THRESHOLD_TYPE) + 0x1,
};

/*! \brief The image reconstruction filters supported by image resampling operations.
 *
 * The edge of a pixel is interpreted as being aligned to the edge of the image.
 * The value for an output pixel is evaluated at the center of that pixel.
 *
 * This means, for example, that an even enlargement of a factor of two in nearest-neighbor
 * interpolation will replicate every source pixel into a 2x2 quad in the destination, and that
 * an even shrink by a factor of two in bilinear interpolation will create each destination pixel
 * by average a 2x2 quad of source pixels.
 *
 * Samples that cross the boundary of the source image have values determined by the border
 * mode - see <tt>\ref vx_border_e</tt> and <tt>\ref VX_NODE_BORDER</tt>.
 * \see vxuScaleImage
 * \see vxScaleImageNode
 * \see VX_KERNEL_SCALE_IMAGE
 * \see vxuWarpAffine
 * \see vxWarpAffineNode
 * \see VX_KERNEL_WARP_AFFINE
 * \see vxuWarpPerspective
 * \see vxWarpPerspectiveNode
 * \see VX_KERNEL_WARP_PERSPECTIVE
 * \ingroup group_basic_features
 */
enum vx_interpolation_type_e
{
	/*! \brief Output values are defined to match the source pixel whose center is nearest to the sample position. */
	VX_INTERPOLATION_NEAREST_NEIGHBOR = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_INTERPOLATION) + 0x0,
	/*! \brief Output values are defined by bilinear interpolation between the pixels whose centers are closest
	 * to the sample position, weighted linearly by the distance of the sample from the pixel centers. */
	VX_INTERPOLATION_BILINEAR = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_INTERPOLATION) + 0x1,
	/*! \brief Output values are determined by averaging the source pixels whose areas fall under the
	 * area of the destination pixel, projected onto the source image. */
	VX_INTERPOLATION_AREA = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_INTERPOLATION) + 0x2,
};

/*! \brief The border mode list.
 * \ingroup group_borders
 */
enum vx_border_e
{
	/*! \brief No defined border mode behavior is given. */
	VX_BORDER_UNDEFINED = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_BORDER) + 0x0,
	/*! \brief For nodes that support this behavior, a constant value is
	 * \e filled-in when accessing out-of-bounds pixels.
	 */
	VX_BORDER_CONSTANT = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_BORDER) + 0x1,
	/*! \brief For nodes that support this behavior, a replication of the nearest
	 * edge pixels value is given for out-of-bounds pixels.
	 */
	VX_BORDER_REPLICATE = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_BORDER) + 0x2,
};

/*! \brief The Round Policy Enumeration.
 * \ingroup group_context
 */
enum vx_round_policy_e
{
	/*! \brief When scaling, this truncates the least significant values that are lost in operations. */
	VX_ROUND_POLICY_TO_ZERO = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_ROUND_POLICY) + 0x1,
	/*! \brief When scaling, this rounds to nearest even output value. */
	VX_ROUND_POLICY_TO_NEAREST_EVEN = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_ROUND_POLICY) + 0x2,
};

/*! \brief The 2D Coordinates structure. HINT: Updated by template parameter
 * \ingroup group_basic_features
 */
template <typename T>
struct vx_coordinates2d_t
{
	T x; /*!< \brief The X coordinate. */
	T y; /*!< \brief The Y coordinate. */
};

enum vx_scalar_operation_e
{
	VX_SCALAR_OP_AND = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_SCALAR_OPERATION) + 0x0,
	VX_SCALAR_OP_OR = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_SCALAR_OPERATION) + 0x1,
	VX_SCALAR_OP_XOR = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_SCALAR_OPERATION) + 0x2,
	VX_SCALAR_OP_NAND = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_SCALAR_OPERATION) + 0x3,
	VX_SCALAR_OP_EQUAL = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_SCALAR_OPERATION) + 0x4,
	VX_SCALAR_OP_NOTEQUAL = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_SCALAR_OPERATION) + 0x5,
	VX_SCALAR_OP_LESS = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_SCALAR_OPERATION) + 0x6,
	VX_SCALAR_OP_LESSEQ = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_SCALAR_OPERATION) + 0x7,
	VX_SCALAR_OP_GREATER = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_SCALAR_OPERATION) + 0x8,
	VX_SCALAR_OP_GREATEREQ = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_SCALAR_OPERATION) + 0x9,
	VX_SCALAR_OP_ADD = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_SCALAR_OPERATION) + 0xA,
	VX_SCALAR_OP_SUBTRACT = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_SCALAR_OPERATION) + 0xB,
	VX_SCALAR_OP_MULTIPLY = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_SCALAR_OPERATION) + 0xC,
	VX_SCALAR_OP_DIVIDE = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_SCALAR_OPERATION) + 0xD,
	VX_SCALAR_OP_MODULUS = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_SCALAR_OPERATION) + 0xE,
	VX_SCALAR_OP_MIN = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_SCALAR_OPERATION) + 0xF,
	VX_SCALAR_OP_MAX = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_SCALAR_OPERATION) + 0x10,
};

/*********************************************************************************************************************/
/* OpenVX NN enums  */
/*********************************************************************************************************************/

/*! \brief NN extension type enums.
 * \ingroup group_cnn
 */
enum vx_nn_enum_e
{
	VX_ENUM_NN_ROUNDING_TYPE = 0x1A,
	VX_ENUM_NN_POOLING_TYPE = 0x1B,
	VX_ENUM_NN_NORMALIZATION_TYPE = 0x1C,
	VX_ENUM_NN_ACTIVATION_FUNCTION_TYPE = 0x1D,
};

/*! \brief down scale rounding.
 * \details Due to different scheme of downscale size calculation in the various training frameworks. Implementation must support 2 rounding methods for down scale calculation.
 * The floor and the ceiling. In convolution and pooling functions.
 * Relevant when input size is even.
 * \ingroup group_cnn
 */
enum vx_nn_rounding_type_e
{
	/*! \brief floor rounding  */
	VX_NN_DS_SIZE_ROUNDING_FLOOR = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_NN_ROUNDING_TYPE) + 0x0,
	/*! \brief ceil rounding */
	VX_NN_DS_SIZE_ROUNDING_CEILING = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_NN_ROUNDING_TYPE) + 0x1
};

/*! \brief The Neural Network pooling type list.
 * \details kind of pooling done in pooling function
 * \ingroup group_cnn
 */
enum vx_nn_pooling_type_e
{
	/*! \brief max pooling*/
	VX_NN_POOLING_MAX = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_NN_POOLING_TYPE) + 0x0,
	/*! \brief average pooling*/
	VX_NN_POOLING_AVG = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_NN_POOLING_TYPE) + 0x1
};

/*! \brief The Neural Network activation functions list.
 * \details
 * <table>
 * <tr><td> <B>Function name </B> <td> <B>Mathematical definition</B> <td> <B>Parameters</B> <td> <B>Parameters type</B>
 * <tr><td>logistic <td> \f$f(x)=1/(1+e^{-x}) \f$  <td>  <td>
 * <tr><td>hyperbolic tangent <td> \f$f(x)=a\cdot tanh(b\cdot x) \f$  <td> a,b  <td> VX_FLOAT32
 * <tr><td>relu <td> \f$f(x)=max(0,x)\f$  <td>  <td>
 * <tr><td>bounded relu <td> \f$f(x)=min(a,max(0,x)) \f$  <td> a  <td> VX_FLOAT32
 * <tr><td>soft relu <td> \f$f(x)=log(1+e^{x}) \f$  <td>  <td>
 * <tr><td>abs <td> \f$f(x)=\mid x\mid \f$  <td>  <td>
 * <tr><td>square <td> \f$f(x)= x^2 \f$  <td>  <td>
 * <tr><td>square root <td> \f$f(x)=\sqrt{x} \f$  <td>  <td>
 * <tr><td>linear <td> \f$f(x)=ax+b \f$  <td>  a,b  <td> VX_FLOAT32
 * </table>
 * \ingroup group_cnn
 */
enum vx_nn_activation_function_e
{
	VX_NN_ACTIVATION_LOGISTIC = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_NN_ACTIVATION_FUNCTION_TYPE) + 0x0,
	VX_NN_ACTIVATION_HYPERBOLIC_TAN = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_NN_ACTIVATION_FUNCTION_TYPE) + 0x1,
	VX_NN_ACTIVATION_RELU = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_NN_ACTIVATION_FUNCTION_TYPE) + 0x2,
	VX_NN_ACTIVATION_BRELU = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_NN_ACTIVATION_FUNCTION_TYPE) + 0x3,
	VX_NN_ACTIVATION_SOFTRELU = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_NN_ACTIVATION_FUNCTION_TYPE) + 0x4,
	VX_NN_ACTIVATION_ABS = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_NN_ACTIVATION_FUNCTION_TYPE) + 0x5,
	VX_NN_ACTIVATION_SQUARE = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_NN_ACTIVATION_FUNCTION_TYPE) + 0x6,
	VX_NN_ACTIVATION_SQRT = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_NN_ACTIVATION_FUNCTION_TYPE) + 0x7,
	VX_NN_ACTIVATION_LINEAR = VX_ENUM_BASE(VX_ID_KHRONOS, VX_ENUM_NN_ACTIVATION_FUNCTION_TYPE) + 0x8,
};
#ifdef __SDSCC__
#include "sds_lib.h"
#endif

#ifdef __EVAL_TIME__
#ifdef __XILINX__
#include "xtime_l.h"
#else
#include <chrono>
#endif
#endif

#if defined(__SYNTHESIS__) || defined(__RTL_SIMULATION__) || defined(__XILINX__)
#include <ap_int.h>
#include <hls_math.h>
#include <hls_stream.h>
#endif

/*********************************************************************************************************************/
/* Own Macros */
/*********************************************************************************************************************/

// Maximum and Minumum values of datatypes
#define VX_INT8_MIN static_cast<int8_t>(0 - 128)		  /*!< \brief Minimum of signed 8 bit type */
#define VX_INT16_MIN static_cast<int16_t>(0 - 32768)	  /*!< \brief Minimum of signed 16 bit type */
#define VX_INT32_MIN static_cast<int32_t>(0 - 2147483648) /*!< \brief Minimum of signed 32 bit type */
#define VX_INT8_MAX static_cast<int8_t>(127)			  /*!< \brief Maximum of signed 8 bit type */
#define VX_INT16_MAX static_cast<int16_t>(32767)		  /*!< \brief Maximum of signed 16 bit type */
#define VX_INT32_MAX static_cast<int32_t>(2147483647)	  /*!< \brief Maximum of signed 32 bit type */
#define VX_UINT8_MAX static_cast<uint8_t>(0xff)			  /*!< \brief Maximum of unsigned 8 bit type */
#define VX_UINT16_MAX static_cast<uint16_t>(0xffff)		  /*!< \brief Maximum of unsigned 16 bit type */
#define VX_UINT32_MAX static_cast<uint32_t>(0xffffffff)	  /*!< \brief Maximum of unsigned 32 bit type */

#ifndef M_PI
#define M_PI 3.14159265358979323846 /*!< \brief PI if not defined by cmath */
#endif

// Minimum and Maximu and Absolute
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define ABS(a) ((a < 0) ? (-a) : (a))

// GCD and LCM
#define GCD(a, b) ((a >= b) * GCD_1(a, b) + (a < b) * GCD_1(b, a))
#define GCD_1(a, b) ((((!(b))) * (a)) + (!!(b)) * GCD_2((b), (a) % ((b) + !(b))))
#define GCD_2(a, b) ((((!(b))) * (a)) + (!!(b)) * GCD_3((b), (a) % ((b) + !(b))))
#define GCD_3(a, b) ((((!(b))) * (a)) + (!!(b)) * GCD_4((b), (a) % ((b) + !(b))))
#define GCD_4(a, b) ((((!(b))) * (a)) + (!!(b)) * GCD_5((b), (a) % ((b) + !(b))))
#define GCD_5(a, b) ((((!(b))) * (a)) + (!!(b)) * GCD_6((b), (a) % ((b) + !(b))))
#define GCD_6(a, b) ((((!(b))) * (a)) + (!!(b)) * GCD_7((b), (a) % ((b) + !(b))))
#define GCD_7(a, b) ((((!(b))) * (a)) + (!!(b)) * GCD_8((b), (a) % ((b) + !(b))))
#define GCD_8(a, b) ((((!(b))) * (a)) + (!!(b)) * GCD_last((b), (a) % ((b) + !(b))))
#define GCD_last(a, b) (a)
#define LCM(a, b) (((a) * (b)) / GCD(a, b))

// For alignment
#define ALIGN(val, parallel) (((val % parallel) == 0) ? (val) : ((val / parallel + 1) * parallel))

/*! \brief Gets the datatype of an integer:
 * \details The output is of type <tt>\ref vx_type_e</tt> and is 8, 16, 32, 64 bit signed or unsigned
 */
#define GET_TYPE(TYPE) (const vx_type_e)(                                                                                                                                                                                                                                                                   \
	(std::numeric_limits<TYPE>::is_integer == true) ? (                                                                                                                                                                                                                                                     \
														  (std::numeric_limits<TYPE>::is_signed == false) ? (                                                                                                                                                                                               \
																												(sizeof(TYPE) == 1) ? (VX_TYPE_UINT8) : ((sizeof(TYPE) == 2) ? (VX_TYPE_UINT16) : ((sizeof(TYPE) == 4) ? (VX_TYPE_UINT32) : ((sizeof(TYPE) == 8) ? (VX_TYPE_UINT64) : (VX_TYPE_INVALID))))) \
																										  : (                                                                                                                                                                                               \
																												(sizeof(TYPE) == 1) ? (VX_TYPE_INT8) : ((sizeof(TYPE) == 2) ? (VX_TYPE_INT16) : ((sizeof(TYPE) == 4) ? (VX_TYPE_INT32) : ((sizeof(TYPE) == 8) ? (VX_TYPE_INT64) : (VX_TYPE_INVALID))))))    \
													: (                                                                                                                                                                                                                                                     \
														  VX_TYPE_INVALID))

#define VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM) (const vx_uint32)((static_cast<vx_uint32>(HEIGHT) * static_cast<vx_uint32>(WIDTH)) / static_cast<vx_uint32>(VEC_NUM))

/*********************************************************************************************************************/
/* Image Data Types */
/*********************************************************************************************************************/

/*! \brief Needed as image type for vectorization
@param TYPE The data type for the pixels
@param SIZE The vectorization degree
*/
template <class TYPE, const size_t SIZE>
struct vx_image_data
{
	TYPE pixel[SIZE];

#ifndef __SDSCC__
#ifdef __LAST__
#ifdef __XILINX__
	ap_uint<1> last;
#else
	vx_uint8 last;
#endif
#endif
#ifdef __USER__
#ifdef __XILINX__
	ap_uint<1> user;
#else
	vx_uint8 user;
#endif
#endif
#endif

#ifndef __SDSCC__
	// = Operator
	inline vx_image_data &operator=(const vx_image_data &a)
	{
#pragma HLS INLINE
		for (size_t i = 0; i < SIZE; ++i)
		{
#pragma HLS UNROLL
			pixel[i] = a.pixel[i];
		}
#ifndef __SDSCC__
#ifdef __LAST__
		last = a.last;
#endif
#ifdef __USER__
		user = a.user;
#endif
#endif
		return *this;
	}
#endif
};

struct KeyPoint
{
	vx_int16 x;
	vx_int16 y;
	vx_int16 response;
	vx_uint8 scale;
	vx_uint8 orientation;
};
union KeyPointConverter
{
	KeyPoint keypoint;
	vx_uint64 data;
	vx_uint8 bytes[8];
};

/*********************************************************************************************************************/
/* Allocate/Free Memory */
/*********************************************************************************************************************/

/*! \brief Creates an image object
@param  ImageType The output image type (use "struct vx_image<...>" for vectorization of 2, 4 and 8)
@param  PixelType The data type of the image pixels
@param  COLS      The image columns
@param  ROWS      The image rows
@return           Pointer to the allocated memory
*/
template <typename ImageType, vx_uint32 PIXELS, vx_uint32 PARALLEL>
__inline ImageType *CreateImage()
{
#ifdef __SDSCC__
	return (ImageType *)sds_alloc((sizeof(ImageType) * PIXELS) / PARALLEL);
#else
	return (ImageType *)(new ImageType[PIXELS / PARALLEL]);
#endif
}

/*! \brief Destroys an image object
@param  ImageType The image type
@param  image     The image
*/
template <typename ImageType>
__inline void DestroyImage(ImageType *image)
{
#ifdef __SDSCC__
	return sds_free(image);
#else
	return delete[] image;
#endif
}

/*********************************************************************************************************************/
/* Measure Time */
/*********************************************************************************************************************/

// Timing functions
#ifdef __EVAL_TIME__
#ifdef __XILINX__
void StartTime(XTime &t1)
{
	XTime_SetTime(0);
	XTime_GetTime(&t1);
}
double EndTime(XTime t1, const char *name)
{
	XTime t2;
	XTime_GetTime(&t2);
	double total_time = (double)(t2 - t1);
	return (total_time / (double)COUNTS_PER_SECOND) * 1000000;
}
#else
void StartTime(std::chrono::high_resolution_clock::time_point &t1)
{
	t1 = std::chrono::high_resolution_clock::now();
}
double EndTime(std::chrono::high_resolution_clock::time_point t1, const char *name)
{
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
	return time_span.count() * 1000000000.0;
}
#endif
#endif

// Evaluation of the timing
template <vx_int64 NUM>
void EvaluateTime(double sw[NUM], double hw[NUM], const char *name)
{

	double sw_time_max = DBL_MIN;
	double sw_time_min = DBL_MAX;
	double sw_time_avg = 0.0;
	double hw_time_max = DBL_MIN;
	double hw_time_min = DBL_MAX;
	double hw_time_avg = 0.0;

	for (vx_int64 i = 0; i < NUM; ++i)
	{
		double sw_time = sw[i];
		sw_time_max = MAX(sw_time_max, sw_time);
		sw_time_min = MIN(sw_time_min, sw_time);
		sw_time_avg += sw_time;
		double hw_time = hw[i];
		hw_time_max = MAX(hw_time_max, hw_time);
		hw_time_min = MIN(hw_time_min, hw_time);
		hw_time_avg += hw_time;
	}
	sw_time_avg /= NUM;
	hw_time_avg /= NUM;

#ifdef __XILINX__
	printf("%s\tTime (us):", name);
	printf("SW: %9.0f(max)   %9.0f(avg)   %9.0f(min) \n", sw_time_max, sw_time_avg, sw_time_min);
	printf("%s\tTime (us):", name);
	printf("HW: %9.0f(max)   %9.0f(avg)   %9.0f(min) \n", hw_time_max, hw_time_avg, hw_time_min);
#else
	printf("%s\tTime (ns):  ", name);
	printf("SW: %9.0f(max)   %9.0f(avg)   %9.0f(min) \n", sw_time_max, sw_time_avg, sw_time_min);
	printf("%s\tTime (ns):  ", name);
	printf("HW: %9.0f(max)   %9.0f(avg)   %9.0f(min) \n", hw_time_max, hw_time_avg, hw_time_min);
#endif
}

/*********************************************************************************************************************/
/* NN Structs */
/*********************************************************************************************************************/

// Mobile Net Paramaters
struct MobileNetParam1
{
	const vx_int64 SRC_ROWS;
	const vx_int64 SRC_COLS;
	const vx_int64 DST_ROWS;
	const vx_int64 DST_COLS;
	const vx_int64 IFM;
	const vx_int64 OFM;
	const vx_int64 DW_PARALLEL;
	const vx_int64 IFM_PARALLEL;
	const vx_int64 OFM_PARALLEL;
	const vx_int64 PW_PARALLEL;
	const vx_int64 DMA_PARALLEL;
	const vx_int64 BATCHES;
	const vx_int64 FIXED_POINT_POSITION;
	const vx_round_policy_e ROUND_POLICY;
	const vx_convert_policy_e OVERFLOW_POLICY;
};

// Parameters for Convolution (Depth-Wise Point-Wise) & Pooling
struct NeuralNetworkParam1
{
	const vx_int64 BATCHES;
	const vx_int64 SRC_ROWS;
	const vx_int64 SRC_COLS;
	const vx_int64 DST_ROWS;
	const vx_int64 DST_COLS;
	const vx_int64 IFM;
	const vx_int64 OFM;
	const vx_int64 IFM_PARALLEL;
	const vx_int64 OFM_PARALLEL;
	const vx_int64 KERNEL_X;
	const vx_int64 KERNEL_Y;
	const vx_int64 BIASES_SIZE;
	const vx_int64 FIXED_POINT_POSITION;
	const vx_convert_policy_e OVERFLOW_POLICY;
	const vx_round_policy_e ROUNDING_POLICY;
	const vx_int64 PADDING_Y;
	const vx_int64 PADDING_X;
	const vx_nn_pooling_type_e POOLING_TYPE;
};

// Parameters for Activation, Softmax, Batch Normalization, Fully Connected
template <typename T>
struct NeuralNetworkParam2
{
	const vx_int64 BATCHES;
	const vx_int64 PIXELS;
	const vx_int64 IFM;
	const vx_int64 OFM;
	const vx_int64 PARALLEL;
	const vx_int64 BIASES_SIZE;
	const vx_int64 FIXED_POINT_POSITION;
	const vx_round_policy_e ROUNDING_POLICY;
	const vx_convert_policy_e OVERFLOW_POLICY;
	const T PARAM_A;
	const T PARAM_B;
	const vx_nn_activation_function_e ACTIVATION_FUNCTION;
	const bool RELAXED_MATH;
};

/*********************************************************************************************************************/
/* Own enums  */
/*********************************************************************************************************************/

/*! \brief Contains the different pixelwise and filter operation types
 */
namespace HIFLIPVX
{

	/*! \brief Perfroms a windowed filter function on an image
	 */
	enum FilterOperation
	{
		GAUSSIAN_FILTER,	 /*!< \brief Gaussian filter (optimized for kernel structure) */
		DERIVATIVE_X,		 /*!< \brief Scharr/Sobel derivative filter (optimized for kernel structure) */
		DERIVATIVE_Y,		 /*!< \brief Scharr/Sobel derivative filter (optimized for kernel structure) */
		CUSTOM_CONVOLUTION,	 /*!< \brief Costum convolution filter */
		BOX_FILTER,			 /*!< \brief Box filter (optimized for kernel structure) */
		MEDIAN_FILTER,		 /*!< \brief Median filter (optimized for kernel structure) */
		ERODE_IMAGE,		 /*!< \brief Erode image filter (sperable kernel only) */
		DILATE_IMAGE,		 /*!< \brief Dilate image filter (sperable kernel only) */
		NON_MAX_SUPPRESSION, /*!< \brief Do Non-Maxima Suppression */
		SEGMENT_TEST_DETECTOR,
		HYSTERESIS,
		ORIENTED_NON_MAX_SUPPRESSION
	};

	/*! \brief Performs an pixelwise operation on an image (same data type for input/output)
	 */
	enum PixelwiseOperationA
	{
		COPY_DATA,				/*!< \brief Copy a data object to another. */
		BITWISE_NOT,			/*!< \brief Performs a bitwise NOT operation on a input images. */
		BITWISE_AND,			/*!< \brief Performs a bitwise AND operation between two unsigned images. */
		BITWISE_OR,				/*!< \brief Performs a bitwise INCLUSIVE OR operation between two unsigned images. */
		BITWISE_XOR,			/*!< \brief Performs a bitwise EXCLUSIVE OR (XOR) operation between two unsigned images. */
		MAX,					/*!< \brief Implements a pixel-wise maximum kernel. */
		MIN,					/*!< \brief Implements a pixel-wise minimum kernel. */
		ABSOLUTE_DIFFERENCE,	/*!< \brief Computes the absolute difference between two images */
		ARITHMETIC_ADDITION,	/*!< \brief Performs addition between two images */
		ARITHMETIC_SUBTRACTION, /*!< \brief Performs subtraction between two images */
		MAGNITUDE,				/*!< \brief Implements the Gradient Magnitude Computation Kernel */
		MULTIPLY,				/*!< \brief Performs element-wise multiplication between two images and a scalar value. */
		THRESHOLD,				/*!< \brief  Thresholds an input image and produces an output Boolean image. */
		WEIGHTED_AVERAGE,		/*!< \brief  Accumulates a weighted value from an input image to an output image.  */
		PHASE
	};
}

/*********************************************************************************************************************/
/* Static Assertion (COMPILE TIME) */
/*********************************************************************************************************************/

// note that we wrap the non existing type inside a struct to avoid warning
// messages about unused variables when static assertions are used at function
// scope
// the use of sizeof makes sure the assertion error is not ignored by SFINAE
template <bool>
struct StaticAssertion;
template <>
struct StaticAssertion<true>
{
}; // StaticAssertion<true>
template <int i>
struct StaticAssertionTest
{
}; // StaticAssertionTest<int>

#define CONCATENATE(arg1, arg2) CONCATENATE1(arg1, arg2)
#define CONCATENATE1(arg1, arg2) CONCATENATE2(arg1, arg2)
#define CONCATENATE2(arg1, arg2) arg1##arg2

/*! \brief Pre-C++11 Static Assertions Without Boost
 * \details: from  http://stackoverflow.com/questions/1980012/boost-static-assert-without-boost/1980156
 *
 * <code>STATIC_ASSERT(expression, message)</code>
 *
 * When the static assertion test fails, a compiler error message that somehow
 * contains the "STATIC_ASSERTION_FAILED_AT_LINE_xxx_message" is generated.
 *
 * /!\ message has to be a valid C++ identifier, that is to say it must not
 * contain space characters, cannot start with a digit, etc.
 *
 * STATIC_ASSERT(true, this_message_will_never_be_displayed);
 */
#define STATIC_ASSERT(expression, message)                                                                                                              \
	struct CONCATENATE(__static_assertion_at_line_, __LINE__)                                                                                           \
	{                                                                                                                                                   \
		StaticAssertion<static_cast<bool>((expression))> CONCATENATE(CONCATENATE(CONCATENATE(STATIC_ASSERTION_FAILED_AT_LINE_, __LINE__), _), message); \
	};                                                                                                                                                  \
	typedef StaticAssertionTest<sizeof(CONCATENATE(__static_assertion_at_line_, __LINE__))> CONCATENATE(__static_assertion_test_at_line_, __LINE__)

/*********************************************************************************************************************/
/* HW: Helper Functions for arithmetic computation  */
/*********************************************************************************************************************/

// Set user(SOF) & last(EOF)
template <typename T, vx_int32 VEC_NUM>
void GenerateDmaSignal(const bool condition_first, const bool condition_last, vx_image_data<T, VEC_NUM> &dst)
{
#pragma HLS INLINE
#ifndef __SDSCC__
#ifdef __LAST__
	dst.last = (condition_last == true) ? (1) : (0);
#endif
#ifdef __USER__
	dst.user = (condition_first == true) ? (1) : (0);
#endif
#endif
}

/*! \brief Gets the maximum value of a certain data type
@param Type  The data type that should be evaluated
@return      The maximum value for "Type"
*/
template <typename Type>
Type ComputeMax()
{
#pragma HLS INLINE
	const vx_type_e MAX_TYPE = GET_TYPE(Type);
	return (MAX_TYPE == VX_TYPE_UINT8) ? (VX_UINT8_MAX) : ((MAX_TYPE == VX_TYPE_UINT16) ? (VX_UINT16_MAX) : ((MAX_TYPE == VX_TYPE_UINT32) ? (VX_UINT32_MAX) : ((MAX_TYPE == VX_TYPE_INT8) ? (VX_INT8_MAX) : ((MAX_TYPE == VX_TYPE_INT16) ? (VX_INT16_MAX) : ((MAX_TYPE == VX_TYPE_INT32) ? (VX_INT32_MAX) : (VX_TYPE_INVALID))))));
}

/*! \brief Gets the minimum value of a certain data type
@param Type  The data type that should be evaluated
@return      The minimum value for "Type"
*/
template <typename Type>
Type ComputeMin()
{
#pragma HLS INLINE
	const vx_type_e MIN_TYPE = GET_TYPE(Type);
	return (MIN_TYPE == VX_TYPE_UINT8) ? (0) : ((MIN_TYPE == VX_TYPE_UINT16) ? (0) : ((MIN_TYPE == VX_TYPE_UINT32) ? (0) : ((MIN_TYPE == VX_TYPE_INT8) ? (VX_INT8_MIN) : ((MIN_TYPE == VX_TYPE_INT16) ? (VX_INT16_MIN) : ((MIN_TYPE == VX_TYPE_INT32) ? (VX_INT32_MIN) : (VX_TYPE_INVALID))))));
}

/*! \brief Saturates a function to a maximum and minimum value
@param Type    The data type of the value
@param data    The input value
@param max_val The maximum value
@param min_val The minimum value
@return        The saturated value
*/
template <typename Type>
Type SaturateMaxMin(Type data, Type max_val, Type min_val)
{
#pragma HLS INLINE
	if (data > max_val)
		return max_val;
	else if (data < min_val)
		return min_val;
	else
		return data;
}

/*! \brief An arithmetic right shift that simulates the behavior of division. For signed values there is a different behavior between shift and division when rounding.
@param Type             The data type of the value
@param SIGNED_DATA_TYPE If value is signed
@param data             The input value
@param shift            The shift value
@return                 The result
*/
template <typename Type, bool SIGNED_DATA_TYPE>
Type ShiftArithmeticRight(Type data, vx_uint16 shift)
{
#pragma HLS INLINE
	Type a = data >> shift;
	if ((SIGNED_DATA_TYPE == true) && (a < 0))
	{
		a += 1;
	}
	return a;
}

/** @brief Computes the ATAN2(x,y) using the cordic algorithm
@param x  x-vector
@param y  y_vector
@return	  atan2(x,y)
*/
template <typename CompType, vx_uint16 STEPS>
CompType atan2Cordic(CompType x, CompType y)
{
#pragma HLS INLINE

	CompType sgn, xh, yh, winkel;
	CompType i_atantab[] = {16384, 9672, 5110, 2594, 1302, 652, 326, 163, 81, 41, 20, 10, 5, 3, 1, 1};

	// Initalization
	sgn = (y >= 0) ? -1 : 1;
	xh = -sgn * y;
	yh = +sgn * x;
	x = xh;
	y = yh;
	winkel = sgn * i_atantab[0];

	// Iteration maximum: i<31
	for (vx_uint16 i = 1, k = 0; i <= STEPS; i++, k++)
	{
#pragma HLS unroll
		sgn = (y >= 0) ? -1 : 1;
		winkel += sgn * i_atantab[i];
		xh = x - sgn * (y >> k);
		yh = y + sgn * (x >> k);
		x = xh;
		y = yh;
		if (y == 0)
			break;
	}

	return -winkel;
}

/** @brief Computes the ATAN2(x,y) using the cordic algorithm
@param x  x-vector
@param y  y_vector
@return	  atan2(x,y)
*/
vx_int64 atan2CordicAccurate(vx_int64 x, vx_int64 y)
{
#pragma HLS INLINE

	vx_int64 sgn, xh, yh, winkel;
	vx_int64 i_atantab[] = {1073741824, 536870912, 316933406,
							167458907, 85004756, 42667331, 21354465, 10679838, 5340245,
							2670163, 1335087, 667544, 333772, 166886, 83443, 41722,
							20861, 10430, 5215, 2608, 1304, 652, 326, 163, 81, 41, 20, 10, 5, 3, 1};

	// Initalization
	sgn = (y >= 0) ? -1 : 1;
	xh = -sgn * y;
	yh = +sgn * x;
	x = xh;
	y = yh;
	winkel = sgn * i_atantab[0];

	// Iteration maximum: i<31
	for (vx_uint16 i = 1, k = 0; i <= 24; i++, k++)
	{
#pragma HLS unroll
		sgn = (y >= 0) ? -1 : 1;
		winkel += sgn * i_atantab[i];
		xh = x - sgn * (y >> k);
		yh = y + sgn * (x >> k);
		x = xh;
		y = yh;
		if (y == 0)
			break;
	}

	return -winkel;
}

/** @brief Computes square root: Rounding to floor or to nearest integer
@param OutType		The data type of the output
@param InType		The data type of the input
@param ROUND_POLICY Rounding policy (to zero & nearest even)
@param CHECK_MAX	Is true, if the maximum value should be checked (needed for rounding to nearest even)
@param value		The input value
@return				The square root of the input value
*/
template <typename OutType, typename InType, bool CHECK_MAX, vx_round_policy_e ROUND_POLICY, vx_uint8 OUTPUT_BIT_WIDTH>
OutType SqrtLester(InType value)
{
#pragma HLS INLINE

	const OutType MAX_VAL = ComputeMax<OutType>();

	// Number of stages (latency)
	const vx_uint8 N = OUTPUT_BIT_WIDTH; // sizeof(OutType) * 8;

	// Variables
	OutType A1 = 0; // A^1 Intermediate result
	InType A2 = 0;	// A^2 Square of the intermediate result

	// Each stage computes 1 bit of the resulting vector
	for (vx_uint8 n = N - 1; n < N; n--)
	{
#pragma HLS unroll

		// Add new bit of position n and compute (A1 + B1)^2
		OutType B1 = static_cast<OutType>(1) << (n);
		InType B2 = static_cast<InType>(B1) << (n);
		InType AB = static_cast<InType>(A1) << (n);
		InType A2_next = A2 + B2 + (AB << 1); // A*A + B*B + 2*A*B

		// Store if tmp does not exceed value
		if (A2_next <= value)
		{
			A1 |= B1;
			A2 = A2_next;
		}
	}

	// Round to the nearest integer and check for overflow
	if (ROUND_POLICY == VX_ROUND_POLICY_TO_NEAREST_EVEN)
	{
		if (CHECK_MAX)
		{
			if (((value - A2) > static_cast<InType>(A1)) && (A1 != MAX_VAL))
				A1++;
		}
		else
		{
			if ((value - A2) > static_cast<InType>(A1))
				A1++;
		}
	}

	// Return result
	return A1;
}

/*********************************************************************************************************************/
/* HW: Helper Functions to Create Kernels (COMPILE TIME) */
/*********************************************************************************************************************/

/** @brief Computes the Gaussian Kernel using the Sigma values (not compile time in all SDx versions)
@param ScalarType Data type of the kernel
@param KERN_SIZE  The size of the kernel
@param kernel     The computed gaussian kernel
@param sigma      The input sigma value
@return           The fraction size of the fixed-point result
*/
template <typename ScalarType, const vx_uint8 KERN_SIZE>
const vx_uint16 ComputeGaussianKernelSigma(ScalarType kernel[KERN_SIZE][KERN_SIZE], const double sigma)
{
#pragma HLS INLINE

	// Constants
	const vx_uint16 K_RAD = (vx_uint16)KERN_SIZE / (vx_uint16)2;
	const double s = 2.0 * sigma * sigma;

	// Variables
	double sum = 0.0;
	double doubleKernel[KERN_SIZE][KERN_SIZE];
#pragma HLS array_partition variable = doubleKernel complete dim = 0

	// Creates the gaussian kernel
	for (vx_uint8 x = 0; x < KERN_SIZE; x++)
	{
#pragma HLS unroll
		for (vx_uint8 y = 0; y < KERN_SIZE; y++)
		{
#pragma HLS unroll
			const vx_uint32 a = static_cast<vx_uint32>((vx_uint16)x - K_RAD);
			const vx_uint32 b = static_cast<vx_uint32>((vx_uint16)y - K_RAD);
			const double c = static_cast<double>(a * a + b * b);
			const double r = sqrt(c);
			doubleKernel[x][y] = (exp(-(r * r) / s)) / (M_PI * s);
			sum += doubleKernel[x][y];
		}
	}

	// Normalizes the gaussian kernel
	for (vx_uint8 x = 0; x < KERN_SIZE; x++)
	{
#pragma HLS unroll
		for (vx_uint8 y = 0; y < KERN_SIZE; y++)
		{
#pragma HLS unroll
			doubleKernel[x][y] /= sum;
		}
	}

	// Computes the fraction for the fixed point representation
	vx_int32 e_max = VX_INT32_MIN;
	for (vx_uint8 i = 0; i < KERN_SIZE; i++)
	{
#pragma HLS unroll
		for (vx_uint8 j = 0; j < KERN_SIZE; j++)
		{
#pragma HLS unroll
			int e = 0;
			frexp(doubleKernel[i][j], &e);
			e_max = MAX(e_max, (vx_int32)e);
		}
	}
	const vx_int32 fraction = 8 * sizeof(ScalarType) - e_max;
	const vx_uint16 kernFraction = static_cast<vx_uint16>(MIN(MAX(fraction, (vx_int32)0), (vx_int32)31));

	// Computes and stores the fixed point kernel
	vx_uint32 shift = 1;
	for (vx_uint16 i = 0; i < kernFraction; i++)
	{
#pragma HLS unroll
		shift *= 2;
	}
	for (vx_uint8 i = 0; i < KERN_SIZE; i++)
	{
#pragma HLS unroll
		for (vx_uint8 j = 0; j < KERN_SIZE; j++)
		{
#pragma HLS unroll
			kernel[i][j] = static_cast<ScalarType>(doubleKernel[i][j] * static_cast<double>(shift));
		}
	}

	// Returns the fraction
	return kernFraction;
}

/** @brief Convolute an array with the convolution array [1 2 1]
@param ScalarType      Data type of the kernel
@param KERN_SIZE       The size of the final kernel
@param BUFFER_SIZE     The amount of kernels that can be stored in "kernel_buffer"
@param kernel_buffer   Buffers input and output kernel
@param cur_kernel_ptr  Pointer where the input kernel is stored
@param cur_kernel_size The size of the input kernel
*/
template <typename ScalarType, vx_uint8 KERN_SIZE, vx_int16 BUFFER_SIZE>
void ComputeConvolution(ScalarType kernel_buffer[BUFFER_SIZE][KERN_SIZE], const vx_int16 cur_kernel_ptr, const vx_int16 cur_kernel_size)
{
#pragma HLS INLINE

	// Constants
	const vx_int16 kernel_size = cur_kernel_size + 2;
	const vx_int16 kernel_rad = kernel_size >> 1;

	// Standard convolution kernel
	ScalarType convoltion[3] = {1, 2, 1};
#pragma HLS array_partition variable = convoltion complete dim = 0

	// convolute kernel
	for (vx_int32 j = 0; j < kernel_size; j++)
	{
#pragma HLS unroll
		const vx_int32 range = MIN((j < kernel_rad) ? (j + 1) : (kernel_size - j), (vx_int32)3);
		const vx_int32 start_0 = MAX(2 - j, (vx_int32)0);
		const vx_int32 start_1 = MAX(j - 2, (vx_int32)0);
		ScalarType sum = 0;
		for (vx_int32 k = 0; k < range; k++)
		{
#pragma HLS unroll
			sum += (convoltion[start_0 + k] * kernel_buffer[cur_kernel_ptr][start_1 + k]);
		}
		kernel_buffer[cur_kernel_ptr + 1][j] = sum;
	}
}

/** @brief Computes 2d kernel from two 1d kernels
@param ScalarType Data type of the kernel
@param KERN_SIZE  The size of the kernel
@param src1       The 1. 1d kernel
@param src2       The 2. 1d kernel
@param dst        The resulting 2d kernel
*/
template <typename ScalarType, vx_uint8 KERN_SIZE>
void ComputeKernel(ScalarType src1[KERN_SIZE], ScalarType src2[KERN_SIZE], ScalarType dst[KERN_SIZE][KERN_SIZE])
{
#pragma HLS INLINE

	for (vx_uint8 i = 0; i < KERN_SIZE; i++)
	{
#pragma HLS unroll
		for (vx_uint8 j = 0; j < KERN_SIZE; j++)
		{
#pragma HLS unroll
			dst[i][j] = src1[i] * src2[j];
		}
	}
}

/** @brief Computes the 1d kernels for the sobel filter
@param ScalarType Data type of the kernel
@param KERN_SIZE  The size of the kernel
@param sobel_x    Stores the sobel kernel in x-direction
@param sobel_y    Stores the sobel kernel in y-direction
*/
template <typename ScalarType, vx_uint8 KERN_SIZE>
void ComputeSobelKernels(ScalarType sobel_x[KERN_SIZE][KERN_SIZE], ScalarType sobel_y[KERN_SIZE][KERN_SIZE])
{
#pragma HLS INLINE

	// Constants and variables
	const vx_int16 ONE = static_cast<vx_int16>(1);
	const vx_int16 THREE = static_cast<vx_int16>(3);
	const vx_int16 BUFFER_SIZE = (((vx_int16)KERN_SIZE - THREE) >> ONE) + ONE;
	vx_int16 buffer_ptr = 0;

	// Sobel 1d kernel
	ScalarType buffer_0[BUFFER_SIZE][KERN_SIZE];
#pragma HLS array_partition variable = buffer_0 complete dim = 0
	buffer_0[0][0] = 1;
	buffer_0[0][1] = 2;
	buffer_0[0][2] = 1;
	ScalarType buffer_1[BUFFER_SIZE][KERN_SIZE];
#pragma HLS array_partition variable = buffer_1 complete dim = 0
	buffer_1[0][0] = -1;
	buffer_1[0][1] = 0;
	buffer_1[0][2] = 1;

	// vx_uint8 kernel for higher kernel size
	for (vx_uint8 i = 3; i < KERN_SIZE; i += 2)
	{
#pragma HLS unroll
		ComputeConvolution<ScalarType, KERN_SIZE, BUFFER_SIZE>(buffer_0, buffer_ptr, (vx_int16)i);
		ComputeConvolution<ScalarType, KERN_SIZE, BUFFER_SIZE>(buffer_1, buffer_ptr, (vx_int16)i);
		buffer_ptr++;
	}

	// Compute the 2d kernel
	ComputeKernel<ScalarType, KERN_SIZE>(buffer_0[buffer_ptr], buffer_1[buffer_ptr], sobel_x);
	ComputeKernel<ScalarType, KERN_SIZE>(buffer_1[buffer_ptr], buffer_0[buffer_ptr], sobel_y);
}

/** @brief Computes the Gaussian kernel
@param ScalarType Data type of the kernel
@param KERN_SIZE  The size of the kernel
@param gaussian   Stores the gaussian kernel
*/
template <typename ScalarType, vx_uint8 KERN_SIZE>
void ComputeGaussianKernels(ScalarType gaussian[KERN_SIZE][KERN_SIZE])
{
#pragma HLS INLINE

	const vx_int16 ONE = static_cast<vx_int16>(1);
	const vx_int16 THREE = static_cast<vx_int16>(3);

	// Constants and variables
	const vx_int16 BUFFER_SIZE = (((vx_int16)KERN_SIZE - THREE) >> ONE) + ONE;
	vx_int16 buffer_ptr = 0;

	// Gaussian 1d kernel
	ScalarType buffer_0[BUFFER_SIZE][KERN_SIZE];
#pragma HLS array_partition variable = buffer_0 complete dim = 0
	buffer_0[0][0] = 1;
	buffer_0[0][1] = 2;
	buffer_0[0][2] = 1;

	// Computer Gaussian kernel with bigger kernel sizes
	for (vx_uint8 i = 3; i < KERN_SIZE; i += 2)
	{
#pragma HLS unroll
		ComputeConvolution<ScalarType, KERN_SIZE, BUFFER_SIZE>(buffer_0, buffer_ptr, (vx_int16)i);
		buffer_ptr++;
	}

	// Compute the 2d kernel from the 1d kernel
	ComputeKernel<ScalarType, KERN_SIZE>(buffer_0[buffer_ptr], buffer_0[buffer_ptr], gaussian);
}

/** @brief Computes the normalization with given sum of kernel coefficients
@param kernel_sum Sum of the kernel coefficients
@param norm_mult  For normalization: multiply with this value
@param norm_shift For normalization: shift the multiplied result with this value
*/
void ComputeNormalization(const vx_uint64 kernel_sum, vx_uint64 &norm_mult, vx_uint32 &norm_shift)
{
#pragma HLS INLINE

	// Constants
	const vx_uint32 MAX_SHIFT = static_cast<vx_uint32>(48);
	const vx_uint32 MIN_SHIFT = static_cast<vx_uint32>(15);
	const vx_uint64 ONE = static_cast<vx_uint64>(1);
	const vx_uint64 ZERO = static_cast<vx_uint64>(0);

	// Variables
	vx_uint16 new_shift = 0;
	vx_uint16 new_mult = 1;
	vx_uint32 old_shift = 0;
	vx_uint64 old_mult = 1;
	vx_uint64 norm_mult_a = 1;
	vx_uint32 norm_shift_a = 0;
	vx_uint64 norm_mult_b = 1;
	vx_uint32 norm_shift_b = 0;
	vx_uint64 temp = 0;
	bool is_power_two = false;

	// Compute Mult and Shift (Not Power of two)
	old_mult = temp = (ONE << MAX_SHIFT) / kernel_sum;
	for (vx_uint32 i = 0; i < MAX_SHIFT; i++)
	{
#pragma HLS unroll
		if (temp > ZERO)
		{
			temp = temp >> static_cast<vx_uint32>(1);
			old_shift = i;
		}
	}
	if (old_shift > 16)
	{
		new_shift = static_cast<vx_uint16>(MAX_SHIFT - (old_shift - MIN_SHIFT));
		new_mult = static_cast<vx_uint16>(old_mult >> (old_shift - MIN_SHIFT));
	}
	else
	{
		new_shift = static_cast<vx_uint16>(MAX_SHIFT);
		new_mult = static_cast<vx_uint16>(old_mult);
	}
	norm_mult_a = static_cast<vx_uint64>(new_mult);
	norm_shift_a = static_cast<vx_uint32>(new_shift);

	// Compute Mult and Shift (Power of two)
	for (vx_uint32 i = 0; i < sizeof(vx_uint32) * 8; i++)
	{
#pragma HLS unroll
		if ((kernel_sum & (ONE << i)) != ZERO)
			norm_shift_b = i;
	}

	// Check if scaling is by a power of two
	is_power_two = (kernel_sum & (kernel_sum - ONE)) == ZERO;

	// Compute Normalization and Multiplication
	norm_mult = (is_power_two) ? (norm_mult_b) : (norm_mult_a);
	norm_shift = (is_power_two) ? (norm_shift_b) : (norm_shift_a);
}

/** @brief Computes the normalization of a 2d kernel ((a * norm_mult) >> norm_shift)
@param KernType   Data type of the kernel
@param KERN_SIZE  The size of the kernel
@param kernel     The kernel itself
@param norm_mult  For normalization: multiply with this value
@param norm_shift For normalization: shift the multiplied result with this value
*/
template <typename KernType, vx_uint8 KERN_SIZE>
void ComputeNormalization2d(KernType kernel[KERN_SIZE][KERN_SIZE], vx_uint64 &norm_mult, vx_uint32 &norm_shift)
{
#pragma HLS INLINE

	// Variables
	vx_uint64 kernel_sum = 0;

	// Sum the kernel values
	for (vx_uint8 i = 0; i < KERN_SIZE; i++)
	{
#pragma HLS unroll
		for (vx_uint8 j = 0; j < KERN_SIZE; j++)
		{
#pragma HLS unroll
			kernel_sum += static_cast<vx_uint64>(abs(static_cast<vx_int64>(kernel[i][j])));
		}
	}

	// Compute Normalization
	ComputeNormalization(kernel_sum, norm_mult, norm_shift);
}

/** @brief Computes the normalization of a 1d kernel ((a * norm_mult) >> norm_shift)
@param KernType   Data type of the kernel
@param KERN_SIZE  The size of the kernel
@param kernel     The kernel itself
@param norm_mult  For normalization: multiply with this value
@param norm_shift For normalization: shift the multiplied result with this value
*/
template <typename KernType, vx_uint8 KERN_SIZE>
void ComputeNormalization1d(KernType kernel[KERN_SIZE], vx_uint64 &norm_mult, vx_uint32 &norm_shift)
{
#pragma HLS INLINE

	// Variables
	vx_uint64 kernel_sum = 0;

	// Sum the kernel values for normalization (pre-compile)
	for (vx_uint8 i = 0; i < KERN_SIZE; i++)
	{
#pragma HLS unroll
		kernel_sum += static_cast<vx_uint64>(abs(static_cast<vx_int64>(kernel[i])));
	}

	// Compute Normalization
	ComputeNormalization(kernel_sum, norm_mult, norm_shift);
}

/***************************************************************************************************************************************************/
/* Compute Magnitude */
/***************************************************************************************************************************************************/

/*! \brief Compute Magnitude of one pixel (signed)
	\details Tested for 8, 16 and 32 bit | exact OpenVX results
@param ScalarInt       Data type of the image pixels
@param ScalarUint      Data type of the image pixels
@param CompInt         Data type for the computation
@param CompUint        Data type for the computation
@param CONV_POLICY     Conversion policy (wrap & saturate)
@param ROUND_POLICY    Rounding policy (to zero & nearest even)
@param input1          1. input pixel
@param input2          2. input pixel
@return                Result
*/
template <typename ScalarInt, typename ScalarUint, typename CompInt, typename CompUint, vx_convert_policy_e CONV_POLICY,
		  vx_round_policy_e ROUND_POLICY>
ScalarInt MagnitudeSigned(ScalarInt input1, ScalarInt input2)
{
#pragma HLS INLINE

	const vx_uint32 COMPUTE_TYPE = sizeof(CompUint);

	// Get max value for overflow
	const ScalarUint MAX_VAL = static_cast<ScalarUint>(ComputeMax<ScalarInt>());

	// Compute magnitude for signed input/output
	CompInt A = static_cast<CompInt>(input1);
	CompInt B = static_cast<CompInt>(input2);
	CompUint AA = static_cast<CompUint>(A * A);
	CompUint BB = static_cast<CompUint>(B * B);
	CompUint C = AA + BB;

	// Square Root
	ScalarUint D = 0;
	if (COMPUTE_TYPE == 8)
	{
		if (ROUND_POLICY == VX_ROUND_POLICY_TO_NEAREST_EVEN)
			D = static_cast<ScalarUint>(sqrt(static_cast<double>(C)) + 0.5);
		else
			D = static_cast<ScalarUint>(sqrt(static_cast<double>(C)));
	}
	else
	{
		D = SqrtLester<ScalarUint, CompUint, true, ROUND_POLICY, sizeof(ScalarUint) * 8>(C);
	}

	// Overflow (Saturation) - due to conversion back to signed
	ScalarUint E = 0;
	if (CONV_POLICY == VX_CONVERT_POLICY_SATURATE)
		E = MIN(D, MAX_VAL);
	else if (CONV_POLICY == VX_CONVERT_POLICY_WRAP)
		E = D;

	// Return result
	return static_cast<ScalarInt>(E);
}

/*! \brief Compute Magnitude of one pixel (unsigned)
	\details Tested for 8, 16 and 32 bit | exact OpenVX results if MAX_VALUE and CHECK_MAX are true \n
@param ScalarUint      Data type of the image pixels
@param CompUint        Data type for the computation
@param CONV_POLICY     Conversion policy (wrap & saturate)
@param ROUND_POLICY    Rounding policy (to zero & nearest even)
@param input1          1. input pixel
@param input2          2. input pixel
@return                Result
*/
template <typename ScalarUint, typename CompUint, vx_convert_policy_e CONV_POLICY, vx_round_policy_e ROUND_POLICY>
ScalarUint MagnitudeUnsigned(ScalarUint input1, ScalarUint input2)
{
#pragma HLS INLINE

	const vx_uint32 COMPUTE_TYPE = sizeof(CompUint);

	// Get max value for overflow
	const ScalarUint MAX_VAL = static_cast<ScalarUint>(ComputeMax<ScalarUint>());

	// Compute magnitude for unsigned input/output
	CompUint A = static_cast<CompUint>(input1);
	CompUint B = static_cast<CompUint>(input2);
	CompUint AA = A * A;
	CompUint BB = B * B;
	CompUint C = AA + BB;

	// Square Root
	ScalarUint D = 0;
	if (COMPUTE_TYPE == 8)
	{
		if (ROUND_POLICY == VX_ROUND_POLICY_TO_NEAREST_EVEN)
			D = static_cast<ScalarUint>(sqrt(static_cast<double>(C)) + 0.5);
		else
			D = static_cast<ScalarUint>(sqrt(static_cast<double>(C)));
	}
	else
	{
		D = SqrtLester<ScalarUint, CompUint, true, ROUND_POLICY, sizeof(ScalarUint) * 8>(C);
	}

	// Overflow (Saturation) - if C alrady has overflow
	ScalarUint E = 0;
	if (CONV_POLICY == VX_CONVERT_POLICY_SATURATE)
		E = (C >= AA && C >= BB) ? (D) : (MAX_VAL);
	else if (CONV_POLICY == VX_CONVERT_POLICY_WRAP)
		E = D;

	// Return result
	return static_cast<ScalarUint>(E);
}

/***************************************************************************************************************************************************/
/* Compute Pixel-wise Multiplication */
/***************************************************************************************************************************************************/

/** @brief Performs element-wise multiplication between two images and a scalar value.
@param ScalarType      Data type of the image pixels
@param CompType        Data type for the computation
@param IS_SIGNED       Is true if it is a signed value
@param CONV_POLICY     Conversion policy (wrap & saturate)
@param ROUND_POLICY    Rounding policy (to zero & nearest even)
@param SCALE           A positive fixed-point (16-bit fraction) number multiplied to each product before overflow handling (between 0.0 and 1.0)
@param input1          1. input pixel
@param input2          2. input pixel
@return                Result
*/
template <typename ScalarType, typename CompType, bool IS_SIGNED, vx_type_e SCALAR_TYPE, vx_convert_policy_e CONV_POLICY,
		  vx_round_policy_e ROUND_POLICY, vx_uint32 SCALE>
ScalarType Multiply(ScalarType input1, ScalarType input2)
{
#pragma HLS INLINE

	// Check function parameters/types
	STATIC_ASSERT(SCALE <= 0x10000, scale_value_must_be_between_1_and_0_It_is_fixed_point_and_has_16_bit_fraction);

	// Get (Max and Min)
	const CompType MIN_VAL = static_cast<CompType>(ComputeMin<ScalarType>());
	const CompType MAX_VAL = static_cast<CompType>(ComputeMax<ScalarType>());

	// Check if scaling is by a power of two
	const bool IS_POWER_TWO = (SCALE & (SCALE - 1)) == 0;

	// Compute the amount of bits data needs to be shiftet, if it is power of two
	vx_uint32 SHIFT = 0;
	for (vx_uint32 i = 0; i < sizeof(SCALE) * 8; i++)
	{
#pragma HLS unroll
		if ((SCALE & static_cast<vx_uint32>(1 << i)) != 0)
			SHIFT = 16 - i;
	}

	// Constants
	const CompType MULT_INT = static_cast<CompType>(SCALE);
	const CompType ROUND_POWER_2 = (SHIFT > 0) ? (static_cast<CompType>(1) << (SHIFT - 1)) : (static_cast<CompType>(0));
	const CompType ROUND_NORMAL = static_cast<CompType>(1) << (15);
	const vx_uint16 SHIFT_POWER_2 = static_cast<vx_uint16>(SHIFT);
	const vx_uint16 SHIFT_NORMAL = 16;

	// Store result
	CompType D = 0, result = 0;

	// Compute Pixelwise Multiplication
	if (MULT_INT > 0)
	{

		// Compute Multiplicaion
		CompType A = static_cast<CompType>(input1);
		CompType B = static_cast<CompType>(input2);
		CompType C = A * B;

		// Multiply and round to nearest integer
		if (ROUND_POLICY == VX_ROUND_POLICY_TO_NEAREST_EVEN)
		{

			// Shift bits, if scale it is a power of two
			if (IS_POWER_TWO)
			{
				D = (C + ROUND_POWER_2);
				D = ShiftArithmeticRight<CompType, IS_SIGNED>(D, SHIFT_POWER_2);

				// Multiply by scale, if it is not a power of two
			}
			else
			{
				if ((SCALAR_TYPE == VX_TYPE_UINT32) || (SCALAR_TYPE == VX_TYPE_INT32))
				{
					D = ShiftArithmeticRight<CompType, IS_SIGNED>(C, SHIFT_NORMAL);
					D = (D * MULT_INT + ROUND_NORMAL);
				}
				else
				{
					D = (C * MULT_INT + ROUND_NORMAL);
					D = ShiftArithmeticRight<CompType, IS_SIGNED>(D, SHIFT_NORMAL);
				}
			}

			// Multiply and truncate the least significant values
		}
		else if (ROUND_POLICY == VX_ROUND_POLICY_TO_ZERO)
		{

			// Shift bits, if scale it is a power of two
			if (IS_POWER_TWO)
			{
				D = ShiftArithmeticRight<CompType, IS_SIGNED>(C, SHIFT_POWER_2);

				// Multiply by scale, if it is not a power of two
			}
			else
			{
				if ((SCALAR_TYPE == VX_TYPE_UINT32) || (SCALAR_TYPE == VX_TYPE_INT32))
				{
					D = ShiftArithmeticRight<CompType, IS_SIGNED>(C, SHIFT_NORMAL);
					D = (D * MULT_INT);
				}
				else
				{
					D = (C * MULT_INT);
					D = ShiftArithmeticRight<CompType, IS_SIGNED>(D, SHIFT_NORMAL);
				}
			}
		}

		// Saturate the result
		if (CONV_POLICY == VX_CONVERT_POLICY_SATURATE)
		{
			if (IS_SIGNED)
			{
				result = SaturateMaxMin<CompType>(D, MAX_VAL, MIN_VAL);
			}
			else
			{
				result = MIN(D, MAX_VAL);
			}
		}
		else if (CONV_POLICY == VX_CONVERT_POLICY_WRAP)
		{
			result = D;
		}
	}

	// Return result
	return static_cast<ScalarType>(result);
}

/***************************************************************************************************************************************************/
/* Compute Phase */
/***************************************************************************************************************************************************/

/** @brief Computes the orientation of a pixel.
@param DataType            Data type of the image pixels
@param CompType            Data type for the computation
@param PHASE_QUANTIZATION  2^PHASE_QUANTIZATION different possibilities for the output
@param input1              1. input pixel
@param input2              2. input pixel
@return                    Result
*/
template <typename DataType, typename CompType, vx_uint8 PHASE_QUANTIZATION>
CompType Phase(CompType input1, CompType input2)
{
#pragma HLS INLINE
	// Constants
	const vx_int32 ACCURACY = 7 + PHASE_QUANTIZATION;
	const vx_int32 SHIFT = (vx_int32)1 << ACCURACY;
	const vx_int32 TURN_POS = SHIFT / (vx_int32)(2 << (vx_int32)PHASE_QUANTIZATION);
	const vx_int32 TURN_NEG = SHIFT - TURN_POS;
	const vx_int32 QUANTIZATION = ACCURACY - (vx_int32)PHASE_QUANTIZATION;
	const vx_int32 ROUNDING = (vx_int32)1 << (QUANTIZATION - (vx_int32)1);

	// Computation
	CompType a1 = atan2Cordic<CompType, 8>((CompType)input1, (CompType)input2); // Compute angle
	CompType a2 = a1 >> (16 - ACCURACY) - ROUNDING;								// Reduce Precision and round
	CompType a3 = (a2 < 0) ? (a2 + SHIFT) : (a2);								// Convert negative degree to positiv
	CompType a4 = (a3 > TURN_NEG) ? (a3 - TURN_NEG) : (a3 + TURN_POS);			// Setting 0 degree to east
	CompType a5 = (a4 >= SHIFT) ? (0) : (a4);									// Setting 360 degree to 0
	return (a5) >> QUANTIZATION;												// Do quantization
}

/***************************************************************************************************************************************************/
/* Arithmetic Operations */
/***************************************************************************************************************************************************/

/** @brief Computes an arithmetic operation
@param ScalarType      Data type of the image pixels
@param OPERATION_TYPE  Operation type (e.g. arithmetic add, sub, mul)
@param CONV_POLICY     Conversion policy (wrap & saturate)
@param ROUND_POLICY    Rounding policy (to zero & nearest even)
@param SCALE           A positive fixed-point (16-bit fraction) number multiplied to each product before overflow handling (between 0.0 and 1.0)
@param input1          1. input pixel
@param input2          2. input pixel
@return                result
*/
template <typename ScalarType, HIFLIPVX::PixelwiseOperationA OPERATION_TYPE, vx_convert_policy_e CONV_POLICY, vx_round_policy_e ROUND_POLICY,
		  vx_uint32 SCALE, vx_threshold_type_e THRESH_TYPE, ScalarType THRESH_VALUE, ScalarType THRESH_UPPER, ScalarType THRESH_LOWER, vx_uint32 ALPHA,
		  vx_uint8 PHASE_QUANTIZATION>
ScalarType Arithmetic(ScalarType input1, ScalarType input2)
{
#pragma HLS INLINE

	// Compile-time-checks
	STATIC_ASSERT((PHASE_QUANTIZATION <= 8) && (PHASE_QUANTIZATION > 0), THE_QUANTIZATION_OF_THE_PHASE_FUNCTION_NEEDS_TO_BE_BETWEEN_1_AND_8);

	// Constants
	const bool IS_SIGNED = std::numeric_limits<ScalarType>::is_signed;
	const vx_type_e SCALAR_TYPE = GET_TYPE(ScalarType);

	// Convert for computation
	const vx_int64 a = static_cast<vx_int64>(input1);
	const vx_int64 b = static_cast<vx_int64>(input2);

	// Get (Max and Min)
	const vx_int64 MIN_VAL = static_cast<vx_int64>(ComputeMin<ScalarType>());
	const vx_int64 MAX_VAL = static_cast<vx_int64>(ComputeMax<ScalarType>());

	// Result
	vx_int64 result = 0;

	// ABSOLUTE_DIFFERENCE
	if (OPERATION_TYPE == HIFLIPVX::ABSOLUTE_DIFFERENCE)
	{
		const vx_int64 c = abs(a - b);

		if (IS_SIGNED)
		{
			if (CONV_POLICY == VX_CONVERT_POLICY_SATURATE)
				result = MIN(c, MAX_VAL);
			else if (CONV_POLICY == VX_CONVERT_POLICY_WRAP)
				result = c;
		}
		else
		{
			if (CONV_POLICY == VX_CONVERT_POLICY_SATURATE)
				result = c;
			else if (CONV_POLICY == VX_CONVERT_POLICY_WRAP)
				result = c;
		}

		// ARITHMETIC_ADDITION
	}
	else if (OPERATION_TYPE == HIFLIPVX::ARITHMETIC_ADDITION)
	{
		const vx_int64 c = a + b;

		if (IS_SIGNED)
		{
			if (CONV_POLICY == VX_CONVERT_POLICY_SATURATE)
				result = SaturateMaxMin<vx_int64>(c, MAX_VAL, MIN_VAL);
			else if (CONV_POLICY == VX_CONVERT_POLICY_WRAP)
				result = c;
		}
		else
		{
			if (CONV_POLICY == VX_CONVERT_POLICY_SATURATE)
				result = MIN(c, MAX_VAL);
			else if (CONV_POLICY == VX_CONVERT_POLICY_WRAP)
				result = c;
		}

		// ARITHMETIC_SUBTRACTION
	}
	else if (OPERATION_TYPE == HIFLIPVX::ARITHMETIC_SUBTRACTION)
	{
		const vx_int64 c = a - b;

		if (IS_SIGNED)
		{
			if (CONV_POLICY == VX_CONVERT_POLICY_SATURATE)
				result = SaturateMaxMin<vx_int64>(c, MAX_VAL, MIN_VAL);
			else if (CONV_POLICY == VX_CONVERT_POLICY_WRAP)
				result = c;
		}
		else
		{
			if (CONV_POLICY == VX_CONVERT_POLICY_SATURATE)
				result = MAX(c, MIN_VAL);
			else if (CONV_POLICY == VX_CONVERT_POLICY_WRAP)
				result = c;
		}

		// MAGNITUDE
	}
	else if (OPERATION_TYPE == HIFLIPVX::MAGNITUDE)
	{
		if (SCALAR_TYPE == VX_TYPE_INT8)
			result = MagnitudeSigned<ScalarType, vx_uint8, vx_int16, vx_uint16, CONV_POLICY, ROUND_POLICY>(input1, input2);
		else if (SCALAR_TYPE == VX_TYPE_INT16)
			result = MagnitudeSigned<ScalarType, vx_uint16, vx_int32, vx_uint32, CONV_POLICY, ROUND_POLICY>(input1, input2);
		else if (SCALAR_TYPE == VX_TYPE_INT32)
			result = MagnitudeSigned<ScalarType, vx_uint32, vx_int64, vx_uint64, CONV_POLICY, ROUND_POLICY>(input1, input2);
		else if (SCALAR_TYPE == VX_TYPE_UINT8)
			result = MagnitudeUnsigned<ScalarType, vx_uint16, CONV_POLICY, ROUND_POLICY>(input1, input2);
		else if (SCALAR_TYPE == VX_TYPE_UINT16)
			result = MagnitudeUnsigned<ScalarType, vx_uint32, CONV_POLICY, ROUND_POLICY>(input1, input2);
		else if (SCALAR_TYPE == VX_TYPE_UINT32)
			result = MagnitudeUnsigned<ScalarType, vx_uint64, CONV_POLICY, ROUND_POLICY>(input1, input2);

		// MULTIPLY
	}
	else if (OPERATION_TYPE == HIFLIPVX::MULTIPLY)
	{
		if (IS_SIGNED)
		{
			result = Multiply<ScalarType, vx_int64, IS_SIGNED, SCALAR_TYPE, CONV_POLICY, ROUND_POLICY, SCALE>(input1, input2);
		}
		else
		{
			result = Multiply<ScalarType, vx_uint64, IS_SIGNED, SCALAR_TYPE, CONV_POLICY, ROUND_POLICY, SCALE>(input1, input2);
		}

		// THRESHOLD
	}
	else if (OPERATION_TYPE == HIFLIPVX::THRESHOLD)
	{
		if (IS_SIGNED == true)
		{
			if (THRESH_TYPE == VX_THRESHOLD_TYPE_BINARY)
				result = (input1 > THRESH_VALUE) ? (-1) : (0);
			else if (THRESH_TYPE == VX_THRESHOLD_TYPE_RANGE)
				result = ((input1 > THRESH_UPPER) || (input1 < THRESH_LOWER)) ? (0) : (-1);
		}
		else
		{
			if (THRESH_TYPE == VX_THRESHOLD_TYPE_BINARY)
				result = (input1 > THRESH_VALUE) ? (MAX_VAL) : (0);
			else if (THRESH_TYPE == VX_THRESHOLD_TYPE_RANGE)
				result = ((input1 > THRESH_UPPER) || (input1 < THRESH_LOWER)) ? (0) : (MAX_VAL);
		}

		// WEIGHTED AVERAGE
	}
	else if (OPERATION_TYPE == HIFLIPVX::WEIGHTED_AVERAGE)
	{
		vx_int64 alpha = ALPHA;
		vx_int64 one = (1 << 16);
		vx_int64 half = (1 << 15);
		vx_int64 src1 = input1;
		vx_int64 src2 = input2;
		if (ROUND_POLICY == VX_ROUND_POLICY_TO_ZERO)
		{
			result = ((one - alpha) * src2 + alpha * src1);
			result = ShiftArithmeticRight<vx_int64, IS_SIGNED>(result, 16);
		}
		else if (ROUND_POLICY == VX_ROUND_POLICY_TO_NEAREST_EVEN)
		{
			result = ((one - alpha) * src2 + alpha * src1 + half);
			result = ShiftArithmeticRight<vx_int64, IS_SIGNED>(result, 16);
		}

		// PHASE
	}
	else if (OPERATION_TYPE == HIFLIPVX::PHASE)
	{
		if ((SCALAR_TYPE == VX_TYPE_UINT8) || (SCALAR_TYPE == VX_TYPE_INT8))
		{
			result = Phase<ScalarType, vx_int16, PHASE_QUANTIZATION>((vx_int16)input1, (vx_int16)input2);
		}
		else if ((SCALAR_TYPE == VX_TYPE_UINT16) || (SCALAR_TYPE == VX_TYPE_INT16))
		{
			result = Phase<ScalarType, vx_int32, PHASE_QUANTIZATION>((vx_int32)input1, (vx_int32)input2);
		}
		else if ((SCALAR_TYPE == VX_TYPE_UINT32) || (SCALAR_TYPE == VX_TYPE_INT32))
		{
			result = Phase<ScalarType, vx_int64, PHASE_QUANTIZATION>((vx_int64)input1, (vx_int64)input2);
		}
	}

	return static_cast<ScalarType>(result);
}

/***************************************************************************************************************************************************/
/* Pixelwise Operations */
/***************************************************************************************************************************************************/

/** @brief Performs a pixelwise operation on an image or between two images
@param ScalarType      Data type of the image pixels
@param OPERATION_TYPE  Operation type (e.g. bitwise or, and, xor, not | arithmetic add, sub, mul)
@param CONV_POLICY     Conversion policy (wrap & saturate)
@param ROUND_POLICY    Rounding policy (to zero & nearest even)
@param SCALE           A positive fixed-point (16-bit fraction) number multiplied to each product before overflow handling (between 0.0 and 1.0)
@param src1            1. input pixel
@param src2            2. input pixel
@param dst             result
*/
template <typename ScalarType, HIFLIPVX::PixelwiseOperationA OPERATION_TYPE, vx_convert_policy_e CONV_POLICY, vx_round_policy_e ROUND_POLICY,
		  vx_uint32 SCALE, vx_threshold_type_e THRESH_TYPE, ScalarType THRESH_VALUE, ScalarType THRESH_UPPER, ScalarType THRESH_LOWER, vx_uint32 ALPHA,
		  vx_uint8 PHASE_QUANTIZATION>
void PixelwiseComputeSameType(ScalarType src1, ScalarType src2, ScalarType &dst)
{
#pragma HLS INLINE

	// Constants
	const bool is_arithmetic_operation = ((OPERATION_TYPE == HIFLIPVX::ABSOLUTE_DIFFERENCE) || (OPERATION_TYPE == HIFLIPVX::ARITHMETIC_ADDITION) ||
										  (OPERATION_TYPE == HIFLIPVX::ARITHMETIC_SUBTRACTION) || (OPERATION_TYPE == HIFLIPVX::MULTIPLY) || (OPERATION_TYPE == HIFLIPVX::MAGNITUDE) ||
										  (OPERATION_TYPE == HIFLIPVX::THRESHOLD) || (OPERATION_TYPE == HIFLIPVX::WEIGHTED_AVERAGE) || (OPERATION_TYPE == HIFLIPVX::PHASE));

	// Copy a data object to another.
	if (OPERATION_TYPE == HIFLIPVX::COPY_DATA)
		dst = src1;

	// Performs a bitwise NOT operation on a input images.
	else if (OPERATION_TYPE == HIFLIPVX::BITWISE_NOT)
		dst = ~(src1);

	// Performs a bitwise AND operation between two unsigned images.
	else if (OPERATION_TYPE == HIFLIPVX::BITWISE_AND)
		dst = src1 & src2;

	// Performs a bitwise INCLUSIVE OR operation between two unsigned images.
	else if (OPERATION_TYPE == HIFLIPVX::BITWISE_OR)
		dst = src1 | src2;

	// Performs a bitwise EXCLUSIVE OR (XOR) operation between two unsigned images.
	else if (OPERATION_TYPE == HIFLIPVX::BITWISE_XOR)
		dst = src1 ^ src2;

	// Implements a pixel-wise maximum kernel.
	else if (OPERATION_TYPE == HIFLIPVX::MAX)
		dst = MAX(src1, src2);

	// Implements a pixel - wise minimum kernel.
	else if (OPERATION_TYPE == HIFLIPVX::MIN)
		dst = MIN(src1, src2);

	// Computes arithmetic operations
	else if (is_arithmetic_operation == true)
		dst = Arithmetic<ScalarType, OPERATION_TYPE, CONV_POLICY, ROUND_POLICY, SCALE, THRESH_TYPE, THRESH_VALUE, THRESH_UPPER, THRESH_LOWER, ALPHA,
						 PHASE_QUANTIZATION>(src1, src2);

	// Operation not found
	else
		dst = 0;
}

/** @brief  Checks if the input parameters are valid
@param ScalarType      Data type of the image pixels
@param VEC_SIZE        Amount of pixels computed in parallel
@param IMG_PIXEL       Amount of pixels in the image
@return                Data beats (IMG_PIXEL / VEC_SIZE)
*/
template <typename ScalarType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL>
vx_uint32 PixelwiseCheckSameType()
{
#pragma HLS INLINE

	// Constants
	const vx_type_e SCALAR_TYPE = GET_TYPE(ScalarType);
	const bool SCALAR_TYPE_CORRECT =
		(SCALAR_TYPE == VX_TYPE_UINT8) || (SCALAR_TYPE == VX_TYPE_UINT16) || (SCALAR_TYPE == VX_TYPE_UINT32) ||
		(SCALAR_TYPE == VX_TYPE_INT8) || (SCALAR_TYPE == VX_TYPE_INT16) || (SCALAR_TYPE == VX_TYPE_INT32);

	// Check function parameters/types
	STATIC_ASSERT(SCALAR_TYPE_CORRECT, data_type_error__uint_and_int_8_to_32_bit_allowed);
	STATIC_ASSERT((IMG_PIXEL % VEC_SIZE) == 0, image_pixels_are_not_multiple_of_vector_size);
	STATIC_ASSERT((VEC_SIZE == 1) || (VEC_SIZE == 2) || (VEC_SIZE == 4) || (VEC_SIZE == 8), _vec_size_musst_be_1_2_4_8__use_vx_image_for_2_4_8);

	// Return vector pixel
	return IMG_PIXEL / static_cast<vx_uint32>(VEC_SIZE);
}

/***************************************************************************************************************************************************/
/* Pixelwise Same Data Type */
/***************************************************************************************************************************************************/

/** @brief Performs a pixelwise operation on an image or between two images (Top function)
@param ScalarType         Data type of the image pixels
@param VEC_SIZE           Amount of pixels computed in parallel
@param IMG_PIXEL          Amount of pixels in the image
@param OPERATION_TYPE     Operation type (e.g. bitwise or, and, xor, not | arithmetic add, sub, mul)
@param CONV_POLICY        Conversion policy (wrap & saturate)
@param ROUND_POLICY       Rounding policy (to zero & nearest even)
@param SCALE              A positive fixed-point (16-bit fraction) number multiplied to each product before overflow handling (between 0.0 and 1.0)
@param THRESH_TYPE        The type of thresholding (VX_THRESHOLD_TYPE_BINARY, VX_THRESHOLD_TYPE_RANGE)
@param THRESH_VALUE       The threshold value if threshold type is VX_THRESHOLD_TYPE_BINARY
@param THRESH_UPPER       The upper threshold value if threshold type is VX_THRESHOLD_TYPE_RANGE
@param THRESH_LOWER       The lower threshold value if threshold type is VX_THRESHOLD_TYPE_RANGE
@param ALPHA              The weighted value in fixed-point between 0 and 1 using 16-bit fraction
@param PHASE_QUANTIZATION The quantization for the different amount of orientations
@param input1             1. input image
@param input2             2. input image
@param output             Output image
*/
template <typename ScalarType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL, HIFLIPVX::PixelwiseOperationA OPERATION_TYPE, vx_convert_policy_e CONV_POLICY,
		  vx_round_policy_e ROUND_POLICY, vx_uint32 SCALE, vx_threshold_type_e THRESH_TYPE, ScalarType THRESH_VALUE, ScalarType THRESH_UPPER,
		  ScalarType THRESH_LOWER, vx_uint32 ALPHA, vx_uint8 PHASE_QUANTIZATION>
void PixelwiseSameType(
	vx_image_data<ScalarType, VEC_SIZE> input1[IMG_PIXEL / VEC_SIZE],
	vx_image_data<ScalarType, VEC_SIZE> input2[IMG_PIXEL / VEC_SIZE],
	vx_image_data<ScalarType, VEC_SIZE> output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE

	// Check if input correct
	const vx_uint32 vector_pixels = PixelwiseCheckSameType<ScalarType, VEC_SIZE, IMG_PIXEL>();

	// Computes pixelwise operations (pipelined)
	for (vx_uint32 i = 0; i < vector_pixels; i++)
	{
#pragma HLS PIPELINE II = 1

		// Variables
		vx_image_data<ScalarType, VEC_SIZE> src1, src2, dst;

		// Read input
		src1 = input1[i];
		if ((OPERATION_TYPE != HIFLIPVX::BITWISE_NOT) || (OPERATION_TYPE == HIFLIPVX::COPY_DATA) || (OPERATION_TYPE == HIFLIPVX::THRESHOLD))
			src2 = input2[i];

		// Computes a vector of pixelwise operations in parallel
		for (vx_uint16 j = 0; j < VEC_SIZE; j++)
		{
#pragma HLS unroll
			PixelwiseComputeSameType<ScalarType, OPERATION_TYPE, CONV_POLICY, ROUND_POLICY, SCALE, THRESH_TYPE, THRESH_VALUE, THRESH_UPPER,
									 THRESH_LOWER, ALPHA, PHASE_QUANTIZATION>(src1.pixel[j], src2.pixel[j], dst.pixel[j]);
		}

		// Set user(SOF) & last(EOF)
		GenerateDmaSignal<ScalarType, VEC_SIZE>((i == 0), (i == vector_pixels - 1), dst);

		// Write output
		output[i] = dst;
	}
}
template <typename ScalarType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL, HIFLIPVX::PixelwiseOperationA OPERATION_TYPE, vx_convert_policy_e CONV_POLICY,
		  vx_round_policy_e ROUND_POLICY, vx_uint32 SCALE, vx_threshold_type_e THRESH_TYPE, ScalarType THRESH_VALUE, ScalarType THRESH_UPPER,
		  ScalarType THRESH_LOWER, vx_uint32 ALPHA, vx_uint8 PHASE_QUANTIZATION>
void PixelwiseSameType(
	ScalarType input1[IMG_PIXEL / VEC_SIZE],
	ScalarType input2[IMG_PIXEL / VEC_SIZE],
	ScalarType output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE

	// Check if input correct
	const vx_uint32 vector_pixels = PixelwiseCheckSameType<ScalarType, VEC_SIZE, IMG_PIXEL>();

	// Computes pixelwise operations (pipelined)
	for (vx_uint32 i = 0; i < vector_pixels; i++)
	{
#pragma HLS PIPELINE II = 1

		// Variables
		ScalarType src1 = 0, src2 = 0, dst = 0;

		// Read input
		src1 = input1[i];
		if ((OPERATION_TYPE != HIFLIPVX::BITWISE_NOT) || (OPERATION_TYPE == HIFLIPVX::COPY_DATA) || (OPERATION_TYPE == HIFLIPVX::THRESHOLD))
			src2 = input2[i];

		// Computes a vector of pixelwise operations in parallel
		PixelwiseComputeSameType<ScalarType, OPERATION_TYPE, CONV_POLICY, ROUND_POLICY, SCALE, THRESH_TYPE, THRESH_VALUE, THRESH_UPPER, THRESH_LOWER,
								 ALPHA, PHASE_QUANTIZATION>(src1, src2, dst);

		// Write output
		output[i] = dst;
	}
}

/*********************************************************************************************************************/
/* Linebuffer Functions */
/*********************************************************************************************************************/

/** @brief Reads data from line buffers
@param VecType     1 vector is 1 linebuffer element
@param KERN_SIZE   The size of the filter kernel
@param VEC_COLS    The amount of columns in the vectorized image
@param input       New image data to be stored into the linebuffer
@param linebuffer  Linebuffers to store (KERN_SIZE-1) image rows
@param output      Data at x coordinates in the linebuffers
@param x           The x coordinate in the vectorized image
*/
template <typename InType, typename BufferType, const vx_uint16 BUFFER_NUM, const vx_uint8 VEC_NUM, const vx_uint16 KERN_SIZE, const vx_uint16 VEC_COLS>
void ReadFromLineBuffer(InType input[VEC_NUM], BufferType linebuffer[BUFFER_NUM][VEC_COLS], InType output[KERN_SIZE][VEC_NUM], const vx_uint16 x)
{
#pragma HLS INLINE

	// For data type conversion to decrease BRAM usage: FACTOR*BUFFER_NUM = (KERN_SIZE-1)*VEC_NUM
	const vx_uint16 FACTOR = sizeof(BufferType) / sizeof(InType);

	// Buffer for data type conversion
	BufferType buffer1[BUFFER_NUM];
#pragma HLS array_partition variable = buffer1 complete dim = 0
	InType buffer2[BUFFER_NUM * FACTOR];
#pragma HLS array_partition variable = buffer2 complete dim = 0

	// Check linebuffer border
	if (x < VEC_COLS)
	{

		// Read data from linebuffer
		for (vx_uint16 i = 0; i < BUFFER_NUM; i++)
		{
#pragma HLS unroll
			buffer1[i] = linebuffer[i][x];
		}

		// Unpack data
		for (vx_uint16 i = 0; i < BUFFER_NUM; i++)
		{
#pragma HLS unroll
			for (vx_uint16 j = 0; j < FACTOR; j++)
			{
#pragma HLS unroll
				vx_uint16 shift = j * static_cast<vx_uint16>(sizeof(InType)) * static_cast<vx_uint16>(8);
				buffer2[i * FACTOR + j] = static_cast<InType>(buffer1[i] >> shift);
			}
		}

		// Pack data for output
		for (vx_uint16 i = 0; i < KERN_SIZE - 1; i++)
		{
#pragma HLS unroll
			for (vx_uint16 j = 0; j < VEC_NUM; j++)
			{
#pragma HLS unroll
				output[i][j] = buffer2[i * VEC_NUM + j];
			}
		}
		for (vx_uint16 j = 0; j < VEC_NUM; j++)
		{
#pragma HLS UNROLL
			output[KERN_SIZE - 1][j] = input[j];
		}
	}
}

/** @brief Writes data to line buffers
@param VecType     1 vector is 1 linebuffer element
@param KERN_SIZE   The size of the filter kernel
@param VEC_COLS    The amount of columns in the vectorized image
@param input       Stores data at the x coordinates of the linebuffers
@param linebuffer  Linebuffers to store (KERN_SIZE-1) image rows
@param x           The x coordinate in the vectorized image
*/
template <typename InType, typename BufferType, const vx_uint16 BUFFER_NUM, const vx_uint8 VEC_NUM, const vx_uint16 KERN_SIZE, const vx_uint16 VEC_COLS>
void WriteToLineBuffer(InType input[KERN_SIZE][VEC_NUM], BufferType linebuffer[BUFFER_NUM][VEC_COLS], const vx_uint16 x)
{
#pragma HLS INLINE

	// For data type conversion to decrease BRAM usage: FACTOR*BUFFER_NUM = (KERN_SIZE-1)*VEC_NUM
	const vx_uint16 FACTOR = sizeof(BufferType) / sizeof(InType);

	// Buffer for data type conversion
	InType buffer1[(KERN_SIZE - 1) * VEC_NUM];
#pragma HLS array_partition variable = buffer1 complete dim = 0
	BufferType buffer2[BUFFER_NUM];
#pragma HLS array_partition variable = buffer2 complete dim = 0

	// Check linebuffer border
	if (x < VEC_COLS)
	{

		// Unpack data from input
		for (vx_uint16 i = 0; i < KERN_SIZE - 1; i++)
		{
#pragma HLS unroll
			for (vx_uint16 j = 0; j < VEC_NUM; j++)
			{
#pragma HLS unroll
				buffer1[i * VEC_NUM + j] = input[i + 1][j];
			}
		}

		// Pack data for linebuffer
		for (vx_uint16 i = 0; i < BUFFER_NUM; i++)
		{
#pragma HLS unroll
			BufferType data = 0;
			for (vx_uint16 j = 0; j < FACTOR; j++)
			{
#pragma HLS unroll
				vx_uint16 shift = j * static_cast<vx_uint16>(sizeof(InType)) * static_cast<vx_uint16>(8);
				data |= (static_cast<BufferType>(buffer1[i * FACTOR + j])) << shift;
			}
			buffer2[i] = data;
		}

		// Write to linebuffer
		for (vx_uint16 i = 0; i < BUFFER_NUM; i++)
		{
#pragma HLS unroll
			linebuffer[i][x] = buffer2[i];
		}
	}
}

/*********************************************************************************************************************/
/* Sliding Window Functions for Different Border Types */
/*********************************************************************************************************************/

/** @brief Replicates the y borders if needed for the sliding window
@param VecType     1 vector is 1 linebuffer element
@param IMG_ROWS    Amount of rows in the image
@param KERN_RAD    Radius of the filter kernel
@param KERN_SIZE   Total amount of rows in the sliding window
@param input       Output of the linebuffers
@param output      Input with replicated borders if needed
@param y           y coordinate of the image
*/
template <typename InType, const vx_uint8 VEC_NUM, const vx_uint32 IMG_ROWS, const vx_uint16 KERN_RAD, const vx_uint16 KERN_SIZE>
void SlidingWindowReplicatedY(const InType input[KERN_SIZE][VEC_NUM], InType output[KERN_SIZE][VEC_NUM], const vx_uint16 y)
{
#pragma HLS INLINE

	// Get upper pixels and check y border
	if (KERN_RAD > 0)
	{
		for (vx_uint16 v = 0; v < VEC_NUM; v++)
		{
#pragma HLS UNROLL
			output[KERN_RAD - 1][v] = (y > KERN_RAD) ? (input[KERN_RAD - 1][v]) : (input[KERN_RAD][v]);
		}
		// output[KERN_RAD - 1] = (y > KERN_RAD) ? (input[KERN_RAD - 1]) : (input[KERN_RAD]);
		for (vx_int32 i = KERN_RAD - 2; i >= 0; i--)
		{
#pragma HLS UNROLL
			for (vx_uint16 v = 0; v < VEC_NUM; v++)
			{
#pragma HLS UNROLL
				output[i][v] = (y > static_cast<vx_uint16>(KERN_SIZE - 2 - i)) ? (input[i][v]) : (output[i + 1][v]);
			}
		}
	}

	// Pass through observed pixel in the image
	for (vx_uint16 v = 0; v < VEC_NUM; v++)
	{
#pragma HLS UNROLL
		output[KERN_RAD][v] = input[KERN_RAD][v];
	}

	// Get lower pixels and check y border
	if (KERN_RAD > 0)
	{
		for (vx_uint16 v = 0; v < VEC_NUM; v++)
		{
#pragma HLS UNROLL
			output[KERN_RAD + 1][v] = (y < IMG_ROWS + KERN_RAD - 1) ? (input[KERN_RAD + 1][v]) : (input[KERN_RAD][v]);
		}
		for (vx_uint16 i = KERN_RAD + 2; i < KERN_SIZE; i++)
		{
#pragma HLS UNROLL
			for (vx_uint16 v = 0; v < VEC_NUM; v++)
			{
#pragma HLS UNROLL
				output[i][v] = (y < static_cast<vx_uint16>(IMG_ROWS + KERN_SIZE - 1 - i)) ? (input[i][v]) : (output[i - 1][v]);
			}
		}
	}
}

/** @brief Moves sliding window and a replicated border in x direction
@param ScalarType  The data type of the image elements
@param KERN_SIZE   Total amount of rows in the sliding window
@param VEC_COLS    The amount of columns in the vectorized image
@param VEC_SIZE    The number of elements in a vector
@param WIN_BORD_A  Internal vertical border for the sliding window
@param WIN_BORD_B  Internal vertical border for the sliding window
@param WIN_COLS    The number of columns in a row
@param input       An array of input data for each row
@param window      The sliding window
@param x           x coordinate of the vectorized image
*/
template <typename ScalarType, const vx_uint16 KERN_SIZE, const vx_uint16 VEC_COLS, const vx_uint16 VEC_SIZE, const vx_uint16 WIN_BORD_A, const vx_uint16 WIN_BORD_B, const vx_uint16 WIN_COLS>
void SlidingWindowReplicatedX(ScalarType input[KERN_SIZE][VEC_SIZE], ScalarType window[KERN_SIZE][WIN_COLS], const vx_uint16 x)
{
#pragma HLS INLINE

	// Move sliding window and check x border
	for (vx_uint16 i = 0; i < KERN_SIZE; i++)
	{
#pragma HLS unroll

		// Move sliding window
		for (vx_uint16 j = 0; j < WIN_BORD_A; j++)
		{
#pragma HLS unroll
			window[i][j] = window[i][j + VEC_SIZE];
		}

		// Move pixel in sliding window and get/check left x border
		for (vx_uint16 j = WIN_BORD_A; j < WIN_BORD_B; j++)
		{
#pragma HLS unroll
			if (x == 0)
				window[i][j] = input[i][0];
			else
				window[i][j] = window[i][j + VEC_SIZE];
		}

		// Get new pixel array and check right x border
		for (vx_uint16 j = WIN_BORD_B; j < WIN_COLS; j++)
		{
#pragma HLS unroll
			if (x >= VEC_COLS)
			{
				window[i][j] = window[i][WIN_BORD_B - 1];
			}
			else
			{
				window[i][j] = input[i][j - WIN_BORD_B];
			}
		}
	}
}

/** @brief Sets a constant border of 0 for the sliding window
@param VecType     1 vector is 1 linebuffer element
@param IMG_ROWS    Amount of rows in the image
@param KERN_RAD    Radius of the filter kernel
@param KERN_SIZE   Total amount of rows in the sliding window
@param input       Output of the linebuffers
@param output      Input with replicated borders if needed
@param y           y coordinate of the image
*/
template <typename InType, const vx_uint8 VEC_NUM, const vx_uint32 IMG_ROWS, const vx_uint16 KERN_RAD, const vx_uint16 KERN_SIZE>
void SlidingWindowConstantY(const InType input[KERN_SIZE][VEC_NUM], InType output[KERN_SIZE][VEC_NUM], const vx_uint16 y)
{
#pragma HLS INLINE

	// Get upper pixels and check y border
	for (vx_uint16 i = 0; i < KERN_RAD; i++)
	{
#pragma HLS unroll
		for (vx_uint16 v = 0; v < VEC_NUM; v++)
		{
#pragma HLS UNROLL
			output[i][v] = (y > KERN_SIZE - 2 - i) ? (input[i][v]) : (0);
		}
	}

	// Pass through observed pixel in the image
	for (vx_uint16 v = 0; v < VEC_NUM; v++)
	{
#pragma HLS UNROLL
		output[KERN_RAD][v] = input[KERN_RAD][v];
	}

	// Get lower pixels and check y border
	for (vx_uint16 i = KERN_RAD + 1; i < KERN_SIZE; i++)
	{
#pragma HLS unroll
		for (vx_uint16 v = 0; v < VEC_NUM; v++)
		{
#pragma HLS UNROLL
			output[i][v] = (y < IMG_ROWS + KERN_SIZE - 1 - i) ? (input[i][v]) : (0);
		}
	}
}

/** @brief Moves sliding window and a constant border in x direction
@param ScalarType  The data type of the image elements
@param KERN_SIZE   Total amount of rows in the sliding window
@param VEC_COLS    The amount of columns in the vectorized image
@param VEC_SIZE    The number of elements in a vector
@param WIN_BORD_A  Internal vertical border for the sliding window
@param WIN_BORD_B  Internal vertical border for the sliding window
@param WIN_COLS    The number of columns in a row
@param input       An array of input data for each row
@param window      The sliding window
@param x           x coordinate of the vectorized image
*/
template <typename ScalarType, const vx_uint16 KERN_SIZE, const vx_uint16 VEC_COLS, const vx_uint16 VEC_SIZE, const vx_uint16 WIN_BORD_A, const vx_uint16 WIN_BORD_B, const vx_uint16 WIN_COLS>
void SlidingWindowConstantX(ScalarType input[KERN_SIZE][VEC_SIZE], ScalarType window[KERN_SIZE][WIN_COLS], const vx_uint16 x)
{
#pragma HLS INLINE

	for (vx_uint16 i = 0; i < KERN_SIZE; i++)
	{
#pragma HLS unroll

		// Move sliding window
		for (vx_uint16 j = 0; j < WIN_BORD_A; j++)
		{
#pragma HLS unroll
			window[i][j] = window[i][j + VEC_SIZE];
		}

		// Move pixel in sliding window and get/check left x border
		for (vx_uint16 j = WIN_BORD_A; j < WIN_BORD_B; j++)
		{
#pragma HLS unroll
			if (x == 0)
				window[i][j] = 0;
			else
				window[i][j] = window[i][j + VEC_SIZE];
		}

		// Get new pixel vector and check right x border
		for (vx_uint16 j = WIN_BORD_B; j < WIN_COLS; j++)
		{
#pragma HLS unroll
			if (x >= VEC_COLS)
				window[i][j] = 0;
			else
				window[i][j] = input[i][j - WIN_BORD_B];
		}
	}
}

/** @brief Moves sliding window without considering borders
@param ScalarType  The data type of the image elements
@param KERN_SIZE   Total amount of rows in the sliding window
@param VEC_SIZE    The number of elements in a vector
@param WIN_BORD_B  Internal vertical border for the sliding window
@param WIN_COLS    The number of columns in a row
@param input       An array of input data for each row
@param window      The sliding window
*/
template <typename ScalarType, const vx_uint16 KERN_SIZE, const vx_uint16 VEC_SIZE, const vx_uint16 WIN_BORD_B, const vx_uint16 WIN_COLS>
void SlidingWindowUnchanged(const ScalarType input[KERN_SIZE][VEC_SIZE], ScalarType window[KERN_SIZE][WIN_COLS])
{
#pragma HLS INLINE

	for (vx_uint16 i = 0; i < KERN_SIZE; i++)
	{
#pragma HLS unroll

		// Move sliding window
		for (vx_uint16 j = 0; j < WIN_BORD_B; j++)
		{
#pragma HLS unroll
			window[i][j] = window[i][j + VEC_SIZE];
		}

		// Get new pixel vector
		for (vx_uint16 j = WIN_BORD_B; j < WIN_COLS; j++)
		{
#pragma HLS unroll
			window[i][j] = input[i][j - WIN_BORD_B];
		}
	}
}

/*********************************************************************************************************************/
/* Main sliding Window Functions */
/*********************************************************************************************************************/

/** @brief Sliding window horizontal main function / considers different border types
@param VecType     1 vector is processed in each clock cycle
@param ScalarType  1 vector contains N scalar elements
@param KERN_RAD    Radius of the filter kernel
@param VEC_COLS    The amount of columns in the vectorized image
@param VEC_SIZE    The number of elements in a vector
@param WIN_COLS    The number of columns in a row
@param BORDER_TYPE The border type that is considered in the sliding window
@param input       The input buffer
@param window      The output sliding window
@param x           The x current coordinate
*/
template <typename ScalarType, const vx_uint16 KERN_RAD, const vx_uint16 VEC_COLS, const vx_uint16 VEC_SIZE, const vx_uint16 WIN_COLS, const vx_border_e BORDER_TYPE>
void SlidingWindowHorizontal(const ScalarType input[VEC_SIZE], ScalarType window[1][WIN_COLS], const vx_uint16 x)
{
#pragma HLS INLINE

	// Constants
	const vx_uint16 WIN_BORD_A = WIN_COLS - VEC_SIZE - KERN_RAD;
	const vx_uint16 WIN_BORD_B = WIN_COLS - VEC_SIZE;

	// Input data rows in scalar representation (after considering y border)
	ScalarType input_vector[1][VEC_SIZE];
#pragma HLS array_partition variable = input_vector complete dim = 0

	for (vx_uint16 i = 0; i < VEC_SIZE; i++)
	{
#pragma HLS unroll
		input_vector[0][i] = input[i];
	}

	// REPLICATED: replicates the border values when exceeding borders
	if (BORDER_TYPE == VX_BORDER_REPLICATE)
	{

		// Sets sliding window and replicated x borders
		SlidingWindowReplicatedX<ScalarType, 1, VEC_COLS, VEC_SIZE, WIN_BORD_A, WIN_BORD_B, WIN_COLS>(input_vector, window, x);

		// CONSTANT: creates a constant border of zeros around the image
	}
	else if (BORDER_TYPE == VX_BORDER_CONSTANT)
	{

		// Sets sliding window and constant x borders
		SlidingWindowConstantX<ScalarType, 1, VEC_COLS, VEC_SIZE, WIN_BORD_A, WIN_BORD_B, WIN_COLS>(input_vector, window, x);

		// UNCHANGED: filters exceeding the borders are invalid
	}
	else if (BORDER_TYPE == VX_BORDER_UNDEFINED)
	{

		// Sets sliding window and does not create borders
		SlidingWindowUnchanged<ScalarType, 1, VEC_SIZE, WIN_BORD_B, WIN_COLS>(input_vector, window);
	}
}

/** @brief Sliding window main function / considers different border types
@param VecType     1 vector is processed in each clock cycle
@param ScalarType  1 vector contains N scalar elements
@param IMG_ROWS    Amount of rows in the image
@param KERN_RAD    Radius of the filter kernel
@param VEC_SIZE    The number of elements in a vector
@param KERN_SIZE   Total amount of rows in the sliding window
@param BORDER_TYPE The border type that is considered in the sliding window
@param input       The input buffer
@param window      The output sliding window
@param y           The y current coordinate
*/
template <typename ScalarType, const vx_uint32 IMG_ROWS, const vx_uint16 KERN_RAD, const vx_uint16 VEC_SIZE, const vx_uint16 KERN_SIZE, const vx_border_e BORDER_TYPE>
void SlidingWindowVertical(const ScalarType input[KERN_SIZE][VEC_SIZE], ScalarType window[KERN_SIZE][VEC_SIZE], const vx_uint16 y)
{
#pragma HLS INLINE

	// Input data rows in vector representation (after considering y border)
	ScalarType buffer_vector[KERN_SIZE][VEC_SIZE];
#pragma HLS array_partition variable = buffer_vector complete dim = 0

	// REPLICATED: replicates the border values when exceeding borders
	if (BORDER_TYPE == VX_BORDER_REPLICATE)
	{

		// Replicated y borders
		SlidingWindowReplicatedY<ScalarType, VEC_SIZE, IMG_ROWS, KERN_RAD, KERN_SIZE>(input, buffer_vector, y);

		// CONSTANT: creates a constant border of zeros around the image
	}
	else if (BORDER_TYPE == VX_BORDER_CONSTANT)
	{

		// Constant y borders
		SlidingWindowConstantY<ScalarType, VEC_SIZE, IMG_ROWS, KERN_RAD, KERN_SIZE>(input, buffer_vector, y);
	}

	// Convert from vector to scalar type
	for (vx_uint16 i = 0; i < KERN_SIZE; i++)
	{
#pragma HLS UNROLL
		for (vx_uint16 j = 0; j < VEC_SIZE; j++)
		{
#pragma HLS UNROLL
			if (BORDER_TYPE == VX_BORDER_REPLICATE || BORDER_TYPE == VX_BORDER_CONSTANT)
				window[i][j] = buffer_vector[i][j];
			else if (BORDER_TYPE == VX_BORDER_UNDEFINED)
				window[i][j] = input[i][j];
		}
	}
}

/** @brief Sliding window main function / considers different border types
@param VecType     1 vector is processed in each clock cycle
@param ScalarType  1 vector contains N scalar elements
@param IMG_ROWS    Amount of rows in the image
@param KERN_RAD    Radius of the filter kernel
@param VEC_COLS    The amount of columns in the vectorized image
@param VEC_SIZE    The number of elements in a vector
@param WIN_COLS    The number of columns in a row
@param KERN_SIZE   Total amount of rows in the sliding window
@param BORDER_TYPE The border type that is considered in the sliding window
@param input       The input buffer
@param window      The output sliding window
@param x           The x current coordinate
@param y           The y current coordinate
*/
template <typename InType, const vx_uint8 VEC_NUM, const vx_uint32 IMG_ROWS, const vx_uint16 KERN_RAD, const vx_uint16 VEC_COLS, const vx_uint16 WIN_COLS, const vx_uint16 KERN_SIZE, const vx_border_e BORDER_TYPE>
void SlidingWindow(const InType input[KERN_SIZE][VEC_NUM], InType window[KERN_SIZE][WIN_COLS], const vx_uint16 x, const vx_uint16 y)
{
#pragma HLS INLINE

	// Constants
	const vx_uint16 WIN_BORD_A = WIN_COLS - VEC_NUM - KERN_RAD;
	const vx_uint16 WIN_BORD_B = WIN_COLS - VEC_NUM;

	// Input data rows in vector representation (after considering y border)
	InType buffer_vector[KERN_SIZE][VEC_NUM];
#pragma HLS array_partition variable = buffer_vector complete dim = 0

	// REPLICATED: replicates the border values when exceeding borders
	if (BORDER_TYPE == VX_BORDER_REPLICATE)
	{

		// Replicated y borders
		SlidingWindowReplicatedY<InType, VEC_NUM, IMG_ROWS, KERN_RAD, KERN_SIZE>(input, buffer_vector, y);

		// Sets sliding window and replicated x borders
		SlidingWindowReplicatedX<InType, KERN_SIZE, VEC_COLS, VEC_NUM, WIN_BORD_A, WIN_BORD_B, WIN_COLS>(buffer_vector, window, x);

		// CONSTANT: creates a constant border of zeros around the image
	}
	else if (BORDER_TYPE == VX_BORDER_CONSTANT)
	{

		// Constant y borders
		SlidingWindowConstantY<InType, VEC_NUM, IMG_ROWS, KERN_RAD, KERN_SIZE>(input, buffer_vector, y);

		// Sets sliding window and constant x borders
		SlidingWindowConstantX<InType, KERN_SIZE, VEC_COLS, VEC_NUM, WIN_BORD_A, WIN_BORD_B, WIN_COLS>(buffer_vector, window, x);

		// UNCHANGED: filters exceeding the borders are invalid
	}
	else if (BORDER_TYPE == VX_BORDER_UNDEFINED)
	{

		// Sets sliding window and does not create borders
		SlidingWindowUnchanged<InType, KERN_SIZE, VEC_NUM, WIN_BORD_B, WIN_COLS>(input, window);
	}
}

/*********************************************************************************************************************/
/* Filter Sub-Functions */
/*********************************************************************************************************************/

/** @brief Compares and swaps 2 elements
@param InType  Data type of the image pixels
@param A       1. element to be compared
@param B       2. element to be compared
@param H       smaller element
@param L       bigger element
*/
template <typename InType>
void CompareAndSwap(InType A, InType B, InType &L, InType &H)
{
#pragma HLS INLINE

	// Compare and Swap
	if (A > B)
	{
		L = B;
		H = A;
	}
	else
	{
		L = A;
		H = B;
	}
}

/*********************************************************************************************************************/
/* Filter Functions */
/*********************************************************************************************************************/

/** @brief Computes a 1d box filter
@param InType        The input scalar data type
@param OutType       The output scalar data type
@param KERN_SIZE     The size of the kernel
@param window        The sliding window of this scalar computation
@param kernel_mult   Multiplier for normalization
@param kernel_shift  Shifter For normalization
@return              The result of the box filter
*/
template <typename ScalarType, const vx_uint16 KERN_SIZE>
ScalarType ComputeBox1d(ScalarType window[KERN_SIZE], const vx_uint64 kernel_mult, const vx_uint32 kernel_shift)
{
#pragma HLS INLINE

	// Variable
	vx_uint64 result = 0;

	// Sum all input data
	for (vx_uint16 i = 0; i < KERN_SIZE; i++)
	{
#pragma HLS unroll
		result += static_cast<vx_uint64>(window[i]);
	}

	// Normalize
	const vx_uint64 rounding = static_cast<vx_uint64>(1) << (kernel_shift - 1);
	const vx_uint64 norm = (result * kernel_mult + rounding) >> kernel_shift;

	// Return result
	return static_cast<ScalarType>(norm);
}

/** @brief Computes a 2d box filter
@param InType        The input scalar data type
@param OutType       The output scalar data type
@param KERN_SIZE     The size of the kernel
@param window        The sliding window of this scalar computation
@param kernel_mult   Multiplier for normalization
@param kernel_shift  Shifter For normalization
@return              The result of the box filter
*/
template <typename InType, typename OutType, const vx_uint16 KERN_SIZE>
OutType ComputeBox2d(InType window[KERN_SIZE][KERN_SIZE], const vx_uint64 kernel_mult, const vx_uint32 kernel_shift)
{
#pragma HLS INLINE

	// Variable
	vx_uint64 result = 0;

	// Sum all input data
	for (vx_uint16 y = 0; y < KERN_SIZE; y++)
	{
#pragma HLS unroll
		for (vx_uint16 x = 0; x < KERN_SIZE; x++)
		{
#pragma HLS unroll
			result += static_cast<vx_uint64>(window[y][x]);
		}
	}

	// Normalize
	const vx_uint64 rounding = static_cast<vx_uint64>(1) << (kernel_shift - 1);
	const vx_uint64 norm = (result * kernel_mult + rounding) >> kernel_shift;

	// Return result
	return static_cast<OutType>(norm);
}

/** @brief Computes a 2d convolution filter
@param InType        The input scalar data type
@param CompType      Data type for internal computation (uint64 or int64)
@param OutType       The output scalar data type
@param KernType      The kernel scalar data type
@param KERN_SIZE     The size of the kernel
@param inKernel      The costum kernel
@param window        The sliding window of this scalar computation
@param kernel_mult   Multiplier for normalization
@param kernel_shift  Shifter For normalization
@return              The result of the convolution filter
*/
template <typename InType, typename CompType, typename OutType, typename KernType, const vx_uint16 KERN_SIZE>
OutType ComputeConvolve2d(KernType kernel[KERN_SIZE][KERN_SIZE], InType window[KERN_SIZE][KERN_SIZE], const vx_uint64 kernel_mult, const vx_uint32 kernel_shift)
{
#pragma HLS INLINE

	// Variables
	CompType result = 0;

	// Compute the costum filter
	for (vx_uint16 i = 0; i < KERN_SIZE; i++)
	{
#pragma HLS unroll
		for (vx_uint16 j = 0; j < KERN_SIZE; j++)
		{
#pragma HLS unroll
			CompType kernelData = static_cast<CompType>(kernel[i][j]);
			CompType windowData = static_cast<CompType>(window[i][j]);
			result += (kernelData * windowData);
		}
	}

	// Normalize
	const vx_uint64 rounding = static_cast<vx_uint64>(1) << (kernel_shift - 1);
	const vx_uint64 norm = (result * kernel_mult + rounding) >> kernel_shift;

	// Return result
	return static_cast<OutType>(norm);
}

/** @brief Computes a 1d dilate filter
@param ScalarType    The Scalar Data type
@param KERN_SIZE     The size of the kernel
@param window        The sliding window of this scalar computation
@return              The result of the dilate filter
*/
template <typename ScalarType, const vx_uint16 KERN_SIZE>
ScalarType ComputeDilate1d(ScalarType window[KERN_SIZE])
{
#pragma HLS INLINE

	// Compute dilate
	ScalarType result = window[0];
	for (vx_uint16 i = 1; i < KERN_SIZE; i++)
	{
#pragma HLS unroll
		result = MAX(result, window[i]);
	}

	// Return result
	return result;
}

/** @brief Computes a 1d erode filter
@param ScalarType    The Scalar Data type
@param KERN_SIZE     The size of the kernel
@param window        The sliding window of this scalar computation
@return              The result of the erode filter
*/
template <typename ScalarType, const vx_uint16 KERN_SIZE>
ScalarType ComputeErode1d(ScalarType window[KERN_SIZE])
{
#pragma HLS INLINE

	// Compute erode
	ScalarType result = window[0];
	for (vx_uint16 i = 1; i < KERN_SIZE; i++)
	{
#pragma HLS unroll
		result = MIN(result, window[i]);
	}

	// Return result
	return result;
}

/** @brief Computes a gaussian 1d filter (optimized to the kernel symmetry)
@param ScalarType    The input/output data type
@param KernType      The kernel scalar data type
@param KERN_SIZE     The size of the kernel
@param kernel        The gaussian kernel
@param window        The sliding window of this scalar computation
@param kernel_mult   Multiplier for normalization
@param kernel_shift  Shifter For normalization
@return              The result of the gaussian convolution
*/
template <typename ScalarType, typename KernelType, const vx_uint16 KERN_SIZE>
ScalarType ComputeGaussian1d(KernelType kernel[KERN_SIZE], ScalarType window[KERN_SIZE], const vx_uint64 kernel_mult, const vx_uint32 kernel_shift)
{
#pragma HLS INLINE

	// Constants
	const vx_uint16 KERN_RAD = KERN_SIZE >> 1;

	// Get middle pixel result
	vx_uint64 result = static_cast<vx_uint64>(kernel[KERN_RAD]) * static_cast<vx_uint64>(window[KERN_RAD]);

	// Add all other pixel to result
	for (vx_uint16 i = 0; i < KERN_RAD; i++)
	{
#pragma HLS unroll
		vx_uint64 A = static_cast<vx_uint64>(kernel[i]);
		vx_uint64 B0 = static_cast<vx_uint64>(window[i]);
		vx_uint64 B1 = static_cast<vx_uint64>(window[KERN_SIZE - i - 1]);
		result += A * (B0 + B1);
	}

	// Normalize
	const vx_uint64 rounding = static_cast<vx_uint64>(1) << (kernel_shift - 1);
	const vx_uint64 norm = (result * kernel_mult + rounding) >> kernel_shift;

	// Return result
	return static_cast<ScalarType>(norm);
}

/** @brief Computes a gaussian 2d filter (optimized to the kernel symmetry)
@param InType        The input scalar data type
@param OutType       The output scalar data type
@param KernType      The kernel scalar data type
@param KERN_SIZE     The size of the kernel
@param kernel        The gaussian kernel
@param window        The sliding window of this scalar computation
@param kernel_mult   Multiplier for normalization
@param kernel_shift  Shifter For normalization
@return              The result of the gaussian convolution
*/
template <typename InType, typename OutType, typename KernType, const vx_uint16 KERN_SIZE>
OutType ComputeGaussian2d(KernType kernel[KERN_SIZE][KERN_SIZE], InType window[KERN_SIZE][KERN_SIZE], const vx_uint64 kernel_mult, const vx_uint32 kernel_shift)
{
#pragma HLS INLINE

	// Constants
	const vx_uint16 KERN_RAD = KERN_SIZE / 2;
	const vx_uint16 KERN_RNG = KERN_SIZE - 1;

	// Store result of the gaussian filter (scalar)
	vx_uint64 result = 0;

	// if: (y == KERN_RAD) && (x == KERN_RAD)
	{
		vx_uint64 sum = static_cast<vx_uint64>(window[KERN_RAD][KERN_RAD]);
		result = (static_cast<vx_uint64>(kernel[KERN_RAD][KERN_RAD]) * sum);
	}

	// if: (y == KERN_RAD) && (x < KERN_RAD)
	for (vx_uint16 x = 0; x < KERN_RAD; x++)
	{
#pragma HLS unroll
		const vx_uint16 RADIUS = KERN_RAD - x;
		vx_uint64 sum = 0;
		sum += static_cast<vx_uint64>(window[KERN_RAD][x]);
		sum += static_cast<vx_uint64>(window[KERN_RAD][KERN_RNG - x]);
		sum += static_cast<vx_uint64>(window[KERN_RAD + RADIUS][x + RADIUS]);
		sum += static_cast<vx_uint64>(window[KERN_RAD - RADIUS][x + RADIUS]);
		result += (static_cast<vx_uint64>(kernel[KERN_RAD][x]) * sum);
	}

	// if: (y == x) && (x < KERN_RAD)
	for (vx_uint16 y = 0; y < KERN_RAD; y++)
	{
#pragma HLS unroll
		vx_uint64 sum = 0;
		sum += static_cast<vx_uint64>(window[y][y]);
		sum += static_cast<vx_uint64>(window[y][KERN_RNG - y]);
		sum += static_cast<vx_uint64>(window[KERN_RNG - y][y]);
		sum += static_cast<vx_uint64>(window[KERN_RNG - y][KERN_RNG - y]);
		result += (static_cast<vx_uint64>(kernel[y][y]) * sum);
	}

	// if: (y > 0) && (y < KERN_RAD) && (y > x)
	for (vx_uint16 x = 0; x <= KERN_RAD; x++)
	{
#pragma HLS unroll
		for (vx_uint16 y = x + 1; y < KERN_RAD; y++)
		{
#pragma HLS unroll
			vx_int64 sum = 0;
			sum += static_cast<vx_uint64>(window[y][x]);
			sum += static_cast<vx_uint64>(window[x][y]);
			sum += static_cast<vx_uint64>(window[KERN_RNG - y][x]);
			sum += static_cast<vx_uint64>(window[x][KERN_RNG - y]);
			sum += static_cast<vx_uint64>(window[KERN_RNG - x][y]);
			sum += static_cast<vx_uint64>(window[y][KERN_RNG - x]);
			sum += static_cast<vx_uint64>(window[KERN_RNG - x][KERN_RNG - y]);
			sum += static_cast<vx_uint64>(window[KERN_RNG - y][KERN_RNG - x]);
			result += (static_cast<vx_uint64>(kernel[y][x]) * sum);
		}
	}

	// Normalize
	const vx_uint64 rounding = static_cast<vx_uint64>(1) << (kernel_shift - 1);
	const vx_uint64 norm = (result * kernel_mult + rounding) >> kernel_shift;

	// Return result
	return static_cast<OutType>(norm);
}

/** @brief Computes a median filter
@details Algorithm taken from the the following paper:
A fault-tolerant implementation of the median filter
from L. A. Aranda and P. Reviriego and J. A. Maestro
@param InType        The input scalar data type
@param OutType       The output scalar data type
@param KERN_SIZE     The size of the kernel
@param window        The sliding window of this scalar computation
@return              The result of the median filter
*/
template <typename InType, typename OutType, const vx_uint16 KERN_SIZE>
OutType ComputeMedian3x3(InType window[KERN_SIZE][KERN_SIZE])
{
#pragma HLS INLINE

	// Variables
	InType B0, B1, B3, B4, B6, B7;
	InType C1, C2, C4, C5, C7, C8;
	InType D0, D1, D3, D4, D6, D7;
	InType E0, E1, E3, E4, E7, E8;
	InType F1, F2, F4, F5, F6, F7;
	InType G3, G4, H3, H4, I4, I5, J3, J4;

	// Input pixel
	InType A0 = window[0][0], A1 = window[0][1], A2 = window[0][2];
	InType A3 = window[1][0], A4 = window[1][1], A5 = window[1][2];
	InType A6 = window[2][0], A7 = window[2][1], A8 = window[2][2];

	// Get median with 19 compare and swap units
	CompareAndSwap(A0, A1, B0, B1);
	CompareAndSwap(A3, A4, B3, B4);
	CompareAndSwap(A6, A7, B6, B7);
	CompareAndSwap(B1, A2, C1, C2);
	CompareAndSwap(B4, A5, C4, C5);
	CompareAndSwap(B7, A8, C7, C8);
	CompareAndSwap(B0, C1, D0, D1);
	CompareAndSwap(B3, C4, D3, D4);
	CompareAndSwap(B6, C7, D6, D7);
	CompareAndSwap(D0, D3, E0, E1);
	CompareAndSwap(D1, D4, E3, E4);
	CompareAndSwap(C5, C8, E7, E8);
	CompareAndSwap(E1, D6, F1, F2);
	CompareAndSwap(E4, D7, F4, F5);
	CompareAndSwap(C2, E7, F6, F7);
	CompareAndSwap(E3, F4, G3, G4);
	CompareAndSwap(F2, G4, H3, H4);
	CompareAndSwap(H4, F6, I4, I5);
	CompareAndSwap(H3, I4, J3, J4);

	// Take median value
	return static_cast<OutType>(J4);
}

/** @brief Computes a median filter
@details Algorithm taken from the the following book:
Knuth in The Art of Computer Programming, vol 3 (algorithm 5.2.2M)
@param InType        The input scalar data type
@param OutType       The output scalar data type
@param KERN_SIZE     The size of the kernel
@param window        The sliding window of this scalar computation
@return              The result of the median filter
*/
template <typename InType, typename OutType, const vx_uint16 KERN_SIZE>
OutType ComputeMedian(InType window[KERN_SIZE][KERN_SIZE])
{
#pragma HLS INLINE

	// Constants and variables
	const vx_uint16 BUFFER_SIZE = KERN_SIZE * KERN_SIZE;
	const vx_uint16 BUFFER_RAD = BUFFER_SIZE >> 1;
	vx_uint16 START = 1;
	vx_uint16 row_ptr = 0;
	vx_uint16 SCALE = BUFFER_SIZE - 1;
	vx_uint16 MSB = 0;

	// Register stages for pipelining of the sorting
	InType buffer[BUFFER_SIZE + 1][BUFFER_SIZE];
#pragma HLS array_partition variable = buffer complete dim = 0

	// Pre-computation
	for (vx_uint16 i = 0; i < sizeof(vx_uint16) * 8; i++)
	{
#pragma HLS unroll
		if ((SCALE & static_cast<vx_uint16>(1 << i)) != 0)
			MSB = i;
	}
	for (vx_uint16 i = 0; i < MSB; i++)
	{
#pragma HLS unroll
		START *= 2;
	}

	// 2d to 1d input window conversion
	for (vx_uint16 i = 0, ptr = 0; i < KERN_SIZE; i++)
	{
#pragma HLS unroll
		for (vx_uint16 j = 0; j < KERN_SIZE; j++)
		{
#pragma HLS unroll
			buffer[0][ptr] = window[i][j];
			ptr++;
		}
	}

	// Sort array using odd-even mergesort
	for (vx_uint16 p = START; p > 0; p >>= 1)
	{
#pragma HLS unroll
		for (vx_uint16 q = START, r = 0, d = p; d > 0; d = q - p, q >>= 1, r = p)
		{
#pragma HLS unroll
			for (vx_uint16 i = 0; i < BUFFER_SIZE; i++)
			{
#pragma HLS unroll
				buffer[row_ptr + 1][i] = buffer[row_ptr][i];
			}
			for (vx_uint16 i = 0; i < BUFFER_SIZE - d; i++)
			{
#pragma HLS unroll
				if ((i & p) == r)
					CompareAndSwap<InType>(buffer[row_ptr][i], buffer[row_ptr][i + d], buffer[row_ptr + 1][i], buffer[row_ptr + 1][i + d]);
			}
			row_ptr++;
		}
	}

	// Take median value
	return static_cast<OutType>(buffer[row_ptr][BUFFER_RAD]);
}

/** @brief Computes the x derivative (optimized for kernel symmetry)
@param InType        The input scalar data type
@param OutType       The output scalar data type
@param KernType      The kernel scalar data type
@param KERN_SIZE     The size of the kernel
@param kernel        The sobel/scharr kernel
@param window        The sliding window of this scalar computation
@param kernel_mult   Multiplier for normalization
@param kernel_shift  Shifter For normalization
@return              The result of the x derivative computation
*/
template <typename InType, typename OutType, typename KernType, const vx_uint16 KERN_SIZE>
OutType ComputeDerivativeX(KernType kernel[KERN_SIZE][KERN_SIZE], InType window[KERN_SIZE][KERN_SIZE], const vx_uint64 kernel_mult, const vx_uint32 kernel_shift)
{
#pragma HLS INLINE

	// Constants
	const vx_uint16 KERN_RAD = KERN_SIZE >> 1;
	const vx_uint16 KERN_RANGE = KERN_SIZE - 1;

	// Compute the filter result
	vx_int64 result = 0;

	for (vx_uint16 y = 0; y < KERN_RAD + 1; y++)
	{
#pragma HLS unroll
		for (vx_uint16 x = 0; x < KERN_RAD; x++)
		{
#pragma HLS unroll

			// Constants
			const vx_uint16 yn = y + KERN_RANGE - y * 2;
			const vx_uint16 xn = x + KERN_RANGE - x * 2;

			// Compute mul
			vx_int64 mul = ABS(static_cast<vx_int64>(kernel[y][x]));

			// compute sum
			vx_int64 sum;
			if (y < KERN_RAD)
			{
				sum = static_cast<vx_int64>(window[y][xn]) +
					  static_cast<vx_int64>(window[yn][xn]) -
					  static_cast<vx_int64>(window[y][x]) -
					  static_cast<vx_int64>(window[yn][x]);
			}
			else
			{
				sum = static_cast<vx_int64>(window[y][xn]) -
					  static_cast<vx_int64>(window[y][x]);
			}

			// Add to result
			result += sum * mul;
		}
	}

	// Normalize
	const vx_uint64 rounding = static_cast<vx_uint64>(1) << (kernel_shift - 1);
	const vx_uint64 norm = (result * kernel_mult + rounding) >> kernel_shift;

	// Return result
	return static_cast<OutType>(norm);
}

/** @brief Computes the y derivative (optimized for kernel symmetry)
@param InType        The input scalar data type
@param OutType       The output scalar data type
@param KernType      The kernel scalar data type
@param KERN_SIZE     The size of the kernel
@param kernel        The sobel/scharr kernel
@param window        The sliding window of this scalar computation
@param kernel_mult   Multiplier for normalization
@param kernel_shift  Shifter For normalization
@return              The result of the y derivative computation
*/
template <typename InType, typename OutType, typename KernType, const vx_uint16 KERN_SIZE>
OutType ComputeDerivativeY(KernType kernel[KERN_SIZE][KERN_SIZE], InType window[KERN_SIZE][KERN_SIZE], const vx_uint64 kernel_mult, const vx_uint32 kernel_shift)
{
#pragma HLS INLINE

	// Constants
	const vx_uint16 KERN_RAD = KERN_SIZE >> 1;
	const vx_uint16 KERN_RANGE = KERN_SIZE - 1;

	// Compute the filter result
	vx_int64 result = 0;

	for (vx_uint16 x = 0; x < KERN_RAD + 1; x++)
	{
#pragma HLS unroll
		for (vx_uint16 y = 0; y < KERN_RAD; y++)
		{
#pragma HLS unroll

			// Constants
			const vx_uint16 yn = y + KERN_RANGE - y * 2;
			const vx_uint16 xn = x + KERN_RANGE - x * 2;

			// Compute mul
			vx_int64 mul = ABS(static_cast<vx_int64>(kernel[y][x]));

			// compute sum
			vx_int64 sum;
			if (x < KERN_RAD)
			{
				sum = static_cast<vx_int64>(window[yn][x]) +
					  static_cast<vx_int64>(window[yn][xn]) -
					  static_cast<vx_int64>(window[y][x]) -
					  static_cast<vx_int64>(window[y][xn]);
			}
			else
			{
				sum = static_cast<vx_int64>(window[yn][x]) -
					  static_cast<vx_int64>(window[y][x]);
			}

			// Add to result
			result += sum * mul;
		}
	}

	// Normalize
	const vx_uint64 rounding = static_cast<vx_uint64>(1) << (kernel_shift - 1);
	const vx_uint64 norm = (result * kernel_mult + rounding) >> kernel_shift;

	// Return result
	return static_cast<OutType>(norm);
}

/** @brief Computes the y derivative (optimized for kernel symmetry)
@param InType        The input data type
@param OutType       The output data type
@param KernType      The kernel scalar data type
@param KERN_SIZE     The size of the kernel/window
@param kernel        The suppression mask  (if mask pixel is 0, check suppression)
@param window        The sliding window of input pixels
@return              The result of the Non-Maxima Suppression
*/
template <typename InType, typename OutType, typename KernType, vx_uint16 KERN_SIZE>
OutType NonMaxSuppression(KernType kernel[KERN_SIZE][KERN_SIZE], InType window[KERN_SIZE][KERN_SIZE])
{
#pragma HLS INLINE

	// Constants
	const vx_type_e data_type = GET_TYPE(InType);
	const InType min_value = ComputeMin<InType>();
	const vx_uint16 KERN_RAD = KERN_SIZE >> 1;

	// Is true, if input is maximum
	bool maximum = true;

	// Input pixel
	InType input = window[KERN_RAD][KERN_RAD];

	// Check if pixel is maxima in mask area
	for (vx_uint16 y = 0; y < KERN_SIZE; y++)
	{
		for (vx_uint16 x = 0; x < KERN_SIZE; x++)
		{
#pragma HLS unroll

			// Pixel to compare
			InType pixel = window[y][x];

			// If mask is zero, check suppresion
			if (kernel[y][x] == 0)
			{

				// Check top left
				if ((y < KERN_RAD) || ((y == KERN_RAD) && (x < KERN_RAD)))
				{
					if (input < pixel)
						maximum = false;

					// Check bottom right
				}
				else if ((y > KERN_RAD) || ((y == KERN_RAD) && (x > KERN_RAD)))
				{
					if (input <= pixel)
						maximum = false;
				}
			}
		}
	}

	// Suppress input to minimum possible value, if it is not a maxima
	InType output = (maximum == false) ? (min_value) : (input);
	return static_cast<OutType>(output);
}

template <typename InType, typename OutType, vx_uint16 KERN_SIZE>
OutType SegmentTestDetector(InType window[KERN_SIZE][KERN_SIZE])
{
#pragma HLS INLINE

	// Variables
	InType circle[16] = {0};
#pragma HLS array_partition variable = circle complete dim = 0
	InType difference[16];
#pragma HLS array_partition variable = difference complete dim = 0
	vx_uint8 direction[16];
#pragma HLS array_partition variable = direction complete dim = 0

	// Input and output
	InType input = 0;
	InType response = 0;

	// Buffer Bresenham circle
	if (KERN_SIZE == 7)
	{
		input = window[3][3];
		circle[0] = window[0][3];
		circle[1] = window[0][4];
		circle[2] = window[1][5];
		circle[3] = window[2][6];
		circle[4] = window[3][6];
		circle[5] = window[4][6];
		circle[6] = window[5][5];
		circle[7] = window[6][4];
		circle[8] = window[6][3];
		circle[9] = window[6][2];
		circle[10] = window[5][1];
		circle[11] = window[4][0];
		circle[12] = window[3][0];
		circle[13] = window[2][0];
		circle[14] = window[1][1];
		circle[15] = window[0][2];
	}

	// Compute diffs and compare if pixel is dark or bright
	for (vx_uint8 i = 0; i < 16; ++i)
	{
#pragma HLS unroll
		if (circle[i] > input)
		{
			difference[i] = circle[i] - input;
			direction[i] = 1;
		}
		else
		{
			difference[i] = input - circle[i];
			direction[i] = 2;
		}
	}

	// Compute response of all possible corners
	for (vx_uint8 i = 0; i < 16; ++i)
	{
#pragma HLS unroll
		InType minimum = std::numeric_limits<InType>::max();
		vx_uint8 c1 = 3;

		// Compute response of 1 possible corner
		// Response is ">0" if all other pixels are small or bigger
		for (vx_uint8 j = i; j < (i + 9); ++j)
		{
#pragma HLS unroll
			vx_uint8 ptr = j % 16;
			if (minimum > difference[ptr])
				minimum = difference[ptr];
			c1 = c1 & direction[ptr];
		}
		InType val = (c1 == 0) ? (0) : (minimum);

		// Get highest response
		if (response < val)
			response = val;
	}

	// Output final response
	return response;
}

template <typename InType, typename OutType, vx_uint16 KERN_SIZE, InType THRESH_LOWER, InType THRESH_UPPER>
OutType Hysteresis(InType window[KERN_SIZE][KERN_SIZE])
{
#pragma HLS INLINE

	// Constants
	vx_uint32 KERN_RAD = KERN_SIZE / 2;
	OutType MAX_VAL = std::numeric_limits<OutType>::max();

	// Input variable
	InType input = window[KERN_RAD][KERN_RAD];

	// Check the strength of the input
	bool strong = (input >= THRESH_UPPER);
	bool weak = (input >= THRESH_LOWER);

	// If variable weak and neighbour strong, set to strong
	for (vx_uint32 y = 0; y < KERN_SIZE; ++y)
	{
#pragma HLS unroll
		for (vx_uint32 x = 0; x < KERN_SIZE; ++x)
		{
#pragma HLS unroll
			if ((y != KERN_RAD) && (x != KERN_RAD))
			{
				InType neighbour = window[y][x];
				if ((neighbour >= THRESH_UPPER) && (weak == true))
				{
					strong = true;
				}
			}
		}
	}
	OutType result = (strong == true) ? (MAX_VAL) : ((OutType)0);

	// Return result
	return result;
}

/*********************************************************************************************************************/
/* Filter Main Function */
/*********************************************************************************************************************/

/** @brief Selects and computes a 1d horizontal filter
@param ScalarType   Data type of the input/output image
@param KernelType   Data type of the kernel
@param KERN_SIZE    Filter kernel size
@param WIN_COLS     Columns of the sliding window
@param VEC_NUM      Vector size
@param window       The sliding window
@param kernel       The convolution kernels
@param kernel_mult  Resulting pixels are 1. multiplied by this amount
@param kernel_shift Resulting pixels are 2. shifted to the right by this amount
@param kernel_type  The type of convolution
@param output       The results (vector) (per clock cycle)
*/
template <typename ScalarType, typename KernelType, vx_uint16 KERN_SIZE, HIFLIPVX::FilterOperation KERN_TYPE, vx_uint16 WIN_COLS, vx_uint16 VEC_NUM>
void ComputeFilterHorizontal(ScalarType window[WIN_COLS], KernelType kernel[KERN_SIZE],
							 const vx_uint64 kernel_mult, const vx_uint32 kernel_shift, ScalarType output[VEC_NUM])
{
#pragma HLS INLINE

	for (vx_uint16 vecId = 0; vecId < VEC_NUM; vecId++)
	{
#pragma HLS unroll

		// Window for single vector element
		ScalarType kernel_window[KERN_SIZE];
#pragma HLS array_partition variable = kernel_window complete dim = 0

		// Get window for single vector element
		for (vx_uint16 i = 0; i < KERN_SIZE; i++)
		{
#pragma HLS unroll
			kernel_window[i] = window[i + vecId];
		}

		// Compute filter for single vector element
		ScalarType result = 0;
		switch (KERN_TYPE)
		{
		case HIFLIPVX::GAUSSIAN_FILTER:
			result = ComputeGaussian1d<ScalarType, KernelType, KERN_SIZE>(kernel, kernel_window, kernel_mult, kernel_shift);
			break;
		case HIFLIPVX::BOX_FILTER:
			result = ComputeBox1d<ScalarType, KERN_SIZE>(kernel_window, kernel_mult, kernel_shift);
			break;
		case HIFLIPVX::ERODE_IMAGE:
			result = ComputeErode1d<ScalarType, KERN_SIZE>(kernel_window);
			break;
		case HIFLIPVX::DILATE_IMAGE:
			result = ComputeDilate1d<ScalarType, KERN_SIZE>(kernel_window);
			break;
		default:
			break;
		}
		output[vecId] = result;
	}
}

/** @brief Selects and computes a 1d vertical filter
@param ScalarType   Data type of the input/output image
@param KernelType   Data type of the kernel
@param KERN_SIZE    Filter kernel size
@param VEC_NUM      Vector size
@param window       The sliding window
@param kernel       The convolution kernels
@param kernel_mult  Resulting pixels are 1. multiplied by this amount
@param kernel_shift Resulting pixels are 2. shifted to the right by this amount
@param kernel_type  The type of convolution
@param output       The results (vector) (per clock cycle)
*/
template <typename ScalarType, typename KernelType, vx_uint16 KERN_SIZE, HIFLIPVX::FilterOperation KERN_TYPE, vx_uint16 VEC_NUM, vx_uint16 IMG_COLS, vx_uint16 IMG_ROWS>
void ComputeFilterVertical(ScalarType window[KERN_SIZE][VEC_NUM], KernelType kernel[KERN_SIZE],
						   const vx_uint64 kernel_mult, const vx_uint32 kernel_shift, vx_image_data<ScalarType, VEC_NUM> &output, vx_uint16 x, vx_uint16 y)
{
#pragma HLS INLINE

	// Constants
	const vx_uint16 VEC_COLS = IMG_COLS / VEC_NUM;
	const vx_uint16 KERN_RAD = KERN_SIZE >> 1;
	const vx_uint16 WIN_COLS = 2 * KERN_RAD + VEC_NUM + (VEC_NUM - (KERN_RAD % VEC_NUM)) % VEC_NUM;
	const vx_uint16 OHD_COLS = (WIN_COLS - KERN_RAD) / VEC_NUM - 1;

	// Output array of the different filter (scalar)
	vx_image_data<ScalarType, VEC_NUM> output_array;

	for (vx_uint16 vecId = 0; vecId < VEC_NUM; vecId++)
	{
#pragma HLS unroll

		// Window for single vector element
		ScalarType kernel_window[KERN_SIZE];
#pragma HLS array_partition variable = kernel_window complete dim = 0

		// Get window for single vector element
		for (vx_uint16 i = 0; i < KERN_SIZE; i++)
		{
#pragma HLS unroll
			kernel_window[i] = window[i][vecId];
		}

		// Compute filter for single vector element
		ScalarType result = 0;
		switch (KERN_TYPE)
		{
		case HIFLIPVX::GAUSSIAN_FILTER:
			result = ComputeGaussian1d<ScalarType, KernelType, KERN_SIZE>(kernel, kernel_window, kernel_mult, kernel_shift);
			break;
		case HIFLIPVX::BOX_FILTER:
			result = ComputeBox1d<ScalarType, KERN_SIZE>(kernel_window, kernel_mult, kernel_shift);
			break;
		case HIFLIPVX::ERODE_IMAGE:
			result = ComputeErode1d<ScalarType, KERN_SIZE>(kernel_window);
			break;
		case HIFLIPVX::DILATE_IMAGE:
			result = ComputeDilate1d<ScalarType, KERN_SIZE>(kernel_window);
			break;
		default:
			break;
		}
		output_array.pixel[vecId] = result;
	}

	// Set user(SOF) & last(EOF)
	const bool sof = ((y == KERN_RAD) && (x == OHD_COLS));
	const bool eof = ((y == (IMG_ROWS + KERN_RAD - 1)) && (x == (VEC_COLS + OHD_COLS - 1)));
	GenerateDmaSignal<ScalarType, VEC_NUM>(sof, eof, output_array);

	// Write output
	output = output_array;
}

/** @brief Selects and computes a filter
@param InType       Data type of the input image
@param OutType      Data type of the output image
@param KernType     Data type of the kernel
@param VEC_NUM     Vector size
@param KERN_NUM     Amount of filter kernel
@param KERN_SIZE    Filter kernel size
@param WIN_COLS     Columns of the sliding window
@param window       The sliding window
@param kernel       The convolution kernels
@param kernel_mult  Resulting pixels are 1. multiplied by this amount
@param kernel_shift Resulting pixels are 2. shifted to the right by this amount
@param kernel_type  The type of convolution
@param output       The results (vector) (per clock cycle)
*/
template <typename InType, typename OutType, typename KernType, vx_uint16 VEC_NUM, vx_uint16 KERN_NUM, HIFLIPVX::FilterOperation KERN_TYPE, vx_uint16 KERN_SIZE, vx_uint16 WIN_COLS, InType THRESH_LOWER, InType THRESH_UPPER, vx_uint16 IMG_COLS, vx_uint16 IMG_ROWS>
void ComputeFilter(InType window[KERN_SIZE][WIN_COLS], KernType kernel[KERN_SIZE][KERN_SIZE],
				   const vx_uint64 kernel_mult, const vx_uint32 kernel_shift, vx_image_data<OutType, VEC_NUM> &output, vx_uint16 x, vx_uint16 y)
{
#pragma HLS INLINE

	// Constants
	const vx_uint16 VEC_COLS = IMG_COLS / VEC_NUM;
	const vx_uint16 KERN_RAD = KERN_SIZE >> 1;
	const vx_uint16 OHD_COLS = (WIN_COLS - KERN_RAD) / VEC_NUM - 1;

	// Output
	vx_image_data<OutType, VEC_NUM> output_vector;

	// Compute KERN_NUM different filter with VEC_NUM elements per clock cycle
	for (vx_uint16 vecId = 0; vecId < VEC_NUM; vecId++)
	{
#pragma HLS unroll

		// Window for single vector element
		InType kernel_window[KERN_SIZE][KERN_SIZE];
#pragma HLS array_partition variable = kernel_window complete dim = 0

		// Get window for single vector element
		for (vx_uint16 i = 0; i < KERN_SIZE; i++)
		{
#pragma HLS unroll
			for (vx_uint16 j = 0; j < KERN_SIZE; j++)
			{
#pragma HLS unroll
				kernel_window[i][j] = window[i][j + vecId];
			}
		}

		// Check, if input or output is signed
		bool isSigned = (std::numeric_limits<InType>::is_signed) || (std::numeric_limits<OutType>::is_signed);

		// Compute filter for single vector element
		OutType result = 0;
		if (KERN_TYPE == HIFLIPVX::GAUSSIAN_FILTER)
		{
			result = ComputeGaussian2d<InType, OutType, KernType, KERN_SIZE>(kernel, kernel_window, kernel_mult, kernel_shift);
		}
		else if (KERN_TYPE == HIFLIPVX::DERIVATIVE_X)
		{
			result = ComputeDerivativeX<InType, OutType, KernType, KERN_SIZE>(kernel, kernel_window, kernel_mult, kernel_shift);
		}
		else if (KERN_TYPE == HIFLIPVX::DERIVATIVE_Y)
		{
			result = ComputeDerivativeY<InType, OutType, KernType, KERN_SIZE>(kernel, kernel_window, kernel_mult, kernel_shift);
		}
		else if (KERN_TYPE == HIFLIPVX::CUSTOM_CONVOLUTION)
		{
			if (isSigned)
				result = ComputeConvolve2d<InType, vx_int64, OutType, KernType, KERN_SIZE>(kernel, kernel_window, kernel_mult, kernel_shift);
			else
				result = ComputeConvolve2d<InType, vx_uint64, OutType, KernType, KERN_SIZE>(kernel, kernel_window, kernel_mult, kernel_shift);
		}
		else if (KERN_TYPE == HIFLIPVX::BOX_FILTER)
		{
			result = ComputeBox2d<InType, OutType, KERN_SIZE>(kernel_window, kernel_mult, kernel_shift);
		}
		else if (KERN_TYPE == HIFLIPVX::MEDIAN_FILTER)
		{
			if (KERN_SIZE == 3)
				result = ComputeMedian3x3<InType, OutType, KERN_SIZE>(kernel_window);
			else
				result = ComputeMedian<InType, OutType, KERN_SIZE>(kernel_window);
		}
		else if (KERN_TYPE == HIFLIPVX::NON_MAX_SUPPRESSION)
		{
			result = NonMaxSuppression<InType, OutType, KernType, KERN_SIZE>(kernel, kernel_window);
		}
		else if (KERN_TYPE == HIFLIPVX::SEGMENT_TEST_DETECTOR)
		{
			result = SegmentTestDetector<InType, OutType, KERN_SIZE>(kernel_window);
		}
		else if (KERN_TYPE == HIFLIPVX::HYSTERESIS)
		{
			result = Hysteresis<InType, OutType, KERN_SIZE, THRESH_LOWER, THRESH_UPPER>(kernel_window);
		}
		output_vector.pixel[vecId] = result;
	}

	// Set user(SOF) & last(EOF)
	const bool sof = ((y == KERN_RAD) && (x == OHD_COLS));
	const bool eof = ((y == (IMG_ROWS + KERN_RAD - 1)) && (x == (VEC_COLS + OHD_COLS - 1)));
	GenerateDmaSignal<OutType, VEC_NUM>(sof, eof, output_vector);

	// Write Output
	output = output_vector;
}

/** @brief  Checks the input parameters of the convolution filter
@param InType       Data type of the input image (8-bit, 16-bit, 32-bit)
@param OutType      Data type of the output image (8-bit, 16-bit, 32-bit)
@param VEC_NUM      Amount of pixels computed in parallel (1, 2, 4, 8)
@param KERN_NUM     Amount of pixels computed in parallel (1, 2)
@param IMG_COLS     Image width
@param KERN_SIZE    Kernel size (3, 5, 7, 9, 11)
*/
template <typename InType, typename OutType, vx_uint16 VEC_NUM, vx_uint16 KERN_NUM, vx_uint16 IMG_COLS, vx_uint16 KERN_SIZE>
void CheckFilterParameters()
{
#pragma HLS INLINE
	// Check function parameters/types
	const vx_uint16 src_size = sizeof(InType);
	const vx_uint16 dst_size = sizeof(OutType);
	const bool allowed_kernel_size = (KERN_SIZE == 3) || (KERN_SIZE == 5) || (KERN_SIZE == 7) || (KERN_SIZE == 9) || (KERN_SIZE == 11);
	const bool allowed_vector_size = (VEC_NUM == 1) || (VEC_NUM == 2) || (VEC_NUM == 4) || (VEC_NUM == 8);
	const bool allowed_data_type = (src_size == 1) || (src_size == 2) || (src_size == 4);
	const bool allowed_kernel_type = (src_size == 1) || (src_size == 2);
	const bool allowed_kernel_num = (KERN_NUM == 1) || (KERN_NUM == 2);
	STATIC_ASSERT(allowed_kernel_size, kernel_size_must_be_3_5_7_9_11);
	STATIC_ASSERT((IMG_COLS % VEC_NUM == 0), image_colums_are_not_multiple_of_vector_size);
	STATIC_ASSERT((src_size == dst_size), size_of_in_and_out_type_must_be_equal);
	STATIC_ASSERT(allowed_vector_size, vector_size_must_be_1_2_4_8);
	STATIC_ASSERT(allowed_data_type, data_type_must_be_8_16_32_bit);
	STATIC_ASSERT(allowed_kernel_type, kernel_data_type_must_be_8_16_bit);
	STATIC_ASSERT(allowed_kernel_num, kernel_num_can_only_be_1__or_2);
}

/*****************************************************************************************************************************************************************************************************/
/* Main Functions */
/*****************************************************************************************************************************************************************************************************/

/** @brief  Computes multiple 1d convolution filter of kernel_type type
@param ScalarType   Data type of the input/output image (8-bit, 16-bit, 32-bit)
@param KernelType   Data type of the kernel (8-bit, 16-bit, 32-bit)
@param BufferType   (sizeof(InType) * VEC_NUM * (KERN_SIZE - 1)) == (sizeof(BufferType) * BUFFER_NUM)
@param BUFFER_NUM   (sizeof(InType) * VEC_NUM * (KERN_SIZE - 1)) == (sizeof(BufferType) * BUFFER_NUM)
@param VEC_PIX      The amount of pixels diveded by the pixels computed in parallel
@param VEC_NUM      Amount of pixels computed in parallel (1, 2, 4, 8)
@param KERN_NUM     Amount of pixels computed in parallel (1, 2)
@param IMG_COLS     Image width
@param IMG_ROWS     Image height
@param KERN_SIZE    Kernel size (3, 5, 7, 9, 11)
@param BORDER_TYPE  Type of border (Constant, Replicated or Undefined)
@param input        Input image
@param output       Output image
@param kernel       The convolution kernel
@param kernel_mult  Resulting pixels are 1. multiplied by this amount
@param kernel_shift Resulting pixels are 2. shifted to the right by this amount
@param kernel_type  The type of convolution
*/
template <typename ScalarType, typename KernelType, typename BufferType, vx_uint16 BUFFER_NUM, vx_uint32 VEC_PIX, vx_uint16 VEC_NUM, vx_uint16 IMG_COLS, vx_uint16 IMG_ROWS, vx_uint16 KERN_SIZE, HIFLIPVX::FilterOperation KERN_TYPE, vx_border_e BORDER_TYPE>
void ComputeFilter1dFunc(
	vx_image_data<ScalarType, VEC_NUM> input[VEC_PIX],
	vx_image_data<ScalarType, VEC_NUM> output[VEC_PIX],
	KernelType kernel[KERN_SIZE],
	const vx_uint64 kernel_mult,
	const vx_uint32 kernel_shift)
{
#pragma HLS INLINE

	// Constants
	const vx_uint16 VEC_COLS = IMG_COLS / VEC_NUM;
	const vx_uint16 KERN_RAD = KERN_SIZE >> 1;
	const vx_uint16 WIN_COLS = 2 * KERN_RAD + VEC_NUM + (VEC_NUM - (KERN_RAD % VEC_NUM)) % VEC_NUM;
	const vx_uint16 OHD_COLS = (WIN_COLS - KERN_RAD) / VEC_NUM - 1;
	const vx_uint16 LINE_BUFFER_WIDTH = VEC_NUM * (KERN_SIZE - 1);

	// Linebuffer
	BufferType linebuffer[BUFFER_NUM][VEC_COLS];

	// Sliding window for complete vector
	ScalarType window_hor[1][WIN_COLS];
#pragma HLS array_partition variable = window_hor complete dim = 0

	ScalarType window_ver[KERN_SIZE][VEC_NUM];
#pragma HLS array_partition variable = window_ver complete dim = 0

	// Compute the filter (pipelined)
	vx_uint32 ptr_src = 0, ptr_dst = 0;
	for (vx_uint16 y = 0; y < IMG_ROWS + KERN_RAD; y++)
	{
		for (vx_uint16 x = 0; x < VEC_COLS + OHD_COLS; x++)
		{
#pragma HLS PIPELINE II = 1

			// Variables (Registers)
			ScalarType input_buffer[VEC_NUM];
#pragma HLS array_partition variable = input_buffer complete dim = 0
			ScalarType buffer[KERN_SIZE][VEC_NUM];
#pragma HLS array_partition variable = buffer complete dim = 0
			ScalarType internal_buffer[VEC_NUM];
#pragma HLS array_partition variable = internal_buffer complete dim = 0
			vx_image_data<ScalarType, VEC_NUM> input_data_2d;
			vx_image_data<ScalarType, VEC_NUM> output_data;

			// Read input data from global memory
			if ((y < IMG_ROWS) && (x < VEC_COLS))
			{
				input_data_2d = input[ptr_src];
				ptr_src++;
			}
			for (vx_uint16 v = 0; v < VEC_NUM; v++)
			{
#pragma HLS unroll
				input_buffer[v] = input_data_2d.pixel[v];
			}

			// Compute Horizontal Filter including sliding window
			SlidingWindowHorizontal<ScalarType, KERN_RAD, VEC_COLS, VEC_NUM, WIN_COLS, BORDER_TYPE>(input_buffer, window_hor, x);
			ComputeFilterHorizontal<ScalarType, KernelType, KERN_SIZE, KERN_TYPE, WIN_COLS, VEC_NUM>(window_hor[0], kernel, kernel_mult, kernel_shift, internal_buffer);

			// Compute linebuffer
			vx_int16 xs = x - OHD_COLS;
			if (xs >= 0)
			{
				ReadFromLineBuffer<ScalarType, BufferType, BUFFER_NUM, VEC_NUM, KERN_SIZE, VEC_COLS>(internal_buffer, linebuffer, buffer, xs);
				WriteToLineBuffer<ScalarType, BufferType, BUFFER_NUM, VEC_NUM, KERN_SIZE, VEC_COLS>(buffer, linebuffer, xs);
			}

			// Compute Vertical Filter including sliding window
			SlidingWindowVertical<ScalarType, IMG_ROWS, KERN_RAD, VEC_NUM, KERN_SIZE, BORDER_TYPE>(buffer, window_ver, y);
			ComputeFilterVertical<ScalarType, KernelType, KERN_SIZE, KERN_TYPE, VEC_NUM, IMG_COLS, IMG_ROWS>(window_ver, kernel, kernel_mult, kernel_shift, output_data, x, y);

			// Write output data to global memory
			if ((y >= KERN_RAD) && (x >= OHD_COLS))
			{
				output[ptr_dst] = output_data;
				ptr_dst++;
			}
		}
	}
}

/** @brief  Computes multiple 2d convolution filter of kernel_type type
@param InType       Data type of the input image (8-bit, 16-bit, 32-bit)
@param OutType      Data type of the output image (8-bit, 16-bit, 32-bit)
@param KernType     Data type of the kernel (8-bit, 16-bit, 32-bit)
@param BufferType   (sizeof(InType) * VEC_NUM * (KERN_SIZE - 1)) == (sizeof(BufferType) * BUFFER_NUM)
@param BUFFER_NUM   (sizeof(InType) * VEC_NUM * (KERN_SIZE - 1)) == (sizeof(BufferType) * BUFFER_NUM)
@param VEC_PIX      The amount of pixels diveded by the pixels computed in parallel
@param VEC_NUM      Amount of pixels computed in parallel (1, 2, 4, 8)
@param KERN_NUM     Amount of pixels computed in parallel (1, 2)
@param IMG_COLS     Image width
@param IMG_ROWS     Image height
@param KERN_SIZE    Kernel size (3, 5, 7, 9, 11)
@param BORDER_TYPE  Type of border (Constant, Replicated or Undefined)
@param input        Input image
@param output1      1. Output image
@param output2      2. Output image
@param kernel       The convolution kernel
@param kernel_mult  Resulting pixels are 1. multiplied by this amount
@param kernel_shift Resulting pixels are 2. shifted to the right by this amount
@param kernel_type  The type of convolution
*/
template <typename InType, typename OutType, typename KernType, typename BufferType, vx_uint16 BUFFER_NUM, vx_uint32 VEC_PIX, vx_uint16 VEC_NUM, vx_uint16 KERN_NUM,
		  HIFLIPVX::FilterOperation KERN_TYPE1, HIFLIPVX::FilterOperation KERN_TYPE2, vx_uint16 IMG_COLS, vx_uint16 IMG_ROWS, vx_uint16 KERN_SIZE, vx_border_e BORDER_TYPE, InType THRESH_LOWER, InType THRESH_UPPER>
void ComputeFilter2dFunc(
	vx_image_data<InType, VEC_NUM> input[VEC_PIX],
	vx_image_data<OutType, VEC_NUM> output1[VEC_PIX],
	vx_image_data<OutType, VEC_NUM> output2[VEC_PIX],
	KernType kernel[KERN_NUM][KERN_SIZE][KERN_SIZE],
	const vx_uint64 kernel_mult,
	const vx_uint32 kernel_shift)
{
#pragma HLS INLINE

	// Constants
	const vx_uint16 VEC_COLS = IMG_COLS / VEC_NUM;
	const vx_uint16 KERN_RAD = KERN_SIZE / 2;
	const vx_uint16 WIN_COLS = 2 * KERN_RAD + VEC_NUM + (VEC_NUM - (KERN_RAD % VEC_NUM)) % VEC_NUM;
	const vx_uint16 OHD_COLS = (WIN_COLS - KERN_RAD) / VEC_NUM - 1;
	const vx_uint16 LINE_BUFFER_WIDTH = VEC_NUM * (KERN_SIZE - 1);

	// Linebuffer
	BufferType linebuffer[BUFFER_NUM][VEC_COLS];

	// Sliding window for complete vector
	InType window[KERN_SIZE][WIN_COLS];
#pragma HLS array_partition variable = window complete dim = 0

	// Compute the filter (pipelined)
	vx_uint32 ptr_src = 0, ptr_dst = 0;
	for (vx_uint16 y = 0; y < IMG_ROWS + KERN_RAD; ++y)
	{
		for (vx_uint16 x = 0; x < VEC_COLS + OHD_COLS; ++x)
		{
#pragma HLS PIPELINE II = 1

			InType input_buffer[VEC_NUM];
#pragma HLS array_partition variable = input_buffer complete dim = 0
			InType buffer[KERN_SIZE][VEC_NUM];
#pragma HLS array_partition variable = buffer complete dim = 0

			// Input & Output
			vx_image_data<InType, VEC_NUM> input_data_2d;
			vx_image_data<OutType, VEC_NUM> output_data[KERN_NUM];

			// Read input data from global memory
			if ((y < IMG_ROWS) && (x < VEC_COLS))
			{
				input_data_2d = input[ptr_src];
				++ptr_src;
			}
			for (vx_uint16 v = 0; v < VEC_NUM; v++)
			{
#pragma HLS unroll
				input_buffer[v] = input_data_2d.pixel[v];
			}

			// Read data from line_buffer to buffer
			ReadFromLineBuffer<InType, BufferType, BUFFER_NUM, VEC_NUM, KERN_SIZE, VEC_COLS>(input_buffer, linebuffer, buffer, x);

			// Write data from buffer to line_buffer
			WriteToLineBuffer<InType, BufferType, BUFFER_NUM, VEC_NUM, KERN_SIZE, VEC_COLS>(buffer, linebuffer, x);

			// Move sliding window with replicated/constant border
			SlidingWindow<InType, VEC_NUM, IMG_ROWS, KERN_RAD, VEC_COLS, WIN_COLS, KERN_SIZE, BORDER_TYPE>(buffer, window, x, y);

			// Compute filter
			if (KERN_NUM > 0)
				ComputeFilter<InType, OutType, KernType, VEC_NUM, KERN_NUM, KERN_TYPE1, KERN_SIZE, WIN_COLS, THRESH_LOWER, THRESH_UPPER, IMG_COLS, IMG_ROWS>(window, kernel[0], kernel_mult, kernel_shift, output_data[0], x, y);
			if (KERN_NUM > 1)
				ComputeFilter<InType, OutType, KernType, VEC_NUM, KERN_NUM, KERN_TYPE2, KERN_SIZE, WIN_COLS, THRESH_LOWER, THRESH_UPPER, IMG_COLS, IMG_ROWS>(window, kernel[1], kernel_mult, kernel_shift, output_data[1], x, y);

			// Write output data to global memory
			if ((y >= KERN_RAD) && (x >= OHD_COLS))
			{
				if (KERN_NUM > 0)
					output1[ptr_dst] = output_data[0];
				if (KERN_NUM > 1)
					output2[ptr_dst] = output_data[1];
				++ptr_dst;
			}
		}
	}
}

/*****************************************************************************************************************************************************************************************************/
/* Main Functions (Top) */
/*****************************************************************************************************************************************************************************************************/

/** @brief  Computes multiple 1d convolution filter of kernel_type type
@param ScalarType   Data type of the input/output image (8-bit, 16-bit, 32-bit)
@param KernType     Data type of the kernel (8-bit, 16-bit, 32-bit)
@param VEC_PIX      The amount of pixels diveded by the pixels computed in parallel
@param VEC_NUM      Amount of pixels computed in parallel (1, 2, 4, 8)
@param IMG_COLS     Image width
@param IMG_ROWS     Image height
@param KERN_SIZE    Kernel size (3, 5, 7, 9, 11)
@param BORDER_TYPE  Type of border (Constant, Replicated or Undefined)
@param input        Input image
@param output       Output image
@param kernel       The convolution kernel
@param kernel_mult  Resulting pixels are 1. multiplied by this amount
@param kernel_shift Resulting pixels are 2. shifted to the right by this amount
@param kernel_type  The type of convolution
*/
template <typename ScalarType, typename KernelType, vx_uint32 VEC_PIX, vx_uint16 VEC_NUM, vx_uint16 IMG_COLS, vx_uint16 IMG_ROWS, vx_uint16 KERN_SIZE, HIFLIPVX::FilterOperation KERN_TYPE, vx_border_e BORDER_TYPE>
void ComputeFilter1d(
	vx_image_data<ScalarType, VEC_NUM> input[VEC_PIX],
	vx_image_data<ScalarType, VEC_NUM> output[VEC_PIX],
	KernelType kernel[KERN_SIZE],
	const vx_uint64 kernel_mult,
	const vx_uint32 kernel_shift)
{
#pragma HLS INLINE

	// Check parameter input
	CheckFilterParameters<ScalarType, ScalarType, VEC_NUM, 1, IMG_COLS, KERN_SIZE>();

	// Constants to compute optimum buffer width
	const vx_uint16 DATA_WIDTH = sizeof(ScalarType) * VEC_NUM * (KERN_SIZE - 1);
	const vx_uint16 BUFFER_UINT32 = DATA_WIDTH % 4;
	const vx_uint16 BUFFER_UINT16 = DATA_WIDTH % 2;
	const vx_uint16 BUFFER_NUM = (BUFFER_UINT32 == 0) ? (DATA_WIDTH >> 2) : ((BUFFER_UINT16 == 0) ? (DATA_WIDTH >> 1) : (DATA_WIDTH));
	const vx_uint16 BUFFER_WIDTH = (BUFFER_UINT32 == 0) ? (4) : ((BUFFER_UINT16 == 0) ? (2) : (1));

	// Sets the Buffer Data type to the maximum possible, to reduce the amount of BRAM used
	if (BUFFER_WIDTH == 4)
		ComputeFilter1dFunc<ScalarType, KernelType, vx_uint32, BUFFER_NUM, VEC_PIX, VEC_NUM, IMG_COLS, IMG_ROWS, KERN_SIZE, KERN_TYPE, BORDER_TYPE>(input, output, kernel, kernel_mult, kernel_shift);
	else if (BUFFER_WIDTH == 2)
		ComputeFilter1dFunc<ScalarType, KernelType, vx_uint16, BUFFER_NUM, VEC_PIX, VEC_NUM, IMG_COLS, IMG_ROWS, KERN_SIZE, KERN_TYPE, BORDER_TYPE>(input, output, kernel, kernel_mult, kernel_shift);
	else if (BUFFER_WIDTH == 1)
		ComputeFilter1dFunc<ScalarType, KernelType, vx_uint8, BUFFER_NUM, VEC_PIX, VEC_NUM, IMG_COLS, IMG_ROWS, KERN_SIZE, KERN_TYPE, BORDER_TYPE>(input, output, kernel, kernel_mult, kernel_shift);
}

/** @brief  Computes multiple 2d convolution filter of kernel_type type
@param InType       Data type of the input image (8-bit, 16-bit, 32-bit)
@param OutType      Data type of the output image (8-bit, 16-bit, 32-bit)
@param KernType     Data type of the kernel (8-bit, 16-bit, 32-bit)
@param VEC_PIX      The amount of pixels diveded by the pixels computed in parallel
@param VEC_NUM      Amount of pixels computed in parallel (1, 2, 4, 8)
@param KERN_NUM     Amount of pixels computed in parallel (1, 2)
@param IMG_COLS     Image width
@param IMG_ROWS     Image height
@param KERN_SIZE    Kernel size (3, 5, 7, 9, 11)
@param BORDER_TYPE  Type of border (Constant, Replicated or Undefined)
@param input        Input image
@param output1      1. Output image
@param output2      2. Output image
@param kernel       The convolution kernel
@param kernel_mult  Resulting pixels are 1. multiplied by this amount
@param kernel_shift Resulting pixels are 2. shifted to the right by this amount
@param kernel_type  The type of convolution
*/
template <typename InType, typename OutType, typename KernType, vx_uint32 VEC_PIX, vx_uint16 VEC_NUM, vx_uint16 KERN_NUM, HIFLIPVX::FilterOperation KERN_TYPE1, HIFLIPVX::FilterOperation KERN_TYPE2,
		  vx_uint16 IMG_COLS, vx_uint16 IMG_ROWS, vx_uint16 KERN_SIZE, vx_border_e BORDER_TYPE, InType THRESH_LOWER, InType THRESH_UPPER>
void ComputeFilter2d(
	vx_image_data<InType, VEC_NUM> input[VEC_PIX],
	vx_image_data<OutType, VEC_NUM> output1[VEC_PIX],
	vx_image_data<OutType, VEC_NUM> output2[VEC_PIX],
	KernType kernel[KERN_NUM][KERN_SIZE][KERN_SIZE],
	const vx_uint64 kernel_mult,
	const vx_uint32 kernel_shift)
{
#pragma HLS INLINE

	// Check parameter input
	CheckFilterParameters<InType, OutType, VEC_NUM, KERN_NUM, IMG_COLS, KERN_SIZE>();

	// Constants to compute optimum buffer width
	const vx_uint16 DATA_WIDTH = sizeof(InType) * VEC_NUM * (KERN_SIZE - 1);
	const vx_uint16 BUFFER_UINT32 = DATA_WIDTH % 4;
	const vx_uint16 BUFFER_UINT16 = DATA_WIDTH % 2;
	const vx_uint16 BUFFER_NUM = (BUFFER_UINT32 == 0) ? (DATA_WIDTH >> 2) : ((BUFFER_UINT16 == 0) ? (DATA_WIDTH >> 1) : (DATA_WIDTH));
	const vx_uint16 BUFFER_WIDTH = (BUFFER_UINT32 == 0) ? (4) : ((BUFFER_UINT16 == 0) ? (2) : (1));

	// Sets the Buffer Data type to the maximum possible, to reduce the amount of BRAM used
	if (BUFFER_WIDTH == 4)
		ComputeFilter2dFunc<InType, OutType, KernType, vx_uint32, BUFFER_NUM, VEC_PIX, VEC_NUM, KERN_NUM, KERN_TYPE1, KERN_TYPE2, IMG_COLS, IMG_ROWS, KERN_SIZE, BORDER_TYPE, THRESH_LOWER, THRESH_UPPER>(input, output1, output2, kernel, kernel_mult, kernel_shift);
	else if (BUFFER_WIDTH == 2)
		ComputeFilter2dFunc<InType, OutType, KernType, vx_uint16, BUFFER_NUM, VEC_PIX, VEC_NUM, KERN_NUM, KERN_TYPE1, KERN_TYPE2, IMG_COLS, IMG_ROWS, KERN_SIZE, BORDER_TYPE, THRESH_LOWER, THRESH_UPPER>(input, output1, output2, kernel, kernel_mult, kernel_shift);
	else if (BUFFER_WIDTH == 1)
		ComputeFilter2dFunc<InType, OutType, KernType, vx_uint8, BUFFER_NUM, VEC_PIX, VEC_NUM, KERN_NUM, KERN_TYPE1, KERN_TYPE2, IMG_COLS, IMG_ROWS, KERN_SIZE, BORDER_TYPE, THRESH_LOWER, THRESH_UPPER>(input, output1, output2, kernel, kernel_mult, kernel_shift);
}

/*****************************************************************************************************************************************************************************************************/
/* Filter Function Definition */
/*****************************************************************************************************************************************************************************************************/

/** @brief  Computes a Box filter over a window of the input image. The output image dimensions should be the same as the dimensions of the input image.
@param DataType    Data type of the input/output image (unsigned)(8-bit, 16-bit, 32-bit)
@param VEC_PIX     The amount of pixels diveded by the pixels computed in parallel
@param VEC_NUM     Amount of pixels computed in parallel (1, 2, 4, 8)
@param WIDTH       Image width
@param HEIGHT      Image height
@param KERN_SIZE   Kernel size (3, 5, 7, 9, 11)
@param BORDER_TYPE Type of border (Constant, Replicated or Undefined)
@param SEPARABLE   Is true, if separable filter should be used
@param input       Input image
@param output      Output image
*/
template <typename ScalarType, vx_uint32 VEC_PIX, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE, vx_bool SEPARABLE>
void HwBox(vx_image_data<ScalarType, VEC_NUM> input[VEC_PIX], vx_image_data<ScalarType, VEC_NUM> output[VEC_PIX])
{
#pragma HLS INLINE

	// Check function parameters/types
	STATIC_ASSERT(numeric_limits<ScalarType>::is_signed == false, scalar_type_must_be_unsigned);

	// Kernel Type
	typedef vx_uint16 KernelType;

	// Kernel Parameters
	const vx_uint8 KERN_NUM = 1;
	vx_uint64 kernel_mult = 1;
	vx_uint32 kernel_shift = 0;
	const ScalarType THRESH_LOWER = 0;
	const ScalarType THRESH_UPPER = 0;

	if (SEPARABLE == vx_false_e)
	{

		// Function Input
		KernelType kernel_vector[KERN_NUM][KERN_SIZE][KERN_SIZE];
#pragma HLS array_partition variable = kernel_vector complete dim = 0

		// Compute kernel and normalization (Compile-Time)
		for (vx_uint8 y = 0; y < KERN_SIZE; y++)
		{
#pragma HLS unroll
			for (vx_uint8 x = 0; x < KERN_SIZE; x++)
			{
#pragma HLS unroll
				kernel_vector[0][y][x] = 1;
			}
		}
		ComputeNormalization2d<KernelType, KERN_SIZE>(kernel_vector[0], kernel_mult, kernel_shift);

		// Compute Filter
		ComputeFilter2d<ScalarType, ScalarType, KernelType, VEC_PIX, VEC_NUM, KERN_NUM, HIFLIPVX::BOX_FILTER, HIFLIPVX::BOX_FILTER, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE, THRESH_LOWER, THRESH_UPPER>(input, output, NULL, kernel_vector, kernel_mult, kernel_shift);
	}
	else
	{

		// Function Input
		KernelType kernel_vector[KERN_SIZE];
#pragma HLS array_partition variable = kernel_vector complete dim = 0

		// Compute kernel and normalization (Compile-Time)
		for (vx_uint8 i = 0; i < KERN_SIZE; i++)
		{
#pragma HLS unroll
			kernel_vector[i] = 1;
		}
		ComputeNormalization1d<KernelType, KERN_SIZE>(kernel_vector, kernel_mult, kernel_shift);

		// Compute Filter
		ComputeFilter1d<ScalarType, KernelType, VEC_PIX, VEC_NUM, WIDTH, HEIGHT, KERN_SIZE, HIFLIPVX::BOX_FILTER, BORDER_TYPE>(input, output, kernel_vector, kernel_mult, kernel_shift);
	}
}

/** @brief  Convolves the input with the client supplied convolution matrix. The output image dimensions should be the same as the dimensions of the input image.
@param DataType    Data type of the input/output image (unsigned, signed)(8-bit, 16-bit, 32-bit)
@param VEC_PIX     The amount of pixels diveded by the pixels computed in parallel
@param VEC_NUM     Amount of pixels computed in parallel (1, 2, 4, 8)
@param WIDTH       Image width
@param HEIGHT      Image height
@param KERN_SIZE   Kernel size (3, 5, 7, 9, 11)
@param BORDER_TYPE Type of border (Constant, Replicated or Undefined)
@param input       Input image
@param output      Output image
@param conv        The custom convolution kernel
*/
template <typename ScalarType, vx_uint32 VEC_PIX, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE>
void HwConvolve(vx_image_data<ScalarType, VEC_NUM> input[VEC_PIX], vx_image_data<ScalarType, VEC_NUM> output[VEC_PIX], const ScalarType conv[KERN_SIZE][KERN_SIZE])
{
#pragma HLS INLINE

	// Kernel Parameters
	const vx_uint8 KERN_NUM = 1;
	vx_uint64 kernel_mult = 1;
	vx_uint32 kernel_shift = 0;
	const ScalarType THRESH_LOWER = 0;
	const ScalarType THRESH_UPPER = 0;

	// Function Input
	ScalarType kernel_vector[KERN_NUM][KERN_SIZE][KERN_SIZE];
#pragma HLS array_partition variable = kernel_vector complete dim = 0

	// Compute kernel and normalization (Compile-Time)
	for (vx_uint8 i = 0; i < KERN_SIZE; i++)
	{
#pragma HLS unroll
		for (vx_uint8 j = 0; j < KERN_SIZE; j++)
		{
#pragma HLS unroll
			kernel_vector[0][i][j] = conv[i][j];
		}
	}
	ComputeNormalization2d<ScalarType, KERN_SIZE>(kernel_vector[0], kernel_mult, kernel_shift);

	// Compute Filter
	ComputeFilter2d<ScalarType, ScalarType, ScalarType, VEC_PIX, VEC_NUM, KERN_NUM, HIFLIPVX::CUSTOM_CONVOLUTION, HIFLIPVX::CUSTOM_CONVOLUTION, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE, THRESH_LOWER, THRESH_UPPER>(input, output, NULL, kernel_vector, kernel_mult, kernel_shift);
}

/** @brief  Implements Dilation, which grows the white space in a Boolean image. The output image dimensions should be the same as the dimensions of the input image.
@param DataType    Data type of the input/output image (unsigned)(8-bit, 16-bit, 32-bit)
@param VEC_PIX     The amount of pixels diveded by the pixels computed in parallel
@param VEC_NUM     Amount of pixels computed in parallel (1, 2, 4, 8)
@param WIDTH       Image width
@param HEIGHT      Image height
@param KERN_SIZE   Kernel size (3, 5, 7, 9, 11)
@param BORDER_TYPE Type of border (Constant, Replicated or Undefined)
@param input       Input image
@param output      Output image
*/
template <typename ScalarType, vx_uint32 VEC_PIX, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE>
void HwDilate(vx_image_data<ScalarType, VEC_NUM> input[VEC_PIX], vx_image_data<ScalarType, VEC_NUM> output[VEC_PIX])
{
#pragma HLS INLINE

	// Check function parameters/types
	STATIC_ASSERT(numeric_limits<ScalarType>::is_signed == false, scalar_type_must_be_unsigned);

	// Kernel Parameters
	typedef vx_uint16 KernelType;

	// Function Input
	KernelType kernel_vector[KERN_SIZE];
#pragma HLS array_partition variable = kernel_vector complete dim = 0

	// Kernel normalization and type
	const vx_uint64 kernel_mult = 1;
	const vx_uint32 kernel_shift = 0;

	// Compute Filter
	ComputeFilter1d<ScalarType, KernelType, VEC_PIX, VEC_NUM, WIDTH, HEIGHT, KERN_SIZE, HIFLIPVX::DILATE_IMAGE, BORDER_TYPE>(input, output, kernel_vector, kernel_mult, kernel_shift);
}

/** @brief  Implements Erosion, which shrinks the white space in a Boolean image. The output image dimensions should be the same as the dimensions of the input image.
@param DataType    Data type of the input/output image (unsigned)(8-bit, 16-bit, 32-bit)
@param VEC_PIX     The amount of pixels diveded by the pixels computed in parallel
@param VEC_NUM     Amount of pixels computed in parallel (1, 2, 4, 8)
@param WIDTH       Image width
@param HEIGHT      Image height
@param KERN_SIZE   Kernel size (3, 5, 7, 9, 11)
@param BORDER_TYPE Type of border (Constant, Replicated or Undefined)
@param input       Input image
@param output      Output image
*/
template <typename ScalarType, vx_uint32 VEC_PIX, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE>
void HwErode(vx_image_data<ScalarType, VEC_NUM> input[VEC_PIX], vx_image_data<ScalarType, VEC_NUM> output[VEC_PIX])
{
#pragma HLS INLINE

	// Check function parameters/types
	STATIC_ASSERT(numeric_limits<ScalarType>::is_signed == false, scalar_type_must_be_unsigned);

	// Kernel Parameters
	typedef vx_uint16 KernelType;

	// Function Input
	KernelType kernel_vector[KERN_SIZE];
#pragma HLS array_partition variable = kernel_vector complete dim = 0

	// Kernel normalization and type
	const vx_uint64 kernel_mult = 1;
	const vx_uint32 kernel_shift = 0;

	// Compute Filter
	ComputeFilter1d<ScalarType, KernelType, VEC_PIX, VEC_NUM, WIDTH, HEIGHT, KERN_SIZE, HIFLIPVX::ERODE_IMAGE, BORDER_TYPE>(input, output, kernel_vector, kernel_mult, kernel_shift);
}

/** @brief  Computes a Gaussian filter over a window of the input image. The output image dimensions should be the same as the dimensions of the input image.
@param DataType    Data type of the input/output image (unsigned)(8-bit, 16-bit, 32-bit)
@param VEC_PIX     The amount of pixels diveded by the pixels computed in parallel
@param VEC_NUM     Amount of pixels computed in parallel (1, 2, 4, 8)
@param WIDTH       Image width
@param HEIGHT      Image height
@param KERN_SIZE   Kernel size (3, 5, 7, 9, 11)
@param BORDER_TYPE Type of border (Constant, Replicated or Undefined)
@param SEPARABLE   Is true, if separable filter should be used
@param input       Input image
@param output      Output image
*/
template <typename ScalarType, vx_uint32 VEC_PIX, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE, vx_bool SEPARABLE>
void HwGaussian(vx_image_data<ScalarType, VEC_NUM> input[VEC_PIX], vx_image_data<ScalarType, VEC_NUM> output[VEC_PIX])
{
#pragma HLS INLINE

	// Check function parameters/types
	STATIC_ASSERT(numeric_limits<ScalarType>::is_signed == false, scalar_type_must_be_unsigned);

	// Kernel Type
	typedef vx_uint16 KernelType;

	// Kernel Parameters
	const vx_uint8 KERN_NUM = 1;
	vx_uint64 kernel_mult = 1;
	vx_uint32 kernel_shift = 0;
	const ScalarType THRESH_LOWER = 0;
	const ScalarType THRESH_UPPER = 0;

	if (SEPARABLE == vx_false_e)
	{

		// Function Input
		KernelType kernel_vector[KERN_NUM][KERN_SIZE][KERN_SIZE];
#pragma HLS array_partition variable = kernel_vector complete dim = 0

		// Compute kernel and normalization (Compile-Time)
		ComputeGaussianKernels<KernelType, KERN_SIZE>(kernel_vector[0]);
		ComputeNormalization2d<KernelType, KERN_SIZE>(kernel_vector[0], kernel_mult, kernel_shift);

		// Compute Filter
		ComputeFilter2d<ScalarType, ScalarType, KernelType, VEC_PIX, VEC_NUM, KERN_NUM, HIFLIPVX::GAUSSIAN_FILTER, HIFLIPVX::GAUSSIAN_FILTER, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE, THRESH_LOWER, THRESH_UPPER>(input, output, NULL, kernel_vector, kernel_mult, kernel_shift);
	}
	else
	{

		// Function Input
		KernelType kernel_vector[KERN_SIZE][KERN_SIZE];
#pragma HLS array_partition variable = kernel_vector complete dim = 0

		// Compute kernel and normalization (Compile-Time)
		ComputeGaussianKernels<KernelType, KERN_SIZE>(kernel_vector);
		ComputeNormalization1d<KernelType, KERN_SIZE>(kernel_vector[0], kernel_mult, kernel_shift);

		// Compute Filter
		ComputeFilter1d<ScalarType, KernelType, VEC_PIX, VEC_NUM, WIDTH, HEIGHT, KERN_SIZE, HIFLIPVX::GAUSSIAN_FILTER, BORDER_TYPE>(input, output, kernel_vector[0], kernel_mult, kernel_shift);
	}
}

/** @brief  Computes a median pixel value over a window of the input image. The output image dimensions should be the same as the dimensions of the input image.
@param DataType    Data type of the input/output image (unsigned)(8-bit, 16-bit, 32-bit)
@param VEC_PIX     The amount of pixels diveded by the pixels computed in parallel
@param VEC_NUM     Amount of pixels computed in parallel (1, 2, 4, 8)
@param WIDTH       Image width
@param HEIGHT      Image height
@param KERN_SIZE   Kernel size (3, 5, 7, 9, 11)
@param BORDER_TYPE Type of border (Constant, Replicated or Undefined)
@param input       Input image
@param output      Output image
*/
template <typename ScalarType, vx_uint32 VEC_PIX, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE>
void HwMedian(vx_image_data<ScalarType, VEC_NUM> input[VEC_PIX], vx_image_data<ScalarType, VEC_NUM> output[VEC_PIX])
{
#pragma HLS INLINE

	// Check function parameters/types
	STATIC_ASSERT(numeric_limits<ScalarType>::is_signed == false, scalar_type_must_be_unsigned);

	// Kernel Type
	typedef vx_uint16 KernelType;

	// Kernel Parameters
	const vx_uint8 KERN_NUM = 1;
	const vx_uint64 kernel_mult = 1;
	const vx_uint32 kernel_shift = 0;
	const ScalarType THRESH_LOWER = 0;
	const ScalarType THRESH_UPPER = 0;

	// Function Input
	KernelType kernel_vector[KERN_NUM][KERN_SIZE][KERN_SIZE];
#pragma HLS array_partition variable = kernel_vector complete dim = 0

	// Compute Filter
	ComputeFilter2d<ScalarType, ScalarType, KernelType, VEC_PIX, VEC_NUM, KERN_NUM, HIFLIPVX::MEDIAN_FILTER, HIFLIPVX::MEDIAN_FILTER, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE, THRESH_LOWER, THRESH_UPPER>(input, output, NULL, kernel_vector, kernel_mult, kernel_shift);
}

/** @brief  Implements the Scharr Image Filter Kernel. The output images dimensions should be the same as the dimensions of the input image.
@param SrcType     Data type of the input image (unsigned)(8-bit, 16-bit, 32-bit)
@param DstType     Data type of the output image (signed)(8-bit, 16-bit, 32-bit)
@param VEC_PIX     The amount of pixels diveded by the pixels computed in parallel
@param VEC_NUM     Amount of pixels computed in parallel (1, 2, 4, 8)
@param WIDTH       Image width
@param HEIGHT      Image height
@param BORDER_TYPE Type of border (Constant, Replicated or Undefined)
@param input       The input image
@param output1     The output image (x derivative)
@param output2     The output image (y derivative)
*/
template <typename InType, typename OutType, vx_uint32 VEC_PIX, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_border_e BORDER_TYPE>
void HwScharr3x3(vx_image_data<InType, VEC_NUM> input[VEC_PIX], vx_image_data<OutType, VEC_NUM> output1[VEC_PIX], vx_image_data<OutType, VEC_NUM> output2[VEC_PIX])
{
#pragma HLS INLINE

	// Check function parameters/types
	STATIC_ASSERT(numeric_limits<InType>::is_signed == false, derivative_input_must_be_unsigned);
	STATIC_ASSERT(numeric_limits<OutType>::is_signed == true, derivative_output_must_be_signed);

	// Kernel Type
	typedef vx_int16 KernelType;

	// Kernel Parameters
	const vx_uint8 KERN_NUM = 2;
	const vx_uint8 KERN_SIZE = 3;
	const vx_uint64 kernel_mult = 1;
	const vx_uint32 kernel_shift = 5;
	const InType THRESH_LOWER = 0;
	const InType THRESH_UPPER = 0;

	// Function Input
	KernelType kernel_vector[2][KERN_SIZE][KERN_SIZE] = {
		{
			{3, 0, -3},
			{10, 0, -10},
			{3, 0, -3},
		},
		{
			{3, 10, 3},
			{0, 0, 0},
			{-3, -10, -3},
		}};
#pragma HLS array_partition variable = kernel_vector complete dim = 0

	// Compute Filter
	ComputeFilter2d<InType, OutType, KernelType, VEC_PIX, VEC_NUM, KERN_NUM, HIFLIPVX::DERIVATIVE_X, HIFLIPVX::DERIVATIVE_Y, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE, THRESH_LOWER, THRESH_UPPER>(input, output1, output2, kernel_vector, kernel_mult, kernel_shift);
}

/** @brief  Implements the Sobel Image Filter Kernel. The output images dimensions should be the same as the dimensions of the input image.
@param SrcType     Data type of the input image (unsigned)(8-bit, 16-bit, 32-bit)
@param DstType     Data type of the output image (signed)(8-bit, 16-bit, 32-bit)
@param VEC_PIX     The amount of pixels diveded by the pixels computed in parallel
@param VEC_NUM     Amount of pixels computed in parallel (1, 2, 4, 8)
@param WIDTH       Image width
@param HEIGHT      Image height
@param KERN_SIZE   Kernel size (3, 5, 7, 9, 11)
@param BORDER_TYPE Type of border (Constant, Replicated or Undefined)
@param input       The input image
@param output1     The output image (x derivative)
@param output2     The output image (y derivative)
*/
template <typename InType, typename OutType, vx_uint32 VEC_PIX, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE>
void HwSobel(vx_image_data<InType, VEC_NUM> input[VEC_PIX], vx_image_data<OutType, VEC_NUM> output1[VEC_PIX], vx_image_data<OutType, VEC_NUM> output2[VEC_PIX])
{
#pragma HLS INLINE

	// Check function parameters/types
	STATIC_ASSERT(numeric_limits<InType>::is_signed == false, input_must_be_unsigned);
	STATIC_ASSERT(numeric_limits<OutType>::is_signed == true, output_must_be_signed);

	// Kernel Type
	typedef vx_int16 KernelType;

	// Kernel Amount
	const vx_uint8 KERN_NUM = 2;

	// Kernel Normalization
	vx_uint64 kernel_mult = 1;
	vx_uint32 kernel_shift = 0;
	const InType THRESH_LOWER = 0;
	const InType THRESH_UPPER = 0;

	// Function Input
	KernelType kernel_vector[KERN_NUM][KERN_SIZE][KERN_SIZE];
#pragma HLS array_partition variable = kernel_vector complete dim = 0

	// Compute kernel and normalization (Compile-Time)
	ComputeSobelKernels<KernelType, KERN_SIZE>(kernel_vector[0], kernel_vector[1]);
	ComputeNormalization2d<KernelType, KERN_SIZE>(kernel_vector[0], kernel_mult, kernel_shift);

	// Compute Filter
	ComputeFilter2d<InType, OutType, KernelType, VEC_PIX, VEC_NUM, KERN_NUM, HIFLIPVX::DERIVATIVE_X, HIFLIPVX::DERIVATIVE_Y, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE, THRESH_LOWER, THRESH_UPPER>(input, output1, output2, kernel_vector, kernel_mult, kernel_shift);
}

/** @brief  Find local maxima in an image, or otherwise suppress pixels that are not local maxima.
@param DataType    Data type of the input/output image (unsigned, signed)(8-bit, 16-bit, 32-bit)
@param VEC_PIX     The amount of pixels diveded by the pixels computed in parallel
@param VEC_NUM     Amount of pixels computed in parallel (1, 2, 4, 8)
@param WIDTH       Image width
@param HEIGHT      Image height
@param KERN_SIZE   The size of window over which to perform the localized non-maxima suppression (3, 5, 7, 9, 11)
@param BORDER_TYPE Type of border (Constant, Replicated or Undefined)
@param input       Input image
@param output      Output image
@param mask        Constrict suppression to a ROI.
*/
template <typename DataType, vx_uint32 VEC_PIX, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE>
void HwNonMaxSuppression(vx_image_data<DataType, VEC_NUM> input[VEC_PIX], vx_image_data<DataType, VEC_NUM> output[VEC_PIX], const vx_uint8 mask[KERN_SIZE][KERN_SIZE])
{
#pragma HLS INLINE

	// Kernel Parameters
	const vx_uint8 KERN_NUM = 1;
	vx_uint64 kernel_mult = 1;
	vx_uint32 kernel_shift = 0;
	const DataType THRESH_LOWER = 0;
	const DataType THRESH_UPPER = 0;

	// Function Input
	vx_uint8 mask_vector[KERN_NUM][KERN_SIZE][KERN_SIZE];
#pragma HLS array_partition variable = mask_vector complete dim = 0

	// Compute kernel and normalization (Compile-Time)
	for (vx_uint8 i = 0; i < KERN_SIZE; i++)
	{
#pragma HLS unroll
		for (vx_uint8 j = 0; j < KERN_SIZE; j++)
		{
#pragma HLS unroll
			mask_vector[0][i][j] = mask[i][j];
		}
	}

	// Compute Filter
	ComputeFilter2d<DataType, DataType, vx_uint8, VEC_PIX, VEC_NUM, KERN_NUM, HIFLIPVX::NON_MAX_SUPPRESSION, HIFLIPVX::NON_MAX_SUPPRESSION, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE, THRESH_LOWER, THRESH_UPPER>(input, output, NULL, mask_vector, kernel_mult, kernel_shift);
}

//
template <typename ScalarType, vx_uint32 VEC_PIX, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_border_e BORDER_TYPE>
void HwSegmentTestDetector(vx_image_data<ScalarType, VEC_NUM> input[VEC_PIX], vx_image_data<ScalarType, VEC_NUM> output[VEC_PIX])
{
#pragma HLS INLINE

	// Kernel Parameters
	const vx_uint8 KERN_NUM = 1;
	const vx_uint8 KERN_SIZE = 7;
	const ScalarType THRESH_LOWER = 0;
	const ScalarType THRESH_UPPER = 0;
	vx_uint64 kernel_mult = 1;
	vx_uint32 kernel_shift = 0;

	// Function Input
	ScalarType kernel_vector[KERN_NUM][KERN_SIZE][KERN_SIZE];
#pragma HLS array_partition variable = kernel_vector complete dim = 0

	// Compute Filter
	ComputeFilter2d<ScalarType, ScalarType, ScalarType, VEC_PIX, VEC_NUM, KERN_NUM, HIFLIPVX::SEGMENT_TEST_DETECTOR, HIFLIPVX::SEGMENT_TEST_DETECTOR, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE, THRESH_LOWER, THRESH_UPPER>(input, output, NULL, kernel_vector, kernel_mult, kernel_shift);
}

//
template <typename ScalarType, vx_uint32 VEC_PIX, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE, ScalarType THRESH_LOWER, ScalarType THRESH_UPPER>
void HwHysteresis(vx_image_data<ScalarType, VEC_NUM> input[VEC_PIX], vx_image_data<ScalarType, VEC_NUM> output[VEC_PIX])
{
#pragma HLS INLINE

	// Kernel Parameters
	const vx_uint8 KERN_NUM = 1;
	vx_uint64 kernel_mult = 1;
	vx_uint32 kernel_shift = 0;

	// Function Input
	ScalarType kernel_vector[KERN_NUM][KERN_SIZE][KERN_SIZE];
#pragma HLS array_partition variable = kernel_vector complete dim = 0

	// Compute Filter
	ComputeFilter2d<ScalarType, ScalarType, ScalarType, VEC_PIX, VEC_NUM, KERN_NUM, HIFLIPVX::HYSTERESIS, HIFLIPVX::HYSTERESIS, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE, THRESH_LOWER, THRESH_UPPER>(input, output, NULL, kernel_vector, kernel_mult, kernel_shift);
}

template <typename InType, typename OutType, vx_uint32 KERN_SIZE, vx_uint32 QUANTIZATION>
OutType ComputeOrientedNonMaxSuppression(InType window1[KERN_SIZE][KERN_SIZE], InType window2[KERN_SIZE][KERN_SIZE])
{
#pragma HLS INLINE

	// Constants
	const InType max_val = std::numeric_limits<InType>::max();
	const InType min_val = std::numeric_limits<InType>::min();
	const vx_uint16 KERN_RAD = KERN_SIZE >> 1;

	// Input pixel
	InType input = window1[KERN_RAD][KERN_RAD];
	InType orientation = window2[KERN_RAD][KERN_RAD];

	// Downscale quantization
	if (QUANTIZATION > 3)
		orientation = orientation >> (QUANTIZATION - 3);

	// Get the pixels in perpendicular lines
	InType a = max_val, b = max_val;
	if (orientation == 0 || orientation == 4)
	{
		a = window1[0][1]; // north
		b = window1[2][1]; // south
	}
	else if (orientation == 1 || orientation == 5)
	{
		a = window1[0][0]; // north/west
		b = window1[2][2]; // south/east
	}
	else if (orientation == 2 || orientation == 6)
	{
		a = window1[1][0]; // west
		b = window1[1][2]; // east
	}
	else if (orientation == 3 || orientation == 7)
	{
		a = window1[2][0]; // south/west
		b = window1[0][2]; // north/east
	}

	// Suppress input to minimum possible value, if it is not a maxima
	InType output = ((input >= a) || (input >= b)) ? (input) : (min_val);
	return static_cast<OutType>(output);
}

template <typename InType, typename OutType, vx_uint32 VEC_NUM, HIFLIPVX::FilterOperation KERN_TYPE, vx_uint32 KERN_SIZE, vx_uint32 WIN_COLS, vx_uint16 IMG_ROWS, vx_uint32 IMG_COLS, vx_uint32 QUANTIZATION>
void ComputeFilter_2input(InType window1[KERN_SIZE][WIN_COLS], InType window2[KERN_SIZE][WIN_COLS], vx_image_data<OutType, VEC_NUM> &output, const vx_uint16 x, const vx_uint16 y)
{
#pragma HLS INLINE

	// Constants
	const vx_uint16 VEC_COLS = IMG_COLS / VEC_NUM;
	const vx_uint16 KERN_RAD = KERN_SIZE / 2;
	const vx_uint16 OHD_COLS = (WIN_COLS - KERN_RAD) / VEC_NUM - 1;

	// Output
	vx_image_data<OutType, VEC_NUM> output_vector;

	// Compute KERN_NUM different filter with VEC_NUM elements per clock cycle
	for (vx_uint16 vecId = 0; vecId < VEC_NUM; vecId++)
	{
#pragma HLS unroll

		// Window for single vector element
		InType kernel_window1[KERN_SIZE][KERN_SIZE];
#pragma HLS array_partition variable = kernel_window1 complete dim = 0
		InType kernel_window2[KERN_SIZE][KERN_SIZE];
#pragma HLS array_partition variable = kernel_window2 complete dim = 0

		// Get window for single vector element
		for (vx_uint16 i = 0; i < KERN_SIZE; i++)
		{
#pragma HLS unroll
			for (vx_uint16 j = 0; j < KERN_SIZE; j++)
			{
#pragma HLS unroll
				kernel_window1[i][j] = window1[i][j + vecId];
				kernel_window2[i][j] = window2[i][j + vecId];
			}
		}

		// Compute filter for single vector element
		OutType result = 0;
		if (KERN_TYPE == HIFLIPVX::ORIENTED_NON_MAX_SUPPRESSION)
		{
			result = ComputeOrientedNonMaxSuppression<InType, OutType, KERN_SIZE, QUANTIZATION>(kernel_window1, kernel_window2);
		}

		output_vector.pixel[vecId] = result;
	}

	// Set user(SOF) & last(EOF)
	const bool sof = ((y == KERN_RAD) && (x == OHD_COLS));
	const bool eof = ((y == (IMG_ROWS + KERN_RAD - 1)) && (x == (VEC_COLS + OHD_COLS - 1)));
	GenerateDmaSignal<OutType, VEC_NUM>(sof, eof, output_vector);

	// Write output
	output = output_vector;
}

template <typename InType, typename OutType, typename BufferType, vx_uint32 BUFFER_NUM, vx_uint32 VEC_PIX, vx_uint32 VEC_NUM, HIFLIPVX::FilterOperation KERN_TYPE,
		  vx_uint16 IMG_COLS, vx_uint16 IMG_ROWS, vx_uint16 KERN_SIZE, vx_border_e BORDER_TYPE1, vx_border_e BORDER_TYPE2, vx_uint32 QUANTIZATION>
void ComputeFilter2dFunc_2input(
	vx_image_data<InType, VEC_NUM> input1[VEC_PIX],
	vx_image_data<InType, VEC_NUM> input2[VEC_PIX],
	vx_image_data<OutType, VEC_NUM> output[VEC_PIX])
{
#pragma HLS INLINE

	// Constants
	const vx_uint16 VEC_COLS = IMG_COLS / VEC_NUM;
	const vx_uint16 KERN_RAD = KERN_SIZE / 2;
	const vx_uint16 WIN_COLS = 2 * KERN_RAD + VEC_NUM + (VEC_NUM - (KERN_RAD % VEC_NUM)) % VEC_NUM;
	const vx_uint16 OHD_COLS = (WIN_COLS - KERN_RAD) / VEC_NUM - 1;

	// Linebuffer
	BufferType linebuffer1[BUFFER_NUM][VEC_COLS];
	BufferType linebuffer2[BUFFER_NUM][VEC_COLS];

	// Sliding window for complete vector
	InType window1[KERN_SIZE][WIN_COLS];
#pragma HLS array_partition variable = window1 complete dim = 0
	InType window2[KERN_SIZE][WIN_COLS];
#pragma HLS array_partition variable = window2 complete dim = 0

	// Compute the filter (pipelined)
	vx_uint32 ptr_src = 0, ptr_dst = 0;
	for (vx_uint16 y = 0; y < IMG_ROWS + KERN_RAD; ++y)
	{
		for (vx_uint16 x = 0; x < VEC_COLS + OHD_COLS; ++x)
		{
#pragma HLS PIPELINE II = 1

			InType input_buffer1[VEC_NUM];
#pragma HLS array_partition variable = input_buffer1 complete dim = 0
			InType input_buffer2[VEC_NUM];
#pragma HLS array_partition variable = input_buffer2 complete dim = 0
			InType buffer1[KERN_SIZE][VEC_NUM];
#pragma HLS array_partition variable = buffer1 complete dim = 0
			InType buffer2[KERN_SIZE][VEC_NUM];
#pragma HLS array_partition variable = buffer2 complete dim = 0

			// Input & Output
			vx_image_data<InType, VEC_NUM> input_data1;
			vx_image_data<InType, VEC_NUM> input_data2;
			vx_image_data<OutType, VEC_NUM> output_data;

			// Read input data from global memory
			if ((y < IMG_ROWS) && (x < VEC_COLS))
			{
				input_data1 = input1[ptr_src];
				input_data2 = input2[ptr_src];
				++ptr_src;
			}
			for (vx_uint16 v = 0; v < VEC_NUM; v++)
			{
#pragma HLS unroll
				input_buffer1[v] = input_data1.pixel[v];
				input_buffer2[v] = input_data2.pixel[v];
			}

			// Read data from line_buffer to buffer
			ReadFromLineBuffer<InType, BufferType, BUFFER_NUM, VEC_NUM, KERN_SIZE, VEC_COLS>(input_buffer1, linebuffer1, buffer1, x);
			ReadFromLineBuffer<InType, BufferType, BUFFER_NUM, VEC_NUM, KERN_SIZE, VEC_COLS>(input_buffer2, linebuffer2, buffer2, x);

			// Write data from buffer to line_buffer
			WriteToLineBuffer<InType, BufferType, BUFFER_NUM, VEC_NUM, KERN_SIZE, VEC_COLS>(buffer1, linebuffer1, x);
			WriteToLineBuffer<InType, BufferType, BUFFER_NUM, VEC_NUM, KERN_SIZE, VEC_COLS>(buffer2, linebuffer2, x);

			// Move sliding window with replicated/constant border
			SlidingWindow<InType, VEC_NUM, IMG_ROWS, KERN_RAD, VEC_COLS, WIN_COLS, KERN_SIZE, BORDER_TYPE1>(buffer1, window1, x, y);
			SlidingWindow<InType, VEC_NUM, IMG_ROWS, KERN_RAD, VEC_COLS, WIN_COLS, KERN_SIZE, BORDER_TYPE2>(buffer2, window2, x, y);

			// Compute filter
			ComputeFilter_2input<InType, OutType, VEC_NUM, KERN_TYPE, KERN_SIZE, WIN_COLS, IMG_ROWS, IMG_COLS, QUANTIZATION>(window1, window2, output_data, x, y);

			// Write output data to global memory
			if ((y >= KERN_RAD) && (x >= OHD_COLS))
			{
				output[ptr_dst] = output_data;
				++ptr_dst;
			}
		}
	}
}

template <typename InType, typename OutType, vx_uint32 VEC_PIX, vx_uint32 VEC_NUM, HIFLIPVX::FilterOperation KERN_TYPE, vx_uint32 IMG_COLS, vx_uint32 IMG_ROWS, vx_uint32 KERN_SIZE, vx_border_e BORDER_TYPE1, vx_border_e BORDER_TYPE2, vx_uint32 QUANTIZATION>
void ComputeFilter2d_2input(
	vx_image_data<InType, VEC_NUM> input[VEC_PIX],
	vx_image_data<InType, VEC_NUM> input_no_window[VEC_PIX],
	vx_image_data<OutType, VEC_NUM> output[VEC_PIX])
{
#pragma HLS INLINE

	// Check parameter input
	CheckFilterParameters<InType, OutType, VEC_NUM, 1, IMG_COLS, KERN_SIZE>();

	// Constants to compute optimum buffer width
	const vx_uint16 DATA_WIDTH = sizeof(InType) * VEC_NUM * (KERN_SIZE - 1);
	const vx_uint16 BUFFER_UINT32 = DATA_WIDTH % 4;
	const vx_uint16 BUFFER_UINT16 = DATA_WIDTH % 2;
	const vx_uint16 BUFFER_NUM = (BUFFER_UINT32 == 0) ? (DATA_WIDTH >> 2) : ((BUFFER_UINT16 == 0) ? (DATA_WIDTH >> 1) : (DATA_WIDTH));
	const vx_uint16 BUFFER_WIDTH = (BUFFER_UINT32 == 0) ? (4) : ((BUFFER_UINT16 == 0) ? (2) : (1));

	// Sets the Buffer Data type to the maximum possible, to reduce the amount of BRAM used
	if (BUFFER_WIDTH == 4)
		ComputeFilter2dFunc_2input<InType, OutType, vx_uint32, BUFFER_NUM, VEC_PIX, VEC_NUM, KERN_TYPE, IMG_COLS, IMG_ROWS, KERN_SIZE, BORDER_TYPE1, BORDER_TYPE2, QUANTIZATION>(input, input_no_window, output);
	if (BUFFER_WIDTH == 2)
		ComputeFilter2dFunc_2input<InType, OutType, vx_uint16, BUFFER_NUM, VEC_PIX, VEC_NUM, KERN_TYPE, IMG_COLS, IMG_ROWS, KERN_SIZE, BORDER_TYPE1, BORDER_TYPE2, QUANTIZATION>(input, input_no_window, output);
	if (BUFFER_WIDTH == 1)
		ComputeFilter2dFunc_2input<InType, OutType, vx_uint8, BUFFER_NUM, VEC_PIX, VEC_NUM, KERN_TYPE, IMG_COLS, IMG_ROWS, KERN_SIZE, BORDER_TYPE1, BORDER_TYPE2, QUANTIZATION>(input, input_no_window, output);
}

template <typename ScalarType, vx_uint32 VEC_PIX, vx_uint32 VEC_NUM, vx_uint32 WIDTH, vx_uint32 HEIGHT, vx_border_e BORDER_TYPE, vx_uint32 QUANTIZATION>
void HwOrientedNonMaxSuppression(
	vx_image_data<ScalarType, VEC_NUM> input[VEC_PIX],
	vx_image_data<ScalarType, VEC_NUM> input_no_window[VEC_PIX],
	vx_image_data<ScalarType, VEC_NUM> output[VEC_PIX])
{
#pragma HLS INLINE

	STATIC_ASSERT(QUANTIZATION >= 3, quantization_of_minimum_3_needed);

	ComputeFilter2d_2input<ScalarType, ScalarType, VEC_PIX, VEC_NUM, HIFLIPVX::ORIENTED_NON_MAX_SUPPRESSION, WIDTH, HEIGHT, 3, BORDER_TYPE, VX_BORDER_UNDEFINED, QUANTIZATION>(input, input_no_window, output);
}

/***************************************************************************************************************************************************/
/** @brief Read from Gray Input
 * @param SrcType      The datatype of the input image
 * @param input       The input image
 * @param input_data  The input pixel
 * @param output_data The output pixels
 */
template <typename SrcType>
void InputGray(SrcType input, vx_uint8 &input_data, vx_uint8 output_data[3])
{
	input_data = static_cast<vx_uint8>(input);
	output_data[0] = input_data; // R
	output_data[1] = input_data; // G
	output_data[2] = input_data; // B
}

/***************************************************************************************************************************************************/
/** @brief Read from RGB Input
 * @param SrcType      The datatype of the input image
 * @param input       The input image
 * @param input_data  The input pixel
 * @param output_data The output pixels
 */
template <typename SrcType>
void InputRgb(SrcType input, vx_uint32 &input_data, vx_uint8 output_data[4])
{
#pragma HLS INLINE
	input_data = static_cast<vx_uint32>(input);
	output_data[0] = static_cast<vx_uint8>((input_data >> 0) & 0xFF);
	output_data[1] = static_cast<vx_uint8>((input_data >> 8) & 0xFF);
	output_data[2] = static_cast<vx_uint8>((input_data >> 16) & 0xFF);
	output_data[3] = static_cast<vx_uint8>((input_data >> 24) & 0xFF);
}

/***************************************************************************************************************************************************/
/** @brief Read from RGBX Input
 * @param SrcType      The datatype of the input image
 * @param input       The input image
 * @param input_data  The input pixel
 * @param output_data The output pixels
 */
template <typename SrcType>
void InputRgbx(SrcType input, vx_uint32 &input_data, vx_uint8 output_data[3])
{
#pragma HLS INLINE
	input_data = static_cast<vx_uint32>(input);
	output_data[0] = static_cast<vx_uint8>((input_data >> 0) & 0xFF);
	output_data[1] = static_cast<vx_uint8>((input_data >> 8) & 0xFF);
	output_data[2] = static_cast<vx_uint8>((input_data >> 16) & 0xFF);
}

/***************************************************************************************************************************************************/
/** @brief Write to Gray output (BT.601)
 * @param DstType     The datatype of the output image
 * @param output_data The input pixels (after conversion)
 * @return            The output image
 */
template <typename DstType>
DstType OutputGray(vx_uint8 output_data[3])
{
#pragma HLS INLINE
	vx_uint32 gray =
		306 * static_cast<vx_uint32>(output_data[0]) + // (int)((0.299 * 1024) + 0.5)
		601 * static_cast<vx_uint32>(output_data[1]) + // (int)((0.587 * 1024) + 0.5)
		117 * static_cast<vx_uint32>(output_data[2]);  // (int)((0.114 * 1024) + 0.5)
	return static_cast<DstType>((gray + 512) >> 10);   // round to nearest
}

/***************************************************************************************************************************************************/
/** @brief Write to RGB output
 * @param DstType     The datatype of the output image
 * @param output_data The input pixels (after conversion)
 * @return            The output image
 */
template <typename DstType>
DstType OutputRgb(vx_uint8 output_data[4])
{
#pragma HLS INLINE
	DstType result =
		static_cast<DstType>(output_data[0] << 0) |
		static_cast<DstType>(output_data[1] << 8) |
		static_cast<DstType>(output_data[2] << 16) |
		static_cast<DstType>(output_data[3] << 24);
	return result;
}

/***************************************************************************************************************************************************/
/** @brief Write to RGBX output
 * @param DstType     The datatype of the output image
 * @param output_data The input pixels (after conversion)
 * @return            The output image
 */
template <typename DstType>
DstType OutputRgbx(vx_uint8 output_data[3])
{
#pragma HLS INLINE
	DstType result =
		(static_cast<DstType>(output_data[0]) << 0) |
		(static_cast<DstType>(output_data[1]) << 8) |
		(static_cast<DstType>(output_data[2]) << 16);
	return result;
}

/***************************************************************************************************************************************************/
/** @brief Converts to RGB.
 * @param cases         Different cases how the 3 rgb pixels are distributed among the 4 input pixels
 * @param internal_data The input pixels
 * @param buffer_data   Internal buffers
 * @param output_data   The output pixels
 */
void ConvertToRgb(vx_uint8 &cases, vx_uint8 internal_data[3], vx_uint8 buffer_data[2], vx_uint8 output_data[4])
{
#pragma HLS INLINE

	switch (cases)
	{
	case 0:
		output_data[0] = internal_data[0];
		output_data[1] = internal_data[1];
		output_data[2] = internal_data[2];
		cases = 1;
		break;
	case 1:
		output_data[3] = internal_data[0];
		buffer_data[0] = internal_data[1];
		buffer_data[1] = internal_data[2];
		cases = 2;
		break;
	case 2:
		output_data[0] = buffer_data[0];
		output_data[1] = buffer_data[1];
		output_data[2] = internal_data[0];
		output_data[3] = internal_data[1];
		buffer_data[0] = internal_data[2];
		cases = 3;
		break;
	default:
		output_data[0] = buffer_data[0];
		output_data[1] = internal_data[0];
		output_data[2] = internal_data[1];
		output_data[3] = internal_data[2];
		cases = 0;
		break;
	}
}

/***************************************************************************************************************************************************/
/** @brief Converts from RGB.
 * @param cases         Different cases how the 3 rgb pixels are distributed among the 4 input pixels
 * @param internal_data The input pixels
 * @param buffer_data   Internal buffers
 * @param output_data   The output pixels
 */
void ConvertFromRgb(vx_uint8 &cases, vx_uint8 internal_data[4], vx_uint8 buffer_data[3], vx_uint8 output_data[3])
{
#pragma HLS INLINE

	switch (cases)
	{
	case 0:
		output_data[0] = internal_data[0];
		output_data[1] = internal_data[1];
		output_data[2] = internal_data[2];
		buffer_data[0] = internal_data[3];
		cases = 1;
		break;
	case 1:
		output_data[0] = buffer_data[0];
		output_data[1] = internal_data[0];
		output_data[2] = internal_data[1];
		buffer_data[0] = internal_data[2];
		buffer_data[1] = internal_data[3];
		cases = 2;
		break;
	case 2:
		output_data[0] = buffer_data[0];
		output_data[1] = buffer_data[1];
		output_data[2] = internal_data[0];
		buffer_data[0] = internal_data[1];
		buffer_data[1] = internal_data[2];
		buffer_data[2] = internal_data[3];
		cases = 3;
		break;
	default:
		output_data[0] = buffer_data[0];
		output_data[1] = buffer_data[1];
		output_data[2] = buffer_data[2];
		cases = 0;
		break;
	}
}

/***************************************************************************************************************************************************/
// Converts the input channels to output channels
template <typename SrcType, vx_df_image_e INPUT_TYPE, vx_uint32 INPUT_SIZE>
void ChannelExtractConversion(vx_uint8 &cases, SrcType input_data, vx_uint8 internal_data[INPUT_SIZE], vx_uint8 buffer_data[3], vx_uint8 output_data[INPUT_SIZE])
{
#pragma HLS INLINE

	// Unpack data
	if (INPUT_SIZE > 0)
		internal_data[0] = static_cast<vx_uint8>((input_data >> 0) & 0xFF);
	if (INPUT_SIZE > 1)
		internal_data[1] = static_cast<vx_uint8>((input_data >> 8) & 0xFF);
	if (INPUT_SIZE > 2)
		internal_data[2] = static_cast<vx_uint8>((input_data >> 16) & 0xFF);
	if (INPUT_SIZE > 3)
		internal_data[3] = static_cast<vx_uint8>((input_data >> 24) & 0xFF);

	// Convert input to output channel
	if (INPUT_TYPE == VX_DF_IMAGE_U16)
	{
		output_data[0] = internal_data[0];
		output_data[1] = internal_data[1];
	}
	else if (INPUT_TYPE == VX_DF_IMAGE_U32)
	{
		output_data[0] = internal_data[0];
		output_data[1] = internal_data[1];
		output_data[2] = internal_data[2];
		output_data[3] = internal_data[3];
	}
	else if (INPUT_TYPE == VX_DF_IMAGE_RGB)
	{
		ConvertFromRgb(cases, internal_data, buffer_data, output_data);
	}
	else if (INPUT_TYPE == VX_DF_IMAGE_RGBX)
	{
		output_data[0] = internal_data[0];
		output_data[1] = internal_data[1];
		output_data[2] = internal_data[2];
		output_data[3] = internal_data[3];
	}
}

/***************************************************************************************************************************************************/
// Checkesif the data types of the input are allowed
template <typename SrcType, const vx_uint16 CHANNEL_ID, vx_df_image_e INPUT_TYPE>
void ChannelExtractDataTypes()
{
#pragma HLS INLINE

	// Constants
	const vx_uint32 INPUT_SIZE = sizeof(SrcType);

	// Check Types (Static Assertions)
	const bool allowed_types1 =
		(CHANNEL_ID <= 2 && INPUT_TYPE == VX_DF_IMAGE_U16) ||
		(CHANNEL_ID <= 4 && INPUT_TYPE == VX_DF_IMAGE_U32) ||
		(CHANNEL_ID <= 3 && INPUT_TYPE == VX_DF_IMAGE_RGB) ||
		(CHANNEL_ID <= 4 && INPUT_TYPE == VX_DF_IMAGE_RGBX);
	const bool allowed_types2 =
		(INPUT_SIZE == 2 && INPUT_TYPE == VX_DF_IMAGE_U16) ||
		(INPUT_SIZE == 4 && INPUT_TYPE == VX_DF_IMAGE_U32) ||
		(INPUT_SIZE == 4 && INPUT_TYPE == VX_DF_IMAGE_RGB) ||
		(INPUT_SIZE == 4 && INPUT_TYPE == VX_DF_IMAGE_RGBX);
	STATIC_ASSERT(allowed_types1, missmatch_channel_id_does_not_fit);
	STATIC_ASSERT(allowed_types2, missmatch_bit_width_of_output_type);
}

/***************************************************************************************************************************************************/
/** @brief Implements the Channel Extraction Kernel.
 * @param SrcType   The datatype of the input image  (vx_uint16 (U16), vx_uint32 (U32, RGB, RGBX))
 * @param CHANNEL_ID  The id of the channel to extract
 * @param IMG_PIXELS  The pixels of the image
 * @param INPUT_TYPE  The color type of the input image (VX_DF_IMAGE_U16, VX_DF_IMAGE_U32, VX_DF_IMAGE_RGB, VX_DF_IMAGE_RGBX)
 * @param input       The input image
 * @param output      The output image
 */
template <typename SrcType, const vx_uint16 CHANNEL_ID, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS, vx_df_image_e INPUT_TYPE>
void ChannelExtract(vx_image_data<SrcType, 1> input[SRC_PIXELS], vx_image_data<vx_uint8, 1> output[DST_PIXELS])
{
#pragma HLS INLINE

	// Constants
	const vx_uint32 INPUT_SIZE = sizeof(SrcType);

	// Variables
	vx_uint8 cases = 0;
	SrcType input_data = 0;
	vx_uint8 internal_data[INPUT_SIZE];
	vx_uint8 buffer_data[3];
	vx_uint8 output_data[INPUT_SIZE];
#pragma HLS array_partition variable = internal_data complete dim = 0
#pragma HLS array_partition variable = buffer_data complete dim = 0
#pragma HLS array_partition variable = output_data complete dim = 0

	// Check Types (Static Assertions)
	ChannelExtractDataTypes<SrcType, CHANNEL_ID, INPUT_TYPE>();
	;

	// Computes bitwise operations (pipelined)
	for (vx_uint32 i = 0, j = 0; i < DST_PIXELS; i++)
	{
#pragma HLS PIPELINE II = 1
		vx_image_data<SrcType, 1> src;
		vx_image_data<vx_uint8, 1> dst;

		// Read from input channel
		if (cases < 3 && j < SRC_PIXELS)
		{
			src = input[j];
			input_data = src.pixel[0];
			j++;
		}

		// Converts the input channels to output channels
		ChannelExtractConversion<SrcType, INPUT_TYPE, INPUT_SIZE>(cases, input_data, internal_data, buffer_data, output_data);

		// Set user(SOF) & last(EOF)
		GenerateDmaSignal<vx_uint8, 1>((i == 0), (i == DST_PIXELS - 1), dst);

		// Write to output channel
		dst.pixel[0] = output_data[CHANNEL_ID];
		output[i] = dst;
	}
}

/***************************************************************************************************************************************************/
/** @brief Implements the Channel Extraction Kernel.
 * @param SrcType   The datatype of the input image  (vx_uint16 (U16), vx_uint32 (U32, RGB, RGBX))
 * @param CHANNEL_ID  The id of the channel to extract
 * @param IMG_PIXELS  The pixels of the image
 * @param INPUT_TYPE  The color type of the input image (VX_DF_IMAGE_U16, VX_DF_IMAGE_U32, VX_DF_IMAGE_RGB, VX_DF_IMAGE_RGBX)
 * @param input       The input image
 * @param output      The output image
 */
template <typename SrcType, const vx_uint16 CHANNEL_ID, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS, vx_df_image_e INPUT_TYPE>
void ChannelExtract(SrcType input[SRC_PIXELS], vx_uint8 output[DST_PIXELS])
{
#pragma HLS INLINE

	// Constants
	const vx_uint32 INPUT_SIZE = sizeof(SrcType);

	// Variables
	vx_uint8 cases = 0;
	SrcType input_data = 0;
	vx_uint8 internal_data[INPUT_SIZE];
	vx_uint8 buffer_data[3];
	vx_uint8 output_data[INPUT_SIZE];
#pragma HLS array_partition variable = internal_data complete dim = 0
#pragma HLS array_partition variable = buffer_data complete dim = 0
#pragma HLS array_partition variable = output_data complete dim = 0

	// Check Types (Static Assertions)
	ChannelExtractDataTypes<SrcType, CHANNEL_ID, INPUT_TYPE>();

	// Computes bitwise operations (pipelined)
	for (vx_uint32 i = 0, j = 0; i < DST_PIXELS; i++)
	{
#pragma HLS PIPELINE II = 1

		// Read from input channel
		if (cases < 3 && j < SRC_PIXELS)
		{
			input_data = input[j];
			j++;
		}

		// Converts the input channels to output channels
		ChannelExtractConversion<SrcType, INPUT_TYPE, INPUT_SIZE>(cases, input_data, internal_data, buffer_data, output_data);

		// Write to output channel
		output[i] = output_data[CHANNEL_ID];
	}
}

/***************************************************************************************************************************************************/
//
template <typename DstType, vx_uint16 CHANNEL_AMOUNT, vx_df_image_e OUTPUT_TYPE>
void ChannelCombineDataTypes()
{

	// Constants
	const vx_uint16 OUTPUT_SIZE = sizeof(DstType);

	// Check Types (Static Assertions)
	const bool allowed_types1 =
		(CHANNEL_AMOUNT == 2 && OUTPUT_TYPE == VX_DF_IMAGE_U16) ||
		(CHANNEL_AMOUNT == 4 && OUTPUT_TYPE == VX_DF_IMAGE_U32) ||
		(CHANNEL_AMOUNT == 3 && OUTPUT_TYPE == VX_DF_IMAGE_RGB) ||
		(CHANNEL_AMOUNT == 3 && OUTPUT_TYPE == VX_DF_IMAGE_RGBX);
	const bool allowed_types2 =
		(OUTPUT_SIZE == 2 && OUTPUT_TYPE == VX_DF_IMAGE_U16) ||
		(OUTPUT_SIZE == 4 && OUTPUT_TYPE == VX_DF_IMAGE_U32) ||
		(OUTPUT_SIZE == 4 && OUTPUT_TYPE == VX_DF_IMAGE_RGB) ||
		(OUTPUT_SIZE == 4 && OUTPUT_TYPE == VX_DF_IMAGE_RGBX);
	STATIC_ASSERT(allowed_types1, missmatch_channel_amount_does_not_fit);
	STATIC_ASSERT(allowed_types2, missmatch_bit_width_of_output_type);
}

/***************************************************************************************************************************************************/
/** @brief Implements the Channel Combine Kernel.
 * @param DstType     The datatype of the > image  (vx_uint16 (U16), vx_uint32 (U32, RGB, RGBX))
 * @param CHANNEL_AMOUNT The amount of channels to combine
 * @param IMG_PIXELS     The pixels of the image
 * @param OUTPUT_TYPE    The color type of the > image (VX_DF_IMAGE_U16, VX_DF_IMAGE_U32, VX_DF_IMAGE_RGB, VX_DF_IMAGE_RGBX)
 * @param input0         The 1. plane of the input image
 * @param input1         The 2. plane of the input image
 * @param input2         The 3. plane of the input image (optional)
 * @param input3         The 4. plane of the input image (optional)
 * @param output         The output image
 */
template <typename DstType, vx_uint16 CHANNEL_AMOUNT, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS, vx_df_image_e OUTPUT_TYPE>
void ChannelCombine(
	vx_image_data<vx_uint8, 1> input0[SRC_PIXELS],
	vx_image_data<vx_uint8, 1> input1[SRC_PIXELS],
	vx_image_data<vx_uint8, 1> input2[SRC_PIXELS],
	vx_image_data<vx_uint8, 1> input3[SRC_PIXELS],
	vx_image_data<DstType, 1> output[DST_PIXELS])
{
#pragma HLS INLINE

	// Constants
	const vx_uint16 OUTPUT_SIZE = sizeof(DstType);

	// Variables
	vx_uint8 cases = 0;
	vx_image_data<vx_uint8, 1> input_data[4];
	vx_uint8 buffer[4];
	vx_uint8 internal_data[4];
	vx_uint8 buffer_data[2];
#pragma HLS array_partition variable = input_data complete dim = 0
#pragma HLS array_partition variable = buffer complete dim = 0
#pragma HLS array_partition variable = internal_data complete dim = 0
#pragma HLS array_partition variable = buffer_data complete dim = 0

	// Check Types (Static Assertions)
	ChannelCombineDataTypes<DstType, CHANNEL_AMOUNT, OUTPUT_TYPE>();

	// Computes the channel conversion
	for (vx_uint32 i = 0, j = 0; i < SRC_PIXELS; i++)
	{
#pragma HLS PIPELINE II = 1
		vx_image_data<DstType, 1> output_data;

		// Read from input channel
		if (CHANNEL_AMOUNT > 0)
			input_data[0] = input0[i];
		if (CHANNEL_AMOUNT > 1)
			input_data[1] = input1[i];
		if (CHANNEL_AMOUNT > 2)
			input_data[2] = input2[i];
		if (CHANNEL_AMOUNT > 3)
			input_data[3] = input3[i];

		// Convert input to output channel
		if (OUTPUT_TYPE == VX_DF_IMAGE_RGB)
		{
			for (vx_uint32 k = 0; k < CHANNEL_AMOUNT; ++k)
				buffer[k] = input_data[k].pixel[0];
			ConvertToRgb(cases, buffer, buffer_data, internal_data);
		}
		else
		{
			for (vx_uint32 k = 0; k < CHANNEL_AMOUNT; ++k)
				internal_data[k] = input_data[k].pixel[0];
		}

		// Pack data
		output_data.pixel[0] = static_cast<DstType>(internal_data[0]);
		output_data.pixel[0] |= static_cast<DstType>(internal_data[1]) << 8;
		if (OUTPUT_TYPE == VX_DF_IMAGE_U32 || OUTPUT_TYPE == VX_DF_IMAGE_RGB || OUTPUT_TYPE == VX_DF_IMAGE_RGBX)
			output_data.pixel[0] |= static_cast<DstType>(internal_data[2]) << 16;
		if (OUTPUT_TYPE == VX_DF_IMAGE_U32 || OUTPUT_TYPE == VX_DF_IMAGE_RGB)
			output_data.pixel[0] |= static_cast<DstType>(internal_data[3]) << 24;

		// Set user(SOF) & last(EOF)
		GenerateDmaSignal<DstType, 1>((j == 0), (j == DST_PIXELS - 1), output_data);

		// Write to output channel
		if (cases != 1 && j < DST_PIXELS)
		{
			output[j] = output_data;
			j++;
		}
	}
}

/***************************************************************************************************************************************************/
/** @brief Implements the Channel Combine Kernel.
 * @param DstType     The datatype of the > image  (vx_uint16 (U16), vx_uint32 (U32, RGB, RGBX))
 * @param CHANNEL_AMOUNT The amount of channels to combine
 * @param IMG_PIXELS     The pixels of the image
 * @param OUTPUT_TYPE    The color type of the > image (VX_DF_IMAGE_U16, VX_DF_IMAGE_U32, VX_DF_IMAGE_RGB, VX_DF_IMAGE_RGBX)
 * @param input0         The 1. plane of the input image
 * @param input1         The 2. plane of the input image
 * @param input2         The 3. plane of the input image (optional)
 * @param input3         The 4. plane of the input image (optional)
 * @param output         The output image
 */
template <typename DstType, vx_uint16 CHANNEL_AMOUNT, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS, vx_df_image_e OUTPUT_TYPE>
void ChannelCombine(
	vx_uint8 input0[SRC_PIXELS],
	vx_uint8 input1[SRC_PIXELS],
	vx_uint8 input2[SRC_PIXELS],
	vx_uint8 input3[SRC_PIXELS],
	DstType output[DST_PIXELS])
{
#pragma HLS INLINE

	// Constants
	const vx_uint16 OUTPUT_SIZE = sizeof(DstType);

	// Variables
	vx_uint8 cases = 0;
	vx_uint8 input_data[4];
	vx_uint8 buffer[4];
	vx_uint8 internal_data[4];
	vx_uint8 buffer_data[2];
#pragma HLS array_partition variable = input_data complete dim = 0
#pragma HLS array_partition variable = buffer complete dim = 0
#pragma HLS array_partition variable = internal_data complete dim = 0
#pragma HLS array_partition variable = buffer_data complete dim = 0

	// Check Types (Static Assertions)
	ChannelCombineDataTypes<DstType, CHANNEL_AMOUNT, OUTPUT_TYPE>();

	// Computes the channel conversion
	for (vx_uint32 i = 0, j = 0; i < SRC_PIXELS; i++)
	{
#pragma HLS PIPELINE II = 1
		DstType output_data;

		// Read from input channel
		if (CHANNEL_AMOUNT > 0)
			input_data[0] = input0[i];
		if (CHANNEL_AMOUNT > 1)
			input_data[1] = input1[i];
		if (CHANNEL_AMOUNT > 2)
			input_data[2] = input2[i];
		if (CHANNEL_AMOUNT > 3)
			input_data[3] = input3[i];

		// Convert input to output channel
		if (OUTPUT_TYPE == VX_DF_IMAGE_RGB)
		{
			for (vx_uint32 k = 0; k < CHANNEL_AMOUNT; ++k)
				buffer[k] = input_data[k];
			ConvertToRgb(cases, buffer, buffer_data, internal_data);
		}
		else
		{
			for (vx_uint32 k = 0; k < CHANNEL_AMOUNT; ++k)
				internal_data[k] = input_data[k];
		}

		// Pack data
		output_data = static_cast<DstType>(internal_data[0]);
		output_data |= static_cast<DstType>(internal_data[1]) << 8;
		if (OUTPUT_TYPE == VX_DF_IMAGE_U32 || OUTPUT_TYPE == VX_DF_IMAGE_RGB || OUTPUT_TYPE == VX_DF_IMAGE_RGBX)
			output_data |= static_cast<DstType>(internal_data[2]) << 16;
		if (OUTPUT_TYPE == VX_DF_IMAGE_U32 || OUTPUT_TYPE == VX_DF_IMAGE_RGB)
			output_data |= static_cast<DstType>(internal_data[3]) << 24;

		// Write to output channel
		if (cases != 1 && j < DST_PIXELS)
		{
			output[j] = output_data;
			j++;
		}
	}
}

/***************************************************************************************************************************************************/
/** @brief Convert from Grayscale to RGB
 * @param SrcType      The datatype of the input imag
 * @param DstType     The datatype of the output image
 * @param IMG_PIXELS  The pixel amount of the image
 * @param input       The input image
 * @param output      The output image
 */
template <typename SrcType, typename DstType, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS>
void ConvertGrayToRgb(vx_image_data<SrcType, 1> input[SRC_PIXELS], vx_image_data<DstType, 1> output[DST_PIXELS])
{
#pragma HLS INLINE

	// Global variables
	vx_uint8 cases = 0;
	vx_uint8 input_data;
	vx_uint8 internal_data[3];
	vx_uint8 buffer_data[2];
	vx_uint8 output_data[4];

	// Convert from Grayscale to RGB
	for (vx_uint32 i = 0, j = 0; i < SRC_PIXELS; i++)
	{
#pragma HLS PIPELINE II = 1
		vx_image_data<SrcType, 1> src;
		vx_image_data<DstType, 1> dst;

		// Read from input
		src = input[i];
		InputGray<SrcType>(src.pixel[0], input_data, internal_data);

		// Conversion
		ConvertToRgb(cases, internal_data, buffer_data, output_data);

		// Write to output
		if (cases != 1)
		{
			GenerateDmaSignal<DstType, 1>((j == 0), (j == DST_PIXELS - 1), dst);
			dst.pixel[0] = OutputRgb<DstType>(output_data);
			output[j] = dst;
			j++;
		}
	}
}
template <typename SrcType, typename DstType, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS>
void ConvertGrayToRgb(SrcType input[SRC_PIXELS], DstType output[DST_PIXELS])
{
#pragma HLS INLINE

	// Global variables
	vx_uint8 cases = 0;
	vx_uint8 input_data;
	vx_uint8 internal_data[3];
	vx_uint8 buffer_data[2];
	vx_uint8 output_data[4];

	// Convert from Grayscale to RGB
	for (vx_uint32 i = 0, j = 0; i < SRC_PIXELS; i++)
	{
#pragma HLS PIPELINE II = 1

		// Read from input
		InputGray<SrcType>(input[i], input_data, internal_data);

		// Conversion
		ConvertToRgb(cases, internal_data, buffer_data, output_data);

		// Write to output
		if (cases != 1)
		{
			output[j] = OutputRgb<DstType>(output_data);
			j++;
		}
	}
}

/***************************************************************************************************************************************************/
/** @brief Convert from Grayscale to RGBX
 * @param SrcType      The datatype of the input imag
 * @param DstType     The datatype of the output image
 * @param IMG_PIXELS  The pixel amount of the image
 * @param input       The input image
 * @param output      The output image
 */
template <typename SrcType, typename DstType, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS>
void ConvertGrayToRgbx(vx_image_data<SrcType, 1> input[SRC_PIXELS], vx_image_data<DstType, 1> output[DST_PIXELS])
{
#pragma HLS INLINE

	// Global variables
	vx_uint8 input_data;
	vx_uint8 output_data[3];

	// Convert grayscale to RGBX
	for (vx_uint32 i = 0; i < SRC_PIXELS; i++)
	{
#pragma HLS PIPELINE II = 1
		vx_image_data<SrcType, 1> src;
		vx_image_data<DstType, 1> dst;

		// Read from input
		src = input[i];
		InputGray<SrcType>(src.pixel[0], input_data, output_data);

		// Write to output
		GenerateDmaSignal<DstType, 1>((i == 0), (i == DST_PIXELS - 1), dst);
		dst.pixel[0] = OutputRgbx<DstType>(output_data);
		output[i] = dst;
	}
}
template <typename SrcType, typename DstType, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS>
void ConvertGrayToRgbx(SrcType input[SRC_PIXELS], DstType output[DST_PIXELS])
{
#pragma HLS INLINE

	// Global variables
	vx_uint8 input_data;
	vx_uint8 output_data[3];

	// Convert grayscale to RGBX
	for (vx_uint32 i = 0; i < SRC_PIXELS; i++)
	{
#pragma HLS PIPELINE II = 1

		// Read from input
		InputGray<SrcType>(input[i], input_data, output_data);

		// Write to output
		output[i] = OutputRgbx<DstType>(output_data);
	}
}

/***************************************************************************************************************************************************/
/** @brief Convert from RGB to Grayscale
 * @param SrcType      The datatype of the input imag
 * @param DstType     The datatype of the output image
 * @param IMG_PIXELS  The pixel amount of the image
 * @param input       The input image
 * @param output      The output image
 */
template <typename SrcType, typename DstType, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS>
void ConvertRgbToGray(vx_image_data<SrcType, 1> input[SRC_PIXELS], vx_image_data<DstType, 1> output[DST_PIXELS])
{
#pragma HLS INLINE

	// Global variables
	vx_uint8 cases = 0;
	vx_uint32 input_data;
	vx_uint8 internal_data[4];
	vx_uint8 buffer_data[3];
	vx_uint8 output_data[3];

	// Compute gray-scale on image
	for (vx_uint32 i = 0, j = 0; i < DST_PIXELS; i++)
	{
#pragma HLS PIPELINE II = 1
		vx_image_data<SrcType, 1> src;
		vx_image_data<DstType, 1> dst;

		// Read from input and store it into internal data
		if (cases < 3)
		{
			src = input[j];
			++j;
		}
		InputRgb<SrcType>(src.pixel[0], input_data, internal_data);

		// Conversion
		ConvertFromRgb(cases, internal_data, buffer_data, output_data);

		// Write to output
		GenerateDmaSignal<DstType, 1>((i == 0), (i == DST_PIXELS - 1), dst);
		dst.pixel[0] = OutputGray<DstType>(output_data);
		output[i] = dst;
	}
}
template <typename SrcType, typename DstType, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS>
void ConvertRgbToGray(SrcType input[SRC_PIXELS], DstType output[DST_PIXELS])
{
#pragma HLS INLINE

	// Global variables
	vx_uint8 cases = 0;
	vx_uint32 input_data;
	vx_uint8 internal_data[4];
	vx_uint8 buffer_data[3];
	vx_uint8 output_data[3];

	// Compute gray-scale on image
	for (vx_uint32 i = 0, j = 0; i < DST_PIXELS; i++)
	{
#pragma HLS PIPELINE II = 1
		SrcType src;

		// Read from input and store it into internal data
		if (cases < 3)
		{
			src = input[j];
			++j;
		}
		InputRgb<SrcType>(src, input_data, internal_data);

		// Conversion
		ConvertFromRgb(cases, internal_data, buffer_data, output_data);

		// Write to output
		output[i] = OutputGray<DstType>(output_data);
	}
}

/***************************************************************************************************************************************************/
/** @brief Convert from RGB to RGBX
 * @param SrcType      The datatype of the input imag
 * @param DstType     The datatype of the output image
 * @param IMG_PIXELS  The pixel amount of the image
 * @param input       The input image
 * @param output      The output image
 */
template <typename SrcType, typename DstType, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS>
void ConvertRgbToRgbx(vx_image_data<SrcType, 1> input[SRC_PIXELS], vx_image_data<DstType, 1> output[DST_PIXELS])
{
#pragma HLS INLINE

	// Global variables
	vx_uint8 cases = 0;
	vx_uint32 input_data;
	vx_uint8 internal_data[4];
	vx_uint8 buffer_data[3];
	vx_uint8 output_data[3];

	// Compute gray-scale on image
	for (vx_uint32 i = 0, j = 0; i < DST_PIXELS; i++)
	{
#pragma HLS PIPELINE II = 1
		vx_image_data<SrcType, 1> src;
		vx_image_data<DstType, 1> dst;

		// Read from input and store it into internal data
		if (cases < 3)
		{
			src = input[j];
			++j;
		}
		InputRgb<SrcType>(src.pixel[0], input_data, internal_data);

		// Conversion
		ConvertFromRgb(cases, internal_data, buffer_data, output_data);

		// Write to output
		GenerateDmaSignal<DstType, 1>((i == 0), (i == DST_PIXELS - 1), dst);
		dst.pixel[0] = OutputRgbx<DstType>(output_data);
		output[i] = dst;
	}
}
template <typename SrcType, typename DstType, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS>
void ConvertRgbToRgbx(SrcType input[SRC_PIXELS], DstType output[DST_PIXELS])
{
#pragma HLS INLINE

	// Global variables
	vx_uint8 cases = 0;
	vx_uint32 input_data;
	vx_uint8 internal_data[4];
	vx_uint8 buffer_data[3];
	vx_uint8 output_data[3];

	// Compute gray-scale on image
	for (vx_uint32 i = 0, j = 0; i < DST_PIXELS; i++)
	{
#pragma HLS PIPELINE II = 1
		SrcType src;

		// Read from input and store it into internal data
		if (cases < 3)
		{
			src = input[j];
			++j;
		}
		InputRgb<SrcType>(src, input_data, internal_data);

		// Conversion
		ConvertFromRgb(cases, internal_data, buffer_data, output_data);

		// Write to output
		output[i] = OutputRgbx<DstType>(output_data);
	}
}

/***************************************************************************************************************************************************/
/** @brief Convert from RGBX to Grayscale
 * @param SrcType      The datatype of the input imag
 * @param DstType     The datatype of the output image
 * @param IMG_PIXELS  The pixel amount of the image
 * @param input       The input image
 * @param output      The output image
 */
template <typename SrcType, typename DstType, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS>
void ConvertRgbxToGray(vx_image_data<SrcType, 1> input[SRC_PIXELS], vx_image_data<DstType, 1> output[DST_PIXELS])
{
#pragma HLS INLINE

	// Global variables
	vx_uint32 input_data;
	vx_uint8 output_data[3];

	// Compute gray-scale on image
	for (vx_uint32 i = 0; i < SRC_PIXELS; i++)
	{
#pragma HLS PIPELINE II = 1
		vx_image_data<SrcType, 1> src;
		vx_image_data<DstType, 1> dst;

		// Read from input
		src = input[i];
		InputRgbx<SrcType>(src.pixel[0], input_data, output_data);

		// Write to output
		GenerateDmaSignal<DstType, 1>((i == 0), (i == DST_PIXELS - 1), dst);
		dst.pixel[0] = OutputGray<DstType>(output_data);
		output[i] = dst;
	}
}
template <typename SrcType, typename DstType, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS>
void ConvertRgbxToGray(SrcType input[SRC_PIXELS], DstType output[DST_PIXELS])
{
#pragma HLS INLINE

	// Global variables
	vx_uint32 input_data;
	vx_uint8 output_data[3];

	// Compute gray-scale on image
	for (vx_uint32 i = 0; i < SRC_PIXELS; i++)
	{
#pragma HLS PIPELINE II = 1

		// Read from input
		InputRgbx<SrcType>(input[i], input_data, output_data);

		// Write to output
		output[i] = OutputGray<DstType>(output_data);
	}
}

/***************************************************************************************************************************************************/
/** @brief Convert from RGBX to RGB
 * @param SrcType      The datatype of the input imag
 * @param DstType     The datatype of the output image
 * @param IMG_PIXELS  The pixel amount of the image
 * @param input       The input image
 * @param output      The output image
 */
template <typename SrcType, typename DstType, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS>
void ConvertRgbxToRgb(vx_image_data<SrcType, 1> input[SRC_PIXELS], vx_image_data<DstType, 1> output[DST_PIXELS])
{
#pragma HLS INLINE

	// Global variables
	vx_uint8 cases = 0;
	vx_uint32 input_data;
	vx_uint8 internal_data[3];
	vx_uint8 buffer_data[2];
	vx_uint8 output_data[4];

	// Compute gray-scale on image
	for (vx_uint32 i = 0, j = 0; i < SRC_PIXELS; i++)
	{
#pragma HLS PIPELINE II = 1
		vx_image_data<SrcType, 1> src;
		vx_image_data<DstType, 1> dst;

		// Read from input
		src = input[i];
		InputRgbx<SrcType>(src.pixel[0], input_data, internal_data);

		// Conversion
		ConvertToRgb(cases, internal_data, buffer_data, output_data);

		// Write to output
		if (cases != 1)
		{
			GenerateDmaSignal<DstType, 1>((j == 0), (j == DST_PIXELS - 1), dst);
			dst.pixel[0] = OutputRgb<DstType>(output_data);
			output[j] = dst;
			j++;
		}
	}
}
template <typename SrcType, typename DstType, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS>
void ConvertRgbxToRgb(SrcType input[SRC_PIXELS], DstType output[DST_PIXELS])
{
#pragma HLS INLINE

	// Global variables
	vx_uint8 cases = 0;
	vx_uint32 input_data;
	vx_uint8 internal_data[3];
	vx_uint8 buffer_data[2];
	vx_uint8 output_data[4];

	// Compute gray-scale on image
	for (vx_uint32 i = 0, j = 0; i < SRC_PIXELS; i++)
	{
#pragma HLS PIPELINE II = 1

		// Read from input
		InputRgbx<SrcType>(input[i], input_data, internal_data);

		// Conversion
		ConvertToRgb(cases, internal_data, buffer_data, output_data);

		// Write to output
		if (cases != 1)
		{
			output[j] = OutputRgb<DstType>(output_data);
			j++;
		}
	}
}

/***************************************************************************************************************************************************/
// Check data types of color conversion
template <typename SrcType, typename DstType, vx_df_image_e INPUT_TYPE, vx_df_image_e OUTPUT_TYPE>
void ConvertColorDataTypes()
{

	// Constants
	const vx_uint32 INPUT_SIZE = sizeof(SrcType);
	const vx_uint32 OUTPUT_SIZE = sizeof(DstType);
	const bool IN_IS_SIGNED = std::numeric_limits<SrcType>::is_signed;
	const bool OUT_IS_SIGNED = std::numeric_limits<DstType>::is_signed;

	// Check types (static assertions)
	const bool allowed_types1 =
		(IN_IS_SIGNED == false) || (OUT_IS_SIGNED == false);
	const bool allowed_types2 =
		(INPUT_SIZE == 1 && INPUT_TYPE == VX_DF_IMAGE_U8) ||
		(INPUT_SIZE == 4 && INPUT_TYPE == VX_DF_IMAGE_RGB) ||
		(INPUT_SIZE == 4 && INPUT_TYPE == VX_DF_IMAGE_RGBX);
	const bool allowed_types3 =
		(OUTPUT_SIZE == 1 && OUTPUT_TYPE == VX_DF_IMAGE_U8) ||
		(OUTPUT_SIZE == 4 && OUTPUT_TYPE == VX_DF_IMAGE_RGB) ||
		(OUTPUT_SIZE == 4 && OUTPUT_TYPE == VX_DF_IMAGE_RGBX);
	STATIC_ASSERT(allowed_types1, datatype_of_input_and_output_must_be_unsigned);
	STATIC_ASSERT(allowed_types2, missmatch_input_datatype_size_and_input_type);
	STATIC_ASSERT(allowed_types3, missmatch_output_datatype_size_and_output_type);
}

/***************************************************************************************************************************************************/
/** @brief Converts the Color of an image between VX_DF_IMAGE_RGB / VX_DF_IMAGE_RGBX / VX_DF_IMAGE_U8 (grayscale)
 * @param SrcType      The datatype of the input image  (uint8 (Gray), uint32 (RGB, RGBX))
 * @param DstType     The datatype of the output image (uint8 (Gray), uint32 (RGB, RGBX))
 * @param IMG_PIXELS  The pixel amount of the image
 * @param INPUT_TYPE  The color type of the input image (RGB, RGBX, Gray)
 * @param OUTPUT_TYPE The color type of the output image (RGB, RGBX, Gray)
 * @param input       The input image
 * @param output      The output image
 */
template <typename SrcType, typename DstType, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS, vx_df_image_e INPUT_TYPE, vx_df_image_e OUTPUT_TYPE>
void ConvertColor(vx_image_data<SrcType, 1> input[SRC_PIXELS], vx_image_data<DstType, 1> output[DST_PIXELS])
{
#pragma HLS INLINE

	// Allowed color conversions
	const bool GRAY_to_RGB = (INPUT_TYPE == VX_DF_IMAGE_U8) && (OUTPUT_TYPE == VX_DF_IMAGE_RGB);
	const bool GRAY_to_RGBX = (INPUT_TYPE == VX_DF_IMAGE_U8) && (OUTPUT_TYPE == VX_DF_IMAGE_RGBX);
	const bool RGB_to_GRAY = (INPUT_TYPE == VX_DF_IMAGE_RGB) && (OUTPUT_TYPE == VX_DF_IMAGE_U8);
	const bool RGB_to_RGBX = (INPUT_TYPE == VX_DF_IMAGE_RGB) && (OUTPUT_TYPE == VX_DF_IMAGE_RGBX);
	const bool RGBX_to_GRAY = (INPUT_TYPE == VX_DF_IMAGE_RGBX) && (OUTPUT_TYPE == VX_DF_IMAGE_U8);
	const bool RGBX_to_RGB = (INPUT_TYPE == VX_DF_IMAGE_RGBX) && (OUTPUT_TYPE == VX_DF_IMAGE_RGB);

	// Check data types of color conversion
	ConvertColorDataTypes<SrcType, DstType, INPUT_TYPE, OUTPUT_TYPE>();
	const bool allowed_types4 = GRAY_to_RGB || GRAY_to_RGBX || RGB_to_GRAY || RGB_to_RGBX || RGBX_to_GRAY || RGBX_to_RGB;
	STATIC_ASSERT(allowed_types4, color_conversion_type_not_supported);

	// Color conversions
	if (GRAY_to_RGB)
		ConvertGrayToRgb<SrcType, DstType, SRC_PIXELS, DST_PIXELS>(input, output);
	else if (GRAY_to_RGBX)
		ConvertGrayToRgbx<SrcType, DstType, SRC_PIXELS, DST_PIXELS>(input, output);
	else if (RGB_to_GRAY)
		ConvertRgbToGray<SrcType, DstType, SRC_PIXELS, DST_PIXELS>(input, output);
	else if (RGB_to_RGBX)
		ConvertRgbToRgbx<SrcType, DstType, SRC_PIXELS, DST_PIXELS>(input, output);
	else if (RGBX_to_GRAY)
		ConvertRgbxToGray<SrcType, DstType, SRC_PIXELS, DST_PIXELS>(input, output);
	else if (RGBX_to_RGB)
		ConvertRgbxToRgb<SrcType, DstType, SRC_PIXELS, DST_PIXELS>(input, output);
}
template <typename SrcType, typename DstType, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS, vx_df_image_e INPUT_TYPE, vx_df_image_e OUTPUT_TYPE>
void ConvertColor(SrcType input[SRC_PIXELS], DstType output[DST_PIXELS])
{
#pragma HLS INLINE

	// Allowed color conversions
	const bool GRAY_to_RGB = (INPUT_TYPE == VX_DF_IMAGE_U8) && (OUTPUT_TYPE == VX_DF_IMAGE_RGB);
	const bool GRAY_to_RGBX = (INPUT_TYPE == VX_DF_IMAGE_U8) && (OUTPUT_TYPE == VX_DF_IMAGE_RGBX);
	const bool RGB_to_GRAY = (INPUT_TYPE == VX_DF_IMAGE_RGB) && (OUTPUT_TYPE == VX_DF_IMAGE_U8);
	const bool RGB_to_RGBX = (INPUT_TYPE == VX_DF_IMAGE_RGB) && (OUTPUT_TYPE == VX_DF_IMAGE_RGBX);
	const bool RGBX_to_GRAY = (INPUT_TYPE == VX_DF_IMAGE_RGBX) && (OUTPUT_TYPE == VX_DF_IMAGE_U8);
	const bool RGBX_to_RGB = (INPUT_TYPE == VX_DF_IMAGE_RGBX) && (OUTPUT_TYPE == VX_DF_IMAGE_RGB);

	// Check data types of color conversion
	ConvertColorDataTypes<SrcType, DstType, INPUT_TYPE, OUTPUT_TYPE>();
	const bool allowed_types4 = GRAY_to_RGB || GRAY_to_RGBX || RGB_to_GRAY || RGB_to_RGBX || RGBX_to_GRAY || RGBX_to_RGB;
	STATIC_ASSERT(allowed_types4, color_conversion_type_not_supported);

	// Color conversions
	if (GRAY_to_RGB)
		ConvertGrayToRgb<SrcType, DstType, SRC_PIXELS, DST_PIXELS>(input, output);
	else if (GRAY_to_RGBX)
		ConvertGrayToRgbx<SrcType, DstType, SRC_PIXELS, DST_PIXELS>(input, output);
	else if (RGB_to_GRAY)
		ConvertRgbToGray<SrcType, DstType, SRC_PIXELS, DST_PIXELS>(input, output);
	else if (RGB_to_RGBX)
		ConvertRgbToRgbx<SrcType, DstType, SRC_PIXELS, DST_PIXELS>(input, output);
	else if (RGBX_to_GRAY)
		ConvertRgbxToGray<SrcType, DstType, SRC_PIXELS, DST_PIXELS>(input, output);
	else if (RGBX_to_RGB)
		ConvertRgbxToRgb<SrcType, DstType, SRC_PIXELS, DST_PIXELS>(input, output);
}

/***************************************************************************************************************************************************/
/** @brief Converts image bit depth.
 * @param SrcType      The datatype of the input image (8, 16, 32 bit unsigned/signed)
 * @param DstType      The datatype of the output image (8, 16, 32 bit unsigned/signed)
 * @param CONV_POLICY  The conversion policy for overflow (VX_CONVERT_POLICY_WRAP or VX_CONVERT_POLICY_SATURATE)
 * @param SHIFT        Bits are shifted by this amount (e.g. up for u8->s16, down for s16->u8),  maximum shift is abs(inBitDepth - outBitDepth)
 * @param src          The input pixel
 * @param dst          The output pixel
 */
template <typename SrcType, typename DstType, const vx_convert_policy_e CONV_POLICY, const vx_uint16 SHIFT>
void ConvertDepthSingle(SrcType src, DstType &dst)
{
#pragma HLS INLINE

	// Result
	DstType result = 0;

	// Constants
	const bool IN_IS_SIGNED = std::numeric_limits<SrcType>::is_signed;
	const bool OUT_IS_SIGNED = std::numeric_limits<DstType>::is_signed;
	const vx_int16 IN_SIZE = sizeof(SrcType);
	const vx_int16 OUT_SIZE = sizeof(DstType);

	// Check for max shift value
	const vx_uint16 MAX_SHIFT = (IN_SIZE > OUT_SIZE) ? static_cast<vx_uint16>(IN_SIZE - OUT_SIZE) : static_cast<vx_uint16>(OUT_SIZE - IN_SIZE);
	STATIC_ASSERT(MAX_SHIFT * 8 >= SHIFT, shift_size_out_of_range);

	// Check if down or up conversion
	bool DOWN_CONVERSION = false;
	bool UP_CONVERSION = false;

	// Border values for VX_CONVERT_POLICY_SATURATE
	vx_int64 MAX_VAL = 0;
	vx_int64 MIN_VAL = 0;

	// Set if down or up conversion
	if ((IN_SIZE == 1 && OUT_SIZE == 2) ||
		(IN_SIZE == 1 && OUT_SIZE == 4) ||
		(IN_SIZE == 2 && OUT_SIZE == 4))
	{
		UP_CONVERSION = true;
	}
	else if (
		(IN_SIZE == 2 && OUT_SIZE == 1) ||
		(IN_SIZE == 4 && OUT_SIZE == 1) ||
		(IN_SIZE == 4 && OUT_SIZE == 2))
	{
		DOWN_CONVERSION = true;
	}

	// Set border values for VX_CONVERT_POLICY_SATURATE
	if (OUT_IS_SIGNED == true)
	{
		if (OUT_SIZE == 1)
		{
			MAX_VAL = VX_INT8_MAX;
			MIN_VAL = VX_INT8_MIN;
		}
		else if (OUT_SIZE == 2)
		{
			MAX_VAL = VX_INT16_MAX;
			MIN_VAL = VX_INT16_MIN;
		}
		else if (OUT_SIZE == 4)
		{
			MAX_VAL = VX_INT32_MAX;
			MIN_VAL = VX_INT32_MIN;
		}
	}
	else if (OUT_IS_SIGNED == false)
	{
		if (OUT_SIZE == 1)
			MAX_VAL = VX_UINT8_MAX;
		else if (OUT_SIZE == 2)
			MAX_VAL = VX_UINT16_MAX;
		else if (OUT_SIZE == 4)
			MAX_VAL = VX_UINT32_MAX;
	}

	// Do up or down conversion
	if (DOWN_CONVERSION == true)
	{
		if (CONV_POLICY == VX_CONVERT_POLICY_WRAP)
		{
			result = (static_cast<DstType>(src >> SHIFT));
		}
		else if (CONV_POLICY == VX_CONVERT_POLICY_SATURATE)
		{
			vx_int64 value = static_cast<vx_int64>(src >> SHIFT);
			value = MAX(MIN(value, MAX_VAL), MIN_VAL);
			result = static_cast<DstType>(value);
		}
	}
	if (UP_CONVERSION == true)
	{
		if (CONV_POLICY == VX_CONVERT_POLICY_WRAP)
		{
			result = (static_cast<DstType>(src)) << SHIFT;
		}
		else if (CONV_POLICY == VX_CONVERT_POLICY_SATURATE)
		{
			if (OUT_IS_SIGNED == true)
			{
				vx_int64 value = (static_cast<vx_int64>(src)) << SHIFT;
				value = static_cast<DstType>(MAX(MIN(value, MAX_VAL), MIN_VAL));
				result = static_cast<DstType>(value);
			}
			else
			{
				result = (static_cast<DstType>(src)) << SHIFT;
			}
		}
	}

	// Convert from signed to unsigned or v.v.
	if ((IN_SIZE == OUT_SIZE) && (IN_IS_SIGNED != OUT_IS_SIGNED))
	{
		if (CONV_POLICY == VX_CONVERT_POLICY_WRAP)
		{
			result = static_cast<DstType>(src);
		}
		else if (CONV_POLICY == VX_CONVERT_POLICY_SATURATE)
		{
			vx_int64 value = static_cast<vx_int64>(src);
			value = MAX(MIN(value, MAX_VAL), MIN_VAL);
			result = static_cast<DstType>(value);
		}
	}

	// Return result
	dst = result;
}

/***************************************************************************************************************************************************/
/** @brief Checks the data type to converts image bit depth.
 * @param SrcType       The datatype of the input image (8, 16, 32 bit unsigned/signed)
 * @param DstType      The datatype of the output image (8, 16, 32 bit unsigned/signed)
 * @param VEC_SIZE     The vector size
 * @param IMG_PIXEL    The amount of image pixels
 */
template <typename SrcType, typename DstType, const vx_uint8 VEC_SIZE, const vx_uint32 IMG_PIXEL>
vx_uint32 ConvertBitDepthCheck()
{

	// Constants
	const vx_type_e IN_TYPE = GET_TYPE(SrcType);
	const vx_type_e OUT_TYPE = GET_TYPE(DstType);
	const bool INPUT_TYPE_CORRECT =
		(IN_TYPE == VX_TYPE_UINT8) || (IN_TYPE == VX_TYPE_UINT16) || (IN_TYPE == VX_TYPE_UINT32) ||
		(IN_TYPE == VX_TYPE_INT8) || (IN_TYPE == VX_TYPE_INT16) || (IN_TYPE == VX_TYPE_INT32);
	const bool OUTPUT_TYPE_CORRECT =
		(OUT_TYPE == VX_TYPE_UINT8) || (OUT_TYPE == VX_TYPE_UINT16) || (OUT_TYPE == VX_TYPE_UINT32) ||
		(OUT_TYPE == VX_TYPE_INT8) || (OUT_TYPE == VX_TYPE_INT16) || (OUT_TYPE == VX_TYPE_INT32);

	// Check function parameters/types
	STATIC_ASSERT(INPUT_TYPE_CORRECT, input_type_error);
	STATIC_ASSERT(OUTPUT_TYPE_CORRECT, output_type_or_output_type_error);
	STATIC_ASSERT((IMG_PIXEL % VEC_SIZE) == 0, image_pixels_are_not_multiple_of_vector_size);
	STATIC_ASSERT((VEC_SIZE == 1) || (VEC_SIZE == 2) || (VEC_SIZE == 4) || (VEC_SIZE == 8), _vec_size_musst_be_multiple_of_two_and_max_8);

	return IMG_PIXEL / static_cast<vx_uint32>(VEC_SIZE);
	;
}

/***************************************************************************************************************************************************/
/** @brief Converts image bit depth.
 * @param SrcType       The datatype of the input image (8, 16, 32 bit unsigned/signed)
 * @param DstType      The datatype of the output image (8, 16, 32 bit unsigned/signed)
 * @param VEC_SIZE     The vector size
 * @param IMG_PIXEL    The amount of image pixels
 * @param CONV_POLICY  The conversion policy for overflow (VX_CONVERT_POLICY_WRAP or VX_CONVERT_POLICY_SATURATE)
 * @param SHIFT        Bits are shifted by this amount (e.g. up for u8->s16, down for s16->u8),  maximum shift is abs(inBitDepth - outBitDepth)
 * @param input        The input image
 * @param output       The output image
 */
template <typename SrcType, typename DstType, const vx_uint8 VEC_SIZE, const vx_uint32 IMG_PIXEL, const vx_convert_policy_e CONV_POLICY, const vx_uint16 SHIFT>
void ConvertBitDepth(vx_image_data<SrcType, VEC_SIZE> input[IMG_PIXEL / VEC_SIZE], vx_image_data<DstType, VEC_SIZE> output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE

	// Constants
	const vx_uint32 VEC_PIXEL = ConvertBitDepthCheck<SrcType, DstType, VEC_SIZE, IMG_PIXEL>();

	// Vector variables
	vx_image_data<SrcType, VEC_SIZE> src;
	vx_image_data<DstType, VEC_SIZE> dst;

	// Computes operations (pipelined)
	for (vx_uint32 i = 0; i < VEC_PIXEL; i++)
	{
#pragma HLS PIPELINE II = 1

		// Read Input
		src = input[i];

		// Compute vector of bit depth operation
		for (vx_uint16 j = 0; j < VEC_SIZE; j++)
		{
#pragma HLS unroll
			ConvertDepthSingle<SrcType, DstType, CONV_POLICY, SHIFT>(src.pixel[j], dst.pixel[j]);
		}

		// Set user(SOF) & last(EOF)
		GenerateDmaSignal<DstType, VEC_SIZE>((i == 0), (i == VEC_PIXEL - 1), dst);

		// Write result
		output[i] = dst;
	}
}
template <typename SrcType, typename DstType, const vx_uint8 VEC_SIZE, const vx_uint32 IMG_PIXEL, const vx_convert_policy_e CONV_POLICY, const vx_uint16 SHIFT>
void ConvertBitDepth(SrcType input[IMG_PIXEL], DstType output[IMG_PIXEL])
{
#pragma HLS INLINE

	// Constants
	const vx_uint32 VEC_PIXEL = ConvertBitDepthCheck<SrcType, DstType, VEC_SIZE, IMG_PIXEL>();

	// Vector variables
	SrcType src = 0;
	DstType dst = 0;

	// Computes operations (pipelined)
	for (vx_uint32 i = 0; i < VEC_PIXEL; i++)
	{
#pragma HLS PIPELINE II = 1

		// Read Input
		src = input[i];

		// Compute bit depth operation
		ConvertDepthSingle<SrcType, DstType, CONV_POLICY, SHIFT>(src, dst);

		// Write result
		output[i] = dst;
	}
}

/***************************************************************************************************************************************************/
template <typename TypeData, vx_int64 BATCHES, vx_int64 SRC_PIXELS, vx_int64 DST_PIXELS, vx_int64 SRC_PARALLEL, vx_int64 DST_PARALLEL>
void ConverterSrcMulitple(
	vx_image_data<TypeData, SRC_PARALLEL> src[(BATCHES * SRC_PIXELS) / SRC_PARALLEL],
	vx_image_data<TypeData, DST_PARALLEL> dst[(BATCHES * DST_PIXELS) / DST_PARALLEL])
{
#pragma HLS INLINE

	// Constants
	const vx_int64 VECTOR = SRC_PIXELS / SRC_PARALLEL;
	const vx_int64 PARALLEL = MAX(SRC_PARALLEL / DST_PARALLEL, 1);

	// Input buffer
	vx_image_data<TypeData, SRC_PARALLEL> inputbuffer;
#pragma HLS array_partition variable = inputbuffer complete dim = 0

	// Copy elements
	for (vx_int64 batch = 0, src_ptr = 0, dst_ptr = 0; batch < BATCHES; ++batch)
	{
		for (vx_int64 i = 0; i < VECTOR * PARALLEL; ++i)
		{
			// for (vx_int64 j = 0; j < PARALLEL; ++j) {
#pragma HLS pipeline II = 1
			vx_int64 j = i % PARALLEL;

			// Output buffer
			vx_image_data<TypeData, DST_PARALLEL> outputbuffer;
#pragma HLS array_partition variable = outputbuffer complete dim = 0

			// Input
			if (j == 0)
			{
				inputbuffer = src[src_ptr];
				++src_ptr;
			}

			// Conversion
			for (vx_int64 k = 0; k < DST_PARALLEL; ++k)
				outputbuffer.pixel[k] = inputbuffer.pixel[j * DST_PARALLEL + k];

			// Set user(SOF) & last(EOF)
			GenerateDmaSignal<TypeData, DST_PARALLEL>((dst_ptr == 0), (dst_ptr == VECTOR - 1), outputbuffer);

			// Output
			dst[dst_ptr] = outputbuffer;
			++dst_ptr;
			//}
		}
	}
}

/***************************************************************************************************************************************************/
template <typename TypeData, vx_int64 BATCHES, vx_int64 SRC_PIXELS, vx_int64 DST_PIXELS, vx_int64 SRC_PARALLEL, vx_int64 DST_PARALLEL>
void ConverterDstMulitple(
	vx_image_data<TypeData, SRC_PARALLEL> src[(BATCHES * SRC_PIXELS) / SRC_PARALLEL],
	vx_image_data<TypeData, DST_PARALLEL> dst[(BATCHES * DST_PIXELS) / DST_PARALLEL])
{
#pragma HLS INLINE

	// Constants
	const vx_int64 VECTOR = DST_PIXELS / DST_PARALLEL;
	const vx_int64 PARALLEL = MAX(DST_PARALLEL / SRC_PARALLEL, 1);

	// Output buffer
	vx_image_data<TypeData, DST_PARALLEL> outputbuffer;
#pragma HLS array_partition variable = outputbuffer complete dim = 0

	// Copy elements
	for (vx_int64 batch = 0, src_ptr = 0, dst_ptr = 0; batch < BATCHES; ++batch)
	{
		for (vx_int64 i = 0; i < VECTOR * PARALLEL; ++i)
		{
			// for (vx_int64 j = 0; j < PARALLEL; ++j) {
#pragma HLS pipeline II = 1
			vx_int64 j = i % PARALLEL;

			// Input buffer
			vx_image_data<TypeData, SRC_PARALLEL> inputbuffer;
#pragma HLS array_partition variable = inputbuffer complete dim = 0

			// Input
			inputbuffer = src[src_ptr];
			++src_ptr;

			// Conversion
			for (vx_int64 k = 0; k < SRC_PARALLEL; ++k)
				outputbuffer.pixel[j * SRC_PARALLEL + k] = inputbuffer.pixel[k];

			// Set user(SOF) & last(EOF)
			GenerateDmaSignal<TypeData, DST_PARALLEL>((dst_ptr == 0), (dst_ptr == VECTOR - 1), outputbuffer);

			// Output
			if (j == (PARALLEL - 1))
			{
				dst[dst_ptr] = outputbuffer;
				++dst_ptr;
			}
			//}
		}
	}
}

/***************************************************************************************************************************************************/
template <typename TypeData, vx_int64 BATCHES, vx_int64 SRC_PIXELS, vx_int64 DST_PIXELS, vx_int64 SRC_PARALLEL, vx_int64 DST_PARALLEL>
void ConverterPassThrough(
	vx_image_data<TypeData, SRC_PARALLEL> src[(BATCHES * SRC_PIXELS) / SRC_PARALLEL],
	vx_image_data<TypeData, DST_PARALLEL> dst[(BATCHES * DST_PIXELS) / DST_PARALLEL])
{
#pragma HLS INLINE

	// Constants
	const vx_int64 VECTOR = SRC_PIXELS / SRC_PARALLEL;
	const vx_int64 PARALLEL = MIN(DST_PARALLEL, SRC_PARALLEL);

	// Copy elements
	for (vx_int64 batch = 0, ptr = 0; batch < BATCHES; ++batch)
	{
		for (vx_int64 i = 0; i < VECTOR; ++i)
		{
#pragma HLS pipeline II = 1

			// Input buffer
			vx_image_data<TypeData, SRC_PARALLEL> inputbuffer;
#pragma HLS array_partition variable = inputbuffer complete dim = 0

			// Output buffer
			vx_image_data<TypeData, DST_PARALLEL> outputbuffer;
#pragma HLS array_partition variable = outputbuffer complete dim = 0

			// Input
			inputbuffer = src[ptr];

			// Conversion ;)
			for (vx_int64 k = 0; k < PARALLEL; ++k)
				outputbuffer.pixel[k] = inputbuffer.pixel[k];

			// Set user(SOF) & last(EOF)
			GenerateDmaSignal<TypeData, DST_PARALLEL>((ptr == 0), (ptr == VECTOR - 1), outputbuffer);

			// Output
			dst[ptr] = outputbuffer;
			++ptr;
		}
	}
}

/***************************************************************************************************************************************************/
template <typename TypeData, vx_int64 BATCHES, vx_int64 SRC_PIXELS, vx_int64 DST_PIXELS, vx_int64 SRC_PARALLEL, vx_int64 DST_PARALLEL>
void ConvertSrcBigger(
	vx_image_data<TypeData, SRC_PARALLEL> src[(BATCHES * SRC_PIXELS) / SRC_PARALLEL],
	vx_image_data<TypeData, DST_PARALLEL> dst[(BATCHES * DST_PIXELS) / DST_PARALLEL])
{
#pragma HLS INLINE

	// Constants
	const vx_int64 DST_VECTOR = DST_PIXELS / DST_PARALLEL;
	const vx_int64 SRC_VECTOR = SRC_PIXELS / SRC_PARALLEL;
	const vx_int64 BUFFER_SIZE = MIN(SRC_PARALLEL * DST_PARALLEL, MAX(DST_PIXELS, SRC_PIXELS));
	const vx_int64 VECTOR = MAX((BATCHES * DST_PIXELS) / (SRC_PARALLEL * DST_PARALLEL), (BATCHES * SRC_PIXELS) / (SRC_PARALLEL * DST_PARALLEL));

	// Long buffer to overcome the SRC/DST PARALLEL missmatch
	TypeData buffer[BUFFER_SIZE]; // TODO: Initialize
#pragma HLS array_partition variable = buffer complete dim = 0

	// Iteration
	for (vx_int64 i = 0, src_ptr = 0, dst_ptr = 0; i < VECTOR; ++i)
	{
		for (vx_int64 j = 0; j < SRC_PARALLEL; ++j)
		{
#pragma HLS pipeline II = 1

			// Input buffer
			vx_image_data<TypeData, SRC_PARALLEL> inputbuffer;
#pragma HLS array_partition variable = inputbuffer complete dim = 0

			// Output buffer
			vx_image_data<TypeData, DST_PARALLEL> outputbuffer;
#pragma HLS array_partition variable = outputbuffer complete dim = 0

			// Read data from input and write to buffer
			if ((j < DST_PARALLEL) && (src_ptr < (BATCHES * SRC_VECTOR)))
			{

				inputbuffer = src[src_ptr];
				++src_ptr;

				for (vx_int64 k = 0; k < SRC_PARALLEL; ++k)
					buffer[j * SRC_PARALLEL + k] = inputbuffer.pixel[k];
			}

			// Read data from buffer and write to output
			if ((j < SRC_PARALLEL) && (dst_ptr < (BATCHES * DST_VECTOR)))
			{

				for (vx_int64 k = 0; k < DST_PARALLEL; ++k)
					outputbuffer.pixel[k] = buffer[j * DST_PARALLEL + k];

				// Set user(SOF) & last(EOF)
				GenerateDmaSignal<TypeData, DST_PARALLEL>((dst_ptr == 0), (dst_ptr == DST_VECTOR - 1), outputbuffer);

				dst[dst_ptr] = outputbuffer;
				++dst_ptr;
			}
		}
	}
}

/***************************************************************************************************************************************************/
template <typename TypeData, vx_int64 BATCHES, vx_int64 SRC_PIXELS, vx_int64 DST_PIXELS, vx_int64 SRC_PARALLEL, vx_int64 DST_PARALLEL>
void ConvertDstBigger(
	vx_image_data<TypeData, SRC_PARALLEL> src[(BATCHES * SRC_PIXELS) / SRC_PARALLEL],
	vx_image_data<TypeData, DST_PARALLEL> dst[(BATCHES * DST_PIXELS) / DST_PARALLEL])
{
#pragma HLS INLINE

	// Constants
	const vx_int64 GCD_PARALLEL = GCD(DST_PARALLEL, SRC_PARALLEL);
	const vx_int64 LCM_PARALLEL = LCM(DST_PARALLEL, SRC_PARALLEL);
	const vx_int64 BUFFER_SIZE = MIN(LCM_PARALLEL, MAX(DST_PIXELS, SRC_PIXELS));
	const vx_int64 DST_VECTOR = DST_PIXELS / DST_PARALLEL;
	const vx_int64 SRC_VECTOR = SRC_PIXELS / SRC_PARALLEL;
	const vx_int64 VECTOR = MAX(SRC_VECTOR, DST_VECTOR);

	// Long buffer to overcome the SRC/DST PARALLEL missmatch
	TypeData buffer[BUFFER_SIZE];
#pragma HLS array_partition variable = buffer complete dim = 0

	// Itaeration
	for (vx_int64 batch = 0; batch < BATCHES; ++batch)
	{
		for (vx_int64 src_ptr = 0, dst_ptr = 0; (src_ptr < VECTOR); ++src_ptr)
		{
#pragma HLS pipeline II = 1

			// Input buffer
			vx_image_data<TypeData, SRC_PARALLEL> inputbuffer;
#pragma HLS array_partition variable = inputbuffer complete dim = 0

			// Output buffer
			vx_image_data<TypeData, DST_PARALLEL> outputbuffer;
#pragma HLS array_partition variable = outputbuffer complete dim = 0

			// Buffer pointer
			const vx_int64 src_cnt = (src_ptr % (DST_PARALLEL / GCD_PARALLEL)) * SRC_PARALLEL;
			const vx_int64 dst_cnt = (dst_ptr % (SRC_PARALLEL / GCD_PARALLEL)) * DST_PARALLEL;

			// Read data from input and write to buffer
			if (src_ptr < SRC_VECTOR)
			{

				inputbuffer = src[batch * SRC_VECTOR + src_ptr];

				for (vx_int64 k = 0; k < SRC_PARALLEL; ++k)
					buffer[src_cnt + k] = inputbuffer.pixel[k];
			}

			// Read data from buffer and write to output
			if (dst_ptr < DST_VECTOR)
			{
				if ((src_cnt + SRC_PARALLEL) >= (dst_cnt + DST_PARALLEL))
				{

					for (vx_int64 k = 0; k < DST_PARALLEL; ++k)
						outputbuffer.pixel[k] = buffer[dst_cnt + k];

					// Set user(SOF) & last(EOF)
					GenerateDmaSignal<TypeData, DST_PARALLEL>((dst_ptr == 0), (dst_ptr == DST_VECTOR - 1), outputbuffer);

					dst[batch * DST_VECTOR + dst_ptr] = outputbuffer;
					++dst_ptr;
				}
			}
		}
	}
}

/***************************************************************************************************************************************************/
// Convert between vector sizes of a stream
template <typename TypeData, vx_int64 BATCHES, vx_int64 SRC_PIXELS, vx_int64 DST_PIXELS, vx_int64 SRC_PARALLEL, vx_int64 DST_PARALLEL>
void DataWidthConverter(
	vx_image_data<TypeData, SRC_PARALLEL> src[(BATCHES * SRC_PIXELS) / SRC_PARALLEL],
	vx_image_data<TypeData, DST_PARALLEL> dst[(BATCHES * DST_PIXELS) / DST_PARALLEL])
{
#pragma HLS INLINE

	// Constants
	const bool MULTIPLE = (SRC_PARALLEL > DST_PARALLEL) ? ((SRC_PARALLEL % DST_PARALLEL) == 0) : ((DST_PARALLEL % SRC_PARALLEL) == 0);

	// Compile time checks
	STATIC_ASSERT((BATCHES > 0) && (SRC_PIXELS > 0) && (DST_PIXELS > 0) && (SRC_PARALLEL > 0) && (DST_PARALLEL > 0), ONE_OF_THE_TEMPLATE_PARAMETERS_IS_ZERO);
	STATIC_ASSERT(((SRC_PIXELS % SRC_PARALLEL) == 0) && (SRC_PIXELS >= SRC_PARALLEL), PIXELS_ARE_NOT_MULTIPLE_OF_SRC_PARALLEL);
	STATIC_ASSERT(((DST_PIXELS % DST_PARALLEL) == 0) && (DST_PIXELS >= DST_PARALLEL), PIXELS_ARE_NOT_MULTIPLE_OF_DST_PARALLEL);

	// Down Conversion
	if (SRC_PARALLEL > DST_PARALLEL)
	{
		if (MULTIPLE == true)
		{
			ConverterSrcMulitple<TypeData, BATCHES, SRC_PIXELS, DST_PIXELS, SRC_PARALLEL, DST_PARALLEL>(src, dst);
		}
		else
		{
			ConvertSrcBigger<TypeData, BATCHES, SRC_PIXELS, DST_PIXELS, SRC_PARALLEL, DST_PARALLEL>(src, dst);
		}

		// Up Conversion
	}
	else if (DST_PARALLEL > SRC_PARALLEL)
	{
		if (MULTIPLE == true)
		{
			ConverterDstMulitple<TypeData, BATCHES, SRC_PIXELS, DST_PIXELS, SRC_PARALLEL, DST_PARALLEL>(src, dst);
		}
		else
		{
			ConvertDstBigger<TypeData, BATCHES, SRC_PIXELS, DST_PIXELS, SRC_PARALLEL, DST_PARALLEL>(src, dst);
		}

		// Pass through
	}
	else if (SRC_PARALLEL == DST_PARALLEL)
	{
		ConverterPassThrough<TypeData, BATCHES, SRC_PIXELS, DST_PIXELS, SRC_PARALLEL, DST_PARALLEL>(src, dst);
	}
}

/***************************************************************************************************************************************************/
// Takes 1 image and sends it to multiple ports
template <typename DataType, vx_uint32 IMG_PIXELS, vx_uint8 VEC_NUM, vx_uint8 OUT_NUM>
void Multicast(
	vx_image_data<DataType, VEC_NUM> input[IMG_PIXELS / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> out1[IMG_PIXELS / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> out2[IMG_PIXELS / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> out3[IMG_PIXELS / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> out4[IMG_PIXELS / VEC_NUM])
{
#pragma HLS INLINE

	for (vx_uint32 i = 0; i < (IMG_PIXELS / VEC_NUM); i++)
	{
#pragma HLS PIPELINE II = 1
		vx_image_data<DataType, VEC_NUM> src = input[i];

		// Set user(SOF) & last(EOF)
		GenerateDmaSignal<DataType, VEC_NUM>((i == 0), (i == (IMG_PIXELS / VEC_NUM - 1)), src);

		if (OUT_NUM >= 1)
			out1[i] = src;
		if (OUT_NUM >= 2)
			out2[i] = src;
		if (OUT_NUM >= 3)
			out3[i] = src;
		if (OUT_NUM >= 4)
			out4[i] = src;
	}
}

/***************************************************************************************************************************************************/
// Takes 1 image and sends it to multiple ports
template <typename DataType, vx_uint32 IMG_PIXELS, vx_uint8 VEC_NUM, vx_uint8 OUT_NUM>
void Multicast(
	DataType input[IMG_PIXELS],
	DataType out1[IMG_PIXELS],
	DataType out2[IMG_PIXELS],
	DataType out3[IMG_PIXELS],
	DataType out4[IMG_PIXELS])
{
#pragma HLS INLINE

	STATIC_ASSERT(VEC_NUM == 1, USE_THE_VX_IMAGE_DATA_TYPE_FOR_VEC_NUM_BIGGER_1);

	for (vx_uint32 i = 0; i < IMG_PIXELS; i++)
	{
#pragma HLS PIPELINE II = 1
		DataType src = input[i];

		if (OUT_NUM >= 1)
			out1[i] = src;
		if (OUT_NUM >= 2)
			out2[i] = src;
		if (OUT_NUM >= 3)
			out3[i] = src;
		if (OUT_NUM >= 4)
			out4[i] = src;
	}
}

/***************************************************************************************************************************************************/
/** @brief Resize the image down to nearest neighbor
 * @param COLS_IN     The columns of the input image
 * @param ROWS_IN     The rows of the input image
 * @param COLS_OUT    The columns of the output image
 * @param ROWS_OUT    The rows of the output image
 * @param input       The input image
 * @param output      The output image
 */
template <vx_uint16 COLS_IN, vx_uint16 ROWS_IN, vx_uint16 COLS_OUT, vx_uint16 ROWS_OUT>
void ScaleDownNearest(vx_image_data<vx_uint8, 1> input[COLS_IN * ROWS_IN], vx_image_data<vx_uint8, 1> output[COLS_OUT * ROWS_OUT])
{
#pragma HLS INLINE

	// Compute the scale factor of the resized image in x and y direction
	const vx_uint32 ACCURACY = 14;
	const vx_uint32 COLS_SCALE = (vx_uint32)(((vx_float64)COLS_IN / (vx_float64)COLS_OUT) * std::pow(2, ACCURACY) + 0.5);
	const vx_uint32 ROWS_SCALE = (vx_uint32)(((vx_float64)ROWS_IN / (vx_float64)ROWS_OUT) * std::pow(2, ACCURACY) + 0.5);

	// Compute the resized image
	for (vx_uint32 y = 0, y_dst = 0, y_dst_next = 0; y < ROWS_IN; y++)
	{
		for (vx_uint32 x = 0, x_dst = 0; x < COLS_IN; x++)
		{
#pragma HLS PIPELINE II = 1

			vx_image_data<vx_uint8, 1> src;
			vx_image_data<vx_uint8, 1> dst;

			// Get next input pixel in a stream
			src = input[y * COLS_IN + x];
			vx_uint8 data = src.pixel[0];

			// Compute the coordinates of the next needed input pixel
			vx_uint32 x_src = (((((x_dst << 1) + 1) * COLS_SCALE) >> ACCURACY) - 1) >> 1; // (vx_int32)floor((x_dst + 0.5f)*(COLS_IN/COLS_OUT) - 0.5f) using floating point computation
			vx_uint32 y_src = (((((y_dst << 1) + 1) * ROWS_SCALE) >> ACCURACY) - 1) >> 1; // (vx_int32)floor((y_dst + 0.5f)*(ROWS_IN/ROWS_OUT) - 0.5f) using floating point computation

			// Check if current input pixel is the needed one
			if ((y_src == y) && (x_src == x))
			{

				// Set user(SOF) & last(EOF)
				GenerateDmaSignal<vx_uint8, 1>((x_dst == 0 && y_dst == 0), (x_dst == (COLS_OUT - 1) && y_dst == (ROWS_OUT - 1)), dst);

				// Write the ouput pixel to stream
				dst.pixel[0] = data;
				output[y_dst * COLS_OUT + x_dst] = dst;

				// Update pointer
				x_dst++;
				y_dst_next = 1;
			}

			// Update pointer
			if ((y_dst_next == 1) && (x == COLS_IN - 1))
			{
				y_dst++;
				y_dst_next = 0;
			}
		}
	}
}

/***************************************************************************************************************************************************/
/** @brief Resize the image down using bilinear interpolation
 * @param COLS_IN     The columns of the input image
 * @param ROWS_IN     The rows of the input image
 * @param COLS_OUT    The columns of the output image
 * @param ROWS_OUT    The rows of the output image
 * @param input       The input image
 * @param output      The output image
 */
template <vx_uint16 COLS_IN, vx_uint16 ROWS_IN, vx_uint16 COLS_OUT, vx_uint16 ROWS_OUT>
void ScaleDownBilinear(vx_image_data<vx_uint8, 1> input[COLS_IN * ROWS_IN], vx_image_data<vx_uint8, 1> output[COLS_OUT * ROWS_OUT])
{
#pragma HLS INLINE

	// Compute constants
	const vx_uint32 ACCURACY = 12; // Minimum 12, Maximum 15
	const vx_uint32 ONE = (1 << ACCURACY);
	const vx_uint32 SHIFT = 2 * ACCURACY - 10 - 8;
	const vx_uint32 MASK_FRAKTION = (1 << (ACCURACY + 2)) - 1;
	const vx_uint32 COLS_SCALE = (vx_uint32)(((vx_float64)COLS_IN / (vx_float64)COLS_OUT) * std::pow(2, ACCURACY) + 0.5);
	const vx_uint32 ROWS_SCALE = (vx_uint32)(((vx_float64)ROWS_IN / (vx_float64)ROWS_OUT) * std::pow(2, ACCURACY) + 0.5);

	// Strt and step size of src ptr with "ACCURACY" fraction size
	// x_src = (x + 0.5) * scale_cols - 0.5 | fraction = 1+1+ACCURACY | not negative: SCALE > 1.0f
	const vx_uint32 X_SRC_STRT = (COLS_SCALE << 1) - 1;
	const vx_uint32 Y_SRC_STRT = (ROWS_SCALE << 1) - 1;
	const vx_uint32 X_SRC_STEP = COLS_SCALE * 4;
	const vx_uint32 Y_SRC_STEP = ROWS_SCALE * 4;

	// Buffer the input pixel
	vx_uint8 data_new = 0;
	vx_uint8 data_left = 0, data_right = 0;
	vx_uint8 buffer_one[COLS_IN];
	vx_uint8 buffer_two[COLS_IN];

	vx_uint32 in_cnt = 0, out_cnt = 0;

	// Compute the resized image
	for (vx_uint32 y = 0, y_dst = 0, y_src = Y_SRC_STRT, y_dst_next = 0; y <= ROWS_IN; y++)
	{
		for (vx_uint32 x = 0, x_dst = 0, x_src = X_SRC_STRT; x <= COLS_IN; x++)
		{
#pragma HLS PIPELINE II = 1

			vx_image_data<vx_uint8, 1> src;
			vx_image_data<vx_uint8, 1> dst;

			vx_uint8 tl, tr, bl, br;

			// Buffer the previous input pixel [x-1]
			vx_uint8 data_old = data_new;

			// Read Input Pixel from Stream
			if (x < COLS_IN && y < ROWS_IN)
			{
				in_cnt++;
				src = input[y * COLS_IN + x];
				data_new = src.pixel[0];
			}

			// Compute the coordinates of all needed input pixels
			vx_uint32 x_fract = (x_src & MASK_FRAKTION) >> 2;
			vx_uint32 y_fract = (y_src & MASK_FRAKTION) >> 2;
			vx_uint16 x_l = (vx_uint16)(x_src >> (ACCURACY + 2));
			vx_uint16 y_t = (vx_uint16)(y_src >> (ACCURACY + 2));
			vx_uint16 x_r = x_l + 1;
			vx_uint16 y_b = y_t + 1;

			// Write/Read data to/from buffer
			if ((y % 2) == 0)
			{
				if (x_l < COLS_IN)
					data_left = buffer_two[x_l];
				if (x_r < COLS_IN)
					data_right = buffer_two[x_r];
				if (x > 0)
					buffer_one[x - 1] = data_old;
			}
			else
			{
				if (x_l < COLS_IN)
					data_left = buffer_one[x_l];
				if (x_r < COLS_IN)
					data_right = buffer_one[x_r];
				if (x > 0)
					buffer_two[x - 1] = data_old;
			}

			// Get the 4 needed input pixel (using replicated borders)
			if (y_t == COLS_IN - 1)
			{
				if (x_l == ROWS_IN - 1)
				{
					tl = tr = bl = br = data_left;
				}
				else
				{
					tr = br = data_right;
					tl = bl = data_left;
				}
			}
			else
			{
				if (x_l == ROWS_IN - 1)
				{
					bl = br = data_old;
					tl = tr = data_left;
				}
				else
				{
					tl = data_right;
					tr = data_left;
					bl = data_old;
					br = data_new;
				}
			}

			// Compute the Bilinear Interpolation (Saturated)
			vx_uint16 tl_part = (vx_uint16)(((((ONE - x_fract) * (ONE - y_fract)) >> 10) * (vx_uint32)tl) >> 8);
			vx_uint16 tr_part = (vx_uint16)(((((x_fract) * (ONE - y_fract)) >> 10) * (vx_uint32)tr) >> 8);
			vx_uint16 bl_part = (vx_uint16)(((((ONE - x_fract) * (y_fract)) >> 10) * (vx_uint32)bl) >> 8);
			vx_uint16 br_part = (vx_uint16)(((((x_fract) * (y_fract)) >> 10) * (vx_uint32)br) >> 8);
			vx_uint16 sum = (tl_part + tr_part + bl_part + br_part) >> (2 * ACCURACY - 10 - 8);
			vx_uint8 result = (vx_uint8)(MIN(sum, (vx_uint16)(255)));

			// Check if the input pixel are the needed ones
			if ((x_r == x) && (y_b == y))
			{
				out_cnt++;

				// Set user(SOF) & last(EOF)
				GenerateDmaSignal<vx_uint8, 1>((x_dst == 0 && y_dst == 0), (x_dst == (COLS_OUT - 1) && y_dst == (ROWS_OUT - 1)), dst);

				// Write ouput pixel to stream
				dst.pixel[0] = result;
				output[y_dst * COLS_OUT + x_dst] = dst;

				// Update pointer
				x_dst++;
				x_src += X_SRC_STEP;
				y_dst_next = 1;
			}

			// Update pointer
			if ((y_dst_next == 1) && (x_dst == COLS_OUT))
			{
				y_dst++;
				y_src += Y_SRC_STEP;
				y_dst_next = 0;
			}
		}
	}
}

/***************************************************************************************************************************************************/
/** @brief Scale an image down using bilinear or nearest neighbor interpolation
 * @param COLS_IN     The columns of the input image
 * @param ROWS_IN     The rows of the input image
 * @param COLS_OUT    The columns of the output image
 * @param ROWS_OUT    The rows of the output image
 * @param SCALE_TYPE  The type of interpolation (VX_INTERPOLATION_BILINEAR or VX_INTERPOLATION_AREA)
 * @param input       The input image
 * @param output      The output image
 */
template <vx_uint16 COLS_IN, vx_uint16 ROWS_IN, vx_uint16 COLS_OUT, vx_uint16 ROWS_OUT, vx_interpolation_type_e SCALE_TYPE>
void ScaleImage(vx_image_data<vx_uint8, 1> input[COLS_IN * ROWS_IN], vx_image_data<vx_uint8, 1> output[COLS_OUT * ROWS_OUT])
{
#pragma HLS INLINE

	// Check if output image resolution is smaller than input image resolution
	STATIC_ASSERT(COLS_IN >= COLS_OUT, only_down_scale_of_image_supported);
	STATIC_ASSERT(ROWS_IN >= ROWS_OUT, only_down_scale_of_image_supported);
	STATIC_ASSERT(SCALE_TYPE == VX_INTERPOLATION_NEAREST_NEIGHBOR || SCALE_TYPE == VX_INTERPOLATION_BILINEAR, scale_type_not_supported);

	// Nearest neighbor interpolation
	if (SCALE_TYPE == VX_INTERPOLATION_NEAREST_NEIGHBOR)
	{
		ScaleDownNearest<COLS_IN, ROWS_IN, COLS_OUT, ROWS_OUT>(input, output);

		// Bilinear Interpolation
	}
	else if (SCALE_TYPE == VX_INTERPOLATION_BILINEAR)
	{
		ScaleDownBilinear<COLS_IN, ROWS_IN, COLS_OUT, ROWS_OUT>(input, output);

		// Interpolation not supported
	}
	else if (SCALE_TYPE == VX_INTERPOLATION_AREA)
	{
	}
}

/***************************************************************************************************************************************************/
/** These features allow for conditional graph flow in OpenVX, via support for a variety of operations between two scalars.
 * @param SrcType           The data type of the input scalars
 * @param DstType           The data type of the output scalar
 * @param scalar_operation  The scalar operation enum
 * @param input1            First scalar operand
 * @param input2            Second scalar operand
 * @param output            Result of the scalar operation (DstType)(A op B)
 */
template <typename SrcType, typename DstType, vx_scalar_operation_e scalar_operation>
void ControlFlow(
	vx_image_data<SrcType, 1> input1[1],
	vx_image_data<SrcType, 1> input2[1],
	vx_image_data<DstType, 1> output[1])
{
#pragma HLS INLINE

	// Get data type information
	const bool is_specialized_src = std::numeric_limits<SrcType>::is_specialized;
	const bool is_specialized_dst = std::numeric_limits<DstType>::is_specialized;
	const bool is_integer_src = std::numeric_limits<SrcType>::is_integer; // Not all operations are possible on floats
	const bool is_integer_dst = std::numeric_limits<DstType>::is_integer;
	const SrcType maximum = std::numeric_limits<SrcType>::max(); // division or modulus not possible

	// Compile time checks
	const bool logical = (scalar_operation == VX_SCALAR_OP_AND) || (scalar_operation == VX_SCALAR_OP_OR) || (scalar_operation == VX_SCALAR_OP_XOR) ||
						 (scalar_operation == VX_SCALAR_OP_NAND) || (scalar_operation == VX_SCALAR_OP_MODULUS);
	const bool logical_float = (logical == true) && (is_integer_src == false);
	STATIC_ASSERT((logical_float == false), logical_operators_and_modulus_are_not_possible_on_float);
	STATIC_ASSERT((is_specialized_src == true) && (is_specialized_dst == true), the_data_type_is_not_known);

	// Read input
	vx_image_data<SrcType, 1> src1 = input1[0];
	vx_image_data<SrcType, 1> src2 = input2[0];
	SrcType A = src1.pixel[0];
	SrcType B = src2.pixel[0];
	SrcType C = 0;
	DstType D = 0;
	vx_image_data<DstType, 1> dst;

	// Compute
	if (scalar_operation == VX_SCALAR_OP_AND)
	{
		C = (A & B);
	}
	else if (scalar_operation == VX_SCALAR_OP_OR)
	{
		C = (A | B);
	}
	else if (scalar_operation == VX_SCALAR_OP_XOR)
	{
		C = (A ^ B);
	}
	else if (scalar_operation == VX_SCALAR_OP_NAND)
	{
		C = !(A & B);
	}
	else if (scalar_operation == VX_SCALAR_OP_EQUAL)
	{
		C = (A == B);
	}
	else if (scalar_operation == VX_SCALAR_OP_NOTEQUAL)
	{
		C = (A != B);
	}
	else if (scalar_operation == VX_SCALAR_OP_LESS)
	{
		C = (A < B);
	}
	else if (scalar_operation == VX_SCALAR_OP_LESSEQ)
	{
		C = (A <= B);
	}
	else if (scalar_operation == VX_SCALAR_OP_GREATER)
	{
		C = (A > B);
	}
	else if (scalar_operation == VX_SCALAR_OP_GREATEREQ)
	{
		C = (A >= B);
	}
	else if (scalar_operation == VX_SCALAR_OP_ADD)
	{
		C = (A + B);
	}
	else if (scalar_operation == VX_SCALAR_OP_SUBTRACT)
	{
		C = (A - B);
	}
	else if (scalar_operation == VX_SCALAR_OP_MULTIPLY)
	{
		C = (A * B);
	}
	else if (scalar_operation == VX_SCALAR_OP_DIVIDE)
	{
		C = (B == 0) ? (maximum) : (A / B);
	}
	else if (scalar_operation == VX_SCALAR_OP_MODULUS)
	{
		C = (B == 0) ? (0) : (A % B);
	}
	else if (scalar_operation == VX_SCALAR_OP_MIN)
	{
		C = MIN(A, B);
	}
	else if (scalar_operation == VX_SCALAR_OP_MAX)
	{
		C = MAX(A, B);
	}

	// integer = float op float (VX_ROUND_POLICY_TO_ZERO, VX_CONVERT_POLICY_SATURATE)
	if ((is_integer_dst == true) && (is_integer_src == false))
	{
		const SrcType sat_max = static_cast<SrcType>(std::numeric_limits<DstType>::max());
		const SrcType sat_min = static_cast<SrcType>(std::numeric_limits<DstType>::min());
		D = static_cast<DstType>(MIN(MAX(C, sat_min), sat_max));

		// Otherwise VX_CONVERT_POLICY_WRAP
	}
	else
	{
		D = static_cast<DstType>(C);
	}

	// Set user(SOF) & last(EOF)
	GenerateDmaSignal<DstType, 1>(true, true, dst);

	// Write output
	dst.pixel[0] = D;
	output[0] = dst;
}

/***************************************************************************************************************************************************/
// Reset the two histogram entries
template <typename T, vx_uint32 BINS>
void ResetHistograms(T LUTA[BINS], T LUTB[BINS])
{
#pragma HLS INLINE

	for (vx_uint32 i = 0; i < BINS; i++)
	{
#pragma HLS PIPELINE II = 1
		LUTA[i] = 0;
		LUTB[i] = 0;
	}
}

/***************************************************************************************************************************************************/
// Cumulative distribution function
template <vx_uint32 IMG_PIXELS, vx_uint32 BINS>
void EqualizeHistDistribution(vx_uint32 LUTA[BINS], vx_uint32 LUTB[BINS], vx_uint32 HIST[BINS], vx_uint8 min_bin)
{
#pragma HLS INLINE

	// Constants
	const vx_uint8 MAX_VAL = std::numeric_limits<vx_uint8>::max();
	const vx_uint32 SHIFT = 24;

	//
	const vx_uint32 cdf_min_ = LUTA[min_bin] + LUTB[min_bin];

	// Pre-compute parts of the cdf computation
	const vx_uint32 divisor_ = (IMG_PIXELS - cdf_min_); // TODO: show that IMG_PIXELS > cdf_min_
	const vx_uint32 dividend_ = ((vx_uint32)(MAX_VAL)) << SHIFT;
	const vx_uint64 multiplicant_ = (vx_uint64)(dividend_ / divisor_);

	// Compute Equalized histogram
	for (vx_uint32 i = 0, cdf_i = 0; i < BINS; i++)
	{
#pragma HLS PIPELINE II = 1

		// Cumulative distribution function
		cdf_i += LUTA[i] + LUTB[i];

		// Compute equalized histogram function
		vx_uint64 cdf = (vx_uint64)(cdf_i - cdf_min_);
		vx_uint32 eqhist_i = (vx_uint32)((cdf * multiplicant_) >> SHIFT);

		// Store result in buffer
		HIST[i] = static_cast<vx_uint32>(eqhist_i);
	}
}

/***************************************************************************************************************************************************/
/** @brief Equalizes the histogram of a grayscale image.
 * @param IMG_PIXELS The amount of pixels for input and output image
 * @param input1     The grayscale input image in VX_DF_IMAGE_U8 (1. read)
 * @param input2     The grayscale input image in VX_DF_IMAGE_U8 (2. read)
 * @param output     The grayscale output image of type vx_uint8 with equalized brightness and contrast and same size as the input image.
 */
template <vx_uint32 IMG_PIXELS>
void EqualizeHist(
	vx_image_data<vx_uint8, 1> input1[IMG_PIXELS],
	vx_image_data<vx_uint8, 1> input2[IMG_PIXELS],
	vx_image_data<vx_uint32, 1> output[IMG_PIXELS])
{
#pragma HLS INLINE

	// Constants
	const vx_uint32 BINS = 256;

	// Variables
	vx_uint8 pre_bin = 0, cur_bin = 0;
	vx_uint32 pre_val = 0, cur_val = 0;
	vx_uint8 min_bin = std::numeric_limits<vx_uint8>::max();

	// Buffer Histogram in BRAM
	vx_uint32 LUTA[BINS], LUTB[BINS], HIST[BINS];

	// Reset histogram
	ResetHistograms<vx_uint32, BINS>(LUTA, LUTB);

	// Compute Histogram
	for (vx_uint32 i = 0; i < IMG_PIXELS + 1; i++)
	{
#pragma HLS PIPELINE II = 1

		// Gett the input data
		if (i < IMG_PIXELS)
		{
			vx_image_data<vx_uint8, 1> src = input1[i];
			cur_bin = src.pixel[0];
		}

		// Compute minimum bin entry
		min_bin = MIN(min_bin, cur_bin);

		// Read current bin & write previous bin
		if (i % 2 == 0)
		{
			cur_val = LUTA[cur_bin];
			LUTB[pre_bin] = pre_val;
		}
		else
		{
			cur_val = LUTB[cur_bin];
			LUTA[pre_bin] = pre_val;
		}

		// Update to store in next iteration
		cur_val++;
		pre_bin = cur_bin;
		pre_val = cur_val;
	}

	// Cumulative distribution function
	EqualizeHistDistribution<IMG_PIXELS, BINS>(LUTA, LUTB, HIST, min_bin);

	// Write equalized image
	for (vx_uint32 i = 0; i < IMG_PIXELS; ++i)
	{
#pragma HLS PIPELINE II = 1
		vx_image_data<vx_uint32, 1> dst;

		// Read input
		vx_image_data<vx_uint8, 1> src = input2[i];

		// Set user(SOF) & last(EOF)
		GenerateDmaSignal<vx_uint32, 1>((i == 0), (i == IMG_PIXELS - 1), dst);

		// Write output
		dst.pixel[0] = HIST[src.pixel[0]];
		output[i] = dst;
	}
}

/***************************************************************************************************************************************************/
/** @brief Equalizes the histogram of a grayscale image.
 * @param IMG_PIXELS The amount of pixels for input and output image
 * @param input1     The grayscale input image in VX_DF_IMAGE_U8 (1. read)
 * @param input2     The grayscale input image in VX_DF_IMAGE_U8 (2. read)
 * @param output     The grayscale output image of type vx_uint8 with equalized brightness and contrast and same size as the input image.
 */
template <vx_uint32 IMG_PIXELS>
void EqualizeHist(vx_uint8 input1[IMG_PIXELS], vx_uint8 input2[IMG_PIXELS], vx_uint32 output[IMG_PIXELS])
{
#pragma HLS INLINE

	// Constants
	const vx_uint32 BINS = 256;

	// Variables
	vx_uint8 pre_bin = 0, cur_bin = 0;
	vx_uint32 pre_val = 0, cur_val = 0;
	vx_uint8 min_bin = std::numeric_limits<vx_uint8>::max();

	// Buffer Histogram in BRAM
	vx_uint32 LUTA[BINS], LUTB[BINS], HIST[BINS];

	// Reset histogram
	ResetHistograms<vx_uint32, BINS>(LUTA, LUTB);

	// Compute Histogram
	for (vx_uint32 i = 0; i < IMG_PIXELS + 1; i++)
	{
#pragma HLS PIPELINE II = 1

		// Gett the input data
		if (i < IMG_PIXELS)
		{
			cur_bin = input1[i];
		}

		// Compute minimum bin entry
		min_bin = MIN(min_bin, cur_bin);

		// Read current bin & write previous bin
		if (i % 2 == 0)
		{
			cur_val = LUTA[cur_bin];
			LUTB[pre_bin] = pre_val;
		}
		else
		{
			cur_val = LUTB[cur_bin];
			LUTA[pre_bin] = pre_val;
		}

		// Update to store in next iteration
		cur_val++;
		pre_bin = cur_bin;
		pre_val = cur_val;
	}

	//
	EqualizeHistDistribution<IMG_PIXELS, BINS>(LUTA, LUTB, HIST, min_bin);

	// Write equalized image
	for (vx_uint32 i = 0; i < IMG_PIXELS; ++i)
	{
#pragma HLS PIPELINE II = 1
		output[i] = HIST[input2[i]];
	}
}

/***************************************************************************************************************************************************/
// Compile time checks for histogram function
template <typename SrcType, vx_uint32 DISTRIBUTION_BINS, vx_uint32 DISTRIBUTION_RANGE, SrcType DISTRIBUTION_OFFSET>
void HistogramCompileTimeChecks()
{
#pragma HLS INLINE

	// Check Datatype, MaximumValue, and that BIN is smaller RANGE
	const vx_type_e TYPE = GET_TYPE(SrcType);
	const bool allowed_type = (TYPE == VX_TYPE_UINT8) || (TYPE == VX_TYPE_UINT16);
	const vx_uint32 MAX_VAL = (TYPE == VX_TYPE_UINT8) ? (static_cast<vx_uint32>(0x100)) : (static_cast<vx_uint32>(0x10000));
	const bool allowed_value1 = ((DISTRIBUTION_BINS <= MAX_VAL) && (DISTRIBUTION_RANGE <= MAX_VAL));
	const bool allowed_value2 = (static_cast<vx_uint32>(DISTRIBUTION_OFFSET) <= (MAX_VAL - static_cast<vx_uint32>(1)));
	const bool allowed_range = DISTRIBUTION_BINS <= DISTRIBUTION_RANGE;
	STATIC_ASSERT(allowed_type, data_type_is_not_allowed_for_histogram);
	STATIC_ASSERT(allowed_value1, BINS_RANGE_value_out_of_range_max_0x100_for_uint8_and_0x10000_for_uint16);
	STATIC_ASSERT(allowed_value2, OFFSET_value_out_of_range_max_0xff_for_uint8_and_0xffff_for_uint16);
	STATIC_ASSERT(allowed_range, RANGE_should_be_smaller_or_equal_to_BINS);
}

/***************************************************************************************************************************************************/
// Updates an entry of the histogram
template <typename SrcType, vx_uint32 IMG_PIXELS, vx_uint32 DISTRIBUTION_BINS, vx_uint32 DISTRIBUTION_RANGE, SrcType DISTRIBUTION_OFFSET>
void HistogramUpdateEntry(vx_uint32 i, SrcType pixel, vx_uint32 LUTA[DISTRIBUTION_BINS], vx_uint32 LUTB[DISTRIBUTION_BINS], vx_uint16 &pre_bin, vx_uint32 &pre_val)
{
#pragma HLS INLINE

	vx_uint16 cur_bin = 0;
	vx_uint32 cur_val = 0;
	vx_bool range = vx_false_e;

	// Compute Scale (BINS / RANGE) "approximation"
	const vx_uint16 ACCURACY = 15;
	const vx_uint16 SCALE = static_cast<vx_uint16>((DISTRIBUTION_BINS << ACCURACY) / DISTRIBUTION_RANGE);

	// Check if bin will be out of range
	if ((DISTRIBUTION_OFFSET <= pixel) && (pixel <= (DISTRIBUTION_OFFSET + DISTRIBUTION_RANGE)) && (i < IMG_PIXELS))
		range = vx_true_e;

	// Subtract offset and compute current bin bin
	if (range)
	{
		const SrcType index = pixel - DISTRIBUTION_OFFSET;

		if (DISTRIBUTION_BINS != DISTRIBUTION_RANGE)
			cur_bin = static_cast<vx_uint16>((static_cast<vx_uint32>(index) * static_cast<vx_uint32>(SCALE)) >> ACCURACY);
		else
			cur_bin = static_cast<vx_uint16>(index);
	}

	// Read current histogram entry & write previous histogram entry
	if (i % 2 == 0)
	{
		cur_val = LUTA[cur_bin];
		LUTB[pre_bin] = pre_val;
	}
	else
	{
		cur_val = LUTB[cur_bin];
		LUTA[pre_bin] = pre_val;
	}

	// Increment histogram value
	if (range)
		cur_val++;

	// Update to store in next iteration
	pre_bin = cur_bin;
	pre_val = cur_val;
}

/***************************************************************************************************************************************************/
/** @brief Generates a distribution from an image.
 * @param SrcType              The Input Type can be vx_uint8 and vx_uint16
 * @param IMG_PIXELS           The amount of pixels for input and output image
 * @param DISTRIBUTION_BINS    Indicates the number of bins.
 * @param DISTRIBUTION_RANG    Indicates the total number of the consecutive values of the distribution interval.
 * @param DISTRIBUTION_OFFSET  Indicates the start of the values to use (inclusive).
 * @param input                The input image (vx_uint8, vx_uint16)
 * @param output               The output image (vx_uint32)
 */
template <typename SrcType, vx_uint32 IMG_PIXELS, vx_uint32 DISTRIBUTION_BINS, vx_uint32 DISTRIBUTION_RANGE, SrcType DISTRIBUTION_OFFSET>
void Histogram(
	vx_image_data<SrcType, 1> input[IMG_PIXELS],
	vx_image_data<vx_uint32, 1> output[IMG_PIXELS])
{
#pragma HLS INLINE

	// Compile time checks for histogram function
	HistogramCompileTimeChecks<SrcType, DISTRIBUTION_BINS, DISTRIBUTION_RANGE, DISTRIBUTION_OFFSET>();

	// Global variables
	vx_uint16 pre_bin = 0;
	vx_uint32 pre_val = 0;

	// Buffer Histogram in BRAM
	vx_uint32 LUTA[DISTRIBUTION_BINS], LUTB[DISTRIBUTION_BINS];

	// Reset histogram
	ResetHistograms<vx_uint32, DISTRIBUTION_BINS>(LUTA, LUTB);

	// Compute Histogram
	for (vx_uint32 i = 0; i < IMG_PIXELS + 1; i++)
	{
#pragma HLS PIPELINE II = 1

		// Variables
		SrcType pixel = 0;

		// Read input data
		if (i < IMG_PIXELS)
		{
			vx_image_data<SrcType, 1> src = input[i];
			pixel = src.pixel[0];
		}

		// Updates an entry of the histogram
		HistogramUpdateEntry<SrcType, IMG_PIXELS, DISTRIBUTION_BINS, DISTRIBUTION_RANGE, DISTRIBUTION_OFFSET>(i, pixel, LUTA, LUTB, pre_bin, pre_val);
	}

	// Write output data
	for (vx_uint32 i = 0; i < DISTRIBUTION_BINS; i++)
	{
#pragma HLS PIPELINE II = 1
		vx_image_data<vx_uint32, 1> dst;

		// Set user(SOF) & last(EOF)
		GenerateDmaSignal<vx_uint32, 1>((i == 0), (i == DISTRIBUTION_BINS - 1), dst);

		dst.pixel[0] = LUTA[i] + LUTB[i];
		output[i] = dst;
	}
}

/***************************************************************************************************************************************************/
/** @brief Generates a distribution from an image.
 * @param SrcType              The Input Type can be vx_uint8 and vx_uint16
 * @param IMG_PIXELS           The amount of pixels for input and output image
 * @param DISTRIBUTION_BINS    Indicates the number of bins.
 * @param DISTRIBUTION_RANG    Indicates the total number of the consecutive values of the distribution interval.
 * @param DISTRIBUTION_OFFSET  Indicates the start of the values to use (inclusive).
 * @param input                The input image (vx_uint8, vx_uint16)
 * @param output               The output image (vx_uint32)
 */
template <typename SrcType, vx_uint32 IMG_PIXELS, vx_uint32 DISTRIBUTION_BINS, vx_uint32 DISTRIBUTION_RANGE, SrcType DISTRIBUTION_OFFSET>
void Histogram(SrcType input[IMG_PIXELS], vx_uint32 output[IMG_PIXELS])
{
#pragma HLS INLINE

	// Compile time checks for histogram function
	HistogramCompileTimeChecks<SrcType, DISTRIBUTION_BINS, DISTRIBUTION_RANGE, DISTRIBUTION_OFFSET>();

	// Global variables
	vx_uint16 pre_bin = 0;
	vx_uint32 pre_val = 0;

	// Buffer Histogram in BRAM
	vx_uint32 LUTA[DISTRIBUTION_BINS], LUTB[DISTRIBUTION_BINS];

	// Reset histogram
	ResetHistograms<vx_uint32, DISTRIBUTION_BINS>(LUTA, LUTB);

	// Compute Histogram
	for (vx_uint32 i = 0; i < IMG_PIXELS + 1; i++)
	{
#pragma HLS PIPELINE II = 1

		// Variables
		SrcType pixel = 0;

		// Read input data
		if (i < IMG_PIXELS)
		{
			pixel = input[i];
		}

		// Updates an entry of the histogram
		HistogramUpdateEntry<SrcType, IMG_PIXELS, DISTRIBUTION_BINS, DISTRIBUTION_RANGE, DISTRIBUTION_OFFSET>(i, pixel, LUTA, LUTB, pre_bin, pre_val);
	}

	// Write output data
	for (vx_uint32 i = 0; i < DISTRIBUTION_BINS; i++)
	{
#pragma HLS PIPELINE II = 1
		output[i] = LUTA[i] + LUTB[i];
	}
}

/***************************************************************************************************************************************************/
/** @brief Computes the integral image of the input.
 * @param IMG_COLS    The columns of the image
 * @param IMG_ROWS    The rows of the image
 * @param input       The input image
 * @param output      The output image
 */
template <const vx_uint16 IMG_COLS, const vx_uint16 IMG_ROWS>
void Integral(
	vx_image_data<vx_uint8, 1> input[IMG_COLS * IMG_ROWS],
	vx_image_data<vx_uint32, 1> output[IMG_COLS * IMG_ROWS])
{
#pragma HLS INLINE

	// Buffers 1 row of the integral image
	vx_uint32 buffer[IMG_COLS];

	// Compute integral on image
	for (vx_uint32 y = 0; y < IMG_ROWS; y++)
	{
		for (vx_uint32 x = 0, sum_row = 0; x < IMG_COLS; x++)
		{
#pragma HLS PIPELINE II = 1
			vx_image_data<vx_uint8, 1> src;
			vx_image_data<vx_uint32, 1> dst;

			// Read input
			src = input[y * IMG_COLS + x];
			vx_uint8 pixel = src.pixel[0];

			// Compute the sum of the current row
			sum_row += pixel;

			// Compute the integral pixel
			vx_uint32 sum_area = sum_row;
			if (y > 0)
				sum_area += buffer[x];

			// Buffer the integral pixels of row for next row
			buffer[x] = sum_area;

			// Set user(SOF) & last(EOF)
			GenerateDmaSignal<vx_uint32, 1>((x == 0 && y == 0), (x == (IMG_COLS - 1) && y == (IMG_ROWS - 1)), dst);

			// Write output
			dst.pixel[0] = sum_area;
			output[y * IMG_COLS + x] = dst;
		}
	}
}
/***************************************************************************************************************************************************/
/** @brief Computes the integral image of the input.
 * @param IMG_COLS    The columns of the image
 * @param IMG_ROWS    The rows of the image
 * @param input       The input image
 * @param output      The output image
 */
template <const vx_uint16 IMG_COLS, const vx_uint16 IMG_ROWS>
void Integral(
	vx_uint8 input[IMG_COLS * IMG_ROWS],
	vx_uint32 output[IMG_COLS * IMG_ROWS])
{
#pragma HLS INLINE

	// Buffers 1 row of the integral image
	vx_uint32 buffer[IMG_COLS];

	// Compute integral on image
	for (vx_uint32 y = 0; y < IMG_ROWS; y++)
	{
		for (vx_uint32 x = 0, sum_row = 0; x < IMG_COLS; x++)
		{
#pragma HLS PIPELINE II = 1

			// Read input
			vx_uint8 pixel = input[y * IMG_COLS + x];

			// Compute the sum of the current row
			sum_row += pixel;

			// Compute the integral pixel
			vx_uint32 sum_area = sum_row;
			if (y > 0)
				sum_area += buffer[x];

			// Buffer the integral pixels of row for next row
			buffer[x] = sum_area;

			// Write output
			output[y * IMG_COLS + x] = sum_area;
		}
	}
}

/***************************************************************************************************************************************************/
/** @brief Computes the mean pixel value of the pixels in the input image.
 * @param DataType    The data type of the input, which can be 8-bit/16-bit signed/unsigned
 * @param IMG_COLS    The amount of columns in the image
 * @param IMG_ROWS    The amount of rows in the image
 * @param input       The input image
 * @param mean        The output average pixel value.
 * @param reciprocal  The reciprocal of the image pixel amount.
 */
template <typename DataType, vx_uint32 IMG_COLS, vx_uint32 IMG_ROWS>
void Mean(vx_image_data<DataType, 1> input[IMG_ROWS * IMG_COLS], vx_float32 &mean, const vx_float32 reciprocal)
{
#pragma HLS INLINE

	// Variables
	vx_int64 sum = 0;

	// Compute the sum for the mean value (pipelined)
	for (vx_uint32 y = 0; y < IMG_ROWS; y++)
	{
		for (vx_uint32 x = 0; x < IMG_COLS; x++)
		{
#pragma HLS PIPELINE II = 1
			vx_image_data<DataType, 1> src;

			// Read Input
			src = input[y * IMG_COLS + x];
			DataType data = src.pixel[0];

			// Compute sum
			sum += static_cast<vx_int64>(data);
		}
	}

	// Write back the mean value
	mean = static_cast<vx_float32>(sum) * reciprocal;
}

/***************************************************************************************************************************************************/
/** @brief Computes the mean pixel value of the pixels in the input image.
 * @param DataType    The data type of the input, which can be 8-bit/16-bit signed/unsigned
 * @param IMG_COLS    The amount of columns in the image
 * @param IMG_ROWS    The amount of rows in the image
 * @param input       The input image
 * @param mean        The output average pixel value.
 * @param reciprocal  The reciprocal of the image pixel amount.
 */
template <typename DataType, vx_uint32 IMG_COLS, vx_uint32 IMG_ROWS>
void Mean(DataType input[IMG_ROWS * IMG_COLS], vx_float32 &mean, const vx_float32 reciprocal)
{
#pragma HLS INLINE

	// Variables
	vx_int64 sum = 0;

	// Compute the sum for the mean value (pipelined)
	for (vx_uint32 y = 0; y < IMG_ROWS; y++)
	{
		for (vx_uint32 x = 0; x < IMG_COLS; x++)
		{
#pragma HLS PIPELINE II = 1

			// Read Input
			DataType data = input[y * IMG_COLS + x];

			// Compute sum
			sum += static_cast<vx_int64>(data);
		}
	}

	// Write back the mean value
	mean = static_cast<vx_float32>(sum) * reciprocal;
}

/***************************************************************************************************************************************************/
/** @brief Computes thestandard deviation of the pixels in the input image.
 * @param DataType       The data type of the input, which can be 8-bit/16-bit signed/unsigned
 * @param IMG_COLS       The amount of columns in the image
 * @param IMG_ROWS       The amount of rows in the image
 * @param input          The input image
 * @param mean           The input average pixel value.
 * @param stddev         The output standard deviation of the pixel values.
 * @param reciprocal     The reciprocal of the image pixel amount.
 */
template <typename DataType, vx_uint32 IMG_COLS, vx_uint32 IMG_ROWS>
void StdDev(vx_image_data<DataType, 1> input[IMG_ROWS * IMG_COLS], vx_float32 mean, vx_float32 &stddev, const vx_float32 reciprocal)
{
#pragma HLS INLINE

	// Variables
	vx_uint64 sum = 0;

	// Compute the sum for the standard deviation value (pipelined)
	for (vx_uint32 y = 0; y < IMG_ROWS; y++)
	{
		for (vx_uint32 x = 0; x < IMG_COLS; x++)
		{
#pragma HLS PIPELINE II = 1
			vx_image_data<DataType, 1> src;

			// Read Input
			src = input[y * IMG_COLS + x];
			DataType data = src.pixel[0];

			// Compute sum
			const vx_int32 sub = (vx_int32)mean - (vx_int32)data;
			sum += (vx_uint64)((vx_int64)sub * (vx_int64)sub);
		}
	}

	// Write back the standard deviation value
	stddev = sqrtf(static_cast<vx_float32>(sum) * reciprocal);
}

/***************************************************************************************************************************************************/
/** @brief Computes thestandard deviation of the pixels in the input image.
 * @param DataType       The data type of the input, which can be 8-bit/16-bit signed/unsigned
 * @param IMG_COLS       The amount of columns in the image
 * @param IMG_ROWS       The amount of rows in the image
 * @param input          The input image
 * @param mean           The input average pixel value.
 * @param stddev         The output standard deviation of the pixel values.
 * @param reciprocal     The reciprocal of the image pixel amount.
 */
template <typename DataType, vx_uint32 IMG_COLS, vx_uint32 IMG_ROWS>
void StdDev(DataType input[IMG_ROWS * IMG_COLS], vx_float32 mean, vx_float32 &stddev, const vx_float32 reciprocal)
{
#pragma HLS INLINE

	// Variables
	vx_uint64 sum = 0;

	// Compute the sum for the standard deviation value (pipelined)
	for (vx_uint32 y = 0; y < IMG_ROWS; y++)
	{
		for (vx_uint32 x = 0; x < IMG_COLS; x++)
		{
#pragma HLS PIPELINE II = 1

			// Read Input
			DataType data = input[y * IMG_COLS + x];

			// Compute sum
			const vx_int32 sub = (vx_int32)mean - (vx_int32)data;
			sum += (vx_uint64)((vx_int64)sub * (vx_int64)sub);
		}
	}

	// Write back the standard deviation value
	stddev = sqrtf(static_cast<vx_float32>(sum) * reciprocal);
}

/***************************************************************************************************************************************************/
/** @brief Computes the mean pixel value and the standard deviation of the pixels in the input image (which has a dimension width and height).
		   Use with or without all parameters marked as optional.
* @param DataType       The data type of the input, which can be 8-bit/16-bit signed/unsigned
* @param IMG_COLS       The amount of columns in the image
* @param IMG_ROWS       The amount of rows in the image
* @param COMPUTE_STDDEV Is true if standard deviation needs to be computed (If [optional] is set)
* @param input1         The input image (read 1. time)
* @param mean           The VX_TYPE_FLOAT32 average pixel value.
* @param input2         [optional] The input image (read 2. time)
* @param stddev         [optional] The VX_TYPE_FLOAT32 standard deviation of the pixel values.
*/
template <typename DataType, vx_uint16 IMG_COLS, vx_uint16 IMG_ROWS, vx_bool COMPUTE_STDDEV>
void MeanStdDev(
	vx_image_data<DataType, 1> input1[IMG_ROWS * IMG_COLS],
	vx_image_data<vx_float32, 1> mean[1],
	vx_image_data<DataType, 1> input2[IMG_ROWS * IMG_COLS],
	vx_image_data<vx_float32, 1> stddev[1])
{
#pragma HLS INLINE

	// Constants
	const vx_float32 reciprocal = 1.0f / (IMG_ROWS * IMG_COLS);

	// Check input
	const vx_type_e TYPE = GET_TYPE(DataType);
	const bool allowed_type = (TYPE == VX_TYPE_UINT8) || (TYPE == VX_TYPE_UINT16) || (TYPE == VX_TYPE_INT8) || (TYPE == VX_TYPE_INT16);
	STATIC_ASSERT(allowed_type, data_type_is_not_allowed_for_mean_stddev);

	// Local variables
	vx_float32 mean_t = 0, stddev_t = 0;
	vx_image_data<vx_float32, 1> mean_v;
	vx_image_data<vx_float32, 1> stddev_v;

	// Compute the mean
	Mean<DataType, IMG_COLS, IMG_ROWS>(input1, mean_t, reciprocal);

	// Store mean
	GenerateDmaSignal<vx_float32, 1>(true, true, mean_v);
	mean_v.pixel[0] = mean_t;
	*mean = mean_v;

	// Compute the standard deviation
	if (COMPUTE_STDDEV == true)
	{
		StdDev<DataType, IMG_COLS, IMG_ROWS>(input2, mean_t + 0.5f, stddev_t, reciprocal);

		// Store standard deviation
		GenerateDmaSignal<vx_float32, 1>(true, true, stddev_v);
		stddev_v.pixel[0] = stddev_t;
		*stddev = stddev_v;
	}
}

/***************************************************************************************************************************************************/
/** @brief Computes the mean pixel value and the standard deviation of the pixels in the input image (which has a dimension width and height).
		   Use with or without all parameters marked as optional.
* @param DataType       The data type of the input, which can be 8-bit/16-bit signed/unsigned
* @param IMG_COLS       The amount of columns in the image
* @param IMG_ROWS       The amount of rows in the image
* @param COMPUTE_STDDEV Is true if standard deviation needs to be computed (If [optional] is set)
* @param input1         The input image (read 1. time)
* @param mean           The VX_TYPE_FLOAT32 average pixel value.
* @param input2         [optional] The input image (read 2. time)
* @param stddev         [optional] The VX_TYPE_FLOAT32 standard deviation of the pixel values.
*/
template <typename DataType, vx_uint16 IMG_COLS, vx_uint16 IMG_ROWS, vx_bool COMPUTE_STDDEV>
void MeanStdDev(
	DataType input1[IMG_ROWS * IMG_COLS],
	vx_float32 mean[1],
	DataType input2[IMG_ROWS * IMG_COLS],
	vx_float32 stddev[1])
{
#pragma HLS INLINE

	// Constants
	const vx_float32 reciprocal = 1.0f / (IMG_ROWS * IMG_COLS);

	// Check input
	const vx_type_e TYPE = GET_TYPE(DataType);
	const bool allowed_type = (TYPE == VX_TYPE_UINT8) || (TYPE == VX_TYPE_UINT16) || (TYPE == VX_TYPE_INT8) || (TYPE == VX_TYPE_INT16);
	STATIC_ASSERT(allowed_type, data_type_is_not_allowed_for_mean_stddev);

	// Local variables
	vx_float32 mean_t = 0, stddev_t = 0;

	// Compute the mean
	Mean<DataType, IMG_COLS, IMG_ROWS>(input1, mean_t, reciprocal);

	// Store mean
	*mean = mean_t;

	// Compute the standard deviation
	if (COMPUTE_STDDEV == true)
	{
		StdDev<DataType, IMG_COLS, IMG_ROWS>(input2, mean_t + 0.5f, stddev_t, reciprocal);

		// Store standard deviation
		*stddev = stddev_t;
	}
}

/***************************************************************************************************************************************************/
// Update Min/max location
template <typename DataType, vx_uint16 CAPACITY, vx_bool COMPUTE_LOCATIONS>
void MinMaxUpdateLocation(vx_uint16 y, vx_uint16 x, DataType data, vx_uint16 min_loc_x_buffer[CAPACITY], vx_uint16 min_loc_y_buffer[CAPACITY],
						  vx_uint16 max_loc_x_buffer[CAPACITY], vx_uint16 max_loc_y_buffer[CAPACITY], DataType &min_value, DataType &max_value, vx_uint16 &min_counter,
						  vx_uint16 &max_counter)
{
#pragma HLS INLINE

	//
	if (COMPUTE_LOCATIONS == vx_true_e)
	{

		// Compute minimum/maximum value, locations and counter
		if (data < min_value)
		{
			min_value = data;
			min_loc_x_buffer[0] = x;
			min_loc_y_buffer[0] = y;
			min_counter = 1;
		}
		else if ((data == min_value) && (min_counter < CAPACITY))
		{
			min_loc_x_buffer[min_counter] = x;
			min_loc_y_buffer[min_counter] = y;
			min_counter++;
		}

		// Compute maximum value, locations and counter
		if (data > max_value)
		{
			max_value = data;
			max_loc_x_buffer[0] = x;
			max_loc_y_buffer[0] = y;
			max_counter = 1;
		}
		else if ((data == max_value) && (max_counter < CAPACITY))
		{
			max_loc_x_buffer[max_counter] = x;
			max_loc_y_buffer[max_counter] = y;
			max_counter++;
		}
	}
	else
	{
		min_value = MIN(data, min_value);
		max_value = MAX(data, max_value);
	}
}

/***************************************************************************************************************************************************/
/** @brief Finds the minimum and maximum values in an image and a location for each. If the input image has several minimums/maximums,
		   the kernel returns all of them. Use with or without all parameters marked as optional.
* @param DataType The data type of the input, which can be 8-bit/16-bit signed/unsigned
* @param IMG_COLS   The amount of columns in the image
* @param IMG_ROWS   The amount of rows in the image
* @param CAPACITY   [optional] The capacity of the arrays that store the locations (minLoc , max_loc)
* @param input      The input image
* @param min_val    The minimum value in the image, which corresponds to the type of the input.
* @param max_val    The maximum value in the image, which corresponds to the type of the input.
* @param min_loc    [optional] The minimum x, y locations. If the input image has several minimums,
							   the kernel will return up to the capacity of the array.
* @param max_loc    [optional] The maximum x, y locations. If the input image has several maximums,
							   the kernel will return up to the capacity of the array.
* @param min_count  [optional] The total number of detected minimums in image.
* @param max_count  [optional] The total number of detected maximums in image.
*/
template <typename DataType, vx_uint16 IMG_COLS, vx_uint16 IMG_ROWS, vx_uint16 CAPACITY, vx_bool COMPUTE_LOCATIONS>
void MinMaxLocation(
	vx_image_data<DataType, 1> input[IMG_ROWS * IMG_COLS],
	vx_image_data<DataType, 1> min_val[1],
	vx_image_data<DataType, 1> max_val[1],
	vx_image_data<vx_uint16, 2> min_loc[CAPACITY],
	vx_image_data<vx_uint16, 2> max_loc[CAPACITY],
	vx_image_data<vx_uint16, 1> min_count[1],
	vx_image_data<vx_uint16, 1> max_count[1])
{
#pragma HLS INLINE

	// Check input
	const vx_type_e TYPE = GET_TYPE(DataType);
	const bool allowed_type = (TYPE == VX_TYPE_UINT8) || (TYPE == VX_TYPE_UINT16) || (TYPE == VX_TYPE_INT8) || (TYPE == VX_TYPE_INT16);
	STATIC_ASSERT(allowed_type, data_type_is_not_allowed_for_min_max_location);

	// Variables and arrays
	vx_uint16 min_loc_x_buffer[CAPACITY];
	vx_uint16 min_loc_y_buffer[CAPACITY];
	vx_uint16 max_loc_x_buffer[CAPACITY];
	vx_uint16 max_loc_y_buffer[CAPACITY];

	DataType min_value = std::numeric_limits<DataType>::max();
	DataType max_value = std::numeric_limits<DataType>::min();
	vx_uint16 min_counter = 0;
	vx_uint16 max_counter = 0;

	// Computes the minimum and maximum values, including their counters and locations (pipelined)
	for (vx_uint16 y = 0; y < IMG_ROWS; y++)
	{
		for (vx_uint16 x = 0; x < IMG_COLS; x++)
		{
#pragma HLS PIPELINE II = 1
			vx_image_data<DataType, 1> src;

			// Read Input
			src = input[y * IMG_COLS + x];
			DataType data = src.pixel[0];

			// Update Min/max location
			MinMaxUpdateLocation<DataType, CAPACITY, COMPUTE_LOCATIONS>(y, x, data, min_loc_x_buffer, min_loc_y_buffer, max_loc_x_buffer,
																		max_loc_y_buffer, min_value, max_value, min_counter, max_counter);
		}
	}

	{
		// Write output
		vx_image_data<DataType, 1> dst1, dst2;
		GenerateDmaSignal<DataType, 1>(true, true, dst1);
		GenerateDmaSignal<DataType, 1>(true, true, dst2);
		dst1.pixel[0] = min_value;
		dst2.pixel[0] = max_value;
		*min_val = dst1; // TODO: put into previous loop
		*max_val = dst2; // TODO: put into previous loop
	}

	// Write optional output
	if (COMPUTE_LOCATIONS == vx_true_e)
	{

		// Get the maximum amount of elements between both location buffers
		const vx_uint16 max_elements = MIN(MAX(min_counter, max_counter), CAPACITY); // TODO: put as loop bound in next loop

		// Store max location information
		for (vx_uint16 i = 0; i < max_elements; i++)
		{
#pragma HLS PIPELINE II = 1
#pragma HLS loop_tripcount min = 1 max = CAPACITY
			vx_image_data<vx_uint16, 1> dst1, dst2;
			vx_image_data<vx_uint16, 2> dst3, dst4;

			if (i == 0)
			{
				GenerateDmaSignal<vx_uint16, 1>(true, true, dst1);
				GenerateDmaSignal<vx_uint16, 1>(true, true, dst2);
				dst1.pixel[0] = min_counter;
				dst2.pixel[0] = max_counter;
				*min_count = dst1;
				*max_count = dst2;
			}
			if (i < min_counter)
			{
				dst3.pixel[0] = min_loc_x_buffer[i];
				dst3.pixel[1] = min_loc_y_buffer[i];
				GenerateDmaSignal<vx_uint16, 2>((i == 0), (i == min_counter - 1), dst3);
				min_loc[i] = dst3;
			}
			if (i < max_counter)
			{
				dst4.pixel[0] = max_loc_x_buffer[i];
				dst4.pixel[1] = max_loc_y_buffer[i];
				GenerateDmaSignal<vx_uint16, 2>((i == 0), (i == max_counter - 1), dst4);
				max_loc[i] = dst4;
			}
		}
	}
}

/***************************************************************************************************************************************************/
/** @brief Finds the minimum and maximum values in an image and a location for each. If the input image has several minimums/maximums,
		   the kernel returns all of them. Use with or without all parameters marked as optional.
* @param DataType The data type of the input, which can be 8-bit/16-bit signed/unsigned
* @param IMG_COLS   The amount of columns in the image
* @param IMG_ROWS   The amount of rows in the image
* @param CAPACITY   [optional] The capacity of the arrays that store the locations (minLoc , max_loc)
* @param input      The input image
* @param min_val    The minimum value in the image, which corresponds to the type of the input.
* @param max_val    The maximum value in the image, which corresponds to the type of the input.
* @param min_loc    [optional] The minimum x, y locations. If the input image has several minimums,
							   the kernel will return up to the capacity of the array.
* @param max_loc    [optional] The maximum x, y locations. If the input image has several maximums,
							   the kernel will return up to the capacity of the array.
* @param min_count  [optional] The total number of detected minimums in image.
* @param max_count  [optional] The total number of detected maximums in image.
*/
template <typename DataType, vx_uint16 IMG_COLS, vx_uint16 IMG_ROWS, vx_uint16 CAPACITY, vx_bool COMPUTE_LOCATIONS>
void MinMaxLocation(
	DataType input[IMG_ROWS * IMG_COLS],
	DataType min_val[1],
	DataType max_val[1],
	vx_image_data<vx_uint16, 2> min_loc[CAPACITY],
	vx_image_data<vx_uint16, 2> max_loc[CAPACITY],
	vx_uint16 min_count[1],
	vx_uint16 max_count[1])
{
#pragma HLS INLINE

	// Check input
	const vx_type_e TYPE = GET_TYPE(DataType);
	const bool allowed_type = (TYPE == VX_TYPE_UINT8) || (TYPE == VX_TYPE_UINT16) || (TYPE == VX_TYPE_INT8) || (TYPE == VX_TYPE_INT16);
	STATIC_ASSERT(allowed_type, data_type_is_not_allowed_for_min_max_location);

	// Variables and arrays
	vx_uint16 min_loc_x_buffer[CAPACITY];
	vx_uint16 min_loc_y_buffer[CAPACITY];
	vx_uint16 max_loc_x_buffer[CAPACITY];
	vx_uint16 max_loc_y_buffer[CAPACITY];

	DataType min_value = ComputeMax<DataType>();
	DataType max_value = ComputeMin<DataType>();
	vx_uint16 min_counter = 0;
	vx_uint16 max_counter = 0;

	// Computes the minimum and maximum values, including their counters and locations (pipelined)
	for (vx_uint16 y = 0; y < IMG_ROWS; y++)
	{
		for (vx_uint16 x = 0; x < IMG_COLS; x++)
		{
#pragma HLS PIPELINE II = 1

			// Read Input
			DataType data = input[y * IMG_COLS + x];

			// Update Min/max location
			MinMaxUpdateLocation<DataType, CAPACITY, COMPUTE_LOCATIONS>(y, x, data, min_loc_x_buffer, min_loc_y_buffer, max_loc_x_buffer,
																		max_loc_y_buffer, min_value, max_value, min_counter, max_counter);
		}
	}

	// Write output
	*min_val = min_value; // TODO: put into previous loop
	*max_val = max_value; // TODO: put into previous loop

	// Write optional output
	if (COMPUTE_LOCATIONS == vx_true_e)
	{

		// Get the maximum amount of elements between both location buffers
		const vx_uint16 max_elements = MIN(MAX(min_counter, max_counter), CAPACITY); // TODO: put as loop bound in next loop

		// Store max location information
		for (vx_uint16 i = 0; i < max_elements; i++)
		{
#pragma HLS PIPELINE II = 1
#pragma HLS loop_tripcount min = 1 max = CAPACITY
			vx_image_data<vx_uint16, 2> dst3, dst4;

			if (i == 0)
			{
				*min_count = min_counter;
				*max_count = max_counter;
			}
			if (i < min_counter)
			{
				dst3.pixel[0] = min_loc_x_buffer[i];
				dst3.pixel[1] = min_loc_y_buffer[i];
				min_loc[i] = dst3;
			}
			if (i < max_counter)
			{
				dst4.pixel[0] = max_loc_x_buffer[i];
				dst4.pixel[1] = max_loc_y_buffer[i];
				max_loc[i] = dst4;
			}
		}
	}
}

/***************************************************************************************************************************************************/
/** @brief Implements the Table Lookup Image Kernel.
 * @param DataType   The data type can be vx_uint8 and vx_int16
 * @param IMG_PIXELS  The amount of pixels for input and output image
 * @param LUT_COUNT   Indicates the number of elements in the LUT.
 * @param LUT_OFFSET  Indicates the index of the input value = 0.
 * @param input       The input image (vx_uint8, vx_int16)
 * @param output      The output image (vx_uint8, vx_int16)
 */
template <typename DataType, const vx_uint32 IMG_PIXELS, const vx_uint32 LUT_COUNT, const vx_uint32 LUT_OFFSET>
void TableLookup(
	vx_image_data<DataType, 1> input[IMG_PIXELS],
	vx_image_data<DataType, 1> lut[LUT_COUNT],
	vx_image_data<DataType, 1> output[IMG_PIXELS])
{
#pragma HLS INLINE

	// Check Datatype
	const vx_type_e TYPE = GET_TYPE(DataType);
	const bool allowed_type = (TYPE == VX_TYPE_UINT8) || (TYPE == VX_TYPE_INT16);
	STATIC_ASSERT(allowed_type, data_type_is_not_allowed_for_histogram);

	// Buffer for lookup table
	DataType table[LUT_COUNT];

	// Read lookup table into buffer
	for (vx_uint32 i = 0; i < LUT_COUNT; i++)
	{
#pragma HLS PIPELINE II = 1
		vx_image_data<DataType, 1> src;
		src = lut[i];
		table[i] = src.pixel[0];
	}

	// Perform table lookup
	for (vx_uint32 i = 0; i < IMG_PIXELS; i++)
	{
#pragma HLS PIPELINE II = 1
		vx_image_data<DataType, 1> src;
		vx_image_data<DataType, 1> dst;

		// Read from Input
		src = input[i];
		DataType data = src.pixel[0];

		// Add Offset
		vx_int32 index = (vx_int32)data + (vx_int32)LUT_OFFSET;

		// Perform Table Lookup and write to output
		if ((index >= 0) && (index < (vx_int32)LUT_COUNT))
			dst.pixel[0] = table[index];
		else
			dst.pixel[0] = 0;

		// Set user(SOF) & last(EOF)
		GenerateDmaSignal<DataType, 1>((i == 0), (i == IMG_PIXELS - 1), dst);

		// Write output
		output[i] = dst;
	}
}

/***************************************************************************************************************************************************/
/** @brief Implements the Table Lookup Image Kernel.
 * @param DataType   The data type can be vx_uint8 and vx_int16
 * @param IMG_PIXELS  The amount of pixels for input and output image
 * @param LUT_COUNT   Indicates the number of elements in the LUT.
 * @param LUT_OFFSET  Indicates the index of the input value = 0.
 * @param input       The input image (vx_uint8, vx_int16)
 * @param output      The output image (vx_uint8, vx_int16)
 */
template <typename DataType, const vx_uint32 IMG_PIXELS, const vx_uint32 LUT_COUNT, const vx_uint32 LUT_OFFSET>
void TableLookup(
	DataType input[IMG_PIXELS],
	DataType lut[LUT_COUNT],
	DataType output[IMG_PIXELS])
{
#pragma HLS INLINE

	// Check Datatype
	const vx_type_e TYPE = GET_TYPE(DataType);
	const bool allowed_type = (TYPE == VX_TYPE_UINT8) || (TYPE == VX_TYPE_INT16);
	STATIC_ASSERT(allowed_type, data_type_is_not_allowed_for_histogram);

	// Buffer for lookup table
	DataType table[LUT_COUNT];

	// Read lookup table into buffer
	for (vx_uint32 i = 0; i < LUT_COUNT; i++)
	{
#pragma HLS PIPELINE II = 1
		table[i] = lut[i];
	}

	// Perform table lookup
	for (vx_uint32 i = 0; i < IMG_PIXELS; i++)
	{
#pragma HLS PIPELINE II = 1
		DataType result = 0;

		// Read from Input
		DataType data = input[i];

		// Add Offset
		vx_int32 index = (vx_int32)data + (vx_int32)LUT_OFFSET;

		// Perform Table Lookup and write to output
		if ((index >= 0) && (index < (vx_int32)LUT_COUNT))
			result = table[index];
		else
			result = 0;

		// Write output
		output[i] = result;
	}
}

/**
 * @file    main.cpp
 * @author  Lester Kalms <lester.kalms@tu-dresden.de>
 * @version 2.0
 *
 * @section LICENSE
 * GNU GPLv3:
 * You may copy, distribute and modify the software as long as you track
 * changes/dates in source files. Any modifications to or software
 * including (via compiler) GPL-licensed code must also be made available
 * under the GPL along with build & install instructions.
 *
 * @section DESCRIPTION
 * This is the main function for testing
 */

/***************************************************************************************************************************************************/
/* Pixelwise Function */
/***************************************************************************************************************************************************/

/** @brief Copy data from an input data object into another data object.
@param DataType        Data type of the image pixels
@param VEC_SIZE        Amount of pixels computed in parallel
@param IMG_PIXEL       Amount of pixels in the image
@param input1          Input image
@param output          Output image
*/
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL>
void ImgCopy(
	vx_image_data<DataType, VEC_SIZE> input1[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input1
#pragma HLS DATA_PACK variable = output
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::COPY_DATA, VX_CONVERT_POLICY_WRAP, VX_ROUND_POLICY_TO_ZERO, 0,
					  VX_THRESHOLD_TYPE_BINARY, 0, 0, 0, 0, 1>(input1, input1, output);
}
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL>
void ImgCopy(DataType input1[IMG_PIXEL / VEC_SIZE], DataType output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::COPY_DATA, VX_CONVERT_POLICY_WRAP, VX_ROUND_POLICY_TO_ZERO, 0,
					  VX_THRESHOLD_TYPE_BINARY, 0, 0, 0, 0, 1>(input1, input1, output);
}

/** @brief Performs a bitwise NOT operation on a input image.
@param DataType      Data type of the image pixels
@param VEC_SIZE        Amount of pixels computed in parallel
@param IMG_PIXEL       Amount of pixels in the image
@param input1          Input image
@param output          Output image
*/
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL>
void ImgNot(
	vx_image_data<DataType, VEC_SIZE> input1[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input1
#pragma HLS DATA_PACK variable = output
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::BITWISE_NOT, VX_CONVERT_POLICY_WRAP, VX_ROUND_POLICY_TO_ZERO, 0,
					  VX_THRESHOLD_TYPE_BINARY, 0, 0, 0, 0, 1>(input1, input1, output);
}
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL>
void ImgNot(DataType input1[IMG_PIXEL / VEC_SIZE], DataType output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::BITWISE_NOT, VX_CONVERT_POLICY_WRAP, VX_ROUND_POLICY_TO_ZERO, 0,
					  VX_THRESHOLD_TYPE_BINARY, 0, 0, 0, 0, 1>(input1, input1, output);
}

/** @brief Performs a bitwise AND operation between two images.
@param DataType      Data type of the image pixels
@param VEC_SIZE        Amount of pixels computed in parallel
@param IMG_PIXEL       Amount of pixels in the image
@param input1          Input image
@param input2          Input image
@param output          Output image
*/
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL>
void ImgAnd(
	vx_image_data<DataType, VEC_SIZE> input1[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> input2[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input1
#pragma HLS DATA_PACK variable = input2
#pragma HLS DATA_PACK variable = output
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::BITWISE_AND, VX_CONVERT_POLICY_WRAP, VX_ROUND_POLICY_TO_ZERO, 0,
					  VX_THRESHOLD_TYPE_BINARY, 0, 0, 0, 0, 1>(input1, input2, output);
}
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL>
void ImgAnd(DataType input1[IMG_PIXEL / VEC_SIZE], DataType input2[IMG_PIXEL / VEC_SIZE], DataType output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::BITWISE_AND, VX_CONVERT_POLICY_WRAP, VX_ROUND_POLICY_TO_ZERO, 0,
					  VX_THRESHOLD_TYPE_BINARY, 0, 0, 0, 0, 1>(input1, input2, output);
}

/** @brief Performs a bitwise INCLUSIVE OR operation between two images.
@param DataType      Data type of the image pixels
@param VEC_SIZE        Amount of pixels computed in parallel
@param IMG_PIXEL       Amount of pixels in the image
@param input1          Input image
@param input2          Input image
@param output          Output image
*/
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL>
void ImgOr(
	vx_image_data<DataType, VEC_SIZE> input1[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> input2[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input1
#pragma HLS DATA_PACK variable = input2
#pragma HLS DATA_PACK variable = output
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::BITWISE_OR, VX_CONVERT_POLICY_WRAP, VX_ROUND_POLICY_TO_ZERO, 0,
					  VX_THRESHOLD_TYPE_BINARY, 0, 0, 0, 0, 1>(input1, input2, output);
}
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL>
void ImgOr(DataType input1[IMG_PIXEL / VEC_SIZE], DataType input2[IMG_PIXEL / VEC_SIZE], DataType output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::BITWISE_OR, VX_CONVERT_POLICY_WRAP, VX_ROUND_POLICY_TO_ZERO, 0,
					  VX_THRESHOLD_TYPE_BINARY, 0, 0, 0, 0, 1>(input1, input2, output);
}

/** @brief Performs a bitwise EXCLUSIVE OR (XOR) operation between two images.
@param DataType      Data type of the image pixels
@param VEC_SIZE        Amount of pixels computed in parallel
@param IMG_PIXEL       Amount of pixels in the image
@param input1          Input image
@param input2          Input image
@param output          Output image
*/
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL>
void ImgXor(
	vx_image_data<DataType, VEC_SIZE> input1[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> input2[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input1
#pragma HLS DATA_PACK variable = input2
#pragma HLS DATA_PACK variable = output
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::BITWISE_XOR, VX_CONVERT_POLICY_WRAP, VX_ROUND_POLICY_TO_ZERO, 0,
					  VX_THRESHOLD_TYPE_BINARY, 0, 0, 0, 0, 1>(input1, input2, output);
}
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL>
void ImgXor(DataType input1[IMG_PIXEL / VEC_SIZE], DataType input2[IMG_PIXEL / VEC_SIZE], DataType output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::BITWISE_XOR, VX_CONVERT_POLICY_WRAP, VX_ROUND_POLICY_TO_ZERO, 0,
					  VX_THRESHOLD_TYPE_BINARY, 0, 0, 0, 0, 1>(input1, input2, output);
}

/** @brief Implements a pixel-wise maximum kernel.
@param DataType      Data type of the image pixels
@param VEC_SIZE        Amount of pixels computed in parallel
@param IMG_PIXEL       Amount of pixels in the image
@param input1          Input image
@param input2          Input image
@param output          Output image
*/
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL>
void ImgMax(
	vx_image_data<DataType, VEC_SIZE> input1[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> input2[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input1
#pragma HLS DATA_PACK variable = input2
#pragma HLS DATA_PACK variable = output
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::MAX, VX_CONVERT_POLICY_WRAP, VX_ROUND_POLICY_TO_ZERO, 0, VX_THRESHOLD_TYPE_BINARY, 0,
					  0, 0, 0, 1>(input1, input2, output);
}
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL>
void ImgMax(DataType input1[IMG_PIXEL / VEC_SIZE], DataType input2[IMG_PIXEL / VEC_SIZE], DataType output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::MAX, VX_CONVERT_POLICY_WRAP, VX_ROUND_POLICY_TO_ZERO, 0, VX_THRESHOLD_TYPE_BINARY, 0,
					  0, 0, 0, 1>(input1, input2, output);
}

/** @brief Implements a pixel-wise minimum kernel.
@param DataType      Data type of the image pixels
@param VEC_SIZE        Amount of pixels computed in parallel
@param IMG_PIXEL       Amount of pixels in the image
@param input1          Input image
@param input2          Input image
@param output          Output image
*/
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL>
void ImgMin(
	vx_image_data<DataType, VEC_SIZE> input1[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> input2[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input1
#pragma HLS DATA_PACK variable = input2
#pragma HLS DATA_PACK variable = output
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::MIN, VX_CONVERT_POLICY_WRAP, VX_ROUND_POLICY_TO_ZERO, 0, VX_THRESHOLD_TYPE_BINARY, 0,
					  0, 0, 0, 1>(input1, input2, output);
}
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL>
void ImgMin(DataType input1[IMG_PIXEL / VEC_SIZE], DataType input2[IMG_PIXEL / VEC_SIZE], DataType output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::MIN, VX_CONVERT_POLICY_WRAP, VX_ROUND_POLICY_TO_ZERO, 0, VX_THRESHOLD_TYPE_BINARY, 0,
					  0, 0, 0, 1>(input1, input2, output);
}

/** @brief Computes the absolute difference between two images.
@param DataType      Data type of the image pixels
@param VEC_SIZE        Amount of pixels computed in parallel
@param IMG_PIXEL       Amount of pixels in the image
@param CONV_POLICY     The round conversion <tt>\ref vx_convert_policy_e</tt>
@param input1          Input image
@param input2          Input image
@param output          Output image
*/
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL, vx_convert_policy_e CONV_POLICY>
void ImgAbsDiff(
	vx_image_data<DataType, VEC_SIZE> input1[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> input2[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input1
#pragma HLS DATA_PACK variable = input2
#pragma HLS DATA_PACK variable = output
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::ABSOLUTE_DIFFERENCE, CONV_POLICY, VX_ROUND_POLICY_TO_ZERO, 0,
					  VX_THRESHOLD_TYPE_BINARY, 0, 0, 0, 0, 1>(input1, input2, output);
}
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL, vx_convert_policy_e CONV_POLICY>
void ImgAbsDiff(DataType input1[IMG_PIXEL / VEC_SIZE], DataType input2[IMG_PIXEL / VEC_SIZE], DataType output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::ABSOLUTE_DIFFERENCE, CONV_POLICY, VX_ROUND_POLICY_TO_ZERO, 0,
					  VX_THRESHOLD_TYPE_BINARY, 0, 0, 0, 0, 1>(input1, input2, output);
}

/** @brief Performs addition between two images.
@param DataType      Data type of the image pixels
@param VEC_SIZE        Amount of pixels computed in parallel
@param IMG_PIXEL       Amount of pixels in the image
@param CONV_POLICY     The round conversion <tt>\ref vx_convert_policy_e</tt>
@param input1          Input image
@param input2          Input image
@param output          Output image
*/
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL, vx_convert_policy_e CONV_POLICY>
void ImgAdd(
	vx_image_data<DataType, VEC_SIZE> input1[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> input2[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input1
#pragma HLS DATA_PACK variable = input2
#pragma HLS DATA_PACK variable = output
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::ARITHMETIC_ADDITION, CONV_POLICY, VX_ROUND_POLICY_TO_ZERO, 0,
					  VX_THRESHOLD_TYPE_BINARY, 0, 0, 0, 0, 1>(input1, input2, output);
}
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL, vx_convert_policy_e CONV_POLICY>
void ImgAdd(DataType input1[IMG_PIXEL / VEC_SIZE], DataType input2[IMG_PIXEL / VEC_SIZE], DataType output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::ARITHMETIC_ADDITION, CONV_POLICY, VX_ROUND_POLICY_TO_ZERO, 0,
					  VX_THRESHOLD_TYPE_BINARY, 0, 0, 0, 0, 1>(input1, input2, output);
}

/** @brief Performs subtraction between two images.
@param DataType      Data type of the image pixels
@param VEC_SIZE        Amount of pixels computed in parallel
@param IMG_PIXEL       Amount of pixels in the image
@param CONV_POLICY     The round conversion <tt>\ref vx_convert_policy_e</tt>
@param input1          Input image
@param input2          Input image
@param output          Output image
*/
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL, vx_convert_policy_e CONV_POLICY>
void ImgSubtract(
	vx_image_data<DataType, VEC_SIZE> input1[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> input2[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input1
#pragma HLS DATA_PACK variable = input2
#pragma HLS DATA_PACK variable = output
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::ARITHMETIC_SUBTRACTION, CONV_POLICY, VX_ROUND_POLICY_TO_ZERO, 0,
					  VX_THRESHOLD_TYPE_BINARY, 0, 0, 0, 0, 1>(input1, input2, output);
}
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL, vx_convert_policy_e CONV_POLICY>
void ImgSubtract(DataType input1[IMG_PIXEL / VEC_SIZE], DataType input2[IMG_PIXEL / VEC_SIZE], DataType output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::ARITHMETIC_SUBTRACTION, CONV_POLICY, VX_ROUND_POLICY_TO_ZERO, 0,
					  VX_THRESHOLD_TYPE_BINARY, 0, 0, 0, 0, 1>(input1, input2, output);
}

/** @brief Implements the Gradient Magnitude Computation Kernel.
@param DataType      Data type of the image pixels
@param VEC_SIZE        Amount of pixels computed in parallel
@param IMG_PIXEL       Amount of pixels in the image
@param ROUND_POLICY    The round policy <tt>\ref vx_round_policy_e</tt>
@param input1          Input image
@param input2          Input image
@param output          Output image
*/
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL, vx_round_policy_e ROUND_POLICY>
void ImgMagnitude(
	vx_image_data<DataType, VEC_SIZE> input1[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> input2[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input1
#pragma HLS DATA_PACK variable = input2
#pragma HLS DATA_PACK variable = output
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::MAGNITUDE, VX_CONVERT_POLICY_SATURATE, ROUND_POLICY, 0, VX_THRESHOLD_TYPE_BINARY, 0,
					  0, 0, 0, 1>(input1, input2, output);
}
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL, vx_round_policy_e ROUND_POLICY>
void ImgMagnitude(DataType input1[IMG_PIXEL / VEC_SIZE], DataType input2[IMG_PIXEL / VEC_SIZE], DataType output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::MAGNITUDE, VX_CONVERT_POLICY_SATURATE, ROUND_POLICY, 0, VX_THRESHOLD_TYPE_BINARY, 0,
					  0, 0, 0, 1>(input1, input2, output);
}

/** @brief Performs element-wise multiplication between two images and a scalar value.
@param DataType        Data type of the image pixels
@param VEC_SIZE        Amount of pixels computed in parallel
@param IMG_PIXEL       Amount of pixels in the image
@param CONV_POLICY     The round conversion <tt>\ref vx_convert_policy_e</tt>
@param ROUND_POLICY    The round policy <tt>\ref vx_round_policy_e</tt>
@param SCALE           A number multiplied to each product before overflow handling.
@param input1          Input image
@param input2          Input image
@param output          Output image
*/
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL, vx_convert_policy_e CONV_POLICY, vx_round_policy_e ROUND_POLICY, vx_uint32 SCALE>
void ImgMultiply(
	vx_image_data<DataType, VEC_SIZE> input1[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> input2[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input1
#pragma HLS DATA_PACK variable = input2
#pragma HLS DATA_PACK variable = output
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::MULTIPLY, CONV_POLICY, ROUND_POLICY, SCALE, VX_THRESHOLD_TYPE_BINARY, 0, 0, 0, 0, 1>(input1, input2, output);
}
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL, vx_convert_policy_e CONV_POLICY, vx_round_policy_e ROUND_POLICY, vx_uint32 SCALE>
void ImgMultiply(DataType input1[IMG_PIXEL / VEC_SIZE], DataType input2[IMG_PIXEL / VEC_SIZE], DataType output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::MULTIPLY, CONV_POLICY, ROUND_POLICY, SCALE, VX_THRESHOLD_TYPE_BINARY, 0, 0, 0, 0, 1>(input1, input2, output);
}

/** @brief  Weighted average value from two input images to an output image.
@param DataType       Data type of the image pixels
@param VEC_SIZE       Amount of pixels computed in parallel
@param IMG_PIXEL      Amount of pixels in the image
@param ROUND_POLICY   The round policy <tt>\ref vx_round_policy_e</tt>
@param ALPHA          The weighted value in fixed-point between 0 and 1 using 16-bit fraction
@param input1         Input image
@param input2         Input image
@param output         Output image
*/
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL, vx_uint32 ALPHA, vx_round_policy_e ROUND_POLICY>
void ImgWeightedAverage(
	vx_image_data<DataType, VEC_SIZE> input1[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> input2[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input1
#pragma HLS DATA_PACK variable = input2
#pragma HLS DATA_PACK variable = output
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::WEIGHTED_AVERAGE, VX_CONVERT_POLICY_WRAP, ROUND_POLICY, 0, VX_THRESHOLD_TYPE_BINARY,
					  0, 0, 0, ALPHA, 1>(input1, input2, output);
}
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL, vx_uint32 ALPHA, vx_round_policy_e ROUND_POLICY>
void ImgWeightedAverage(DataType input1[IMG_PIXEL / VEC_SIZE], DataType input2[IMG_PIXEL / VEC_SIZE], DataType output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::WEIGHTED_AVERAGE, VX_CONVERT_POLICY_WRAP, ROUND_POLICY, 0, VX_THRESHOLD_TYPE_BINARY,
					  0, 0, 0, ALPHA, 1>(input1, input2, output);
}

/** @brief  Thresholds an input image and produces an output Boolean image.
@param DataType       Data type of the image pixels
@param VEC_SIZE       Amount of pixels computed in parallel
@param IMG_PIXEL      Amount of pixels in the image
@param THRESH_TYPE    The type of thresholding (VX_THRESHOLD_TYPE_BINARY, VX_THRESHOLD_TYPE_RANGE)
@param THRESH_VALUE   The threshold value if threshold type is VX_THRESHOLD_TYPE_BINARY
@param THRESH_UPPER   The upper threshold value if threshold type is VX_THRESHOLD_TYPE_RANGE
@param THRESH_LOWER   The lower threshold value if threshold type is VX_THRESHOLD_TYPE_RANGE
@param input1         Input image
@param input2         Input image
@param output         Output image
*/
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL, vx_threshold_type_e THRESH_TYPE, DataType THRESH_VALUE, DataType THRESH_UPPER,
		  DataType THRESH_LOWER>
void ImgThreshold(
	vx_image_data<DataType, VEC_SIZE> input1[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input1
#pragma HLS DATA_PACK variable = output
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::THRESHOLD, VX_CONVERT_POLICY_WRAP, VX_ROUND_POLICY_TO_ZERO, 0, THRESH_TYPE,
					  THRESH_VALUE, THRESH_UPPER, THRESH_LOWER, 0, 1>(input1, input1, output);
}
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL, vx_threshold_type_e THRESH_TYPE, DataType THRESH_VALUE, DataType THRESH_UPPER,
		  DataType THRESH_LOWER>
void ImgThreshold(DataType input1[IMG_PIXEL / VEC_SIZE], DataType output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::THRESHOLD, VX_CONVERT_POLICY_WRAP, VX_ROUND_POLICY_TO_ZERO, 0, THRESH_TYPE,
					  THRESH_VALUE, THRESH_UPPER, THRESH_LOWER, 0, 1>(input1, input1, output);
}

/** @brief  Computes the orientation of vector(x,y). East is 0. The values increase counter clock wise depending on the quantization.
@param DataType       Data type of the image pixels
@param VEC_SIZE       Amount of pixels computed in parallel
@param IMG_PIXEL      Amount of pixels in the image
@param QUANTIZATION   The quantisazion of the orientation values. Allowed values Q = [1..8]. 2^(Q) different output values
@param input_x        Input vectors in x direction
@param input_y        Input vectors in y direction
@param output         Output orientations
*/
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL, vx_uint8 QUANTIZATION>
void ImgPhase(
	vx_image_data<DataType, VEC_SIZE> input_x[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> input_y[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DataType, VEC_SIZE> output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input_x
#pragma HLS DATA_PACK variable = input_y
#pragma HLS DATA_PACK variable = output
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::PHASE, VX_CONVERT_POLICY_WRAP, VX_ROUND_POLICY_TO_ZERO, 1, VX_THRESHOLD_TYPE_BINARY,
					  1, 1, 1, 1, QUANTIZATION>(input_x, input_y, output);
}
template <typename DataType, vx_uint8 VEC_SIZE, vx_uint32 IMG_PIXEL, vx_uint8 QUANTIZATION>
void ImgPhase(DataType input_x[IMG_PIXEL / VEC_SIZE], DataType input_y[IMG_PIXEL / VEC_SIZE], DataType output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
	PixelwiseSameType<DataType, VEC_SIZE, IMG_PIXEL, HIFLIPVX::PHASE, VX_CONVERT_POLICY_WRAP, VX_ROUND_POLICY_TO_ZERO, 1, VX_THRESHOLD_TYPE_BINARY,
					  1, 1, 1, 1, QUANTIZATION>(input_x, input_y, output);
}

/***************************************************************************************************************************************************/
/* Filter Function Declaration */
/***************************************************************************************************************************************************/

/** @brief  Computes a Box filter over a window of the input image.
@param DataType    Data type of the input/output image (unsigned)(8-bit, 16-bit, 32-bit)
@param VEC_NUM     Amount of pixels computed in parallel (1, 2, 4, 8)
@param WIDTH       Image width
@param HEIGHT      Image height
@param KERN_SIZE   Kernel size (3, 5, 7, 9, 11)
@param BORDER_TYPE Type of border (Constant, Replicated or Undefined)
@param SEPARABLE   Is true, if separable filter should be used
@param input       Input image
@param output      Output image
*/
template <typename DataType, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE, vx_bool SEPARABLE>
void ImgBox(
	vx_image_data<DataType, VEC_NUM> input[(HEIGHT * WIDTH) / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> output[(HEIGHT * WIDTH) / VEC_NUM])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = output
	HwBox<DataType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE, SEPARABLE>(input, output);
}
template <typename DataType, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE, vx_bool SEPARABLE>
void ImgBox(
	DataType input[(HEIGHT * WIDTH) / VEC_NUM],
	DataType output[(HEIGHT * WIDTH) / VEC_NUM])
{
#pragma HLS INLINE
	HwBox<DataType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE, SEPARABLE>((vx_image_data<DataType,
																																	 VEC_NUM> *)input,
																													  (vx_image_data<DataType, VEC_NUM> *)output);
}

/** @brief  Convolves the input with the client supplied convolution matrix.
@param DataType    Data type of the input/output image (unsigned, signed)(8-bit, 16-bit, 32-bit)
@param VEC_NUM     Amount of pixels computed in parallel (1, 2, 4, 8)
@param WIDTH       Image width
@param HEIGHT      Image height
@param KERN_SIZE   Kernel size (3, 5, 7, 9, 11)
@param BORDER_TYPE Type of border (Constant, Replicated or Undefined)
@param input       Input image
@param output      Output image
@param conv        The custom convolution kernel
*/
template <typename DataType, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE>
void ImgConvolve(
	vx_image_data<DataType, VEC_NUM> input[(HEIGHT * WIDTH) / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> output[(HEIGHT * WIDTH) / VEC_NUM],
	const DataType conv[KERN_SIZE][KERN_SIZE])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = output
	HwConvolve<DataType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE>(input, output, conv);
}
template <typename DataType, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE>
void ImgConvolve(
	DataType input[(HEIGHT * WIDTH) / VEC_NUM],
	DataType output[(HEIGHT * WIDTH) / VEC_NUM],
	const DataType conv[KERN_SIZE][KERN_SIZE])
{
#pragma HLS INLINE
	HwConvolve<DataType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE>(
		(vx_image_data<DataType, VEC_NUM> *)input, (vx_image_data<DataType, VEC_NUM> *)output, conv);
}

/** @brief  Implements Dilation, which grows the white space in a Boolean image.
@param DataType    Data type of the input/output image (unsigned)(8-bit, 16-bit, 32-bit)
@param VEC_NUM     Amount of pixels computed in parallel (1, 2, 4, 8)
@param WIDTH       Image width
@param HEIGHT      Image height
@param KERN_SIZE   Kernel size (3, 5, 7, 9, 11)
@param BORDER_TYPE Type of border (Constant, Replicated or Undefined)
@param input       Input image
@param output      Output image
*/
template <typename DataType, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE>
void ImgDilate(
	vx_image_data<DataType, VEC_NUM> input[(HEIGHT * WIDTH) / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> output[(HEIGHT * WIDTH) / VEC_NUM])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = output
	HwDilate<DataType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE>(input, output);
}
template <typename DataType, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE>
void ImgDilate(
	DataType input[(HEIGHT * WIDTH) / VEC_NUM],
	DataType output[(HEIGHT * WIDTH) / VEC_NUM])
{
#pragma HLS INLINE
	HwDilate<DataType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE>(
		(vx_image_data<DataType, VEC_NUM> *)input, (vx_image_data<DataType, VEC_NUM> *)output);
}

/** @brief  Implements Erosion, which shrinks the white space in a Boolean image.
@param DataType    Data type of the input/output image (unsigned)(8-bit, 16-bit, 32-bit)
@param VEC_NUM     Amount of pixels computed in parallel (1, 2, 4, 8)
@param WIDTH       Image width
@param HEIGHT      Image height
@param KERN_SIZE   Kernel size (3, 5, 7, 9, 11)
@param BORDER_TYPE Type of border (Constant, Replicated or Undefined)
@param input       Input image
@param output      Output image
*/
template <typename DataType, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE>
void ImgErode(
	vx_image_data<DataType, VEC_NUM> input[(HEIGHT * WIDTH) / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> output[(HEIGHT * WIDTH) / VEC_NUM])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = output
	HwErode<DataType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE>(input, output);
}
template <typename DataType, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE>
void ImgErode(
	DataType input[(HEIGHT * WIDTH) / VEC_NUM],
	DataType output[(HEIGHT * WIDTH) / VEC_NUM])
{
#pragma HLS INLINE
	HwErode<DataType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE>(
		(vx_image_data<DataType, VEC_NUM> *)input, (vx_image_data<DataType, VEC_NUM> *)output);
}

/** @brief  Computes a Gaussian filter over a window of the input image.
@param DataType    Data type of the input/output image (unsigned)(8-bit, 16-bit, 32-bit)
@param VEC_NUM     Amount of pixels computed in parallel (1, 2, 4, 8)
@param WIDTH       Image width
@param HEIGHT      Image height
@param KERN_SIZE   Kernel size (3, 5, 7, 9, 11)
@param BORDER_TYPE Type of border (Constant, Replicated or Undefined)
@param SEPARABLE   Is true, if separable filter should be used
@param input       Input image
@param output      Output image
*/
template <typename DataType, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE, vx_bool SEPARABLE>
void ImgGaussian(
	vx_image_data<DataType, VEC_NUM> input[(HEIGHT * WIDTH) / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> output[(HEIGHT * WIDTH) / VEC_NUM])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = output
	HwGaussian<DataType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE, SEPARABLE>(input, output);
}
template <typename DataType, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE, vx_bool SEPARABLE>
void ImgGaussian(
	DataType input[(HEIGHT * WIDTH) / VEC_NUM],
	DataType output[(HEIGHT * WIDTH) / VEC_NUM])
{
#pragma HLS INLINE
	HwGaussian<DataType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE, SEPARABLE>(
		(vx_image_data<DataType, VEC_NUM> *)input, (vx_image_data<DataType, VEC_NUM> *)output);
}

/** @brief  Computes a median pixel value over a window of the input image.
@param DataType    Data type of the input/output image (unsigned)(8-bit, 16-bit, 32-bit)
@param VEC_NUM     Amount of pixels computed in parallel (1, 2, 4, 8)
@param WIDTH       Image width
@param HEIGHT      Image height
@param KERN_SIZE   Kernel size (3, 5, 7, 9, 11)
@param BORDER_TYPE Type of border (Constant, Replicated or Undefined)
@param input       Input image
@param output      Output image
*/
template <typename DataType, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE>
void ImgMedian(
	vx_image_data<DataType, VEC_NUM> input[(HEIGHT * WIDTH) / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> output[(HEIGHT * WIDTH) / VEC_NUM])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = output
	HwMedian<DataType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE>(input, output);
}
template <typename DataType, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE>
void ImgMedian(
	DataType input[(HEIGHT * WIDTH) / VEC_NUM],
	DataType output[(HEIGHT * WIDTH) / VEC_NUM])
{
#pragma HLS INLINE
	HwMedian<DataType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE>(
		(vx_image_data<DataType, VEC_NUM> *)input, (vx_image_data<DataType, VEC_NUM> *)output);
}

/** @brief  Implements the Scharr Image Filter Kernel.
@param SrcType     Data type of the input image (unsigned)(8-bit, 16-bit, 32-bit)
@param DstType     Data type of the output image (signed)(8-bit, 16-bit, 32-bit)
@param VEC_NUM     Amount of pixels computed in parallel (1, 2, 4, 8)
@param WIDTH       Image width
@param HEIGHT      Image height
@param BORDER_TYPE Type of border (Constant, Replicated or Undefined)
@param input       The input image
@param output1     The output image (x derivative)
@param output2     The output image (y derivative)
*/
template <typename SrcType, typename DstType, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_border_e BORDER_TYPE>
void ImgScharr3x3(
	vx_image_data<SrcType, VEC_NUM> input[(HEIGHT * WIDTH) / VEC_NUM],
	vx_image_data<DstType, VEC_NUM> output1[(HEIGHT * WIDTH) / VEC_NUM],
	vx_image_data<DstType, VEC_NUM> output2[(HEIGHT * WIDTH) / VEC_NUM])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = output1
#pragma HLS DATA_PACK variable = output2
	HwScharr3x3<SrcType, DstType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, BORDER_TYPE>(input, output1, output2);
}
template <typename SrcType, typename DstType, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_border_e BORDER_TYPE>
void ImgScharr3x3(
	SrcType input[(HEIGHT * WIDTH) / VEC_NUM],
	DstType output1[(HEIGHT * WIDTH) / VEC_NUM],
	DstType output2[(HEIGHT * WIDTH) / VEC_NUM])
{
#pragma HLS INLINE
	HwScharr3x3<SrcType, DstType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, BORDER_TYPE>(
		(vx_image_data<SrcType, VEC_NUM> *)input, (vx_image_data<DstType, VEC_NUM> *)output1, (vx_image_data<DstType, VEC_NUM> *)output2);
}

/** @brief  Implements the Sobel Image Filter Kernel.
@param SrcType     Data type of the input image (unsigned)(8-bit, 16-bit, 32-bit)
@param DstType     Data type of the output image (signed)(8-bit, 16-bit, 32-bit)
@param VEC_NUM     Amount of pixels computed in parallel (1, 2, 4, 8)
@param WIDTH       Image width
@param HEIGHT      Image height
@param KERN_SIZE   Kernel size (3, 5, 7, 9, 11)
@param BORDER_TYPE Type of border (Constant, Replicated or Undefined)
@param input       The input image
@param output1     The output image (x derivative)
@param output2     The output image (y derivative)
*/
template <typename SrcType, typename DstType, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE>
void ImgSobel(
	vx_image_data<SrcType, VEC_NUM> input[(HEIGHT * WIDTH) / VEC_NUM],
	vx_image_data<DstType, VEC_NUM> output1[(HEIGHT * WIDTH) / VEC_NUM],
	vx_image_data<DstType, VEC_NUM> output2[(HEIGHT * WIDTH) / VEC_NUM])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = output1
#pragma HLS DATA_PACK variable = output2
	HwSobel<SrcType, DstType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE>(input, output1, output2);
}
template <typename SrcType, typename DstType, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE>
void ImgSobel(
	SrcType input[(HEIGHT * WIDTH) / VEC_NUM],
	DstType output1[(HEIGHT * WIDTH) / VEC_NUM],
	DstType output2[(HEIGHT * WIDTH) / VEC_NUM])
{
#pragma HLS INLINE
	HwSobel<SrcType, DstType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE>(
		(vx_image_data<SrcType, VEC_NUM> *)input, (vx_image_data<DstType, VEC_NUM> *)output1, (vx_image_data<DstType, VEC_NUM> *)output2);
}

/** @brief  Find local maxima in an image, or otherwise suppress pixels that are not local maxima.
@param DataType    Data type of the input/output image (unsigned, signed)(8-bit, 16-bit, 32-bit)
@param VEC_NUM     Amount of pixels computed in parallel (1, 2, 4, 8)
@param WIDTH       Image width
@param HEIGHT      Image height
@param KERN_SIZE   The size of window over which to perform the localized non-maxima suppression (3, 5, 7, 9, 11)
@param BORDER_TYPE Type of border (Constant, Replicated or Undefined)
@param input       Input image
@param output      Output image
@param mask        Constrict suppression to a ROI.
*/
template <typename DataType, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE>
void ImgNonMaxSuppression(
	vx_image_data<DataType, VEC_NUM> input[(HEIGHT * WIDTH) / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> output[(HEIGHT * WIDTH) / VEC_NUM],
	const vx_uint8 mask[KERN_SIZE][KERN_SIZE])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = output
	HwNonMaxSuppression<DataType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE>(input, output, mask);
}
template <typename DataType, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE>
void ImgNonMaxSuppression(
	DataType input[(HEIGHT * WIDTH) / VEC_NUM],
	DataType output[(HEIGHT * WIDTH) / VEC_NUM],
	const vx_uint8 mask[KERN_SIZE][KERN_SIZE])
{
#pragma HLS INLINE
	HwNonMaxSuppression<DataType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE>(
		(vx_image_data<DataType, VEC_NUM> *)input, (vx_image_data<DataType, VEC_NUM> *)output, mask);
}

/** @brief  Computes an image of response values according to the FAST9 corner detector
@param DataType    Data type of the input/output image (unsigned, signed)(8-bit, 16-bit, 32-bit)
@param VEC_NUM     Amount of pixels computed in parallel (1, 2, 4, 8)
@param WIDTH       Image width
@param HEIGHT      Image height
@param BORDER_TYPE Type of border (Constant, Replicated or Undefined)
@param input       Input image
@param output      Output image
*/
template <typename DataType, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_border_e BORDER_TYPE>
void ImgSegmentTestDetector(
	vx_image_data<DataType, VEC_NUM> input[(HEIGHT * WIDTH) / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> output[(HEIGHT * WIDTH) / VEC_NUM])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = output
	HwSegmentTestDetector<DataType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, BORDER_TYPE>(input, output);
}
template <typename DataType, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_border_e BORDER_TYPE>
void ImgSegmentTestDetector(
	DataType input[(HEIGHT * WIDTH) / VEC_NUM],
	DataType output[(HEIGHT * WIDTH) / VEC_NUM])
{
#pragma HLS INLINE
	HwSegmentTestDetector<DataType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, BORDER_TYPE>(
		(vx_image_data<DataType, VEC_NUM> *)input, (vx_image_data<DataType, VEC_NUM> *)output);
}

/** @brief  Observed pixel (n) is true if it is bigger than THRESH_UPPER or if it is bigger THRESH_LOWER and
			the other pixel in window is bigger than THRESH_UPPER
@param DataType     Data type of the input/output image (unsigned, signed)(8-bit, 16-bit, 32-bit)
@param VEC_NUM      Amount of pixels computed in parallel (1, 2, 4, 8)
@param WIDTH        Image width
@param HEIGHT       Image height
@param KERN_SIZE    The size of window over which to perform the localized non-maxima suppression (3, 5, 7, 9, 11)
@param BORDER_TYPE  Type of border (Constant, Replicated or Undefined)
@param THRESH_LOWER Upper threshold
@param THRESH_UPPER Lower threshold
@param input        Input image
@param output       Output image
*/
template <typename DataType, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE, DataType THRESH_LOWER,
		  DataType THRESH_UPPER>
void ImgHysteresis(
	vx_image_data<DataType, VEC_NUM> input[(HEIGHT * WIDTH) / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> output[(HEIGHT * WIDTH) / VEC_NUM])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = output
	HwHysteresis<DataType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE, THRESH_LOWER, THRESH_UPPER>(input, output);
}
template <typename DataType, vx_uint8 VEC_NUM, vx_uint16 WIDTH, vx_uint16 HEIGHT, vx_uint8 KERN_SIZE, vx_border_e BORDER_TYPE, DataType THRESH_LOWER,
		  DataType THRESH_UPPER>
void ImgHysteresis(
	DataType input[(HEIGHT * WIDTH) / VEC_NUM],
	DataType output[(HEIGHT * WIDTH) / VEC_NUM])
{
#pragma HLS INLINE
	HwHysteresis<DataType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, KERN_SIZE, BORDER_TYPE, THRESH_LOWER, THRESH_UPPER>(
		(vx_image_data<DataType, VEC_NUM> *)input, (vx_image_data<DataType, VEC_NUM> *)output);
}

/** @brief  Find local maxima in an image depending on the phase, or otherwise suppress pixels that are not local maxima.
@param DataType     Data type of the input/output image (unsigned, signed)(8-bit, 16-bit, 32-bit)
@param VEC_NUM      Amount of pixels computed in parallel (1, 2, 4, 8)
@param WIDTH        Image width
@param HEIGHT       Image height
@param BORDER_TYPE  Type of border (Constant, Replicated or Undefined)
@param QUANTIZATION The quantisazion of the orientation values. Allowed values Q = [1..8]. 2^(Q) different output values
@param input1       Input image (Gradient Magnitude)
@param input2       Input image (Orientation)
@param output       Output image
*/
template <typename DataType, vx_uint32 VEC_NUM, vx_uint32 WIDTH, vx_uint32 HEIGHT, vx_border_e BORDER_TYPE, vx_uint32 QUANTIZATION>
void ImgOrientedNonMaxSuppression(
	vx_image_data<DataType, VEC_NUM> input1[(HEIGHT * WIDTH) / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> input2[(HEIGHT * WIDTH) / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> output[(HEIGHT * WIDTH) / VEC_NUM])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input1
#pragma HLS DATA_PACK variable = input2
#pragma HLS DATA_PACK variable = output
	HwOrientedNonMaxSuppression<DataType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, BORDER_TYPE, QUANTIZATION>(
		input1, input2, output);
}
template <typename DataType, vx_uint32 VEC_NUM, vx_uint32 WIDTH, vx_uint32 HEIGHT, vx_border_e BORDER_TYPE, vx_uint32 QUANTIZATION>
void ImgOrientedNonMaxSuppression(
	DataType input1[(HEIGHT * WIDTH) / VEC_NUM],
	DataType input2[(HEIGHT * WIDTH) / VEC_NUM],
	DataType output[(HEIGHT * WIDTH) / VEC_NUM])
{
#pragma HLS INLINE
	HwOrientedNonMaxSuppression<DataType, VECTOR_PIXELS(HEIGHT, WIDTH, VEC_NUM), VEC_NUM, WIDTH, HEIGHT, BORDER_TYPE, QUANTIZATION>(
		(vx_image_data<DataType, VEC_NUM> *)input1, (vx_image_data<DataType, VEC_NUM> *)input2, (vx_image_data<DataType, VEC_NUM> *)output);
}

/** These features allow for conditional graph flow in OpenVX, via support for a variety of operations between two scalars.
 * @param SrcType           The data type of the input scalars
 * @param DstType           The data type of the output scalar
 * @param scalar_operation  The scalar operation enum
 * @param a                 First scalar operand
 * @param b                 Second scalar operand
 * @param output            Result of the scalar operation
 */
template <typename SrcType, typename DstType, vx_scalar_operation_e scalar_operation>
void ImgControlFlow(vx_image_data<SrcType, 1> a[1], vx_image_data<SrcType, 1> b[1], vx_image_data<DstType, 1> output[1])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = a
#pragma HLS DATA_PACK variable = b
#pragma HLS DATA_PACK variable = output
	ControlFlow<SrcType, DstType, scalar_operation>(a, b, output);
}
template <typename SrcType, typename DstType, vx_scalar_operation_e scalar_operation>
void ImgControlFlow(SrcType a[1], SrcType b[1], DstType output[1])
{
#pragma HLS INLINE
	ControlFlow<SrcType, DstType, scalar_operation>((vx_image_data<SrcType, 1> *)a, (vx_image_data<SrcType, 1> *)b, (vx_image_data<DstType, 1> *)output);
}

/** @brief   Equalizes the histogram of a grayscale image. The output image dimensions should be the same as the dimensions of the input image.
*   @details This kernel uses Histogram Equalization to modify the values of a grayscale image so that it will automatically have a standardized
			 brightness and contrast.
* @param IMG_PIXELS The amount of pixels for input and output image
* @param input1     The grayscale input image in vx_uint8 (1. read)
* @param input2     The grayscale input image in vx_uint8 (2. read)
* @param output     The grayscale output image of type vx_uint8 with equalized brightness and contrast and same size as the input image.
*/
template <vx_uint32 IMG_PIXELS>
void ImgEqualizeHist(
	vx_image_data<vx_uint8, 1> input1[IMG_PIXELS],
	vx_image_data<vx_uint8, 1> input2[IMG_PIXELS],
	vx_image_data<vx_uint32, 1> output[IMG_PIXELS])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input1
#pragma HLS DATA_PACK variable = input2
#pragma HLS DATA_PACK variable = output
	EqualizeHist<IMG_PIXELS>(input1, input2, output);
}
template <vx_uint32 IMG_PIXELS>
void ImgEqualizeHist(vx_uint8 input1[IMG_PIXELS], vx_uint8 input2[IMG_PIXELS], vx_uint32 output[IMG_PIXELS])
{
#pragma HLS INLINE
	EqualizeHist<IMG_PIXELS>(input1, input2, output);
}

/** @brief  Generates a distribution from an image.
 *   @details This kernel counts the number of occurrences of each pixel value within the window size of a pre-calculated number of bins.
 * @param SrcType              The Input Type can be vx_uint8 and vx_uint16
 * @param IMG_PIXELS           The amount of pixels for input and output image
 * @param DISTRIBUTION_BINS    Indicates the number of bins.
 * @param DISTRIBUTION_RANG    Indicates the total number of the consecutive values of the distribution interval.
 * @param DISTRIBUTION_OFFSET  Indicates the start of the values to use (inclusive).
 * @param input                The input image (vx_uint8, vx_uint16)
 * @param output               The output image (vx_uint32)
 */
template <typename SrcType, vx_uint32 IMG_PIXELS, vx_uint32 DISTRIBUTION_BINS, vx_uint32 DISTRIBUTION_RANG, SrcType DISTRIBUTION_OFFSET>
void ImgHistogram(
	vx_image_data<SrcType, 1> input[IMG_PIXELS],
	vx_image_data<vx_uint32, 1> output[IMG_PIXELS])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = output
	Histogram<SrcType, IMG_PIXELS, DISTRIBUTION_BINS, DISTRIBUTION_RANG, DISTRIBUTION_OFFSET>(input, output);
}
template <typename SrcType, vx_uint32 IMG_PIXELS, vx_uint32 DISTRIBUTION_BINS, vx_uint32 DISTRIBUTION_RANG, SrcType DISTRIBUTION_OFFSET>
void ImgHistogram(SrcType input[IMG_PIXELS], vx_uint32 output[IMG_PIXELS])
{
#pragma HLS INLINE
	Histogram<SrcType, IMG_PIXELS, DISTRIBUTION_BINS, DISTRIBUTION_RANG, DISTRIBUTION_OFFSET>(input, output);
}

/** @brief  Computes the integral image of the input. The output image dimensions should be the same as the dimensions of the input image.
*   @details Each output pixel is the sum of the corresponding input pixel and all other pixels above and to the left of it.
			 The overflow policy used is VX_CONVERT_POLICY_WRAP.
* @param IMG_COLS    The columns of the image
* @param IMG_ROWS    The rows of the image
* @param input       The input image
* @param output      The output image
*/
template <vx_uint16 IMG_COLS, vx_uint16 IMG_ROWS>
void ImgIntegral(
	vx_image_data<vx_uint8, 1> input[IMG_COLS * IMG_ROWS],
	vx_image_data<vx_uint32, 1> output[IMG_COLS * IMG_ROWS])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = output
	Integral<IMG_COLS, IMG_ROWS>(input, output);
}
template <vx_uint16 IMG_COLS, vx_uint16 IMG_ROWS>
void ImgIntegral(vx_uint8 input[IMG_ROWS * IMG_COLS], vx_uint32 output[IMG_ROWS * IMG_COLS])
{
#pragma HLS INLINE
	Integral<IMG_COLS, IMG_ROWS>(input, output);
}

/** @brief Computes the mean pixel value and the standard deviation of the pixels in the input image (which has a dimension width and height).
		   Use with or without all parameters marked as optional.
* @param DataType   The data type of the input, which can be 8-bit/16-bit signed/unsigned
* @param IMG_COLS   The amount of columns in the image
* @param IMG_ROWS   The amount of rows in the image
* @param input1     The input image (read 1. time)
* @param mean       The VX_TYPE_FLOAT32 average pixel value.
* @param input2     [optional] The input image (read 2. time)
* @param stddev     [optional] The VX_TYPE_FLOAT32 standard deviation of the pixel values. (a small aproximation made here)
*/
template <typename DataType, vx_uint32 IMG_COLS, vx_uint32 IMG_ROWS>
void ImgMeanStdDev(
	vx_image_data<DataType, 1> input1[IMG_ROWS * IMG_COLS],
	vx_image_data<vx_float32, 1> mean[1],
	vx_image_data<DataType, 1> input2[IMG_ROWS * IMG_COLS],
	vx_image_data<vx_float32, 1> stddev[1])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input1
#pragma HLS DATA_PACK variable = mean
#pragma HLS DATA_PACK variable = input2
#pragma HLS DATA_PACK variable = stddev
	MeanStdDev<DataType, IMG_COLS, IMG_ROWS, vx_true_e>(input1, mean, input2, stddev);
}
template <typename DataType, vx_uint32 IMG_COLS, vx_uint32 IMG_ROWS>
void ImgMeanStdDev(DataType input1[IMG_ROWS * IMG_COLS], vx_float32 mean[1], DataType input2[IMG_ROWS * IMG_COLS], vx_float32 stddev[1])
{
#pragma HLS INLINE
	MeanStdDev<DataType, IMG_COLS, IMG_ROWS, vx_true_e>(input1, mean, input2, stddev);
}
template <typename DataType, vx_uint32 IMG_COLS, vx_uint32 IMG_ROWS>
void ImgMeanStdDev(
	vx_image_data<DataType, 1> input1[IMG_ROWS * IMG_COLS],
	vx_image_data<vx_float32, 1> mean[1])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input1
#pragma HLS DATA_PACK variable = mean
	MeanStdDev<DataType, IMG_COLS, IMG_ROWS, vx_false_e>(input1, mean, NULL, NULL);
}
template <typename DataType, vx_uint32 IMG_COLS, vx_uint32 IMG_ROWS>
void ImgMeanStdDev(DataType input1[IMG_ROWS * IMG_COLS], vx_float32 mean[1])
{
#pragma HLS INLINE
	MeanStdDev<DataType, IMG_COLS, IMG_ROWS, vx_false_e>(input1, mean, NULL, NULL);
}

/** @brief Finds the minimum and maximum values in an image and a location for each. If the input image has several minimums/maximums,
		   the kernel returns all of them. Use with or without all parameters marked as optional.
* @param DataType The data type of the input, which can be 8-bit/16-bit signed/unsigned
* @param IMG_COLS   The amount of columns in the image
* @param IMG_ROWS   The amount of rows in the image
* @param CAPACITY   [optional] The capacity of the arrays that store the locations (minLoc , max_loc)
* @param input      The input image
* @param min_val    The minimum value in the image, which corresponds to the type of the input.
* @param max_val    The maximum value in the image, which corresponds to the type of the input.
* @param min_loc    [optional] The minimum VX_TYPE_COORDINATES2D locations. If the input image has several minimums,
							   the kernel will return up to the capacity of the array.
* @param max_loc    [optional] The maximum VX_TYPE_COORDINATES2D locations. If the input image has several maximums,
							   the kernel will return up to the capacity of the array.
* @param min_count  [optional] The total number of detected minimums in image.
* @param max_count  [optional] The total number of detected maximums in image.
*/
template <typename DataType, vx_uint32 IMG_COLS, vx_uint32 IMG_ROWS, vx_uint16 CAPACITY>
void ImgMinMaxLocation(
	vx_image_data<DataType, 1> input[IMG_ROWS * IMG_COLS],
	vx_image_data<DataType, 1> min_val[1],
	vx_image_data<DataType, 1> max_val[1],
	vx_image_data<vx_uint16, 2> min_loc[CAPACITY],
	vx_image_data<vx_uint16, 2> max_loc[CAPACITY],
	vx_image_data<vx_uint16, 1> min_count[1],
	vx_image_data<vx_uint16, 1> max_count[1])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = min_val
#pragma HLS DATA_PACK variable = max_val
#pragma HLS DATA_PACK variable = min_loc
#pragma HLS DATA_PACK variable = max_loc
#pragma HLS DATA_PACK variable = min_count
#pragma HLS DATA_PACK variable = max_count
	MinMaxLocation<DataType, IMG_COLS, IMG_ROWS, CAPACITY, vx_true_e>(input, min_val, max_val, min_loc, max_loc, min_count, max_count);
}
template <typename DataType, vx_uint32 IMG_COLS, vx_uint32 IMG_ROWS, vx_uint16 CAPACITY>
void ImgMinMaxLocation(
	DataType input[IMG_ROWS * IMG_COLS],
	DataType min_val[1],
	DataType max_val[1],
	vx_image_data<vx_uint16, 2> min_loc[CAPACITY],
	vx_image_data<vx_uint16, 2> max_loc[CAPACITY],
	vx_uint16 min_count[1],
	vx_uint16 max_count[1])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = min_loc
#pragma HLS DATA_PACK variable = max_loc
	MinMaxLocation<DataType, IMG_COLS, IMG_ROWS, CAPACITY, vx_true_e>(input, min_val, max_val, min_loc, max_loc, min_count, max_count);
}
template <typename DataType, vx_uint32 IMG_COLS, vx_uint32 IMG_ROWS>
void ImgMinMaxLocation(
	vx_image_data<DataType, 1> input[IMG_ROWS * IMG_COLS],
	vx_image_data<DataType, 1> min_val[1],
	vx_image_data<DataType, 1> max_val[1])
{
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = min_val
#pragma HLS DATA_PACK variable = max_val
#pragma HLS INLINE
	MinMaxLocation<DataType, IMG_COLS, IMG_ROWS, (vx_uint16)1, vx_false_e>(input, min_val, max_val, NULL, NULL, NULL, NULL);
}
template <typename DataType, vx_uint32 IMG_COLS, vx_uint32 IMG_ROWS>
void ImgMinMaxLocation(DataType input[IMG_ROWS * IMG_COLS], DataType min_val[1], DataType max_val[1])
{
#pragma HLS INLINE
	MinMaxLocation<DataType, IMG_COLS, IMG_ROWS, (vx_uint16)1, vx_false_e>(input, min_val, max_val, NULL, NULL, NULL, NULL);
}

/** @brief  Implements the Table Lookup Image Kernel. The output image dimensions should be the same as the dimensions of the input image.
*   @details This kernel uses each pixel in an image to index into a LUT and put the indexed LUT value into the output image.
			 The formats supported are vx_uint8 and vx_int16.
* @param DataType   The data type can be vx_uint8 and vx_int16
* @param IMG_PIXELS  The amount of pixels for input and output image
* @param LUT_COUNT   Indicates the number of elements in the LUT.
* @param LUT_OFFSET  Indicates the index of the input value = 0.
* @param input       The input image (vx_uint8, vx_int16)
* @param output      The output image (vx_uint8, vx_int16)
*/
template <typename DataType, const vx_uint32 IMG_PIXELS, const vx_uint32 LUT_COUNT, const vx_uint32 LUT_OFFSET>
void ImgTableLookup(
	vx_image_data<DataType, 1> input[IMG_PIXELS],
	vx_image_data<DataType, 1> lut[LUT_COUNT],
	vx_image_data<DataType, 1> output[IMG_PIXELS])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = lut
#pragma HLS DATA_PACK variable = output
	TableLookup<DataType, IMG_PIXELS, LUT_COUNT, LUT_OFFSET>(input, lut, output);
}
template <typename DataType, const vx_uint32 IMG_PIXELS, const vx_uint32 LUT_COUNT, const vx_uint32 LUT_OFFSET>
void ImgTableLookup(DataType input[IMG_PIXELS], DataType lut[LUT_COUNT], DataType output[IMG_PIXELS])
{
#pragma HLS INLINE
	TableLookup<DataType, IMG_PIXELS, LUT_COUNT, LUT_OFFSET>(input, lut, output);
}

/** @brief  Implements the Channel Combine Kernel.
 * @param DstType     The datatype of the > image  (vx_uint16 (U16), vx_uint32 (U32, RGB, RGBX))
 * @param CHANNEL_AMOUNT The amount of channels to combine
 * @param SRC_PIXELS  The pixels of the input image
 * @param DST_PIXELS  The pixels of the output image (can differ for RGB, since the 24-bit are interleaved)
 * @param OUTPUT_TYPE    The color type of the > image (VX_DF_IMAGE_U16, VX_DF_IMAGE_U32, VX_DF_IMAGE_RGB, VX_DF_IMAGE_RGBX)
 * @param input0         The 1. plane of the input image
 * @param input1         The 2. plane of the input image
 * @param input2         The 3. plane of the input image (optional)
 * @param input3         The 4. plane of the input image (optional)
 * @param output         The output image
 */
template <typename DstType, vx_uint16 CHANNEL_AMOUNT, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS, vx_df_image_e OUTPUT_TYPE>
void ImgChannelCombine(
	vx_image_data<vx_uint8, 1> input0[SRC_PIXELS],
	vx_image_data<vx_uint8, 1> input1[SRC_PIXELS],
	vx_image_data<vx_uint8, 1> input2[SRC_PIXELS],
	vx_image_data<vx_uint8, 1> input3[SRC_PIXELS],
	vx_image_data<DstType, 1> output[DST_PIXELS])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input0
#pragma HLS DATA_PACK variable = input1
#pragma HLS DATA_PACK variable = input2
#pragma HLS DATA_PACK variable = input3
#pragma HLS DATA_PACK variable = output
	ChannelCombine<DstType, CHANNEL_AMOUNT, SRC_PIXELS, DST_PIXELS, OUTPUT_TYPE>(input0, input1, input2, input3, output);
}
template <typename DstType, vx_uint16 CHANNEL_AMOUNT, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS, vx_df_image_e OUTPUT_TYPE>
void ImgChannelCombine(vx_uint8 input0[SRC_PIXELS], vx_uint8 input1[SRC_PIXELS], vx_uint8 input2[SRC_PIXELS], vx_uint8 input3[SRC_PIXELS],
					   DstType output[DST_PIXELS])
{
#pragma HLS INLINE
	ChannelCombine<DstType, CHANNEL_AMOUNT, SRC_PIXELS, DST_PIXELS, OUTPUT_TYPE>(input0, input1, input2, input3, output);
}

/** @brief  Implements the Channel Extraction Kernel. \n
 * @param SrcType   The datatype of the input image  (vx_uint16 (U16), vx_uint32 (U32, RGB, RGBX))
 * @param CHANNEL_ID  The id of the channel to extract
 * @param SRC_PIXELS  The pixels of the input image
 * @param DST_PIXELS  The pixels of the output image (can differ for RGB, since the 24-bit are interleaved)
 * @param INPUT_TYPE  The color type of the input image (VX_DF_IMAGE_U16, VX_DF_IMAGE_U32, VX_DF_IMAGE_RGB, VX_DF_IMAGE_RGBX)
 * @param input       The input image
 * @param output      The output image
 */
template <typename SrcType, const vx_uint16 CHANNEL_ID, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS, vx_df_image_e INPUT_TYPE>
void ImgChannelExtract(
	vx_image_data<SrcType, 1> input[SRC_PIXELS],
	vx_image_data<vx_uint8, 1> output[DST_PIXELS])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = output
	ChannelExtract<SrcType, CHANNEL_ID, SRC_PIXELS, DST_PIXELS, INPUT_TYPE>(input, output);
}
template <typename SrcType, const vx_uint16 CHANNEL_ID, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS, vx_df_image_e INPUT_TYPE>
void ImgChannelExtract(SrcType input[SRC_PIXELS], vx_uint8 output[DST_PIXELS])
{
#pragma HLS INLINE
	ChannelExtract<SrcType, CHANNEL_ID, SRC_PIXELS, DST_PIXELS, INPUT_TYPE>(input, output);
}

/** @brief  Converts the Color of an image between RGB/RGBX/Gray \n
 *   @details Possible Conversions are \n
 * VX_DF_IMAGE_U8   -> VX_DF_IMAGE_RGB \n
 * VX_DF_IMAGE_U8   -> VX_DF_IMAGE_RGBX \n
 * VX_DF_IMAGE_RGB  -> VX_DF_IMAGE_U8 \n
 * VX_DF_IMAGE_RGB  -> VX_DF_IMAGE_RGBX \n
 * VX_DF_IMAGE_RGBX -> VX_DF_IMAGE_U8 \n
 * VX_DF_IMAGE_RGBX -> VX_DF_IMAGE_RGB \n
 * @param SrcType      The datatype of the input image  (uint8 (Gray), uint32 (RGB, RGBX))
 * @param DstType     The datatype of the output image (uint8 (Gray), uint32 (RGB, RGBX))
 * @param IMG_PIXELS  The pixels of the image
 * @param INPUT_TYPE  The color type of the input image (RGB, RGBX, Gray)
 * @param OUTPUT_TYPE The color type of the output image (RGB, RGBX, Gray)
 * @param input       The input image
 * @param output      The output image
 */
template <typename SrcType, typename DstType, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS, vx_df_image_e INPUT_TYPE, vx_df_image_e OUTPUT_TYPE>
void ImgConvertColor(
	vx_image_data<SrcType, 1> input[SRC_PIXELS],
	vx_image_data<DstType, 1> output[DST_PIXELS])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = output
	ConvertColor<SrcType, DstType, SRC_PIXELS, DST_PIXELS, INPUT_TYPE, OUTPUT_TYPE>(input, output);
}
template <typename SrcType, typename DstType, vx_uint32 SRC_PIXELS, vx_uint32 DST_PIXELS, vx_df_image_e INPUT_TYPE, vx_df_image_e OUTPUT_TYPE>
void ImgConvertColor(SrcType input[SRC_PIXELS], DstType output[DST_PIXELS])
{
#pragma HLS INLINE
	ConvertColor<SrcType, DstType, SRC_PIXELS, DST_PIXELS, INPUT_TYPE, OUTPUT_TYPE>(input, output);
}

/** @brief Converts image bit depth. The output image dimensions should be the same as the dimensions of the input image. \n
 *   @details (d = down | u = up | s = sign) \n
 * type|u8 |s8 |u16|s16|u32|s32
 * ----|---|---|---|---|---|---
 * u8	| -	| s	| u	| u	| u	| u
 * s8	| s	| -	| u	| u	| u	| u
 * u16	| d	| d	| -	| s	| u	| u
 * s16	| d	| d	| s	| -	| u	| u
 * u32	| d	| d	| d	| d	| -	| s
 * s32	| d	| d	| d	| d	| s	| -
 * @param SrcType       The datatype of the input image (8, 16, 32 bit unsigned/signed)
 * @param DstType      The datatype of the output image (8, 16, 32 bit unsigned/signed)
 * @param VEC_SIZE     The vector size
 * @param IMG_PIXEL    The amount of image pixels
 * @param CONV_POLICY  The conversion policy for overflow (VX_CONVERT_POLICY_WRAP or VX_CONVERT_POLICY_SATURATE)
 * @param SHIFT        Bits are shifted by this amount (e.g. up for u8->s16, down for s16->u8),  maximum shift is abs(inBitDepth - outBitDepth)
 * @param input        The input image
 * @param output       The output image
 */
template <typename SrcType, typename DstType, const vx_uint8 VEC_SIZE, const vx_uint32 IMG_PIXEL, const vx_convert_policy_e CONV_POLICY,
		  const vx_uint16 SHIFT>
void ImgConvertBitDepth(
	vx_image_data<SrcType, VEC_SIZE> input[IMG_PIXEL / VEC_SIZE],
	vx_image_data<DstType, VEC_SIZE> output[IMG_PIXEL / VEC_SIZE])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = output
	ConvertBitDepth<SrcType, DstType, VEC_SIZE, IMG_PIXEL, CONV_POLICY, SHIFT>(input, output);
}
template <typename SrcType, typename DstType, const vx_uint8 VEC_SIZE, const vx_uint32 IMG_PIXEL, const vx_convert_policy_e CONV_POLICY,
		  const vx_uint16 SHIFT>
void ImgConvertBitDepth(SrcType input[IMG_PIXEL], DstType output[IMG_PIXEL])
{
#pragma HLS INLINE
	ConvertBitDepth<SrcType, DstType, VEC_SIZE, IMG_PIXEL, CONV_POLICY, SHIFT>(input, output);
}

/** Converts converts between two buffers with a different vector sizes (parallelization degree). If needed: bigger image needs to be aligned.
 * @param DataType     The data type of the input and output
 * @param IMAGES       The amount of images
 * @param SRC_PIXELS   Amount of pixels in the input image
 * @param DST_PIXELS   Amount of pixels in the output image
 * @param SRC_PARALLEL The vector size of input image
 * @param DST_PARALLEL The vector size of output image
 * @param src          input image
 * @param dst          output image
 */
template <typename DataType, vx_int64 IMAGES, vx_int64 SRC_PIXELS, vx_int64 DST_PIXELS, vx_int64 SRC_PARALLEL, vx_int64 DST_PARALLEL>
void ImgDataWidthConverter(
	vx_image_data<DataType, SRC_PARALLEL> input[(IMAGES * SRC_PIXELS) / SRC_PARALLEL],
	vx_image_data<DataType, DST_PARALLEL> output[(IMAGES * DST_PIXELS) / DST_PARALLEL])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = output
	DataWidthConverter<DataType, IMAGES, SRC_PIXELS, DST_PIXELS, SRC_PARALLEL, DST_PARALLEL>(input, output);
}
template <typename DataType, vx_int64 IMAGES, vx_int64 SRC_PIXELS, vx_int64 DST_PIXELS, vx_int64 SRC_PARALLEL, vx_int64 DST_PARALLEL>
void ImgDataWidthConverter(
	DataType input[(IMAGES * SRC_PIXELS) / SRC_PARALLEL],
	vx_image_data<DataType, DST_PARALLEL> output[(IMAGES * DST_PIXELS) / DST_PARALLEL])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = output
	DataWidthConverter<DataType, IMAGES, SRC_PIXELS, DST_PIXELS, SRC_PARALLEL, DST_PARALLEL>((vx_image_data<DataType, SRC_PARALLEL> *)input, output);
}
template <typename DataType, vx_int64 IMAGES, vx_int64 SRC_PIXELS, vx_int64 DST_PIXELS, vx_int64 SRC_PARALLEL, vx_int64 DST_PARALLEL>
void ImgDataWidthConverter(
	vx_image_data<DataType, SRC_PARALLEL> input[(IMAGES * SRC_PIXELS) / SRC_PARALLEL],
	DataType output[(IMAGES * DST_PIXELS) / DST_PARALLEL])
{
#pragma HLS INLINE
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
	DataWidthConverter<DataType, IMAGES, SRC_PIXELS, DST_PIXELS, SRC_PARALLEL, DST_PARALLEL>(input, (vx_image_data<DataType, DST_PARALLEL> *)output);
}

/** Copies the input image to multiple output images
 * @param DataType   The data type of the input and output
 * @param IMG_PIXELS The amount of images
 * @param VEC_NUM    Amount of pixels in the input image
 * @param input        input image
 * @param out1        output image
 * @param out2        output image
 * @param out3        output image
 * @param out4        output image
 */
template <typename DataType, vx_uint32 IMG_PIXELS, vx_uint8 VEC_NUM>
void ImgMulticast(
	vx_image_data<DataType, VEC_NUM> input[IMG_PIXELS / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> out1[IMG_PIXELS / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> out2[IMG_PIXELS / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> out3[IMG_PIXELS / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> out4[IMG_PIXELS / VEC_NUM])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = out1
#pragma HLS DATA_PACK variable = out2
#pragma HLS DATA_PACK variable = out3
#pragma HLS DATA_PACK variable = out4
	Multicast<DataType, IMG_PIXELS, VEC_NUM, 4>(input, out1, out2, out3, out4);
}
template <typename DataType, vx_uint32 IMG_PIXELS, vx_uint8 VEC_NUM>
void ImgMulticast(
	DataType input[IMG_PIXELS],
	DataType out1[IMG_PIXELS],
	DataType out2[IMG_PIXELS],
	DataType out3[IMG_PIXELS],
	DataType out4[IMG_PIXELS])
{
#pragma HLS INLINE
	Multicast<DataType, IMG_PIXELS, VEC_NUM, 4>(input, out1, out2, out3, out4);
}

/** Copies the input image to multiple output images
 * @param DataType   The data type of the input and output
 * @param IMG_PIXELS The amount of images
 * @param VEC_NUM    Amount of pixels in the input image
 * @param input        input image
 * @param out1        output image
 * @param out2        output image
 * @param out3        output image
 */
template <typename DataType, vx_uint32 IMG_PIXELS, vx_uint8 VEC_NUM>
void ImgMulticast(
	vx_image_data<DataType, VEC_NUM> input[IMG_PIXELS / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> out1[IMG_PIXELS / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> out2[IMG_PIXELS / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> out3[IMG_PIXELS / VEC_NUM])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = out1
#pragma HLS DATA_PACK variable = out2
#pragma HLS DATA_PACK variable = out3
	Multicast<DataType, IMG_PIXELS, VEC_NUM, 3>(input, out1, out2, out3, NULL);
}
template <typename DataType, vx_uint32 IMG_PIXELS, vx_uint8 VEC_NUM>
void ImgMulticast(
	DataType input[IMG_PIXELS / VEC_NUM],
	DataType out1[IMG_PIXELS / VEC_NUM],
	DataType out2[IMG_PIXELS / VEC_NUM],
	DataType out3[IMG_PIXELS / VEC_NUM])
{
#pragma HLS INLINE
	Multicast<DataType, IMG_PIXELS, VEC_NUM, 3>(input, out1, out2, out3, NULL);
}

/** Copies the input image to multiple output images
 * @param DataType   The data type of the input and output
 * @param IMG_PIXELS The amount of images
 * @param VEC_NUM    Amount of pixels in the input image
 * @param input        input image
 * @param out1        output image
 * @param out2        output image
 */
template <typename DataType, vx_uint32 IMG_PIXELS, vx_uint8 VEC_NUM>
void ImgMulticast(
	vx_image_data<DataType, VEC_NUM> input[IMG_PIXELS / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> out1[IMG_PIXELS / VEC_NUM],
	vx_image_data<DataType, VEC_NUM> out2[IMG_PIXELS / VEC_NUM])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = out1
#pragma HLS DATA_PACK variable = out2
	Multicast<DataType, IMG_PIXELS, VEC_NUM, 2>(input, out1, out2, NULL, NULL);
}
template <typename DataType, vx_uint32 IMG_PIXELS, vx_uint8 VEC_NUM>
void ImgMulticast(
	DataType input[IMG_PIXELS / VEC_NUM],
	DataType out1[IMG_PIXELS / VEC_NUM],
	DataType out2[IMG_PIXELS / VEC_NUM])
{
#pragma HLS INLINE
	Multicast<DataType, IMG_PIXELS, VEC_NUM, 2>(input, out1, out2, NULL, NULL);
}

/** @brief  Scale an image down using bilinear or nearest neighbor interpolation
 * @param COLS_IN     The columns of the input image
 * @param ROWS_IN     The rows of the input image
 * @param COLS_OUT    The columns of the output image
 * @param ROWS_OUT    The rows of the output image
 * @param SCALE_TYPE  The type of interpolation (VX_INTERPOLATION_BILINEAR or VX_INTERPOLATION_AREA)
 * @param input       The input image
 * @param output      The output image
 */
template <vx_uint16 COLS_IN, vx_uint16 ROWS_IN, vx_uint16 COLS_OUT, vx_uint16 ROWS_OUT, vx_interpolation_type_e SCALE_TYPE>
void ImgScaleImage(vx_image_data<vx_uint8, 1> input[COLS_IN * ROWS_IN], vx_image_data<vx_uint8, 1> output[COLS_OUT * ROWS_OUT])
{
#pragma HLS INLINE
#pragma HLS DATA_PACK variable = input
#pragma HLS DATA_PACK variable = output
	ScaleImage<COLS_IN, ROWS_IN, COLS_OUT, ROWS_OUT, SCALE_TYPE>(input, output);
}
template <vx_uint16 COLS_IN, vx_uint16 ROWS_IN, vx_uint16 COLS_OUT, vx_uint16 ROWS_OUT, vx_interpolation_type_e SCALE_TYPE>
void ImgScaleImage(vx_uint8 input[COLS_IN * ROWS_IN], vx_uint8 output[COLS_OUT * ROWS_OUT])
{
#pragma HLS INLINE
	ScaleImage<COLS_IN, ROWS_IN, COLS_OUT, ROWS_OUT, SCALE_TYPE>((vx_image_data<vx_uint8, 1> *)input, (vx_image_data<vx_uint8, 1> *)output);
}

#ifndef __XILINX__

/***************************************************************************************************************************************************/
/* Test Functions Headers */
/***************************************************************************************************************************************************/

template <typename Type, const vx_uint16 WIDTH, const vx_uint16 HEIGHT, const vx_uint16 KERN_SIZE, const vx_border_e BORDER_TYPE>
void SwBox(Type *input, Type *output);
template <typename Type, const vx_uint16 WIDTH, const vx_uint16 HEIGHT, const vx_uint16 KERN_SIZE, const vx_border_e BORDER_TYPE>
void SwConvolve(Type *input, Type *output, const Type imageKernel[KERN_SIZE][KERN_SIZE]);
template <typename Type, const vx_uint16 WIDTH, const vx_uint16 HEIGHT, const vx_uint16 KERN_SIZE, const vx_border_e BORDER_TYPE>
void SwDilate(Type *input, Type *output);
template <typename Type, const vx_uint16 WIDTH, const vx_uint16 HEIGHT, const vx_uint16 KERN_SIZE, const vx_border_e BORDER_TYPE>
void SwErode(Type *input, Type *output);
template <typename Type, const vx_uint16 WIDTH, const vx_uint16 HEIGHT, const vx_uint16 KERN_SIZE, const vx_border_e BORDER_TYPE>
void SwGaussian(Type *input, Type *output);
template <typename Type, const vx_uint16 WIDTH, const vx_uint16 HEIGHT, const vx_uint16 KERN_SIZE, const vx_border_e BORDER_TYPE>
void SwMedian(Type *input, Type *output);
template <typename InType, typename OutType, const vx_uint16 WIDTH, const vx_uint16 HEIGHT, const vx_border_e BORDER_TYPE>
void SwScharr3x3(InType *input, OutType *outputX, OutType *outputY);
template <typename InType, typename OutType, const vx_uint16 WIDTH, const vx_uint16 HEIGHT, const vx_uint16 KERN_SIZE, const vx_border_e BORDER_TYPE>
void SwSobel(InType *input, OutType *output_x, OutType *output_y);
template <typename Type, const vx_int32 WIDTH, const vx_int32 HEIGHT, const vx_int32 KERN_SIZE, const vx_border_e BORDER_TYPE>
void SwNonMaximaSuppression(Type *src, Type *dst);
template <typename Type, const vx_uint16 WIDTH, const vx_uint16 HEIGHT, const vx_border_e BORDER_TYPE>
void SwSegmentTestDetector(Type *src, Type *dst);
template <typename Type, const vx_uint16 WIDTH, const vx_uint16 HEIGHT, const vx_uint16 KERN_SIZE, const vx_border_e BORDER_TYPE, Type THRESH_LOWER,
		  Type THRESH_UPPER>
void SwHysteresis(Type *src, Type *dst);

template <typename TypeUint, typename TypeInt, vx_uint8 VEC_NUM, vx_uint16 COLS_FHD, vx_uint16 ROWS_FHD, vx_uint16 FILTER_SIZE,
		  vx_border_e BORDER_TYPE, TypeUint THRESH_LOWER, TypeUint THRESH_UPPER>
void SwFilters(TypeUint convolve_kernel[FILTER_SIZE][FILTER_SIZE], TypeUint *input, TypeUint *output_sw, TypeUint *output_hw, TypeInt *output_sw_x,
			   TypeInt *output_sw_y, TypeInt *output_hw_x, TypeInt *output_hw_y);

/***************************************************************************************************************************************************/
/** @brief SW: Computes the maximum absolute error between two images
 */
template <typename Type, const vx_uint32 IMG_COLS, const vx_uint32 IMG_ROWS, const vx_uint32 BORDER_RADIUS>
void CheckError(Type *output_sw, Type *output_hw)
{

	float absDifMax = 0;

	for (vx_uint32 y = BORDER_RADIUS; y < IMG_ROWS - BORDER_RADIUS; y++)
	{
		for (vx_uint32 x = BORDER_RADIUS; x < IMG_COLS - BORDER_RADIUS; x++)
		{
			vx_uint32 ptr = y * IMG_COLS + x;
			float A = static_cast<float>(output_sw[ptr]);
			float B = static_cast<float>(output_hw[ptr]);
			float absDif = ABS(A - B);
			absDifMax = MAX(absDifMax, absDif);

			if (absDif > 4)
			{
				printf("%4d%4d:\t %f\t%f\t%f\n", y, x, A, B, absDif);
				// getchar();
			}
		}
	}
	printf("Max. absolut error: %0.2f\n", absDifMax);
}

/***************************************************************************************************************************************************/
/* SW Test Main Function */
/***************************************************************************************************************************************************/

/*! \brief Test all filter functions */
void TestFilterMain(void)
{

	/******** Constants to test the functions ********************************************************************/

	// Test parameters
	const vx_uint16 COLS_FHD = 640;
	const vx_uint16 ROWS_FHD = 480;
	const vx_uint16 FILTER_SIZE = 5; // 3, 5, 7, 9, 11
	const vx_uint8 VEC_NUM = 2;
	typedef vx_uint8 imgUintT;
	typedef vx_int8 imgIntT;

	const imgUintT THRESH_LOWER = 20;
	const imgUintT THRESH_UPPER = 40;

	//
	const vx_uint32 PIXELS_FHD = COLS_FHD * ROWS_FHD;

	// Convolution kernel for the HwConvolve filter
	imgUintT convolve_kernel[FILTER_SIZE][FILTER_SIZE];
	for (vx_uint16 i = 0; i < FILTER_SIZE; i++)
	{
		for (vx_uint16 j = 0; j < FILTER_SIZE; j++)
		{
			convolve_kernel[i][j] = static_cast<imgUintT>(rand() % 256);
		}
	}

	/******** Allocate memory ***********************************************************************/

	imgUintT *input = new imgUintT[PIXELS_FHD];
	imgUintT *output_sw = new imgUintT[PIXELS_FHD];
	imgUintT *output_hw = new imgUintT[PIXELS_FHD];
	imgIntT *output_sw_x = new imgIntT[PIXELS_FHD];
	imgIntT *output_sw_y = new imgIntT[PIXELS_FHD];
	imgIntT *output_hw_x = new imgIntT[PIXELS_FHD];
	imgIntT *output_hw_y = new imgIntT[PIXELS_FHD];

	/******** Read or create image ******************************************************************/

	for (vx_uint32 i = 0; i < PIXELS_FHD; i++)
		input[i] = rand() % 256;

		/******** Test accelerated functions ************************************************************/
#if !defined(__LAST__) && !defined(__LAST__)
	printf("___________________________________________________________\n");
	printf("Border Type: VX_BORDER_UNDEFINED:\n");
	SwFilters<imgUintT, imgIntT, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_SIZE, VX_BORDER_UNDEFINED, THRESH_LOWER, THRESH_UPPER>(convolve_kernel, input,
																															output_sw, output_hw, output_sw_x, output_sw_y, output_hw_x, output_hw_y);

	printf("___________________________________________________________\n");
	printf("Border Type: VX_BORDER_CONSTANT:\n");
	SwFilters<imgUintT, imgIntT, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_SIZE, VX_BORDER_CONSTANT, THRESH_LOWER, THRESH_UPPER>(convolve_kernel, input,
																														   output_sw, output_hw, output_sw_x, output_sw_y, output_hw_x, output_hw_y);

	printf("___________________________________________________________\n");
	printf("Border Type: VX_BORDER_REPLICATE:\n");
	SwFilters<imgUintT, imgIntT, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_SIZE, VX_BORDER_REPLICATE, THRESH_LOWER, THRESH_UPPER>(convolve_kernel, input,
																															output_sw, output_hw, output_sw_x, output_sw_y, output_hw_x, output_hw_y);
#endif

	/******** Free memory ***************************************************************************/

	// Free Memory
	delete[] input;
	delete[] output_sw;
	delete[] output_hw;
	delete[] output_sw_x;
	delete[] output_sw_y;
	delete[] output_hw_x;
	delete[] output_hw_y;
}

/***************************************************************************************************************************************************/
/* SW Test Functions */
/***************************************************************************************************************************************************/

/*! \brief Test all filter functions */
template <typename TypeUint, typename TypeInt, vx_uint8 VEC_NUM, vx_uint16 COLS_FHD, vx_uint16 ROWS_FHD, vx_uint16 FILTER_SIZE,
		  vx_border_e BORDER_TYPE, TypeUint THRESH_LOWER, TypeUint THRESH_UPPER>
void SwFilters(TypeUint convolve_kernel[FILTER_SIZE][FILTER_SIZE], TypeUint *input, TypeUint *output_sw, TypeUint *output_hw, TypeInt *output_sw_x,
			   TypeInt *output_sw_y, TypeInt *output_hw_x, TypeInt *output_hw_y)
{

	const vx_uint32 BORDER_RADIUS = (BORDER_TYPE == VX_BORDER_UNDEFINED) ? (FILTER_SIZE / 2) : (0);
	const vx_uint32 BORDER_RADIUS_FAST = (BORDER_TYPE == VX_BORDER_UNDEFINED) ? (7 / 2) : (0);

	std::string name01 = "Box Filter:            ";
	std::string name02 = "Box Filter (sep):      ";
	std::string name03 = "Convolve Filter:       ";
	std::string name04 = "Erode Filter:          ";
	std::string name05 = "Dilate Filter:         ";
	std::string name06 = "Gaussian Filter:       ";
	std::string name07 = "Gaussian Filter (sep): ";
	std::string name08 = "Median Filter:         ";
	std::string name09 = "Scharr3x3 Filter:      ";
	std::string name10 = "                       ";
	std::string name11 = "Sobel Filter:          ";
	std::string name12 = "                       ";
	std::string name13 = "Non-max Suppression:   ";
	std::string name14 = "Segment Test Detector: ";
	std::string name15 = "Hysteresis:            ";

	// Non-max Suppression Mask
	TypeUint nms_mask[FILTER_SIZE][FILTER_SIZE];
	for (vx_int32 i = 0; i < FILTER_SIZE; ++i)
	{
		for (vx_int32 j = 0; j < FILTER_SIZE; ++j)
		{
			nms_mask[i][j] = 0;
		}
	}

	SwBox<TypeUint, COLS_FHD, ROWS_FHD, FILTER_SIZE, BORDER_TYPE>(input, output_sw);
	ImgBox<TypeUint, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_SIZE, BORDER_TYPE, vx_false_e>((vx_image_data<TypeUint, VEC_NUM> *)input,
																						(vx_image_data<TypeUint, VEC_NUM> *)output_hw);
	std::cout << name01.c_str();
	CheckError<TypeUint, COLS_FHD, ROWS_FHD, BORDER_RADIUS>(output_sw, output_hw);
	ImgBox<TypeUint, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_SIZE, BORDER_TYPE, vx_true_e>((vx_image_data<TypeUint, VEC_NUM> *)input,
																					   (vx_image_data<TypeUint, VEC_NUM> *)output_hw);
	std::cout << name02.c_str();
	CheckError<TypeUint, COLS_FHD, ROWS_FHD, BORDER_RADIUS>(output_sw, output_hw);

	SwConvolve<TypeUint, COLS_FHD, ROWS_FHD, FILTER_SIZE, BORDER_TYPE>(input, output_sw, convolve_kernel);
	ImgConvolve<TypeUint, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_SIZE, BORDER_TYPE>((vx_image_data<TypeUint, VEC_NUM> *)input,
																				 (vx_image_data<TypeUint, VEC_NUM> *)output_hw, convolve_kernel);
	std::cout << name03.c_str();
	CheckError<TypeUint, COLS_FHD, ROWS_FHD, BORDER_RADIUS>(output_sw, output_hw);

	SwErode<TypeUint, COLS_FHD, ROWS_FHD, FILTER_SIZE, BORDER_TYPE>(input, output_sw);
	ImgErode<TypeUint, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_SIZE, BORDER_TYPE>((vx_image_data<TypeUint, VEC_NUM> *)input,
																			  (vx_image_data<TypeUint, VEC_NUM> *)output_hw);
	std::cout << name04.c_str();
	CheckError<TypeUint, COLS_FHD, ROWS_FHD, BORDER_RADIUS>(output_sw, output_hw);

	SwDilate<TypeUint, COLS_FHD, ROWS_FHD, FILTER_SIZE, BORDER_TYPE>(input, output_sw);
	ImgDilate<TypeUint, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_SIZE, BORDER_TYPE>((vx_image_data<TypeUint, VEC_NUM> *)input,
																			   (vx_image_data<TypeUint, VEC_NUM> *)output_hw);
	std::cout << name05.c_str();
	CheckError<TypeUint, COLS_FHD, ROWS_FHD, BORDER_RADIUS>(output_sw, output_hw);

	std::cout << name06.c_str();
	SwGaussian<TypeUint, COLS_FHD, ROWS_FHD, FILTER_SIZE, BORDER_TYPE>(input, output_sw);
	ImgGaussian<TypeUint, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_SIZE, BORDER_TYPE, vx_false_e>((vx_image_data<TypeUint, VEC_NUM> *)input,
																							 (vx_image_data<TypeUint, VEC_NUM> *)output_hw);
	CheckError<TypeUint, COLS_FHD, ROWS_FHD, BORDER_RADIUS>(output_sw, output_hw);
	ImgGaussian<TypeUint, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_SIZE, BORDER_TYPE, vx_true_e>((vx_image_data<TypeUint, VEC_NUM> *)input,
																							(vx_image_data<TypeUint, VEC_NUM> *)output_hw);
	std::cout << name07.c_str();
	CheckError<TypeUint, COLS_FHD, ROWS_FHD, BORDER_RADIUS>(output_sw, output_hw);

	SwMedian<TypeUint, COLS_FHD, ROWS_FHD, FILTER_SIZE, BORDER_TYPE>(input, output_sw);
	ImgMedian<TypeUint, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_SIZE, BORDER_TYPE>((vx_image_data<TypeUint, VEC_NUM> *)input,
																			   (vx_image_data<TypeUint, VEC_NUM> *)output_hw);
	std::cout << name08.c_str();
	CheckError<TypeUint, COLS_FHD, ROWS_FHD, BORDER_RADIUS>(output_sw, output_hw);

	SwScharr3x3<TypeUint, TypeInt, COLS_FHD, ROWS_FHD, BORDER_TYPE>(input, output_sw_x, output_sw_y);
	ImgScharr3x3<TypeUint, TypeInt, VEC_NUM, COLS_FHD, ROWS_FHD, BORDER_TYPE>((vx_image_data<TypeUint, VEC_NUM> *)input,
																			  (vx_image_data<TypeInt, VEC_NUM> *)output_hw_x, (vx_image_data<TypeInt, VEC_NUM> *)output_hw_y);
	std::cout << name09.c_str();
	CheckError<TypeInt, COLS_FHD, ROWS_FHD, BORDER_RADIUS>(output_sw_x, output_hw_x);
	std::cout << name10.c_str();
	CheckError<TypeInt, COLS_FHD, ROWS_FHD, BORDER_RADIUS>(output_sw_y, output_hw_y);

	SwSobel<TypeUint, TypeInt, COLS_FHD, ROWS_FHD, FILTER_SIZE, BORDER_TYPE>(input, output_sw_x, output_sw_y);
	ImgSobel<TypeUint, TypeInt, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_SIZE, BORDER_TYPE>((vx_image_data<TypeUint, VEC_NUM> *)input,
																					   (vx_image_data<TypeInt, VEC_NUM> *)output_hw_x, (vx_image_data<TypeInt, VEC_NUM> *)output_hw_y);
	std::cout << name11.c_str();
	CheckError<TypeInt, COLS_FHD, ROWS_FHD, BORDER_RADIUS>(output_sw_x, output_hw_x);
	std::cout << name12.c_str();
	CheckError<TypeInt, COLS_FHD, ROWS_FHD, BORDER_RADIUS>(output_sw_y, output_hw_y);

	ImgNonMaxSuppression<TypeUint, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_SIZE, BORDER_TYPE>((vx_image_data<TypeUint, VEC_NUM> *)input,
																						  (vx_image_data<TypeUint, VEC_NUM> *)output_hw, nms_mask);
	SwNonMaximaSuppression<TypeUint, COLS_FHD, ROWS_FHD, FILTER_SIZE, BORDER_TYPE>(input, output_sw);
	std::cout << name13.c_str();
	CheckError<TypeUint, COLS_FHD, ROWS_FHD, BORDER_RADIUS>(output_sw, output_hw);

	ImgSegmentTestDetector<TypeUint, VEC_NUM, COLS_FHD, ROWS_FHD, BORDER_TYPE>((vx_image_data<TypeUint, VEC_NUM> *)input,
																			   (vx_image_data<TypeUint, VEC_NUM> *)output_hw);
	SwSegmentTestDetector<TypeUint, COLS_FHD, ROWS_FHD, BORDER_TYPE>(input, output_sw);
	std::cout << name14.c_str();
	CheckError<TypeUint, COLS_FHD, ROWS_FHD, BORDER_RADIUS_FAST>(output_sw, output_hw);

	ImgHysteresis<TypeUint, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_SIZE, BORDER_TYPE, THRESH_LOWER, THRESH_UPPER>((vx_image_data<TypeUint, VEC_NUM> *)input, (vx_image_data<TypeUint, VEC_NUM> *)output_hw);
	SwHysteresis<TypeUint, COLS_FHD, ROWS_FHD, FILTER_SIZE, BORDER_TYPE, THRESH_LOWER, THRESH_UPPER>(input, output_sw);
	std::cout << name15.c_str();
	CheckError<TypeUint, COLS_FHD, ROWS_FHD, BORDER_RADIUS>(output_sw, output_hw);
}

/***************************************************************************************************************************************************/
/**
@brief  Computes a Box filter over a window of the input image.
@param Type         The data type of the input and output
@param WIDTH        The image height
@param HEIGHT       The image width
@param KERN_SIZE    The kernel size of the filter
@param BORDER_TYPE  The border type if filter exceeds border
@param input        The input image
@param output       The output image
*/
template <typename Type, const vx_uint16 WIDTH, const vx_uint16 HEIGHT, const vx_uint16 KERN_SIZE, const vx_border_e BORDER_TYPE>
void SwBox(Type *input, Type *output)
{

	// Constants
	const vx_int32 KERN_RAD = KERN_SIZE / 2;
	const float NORM = 1.0f / powf(KERN_SIZE, 2);

	// Compute box filter
	for (vx_int32 y = 0; y < HEIGHT; y++)
	{
		for (vx_int32 x = 0; x < WIDTH; x++)
		{

			// Data is passed through if filter exceeds border
			if (BORDER_TYPE == VX_BORDER_UNDEFINED)
			{
				if (x < KERN_RAD || x >= WIDTH - KERN_RAD || y < KERN_RAD || y >= HEIGHT - KERN_RAD)
				{
					output[y * WIDTH + x] = input[y * WIDTH + x];
					continue;
				}
			}

			// Compute single box filter
			float sum = 0.0f;
			for (vx_int32 i = -KERN_RAD; i <= KERN_RAD; i++)
			{
				for (vx_int32 j = -KERN_RAD; j <= KERN_RAD; j++)
				{

					// Replicated border
					if (BORDER_TYPE == VX_BORDER_REPLICATE)
					{
						vx_int32 yi = MIN(MAX(y + i, static_cast<vx_int32>(0)), (vx_int32)(HEIGHT - 1));
						vx_int32 xj = MIN(MAX(x + j, static_cast<vx_int32>(0)), (vx_int32)(WIDTH - 1));
						sum += static_cast<float>(input[yi * WIDTH + xj]);

						// Constant border
					}
					else if (BORDER_TYPE == VX_BORDER_CONSTANT)
					{
						vx_int32 yi = y + i;
						vx_int32 xj = x + j;
						if ((xj >= 0) && (xj < WIDTH) && (yi >= 0) && (yi < HEIGHT))
							sum += static_cast<float>(input[yi * WIDTH + xj]);

						// Data is passed through if filter exceeds border
					}
					else if (BORDER_TYPE == VX_BORDER_UNDEFINED)
					{
						vx_int32 yi = y + i;
						vx_int32 xj = x + j;
						sum += static_cast<float>(input[yi * WIDTH + xj]);
					}
				}
			}

			// Store result
			output[y * WIDTH + x] = static_cast<Type>(sum * NORM + 0.5f);
		}
	}
}

/***************************************************************************************************************************************************/
/**
@brief  Convolves the input with the client supplied convolution matrix.
@param Type         The data type of the input and output
@param WIDTH        The image height
@param HEIGHT       The image width
@param KERN_SIZE    The kernel size of the filter
@param BORDER_TYPE  The border type if filter exceeds border
@param input        The input image
@param output       The output image
@param output       The convolve kernel
*/
template <typename Type, const vx_uint16 WIDTH, const vx_uint16 HEIGHT, const vx_uint16 KERN_SIZE, const vx_border_e BORDER_TYPE>
void SwConvolve(Type *input, Type *output, const Type kernel[KERN_SIZE][KERN_SIZE])
{

	// Constants
	const vx_int32 KERN_RAD = KERN_SIZE / 2;

	float NORM = 0.0f;
	for (vx_int32 i = 0; i < KERN_SIZE; i++)
	{
		for (vx_int32 j = 0; j < KERN_SIZE; j++)
		{
			NORM += kernel[i][j];
		}
	}
	NORM = 1.0f / NORM;

	// Compute custom filter
	for (vx_int32 y = 0; y < HEIGHT; y++)
	{
		for (vx_int32 x = 0; x < WIDTH; x++)
		{

			// Data is passed through if filter exceeds border
			if (BORDER_TYPE == VX_BORDER_UNDEFINED)
			{
				if (x < KERN_RAD || x >= WIDTH - KERN_RAD || y < KERN_RAD || y >= HEIGHT - KERN_RAD)
				{
					output[y * WIDTH + x] = input[y * WIDTH + x];
					continue;
				}
			}

			// Compute single custom filter
			float sum = 0.0f;
			for (vx_int32 i = -KERN_RAD; i <= KERN_RAD; i++)
			{
				for (vx_int32 j = -KERN_RAD; j <= KERN_RAD; j++)
				{

					// Replicated border
					if (BORDER_TYPE == VX_BORDER_REPLICATE)
					{
						vx_int32 yi = MIN(MAX(y + i, static_cast<vx_int32>(0)), (vx_int32)(HEIGHT - 1));
						vx_int32 xj = MIN(MAX(x + j, static_cast<vx_int32>(0)), (vx_int32)(WIDTH - 1));
						float A = static_cast<float>(input[yi * WIDTH + xj]);
						float B = static_cast<float>(kernel[i + KERN_RAD][j + KERN_RAD]);
						sum += (A * B);

						// Constant border
					}
					else if (BORDER_TYPE == VX_BORDER_CONSTANT)
					{
						vx_int32 yi = y + i;
						vx_int32 xj = x + j;
						if ((xj >= 0) && (xj < WIDTH) && (yi >= 0) && (yi < HEIGHT))
						{
							float A = static_cast<float>(input[yi * WIDTH + xj]);
							float B = static_cast<float>(kernel[i + KERN_RAD][j + KERN_RAD]);
							sum += (A * B);
						}

						// Data is passed through if filter exceeds border
					}
					else if (BORDER_TYPE == VX_BORDER_UNDEFINED)
					{
						vx_int32 yi = y + i;
						vx_int32 xj = x + j;
						float A = static_cast<float>(input[yi * WIDTH + xj]);
						float B = static_cast<float>(kernel[i + KERN_RAD][j + KERN_RAD]);
						sum += (A * B);
					}
				}
			}

			// Store result
			output[y * WIDTH + x] = static_cast<Type>(sum * NORM + 0.5f);
		}
	}
}

/***************************************************************************************************************************************************/
/**
@brief  Implements Dilation, which grows the white space in an image.
@param Type         The data type of the input and output
@param WIDTH        The image height
@param HEIGHT       The image width
@param KERN_SIZE    The kernel size of the filter
@param BORDER_TYPE  The border type if filter exceeds border
@param input        The input image
@param output       The output image
*/
template <typename Type, const vx_uint16 WIDTH, const vx_uint16 HEIGHT, const vx_uint16 KERN_SIZE, const vx_border_e BORDER_TYPE>
void SwDilate(Type *input, Type *output)
{

	// Constants
	const vx_int32 KERN_RAD = KERN_SIZE / 2;

	// Compute Dilate function
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{

			// Data is passed through if filter exceeds border
			if (BORDER_TYPE == VX_BORDER_UNDEFINED)
			{
				if (x < KERN_RAD || x >= WIDTH - KERN_RAD || y < KERN_RAD || y >= HEIGHT - KERN_RAD)
				{
					output[y * WIDTH + x] = input[y * WIDTH + x];
					continue;
				}
			}

			// Single Result
			Type result = std::numeric_limits<Type>::min();

			// Compute Dilate value
			for (int i = (-1) * KERN_RAD; i <= KERN_RAD; i++)
			{
				for (int j = (-1) * KERN_RAD; j <= KERN_RAD; j++)
				{

					// Get kernel coordinates
					int yi = i + y;
					int xj = j + x;

					// Update dilate value
					if (BORDER_TYPE == VX_BORDER_REPLICATE)
					{
						if (yi >= 0 && xj >= 0 && yi < HEIGHT && xj < WIDTH)
						{
							Type value = input[yi * WIDTH + xj];
							result = MAX(result, value);
						}
					}
					else if (BORDER_TYPE == VX_BORDER_UNDEFINED)
					{
						Type value = input[yi * WIDTH + xj];
						result = MAX(result, value);
					}
					else if (BORDER_TYPE == VX_BORDER_CONSTANT)
					{
						if (yi >= 0 && xj >= 0 && yi < HEIGHT && xj < WIDTH)
						{
							Type value = input[yi * WIDTH + xj];
							result = MAX(result, value);
						}
						else
						{
							result = MAX(result, (Type)0);
						}
					}
				}
			}

			// Write back result
			output[y * WIDTH + x] = result;
		}
	}
}

/***************************************************************************************************************************************************/
/**
@brief  Implements Erosion, which shrinks the white space in an image.
@param Type         The data type of the input and output
@param WIDTH        The image height
@param HEIGHT       The image width
@param KERN_SIZE    The kernel size of the filter
@param BORDER_TYPE  The border type if filter exceeds border
@param input        The input image
@param output       The output image
*/
template <typename Type, const vx_uint16 WIDTH, const vx_uint16 HEIGHT, const vx_uint16 KERN_SIZE, const vx_border_e BORDER_TYPE>
void SwErode(Type *input, Type *output)
{

	// Constants
	const vx_int32 KERN_RAD = KERN_SIZE / 2;

	// Compute Dilate function
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{

			// Data is passed through if filter exceeds border
			if (BORDER_TYPE == VX_BORDER_UNDEFINED)
			{
				if (x < KERN_RAD || x >= WIDTH - KERN_RAD || y < KERN_RAD || y >= HEIGHT - KERN_RAD)
				{
					output[y * WIDTH + x] = input[y * WIDTH + x];
					continue;
				}
			}

			// Single Result
			Type result = std::numeric_limits<Type>::max();

			// Compute Dilate value
			for (int i = (-1) * KERN_RAD; i <= KERN_RAD; i++)
			{
				for (int j = (-1) * KERN_RAD; j <= KERN_RAD; j++)
				{

					// Get kernel coordinates
					int yi = i + y;
					int xj = j + x;

					// Update dilate value
					if (BORDER_TYPE == VX_BORDER_REPLICATE)
					{
						if (yi >= 0 && xj >= 0 && yi < HEIGHT && xj < WIDTH)
						{
							Type value = input[yi * WIDTH + xj];
							result = MIN(result, value);
						}
					}
					else if (BORDER_TYPE == VX_BORDER_UNDEFINED)
					{
						Type value = input[yi * WIDTH + xj];
						result = MIN(result, value);
					}
					else if (BORDER_TYPE == VX_BORDER_CONSTANT)
					{
						if (yi >= 0 && xj >= 0 && yi < HEIGHT && xj < WIDTH)
						{
							Type value = input[yi * WIDTH + xj];
							result = MIN(result, value);
						}
						else
						{
							result = MIN(result, (Type)0);
						}
					}
				}
			}

			// Write back result
			output[y * WIDTH + x] = result;
		}
	}
}

/***************************************************************************************************************************************************/
/**
@brief  Computes a Gaussian filter over a window of the input image.
@param Type         The data type of the input and output
@param WIDTH        The image height
@param HEIGHT       The image width
@param KERN_SIZE    The kernel size of the filter
@param BORDER_TYPE  The border type if filter exceeds border
@param input        The input image
@param output       The output image
*/
template <typename Type, const vx_uint16 WIDTH, const vx_uint16 HEIGHT, const vx_uint16 KERN_SIZE, const vx_border_e BORDER_TYPE>
void SwGaussian(Type *input, Type *output)
{

	// Constants
	const vx_uint16 KERN_RAD = KERN_SIZE / 2;

	// Kernel Type
	typedef vx_uint16 KernelTypeT;

	// Normalization
	float norm = 0.0;

	// Kernel
	KernelTypeT kernel[KERN_SIZE][KERN_SIZE];

	// Compute kernel and normalization (Compile-Time)
	ComputeGaussianKernels<KernelTypeT, KERN_SIZE>(kernel);

	// Normalization
	for (vx_uint16 x = 0; x < KERN_SIZE; x++)
	{
		for (vx_uint16 y = 0; y < KERN_SIZE; y++)
		{
			norm += static_cast<float>(kernel[y][x]);
		}
	}

	// Compute gaussian filter
	for (vx_int32 y = 0; y < HEIGHT; y++)
	{
		for (vx_int32 x = 0; x < WIDTH; x++)
		{

			// Data is passed through if filter exceeds border
			if (BORDER_TYPE == VX_BORDER_UNDEFINED)
			{
				if (x < KERN_RAD || x >= WIDTH - KERN_RAD || y < KERN_RAD || y >= HEIGHT - KERN_RAD)
				{
					output[y * WIDTH + x] = input[y * WIDTH + x];
					continue;
				}
			}

			// Compute single gaussian filter
			float sum = 0.0f;
			for (vx_int32 i = -KERN_RAD; i <= KERN_RAD; i++)
			{
				for (vx_int32 j = -KERN_RAD; j <= KERN_RAD; j++)
				{
					if (BORDER_TYPE == VX_BORDER_REPLICATE)
					{
						vx_int32 yi = MIN(MAX(y + i, static_cast<vx_int32>(0)), (vx_int32)(HEIGHT - 1));
						vx_int32 xj = MIN(MAX(x + j, static_cast<vx_int32>(0)), (vx_int32)(WIDTH - 1));
						float A = static_cast<float>(input[yi * WIDTH + xj]);
						float B = static_cast<float>(kernel[i + KERN_RAD][j + KERN_RAD]);
						sum += (A * B);
					}
					else if (BORDER_TYPE == VX_BORDER_CONSTANT)
					{
						vx_int32 yi = y + i;
						vx_int32 xj = x + j;
						if ((xj >= 0) && (xj < WIDTH) && (yi >= 0) && (yi < HEIGHT))
						{
							float A = static_cast<float>(input[yi * WIDTH + xj]);
							float B = static_cast<float>(kernel[i + KERN_RAD][j + KERN_RAD]);
							sum += (A * B);
						}
					}
					else if (BORDER_TYPE == VX_BORDER_UNDEFINED)
					{
						vx_int32 yi = y + i;
						vx_int32 xj = x + j;
						float A = static_cast<float>(input[yi * WIDTH + xj]);
						float B = static_cast<float>(kernel[i + KERN_RAD][j + KERN_RAD]);
						sum += (A * B);
					}
				}
			}

			// Store result
			output[y * WIDTH + x] = static_cast<Type>(sum / norm + 0.5f);
		}
	}
}

/***************************************************************************************************************************************************/
/**
@brief  Computes a median pixel value over a window of the input image.
@param Type         The data type of the input and output
@param WIDTH        The image height
@param HEIGHT       The image width
@param KERN_SIZE    The kernel size of the filter
@param BORDER_TYPE  The border type if filter exceeds border
@param input        The input image
@param output       The output image
*/
template <typename Type, const vx_uint16 WIDTH, const vx_uint16 HEIGHT, const vx_uint16 KERN_SIZE, const vx_border_e BORDER_TYPE>
void SwMedian(Type *input, Type *output)
{

	// Constants
	const vx_uint16 KERN_RAD = KERN_SIZE / 2;
	const vx_uint16 WIN_SIZE = KERN_SIZE * KERN_SIZE;
	const vx_uint16 MEDIAN = WIN_SIZE / 2;

	// Window
	Type data[WIN_SIZE];

	// Compute Median filter
	for (vx_int32 y = 0; y < HEIGHT; y++)
	{
		for (vx_int32 x = 0; x < WIDTH; x++)
		{

			// Data is passed through if filter exceeds border
			if (BORDER_TYPE == VX_BORDER_UNDEFINED)
			{
				if (x < KERN_RAD || x >= WIDTH - KERN_RAD || y < KERN_RAD || y >= HEIGHT - KERN_RAD)
				{
					output[y * WIDTH + x] = input[y * WIDTH + x];
					continue;
				}
			}

			// Compute single Median filter
			vx_uint16 ptr = 0;
			for (vx_int32 i = -KERN_RAD; i <= KERN_RAD; i++)
			{
				for (vx_int32 j = -KERN_RAD; j <= KERN_RAD; j++)
				{
					if (BORDER_TYPE == VX_BORDER_REPLICATE)
					{
						vx_int32 yi = MIN(MAX(y + i, static_cast<vx_int32>(0)), (vx_int32)(HEIGHT - 1));
						vx_int32 xj = MIN(MAX(x + j, static_cast<vx_int32>(0)), (vx_int32)(WIDTH - 1));
						data[ptr] = input[yi * WIDTH + xj];
					}
					else if (BORDER_TYPE == VX_BORDER_CONSTANT)
					{
						vx_int32 yi = y + i;
						vx_int32 xj = x + j;
						if ((xj >= 0) && (xj < WIDTH) && (yi >= 0) && (yi < HEIGHT))
							data[ptr] = input[yi * WIDTH + xj];
						else
							data[ptr] = 0;
					}
					else if (BORDER_TYPE == VX_BORDER_UNDEFINED)
					{
						vx_int32 yi = y + i;
						vx_int32 xj = x + j;
						data[ptr] = input[yi * WIDTH + xj];
					}
					ptr++;
				}
			}
			sort(data, data + WIN_SIZE);

			// Store result
			output[y * WIDTH + x] = data[MEDIAN];
		}
	}
}

/***************************************************************************************************************************************************/
/**
@brief  Implements the Scharr Image Filter Kernel.
@param Type         The data type of the input and output
@param WIDTH        The image height
@param HEIGHT       The image width
@param BORDER_TYPE  The border type if filter exceeds border
@param input        The input image
@param output_x     The output x image
@param output_y     The output y image
*/
template <typename InType, typename OutType, const vx_uint16 WIDTH, const vx_uint16 HEIGHT, const vx_border_e BORDER_TYPE>
void SwScharr3x3(InType *input, OutType *output_x, OutType *output_y)
{

	// Kernel Type
	typedef vx_int16 KernelTypeT;

	// Kernel Parameters
	const vx_uint16 KERN_NUM = 2;
	const vx_uint16 KERN_SIZE = 3;
	const vx_int32 KERN_RAD = KERN_SIZE / 2;
	const float NORM = 32;

	// Function Input
	const KernelTypeT kernel[KERN_NUM][KERN_SIZE][KERN_SIZE] = {
		{
			{-3, 0, 3},
			{-10, 0, 10},
			{-3, 0, 3},
		},
		{
			{-3, -10, -3},
			{0, 0, 0},
			{3, 10, 3},
		}};

	// Compute Scharr filter
	for (vx_int32 y = 0; y < HEIGHT; y++)
	{
		for (vx_int32 x = 0; x < WIDTH; x++)
		{

			// Data is passed through if filter exceeds border
			if (BORDER_TYPE == VX_BORDER_UNDEFINED)
			{
				if (x < KERN_RAD || x >= WIDTH - KERN_RAD || y < KERN_RAD || y >= HEIGHT - KERN_RAD)
				{
					output_x[y * WIDTH + x] = input[y * WIDTH + x];
					output_y[y * WIDTH + x] = input[y * WIDTH + x];
					continue;
				}
			}

			// Compute single custom filter
			float sum_x = 0.0f, sum_y = 0.0f;
			;
			for (vx_int32 i = -KERN_RAD; i <= KERN_RAD; i++)
			{
				for (vx_int32 j = -KERN_RAD; j <= KERN_RAD; j++)
				{

					if (BORDER_TYPE == VX_BORDER_REPLICATE)
					{
						vx_int32 yi = MIN(MAX(y + i, static_cast<vx_int32>(0)), (vx_int32)(HEIGHT - 1));
						vx_int32 xj = MIN(MAX(x + j, static_cast<vx_int32>(0)), (vx_int32)(WIDTH - 1));
						float A = static_cast<float>(input[yi * WIDTH + xj]);
						float B = static_cast<float>(kernel[0][i + KERN_RAD][j + KERN_RAD]);
						float C = static_cast<float>(kernel[1][i + KERN_RAD][j + KERN_RAD]);
						sum_x += (A * B);
						sum_y += (A * C);
					}
					else if (BORDER_TYPE == VX_BORDER_CONSTANT)
					{
						vx_int32 yi = y + i;
						vx_int32 xj = x + j;
						if ((xj >= 0) && (xj < WIDTH) && (yi >= 0) && (yi < HEIGHT))
						{
							float A = static_cast<float>(input[yi * WIDTH + xj]);
							float B = static_cast<float>(kernel[0][i + KERN_RAD][j + KERN_RAD]);
							float C = static_cast<float>(kernel[1][i + KERN_RAD][j + KERN_RAD]);
							sum_x += (A * B);
							sum_y += (A * C);
						}
					}
					else if (BORDER_TYPE == VX_BORDER_UNDEFINED)
					{
						vx_int32 yi = y + i;
						vx_int32 xj = x + j;
						float A = static_cast<float>(input[yi * WIDTH + xj]);
						float B = static_cast<float>(kernel[0][i + KERN_RAD][j + KERN_RAD]);
						float C = static_cast<float>(kernel[1][i + KERN_RAD][j + KERN_RAD]);
						sum_x += (A * B);
						sum_y += (A * C);
					}
				}
			}

			// Store result
			output_x[y * WIDTH + x] = static_cast<OutType>(sum_x / NORM + 0.5f);
			output_y[y * WIDTH + x] = static_cast<OutType>(sum_y / NORM + 0.5f);
		}
	}
}

/***************************************************************************************************************************************************/
/**
@brief  Implements the Sobel Image Filter Kernel.
@param Type         The data type of the input and output
@param WIDTH        The image height
@param HEIGHT       The image width
@param KERN_SIZE    The kernel size of the filter
@param BORDER_TYPE  The border type if filter exceeds border
@param input        The input image
@param output_x     The output x image
@param output_y     The output y image
*/
template <typename InType, typename OutType, const vx_uint16 WIDTH, const vx_uint16 HEIGHT, const vx_uint16 KERN_SIZE, const vx_border_e BORDER_TYPE>
void SwSobel(InType *input, OutType *output_x, OutType *output_y)
{

	// Kernel Type
	typedef vx_int16 KernelTypeT;

	// Kernel Parameters
	const vx_uint16 KERN_NUM = 2;
	const vx_int32 KERN_RAD = KERN_SIZE / 2;

	// Normalization
	float norm = 0.0;

	// Function Input
	KernelTypeT kernel[KERN_NUM][KERN_SIZE][KERN_SIZE];

	// Compute kernel and normalization (Compile-Time)
	ComputeSobelKernels<KernelTypeT, KERN_SIZE>(kernel[0], kernel[1]);

	// Normalization
	for (vx_uint16 x = 0; x < KERN_SIZE; x++)
	{
		for (vx_uint16 y = 0; y < KERN_SIZE; y++)
		{
			norm += static_cast<float>(abs(kernel[0][y][x]));
		}
	}

	// Compute Sobel filter
	for (vx_int32 y = 0; y < HEIGHT; y++)
	{
		for (vx_int32 x = 0; x < WIDTH; x++)
		{

			// Data is passed through if filter exceeds border
			if (BORDER_TYPE == VX_BORDER_UNDEFINED)
			{
				if (x < KERN_RAD || x >= WIDTH - KERN_RAD || y < KERN_RAD || y >= HEIGHT - KERN_RAD)
				{
					output_x[y * WIDTH + x] = input[y * WIDTH + x];
					output_y[y * WIDTH + x] = input[y * WIDTH + x];
					continue;
				}
			}

			// Compute single custom filter
			float sum_x = 0.0f, sum_y = 0.0f;
			;
			for (vx_int32 i = -KERN_RAD; i <= KERN_RAD; i++)
			{
				for (vx_int32 j = -KERN_RAD; j <= KERN_RAD; j++)
				{

					if (BORDER_TYPE == VX_BORDER_REPLICATE)
					{
						vx_int32 yi = MIN(MAX(y + i, static_cast<vx_int32>(0)), (vx_int32)(HEIGHT - 1));
						vx_int32 xj = MIN(MAX(x + j, static_cast<vx_int32>(0)), (vx_int32)(WIDTH - 1));
						float A = static_cast<float>(input[yi * WIDTH + xj]);
						float B = static_cast<float>(kernel[0][i + KERN_RAD][j + KERN_RAD]);
						float C = static_cast<float>(kernel[1][i + KERN_RAD][j + KERN_RAD]);
						sum_x += (A * B);
						sum_y += (A * C);
					}
					else if (BORDER_TYPE == VX_BORDER_CONSTANT)
					{
						vx_int32 yi = y + i;
						vx_int32 xj = x + j;
						if ((xj >= 0) && (xj < WIDTH) && (yi >= 0) && (yi < HEIGHT))
						{
							float A = static_cast<float>(input[yi * WIDTH + xj]);
							float B = static_cast<float>(kernel[0][i + KERN_RAD][j + KERN_RAD]);
							float C = static_cast<float>(kernel[1][i + KERN_RAD][j + KERN_RAD]);
							sum_x += (A * B);
							sum_y += (A * C);
						}
					}
					else if (BORDER_TYPE == VX_BORDER_UNDEFINED)
					{
						vx_int32 yi = y + i;
						vx_int32 xj = x + j;
						float A = static_cast<float>(input[yi * WIDTH + xj]);
						float B = static_cast<float>(kernel[0][i + KERN_RAD][j + KERN_RAD]);
						float C = static_cast<float>(kernel[1][i + KERN_RAD][j + KERN_RAD]);
						sum_x += (A * B);
						sum_y += (A * C);
					}
				}
			}

			// Store result
			output_x[y * WIDTH + x] = static_cast<OutType>((sum_x / norm) + 0.5f);
			output_y[y * WIDTH + x] = static_cast<OutType>((sum_y / norm) + 0.5f);
		}
	}
}

/***************************************************************************************************************************************************/
/*! \brief Compute the Non-max supression for 1 pixel */
template <typename Type, vx_int32 KERN_RAD>
bool CheckNonMax(vx_int32 y, vx_int32 x, Type pixel, Type input)
{

	bool maximum = false;

	// Check top left
	if ((y < KERN_RAD) || ((y == KERN_RAD) && (x < KERN_RAD)))
	{
		if (input < pixel)
			maximum = false;

		// Check bottom right
	}
	else if ((y > KERN_RAD) || ((y == KERN_RAD) && (x > KERN_RAD)))
	{
		if (input <= pixel)
			maximum = false;
	}

	return maximum;
}

/***************************************************************************************************************************************************/
template <typename Type, const vx_int32 WIDTH, const vx_int32 HEIGHT, const vx_int32 KERN_SIZE, const vx_border_e BORDER_TYPE>
void SwNonMaximaSuppression(Type *src, Type *dst)
{

	// Constants
	const vx_int32 KERN_RAD = KERN_SIZE / 2;
	const Type min_value = ComputeMin<Type>();

	// Compute  function
	for (vx_int32 y = 0; y < HEIGHT; y++)
	{
		for (vx_int32 x = 0; x < WIDTH; x++)
		{

			// Data is passed through if filter exceeds border
			if (BORDER_TYPE == VX_BORDER_UNDEFINED)
			{
				if (x < KERN_RAD || x >= WIDTH - KERN_RAD || y < KERN_RAD || y >= HEIGHT - KERN_RAD)
				{
					dst[y * WIDTH + x] = src[y * WIDTH + x];
					continue;
				}
			}

			// Variables
			vx_int32 yi = 0, xj = 0;
			Type input = 0;
			bool maximum = true;

			// Input
			Type pixel = src[y * WIDTH + x];

			// Compute  value
			for (vx_int32 i = (-1) * KERN_RAD; i <= KERN_RAD; i++)
			{
				for (vx_int32 j = (-1) * KERN_RAD; j <= KERN_RAD; j++)
				{

					// Update  value
					if (BORDER_TYPE == VX_BORDER_REPLICATE)
					{
						yi = MIN(MAX(y + i, static_cast<vx_int32>(0)), (vx_int32)(HEIGHT - 1));
						xj = MIN(MAX(x + j, static_cast<vx_int32>(0)), (vx_int32)(WIDTH - 1));
						input = src[yi * WIDTH + xj];
						maximum = CheckNonMax<Type, KERN_RAD>(y, x, pixel, input);
					}
					else if (BORDER_TYPE == VX_BORDER_UNDEFINED)
					{
						yi = i + y;
						xj = j + x;
						input = src[yi * WIDTH + xj];
						maximum = CheckNonMax<Type, KERN_RAD>(y, x, pixel, input);
					}
					else if (BORDER_TYPE == VX_BORDER_CONSTANT)
					{
						yi = i + y;
						xj = j + x;
						if (yi >= 0 && xj >= 0 && yi < HEIGHT && xj < WIDTH)
						{
							input = src[yi * WIDTH + xj];
							maximum = CheckNonMax<Type, KERN_RAD>(y, x, pixel, input);
						}
						else
						{
							maximum = CheckNonMax<Type, KERN_RAD>(y, x, pixel, (Type)0);
						}
					}
				}
			}

			// Write back result
			dst[y * WIDTH + x] = (maximum == false) ? (min_value) : (input);
		}
	}
}

/***************************************************************************************************************************************************/
template <typename Type, const vx_uint16 WIDTH, const vx_uint16 HEIGHT, const vx_uint16 KERN_SIZE, const vx_border_e BORDER_TYPE>
void SwNonMaximaSuppressionPhase(Type *input, Type *output)
{

	//// Constants
	// const vx_int32 KERN_RAD = KERN_SIZE / 2;

	//// Compute  function
	// for (vx_int32 y = 0; y < HEIGHT; y++) {
	//	for (vx_int32 x = 0; x < WIDTH; x++) {

	//		// Data is passed through if filter exceeds border
	//		if (BORDER_TYPE == VX_BORDER_UNDEFINED) {
	//			if (x < KERN_RAD || x >= WIDTH - KERN_RAD || y < KERN_RAD || y >= HEIGHT - KERN_RAD) {
	//				output[y*WIDTH + x] = input[y*WIDTH + x];
	//				continue;
	//			}
	//		}

	//		// Single Result
	//		Type result = 0;

	//		// Compute  value
	//		for (vx_int32 i = (-1) * KERN_RAD; i <= KERN_RAD; i++) {
	//			for (vx_int32 j = (-1) * KERN_RAD; j <= KERN_RAD; j++) {

	//				// Get kernel coordinates
	//				vx_int32 yi = i + y;
	//				vx_int32 xj = j + x;

	//				// Update  value
	//				if (BORDER_TYPE == VX_BORDER_REPLICATE) {
	//					if (yi >= 0 && xj >= 0 && yi < HEIGHT && xj < WIDTH) {
	//						Type value = input[yi*WIDTH + xj];
	//						//result = MIN(result, value);
	//					}
	//				} else if (BORDER_TYPE == VX_BORDER_UNDEFINED) {
	//					Type value = input[yi*WIDTH + xj];
	//					//result = MIN(result, value);
	//				} else if (BORDER_TYPE == VX_BORDER_CONSTANT) {
	//					if (yi >= 0 && xj >= 0 && yi < HEIGHT && xj < WIDTH) {
	//						Type value = input[yi*WIDTH + xj];
	//						//result = MIN(result, value);
	//					} else {
	//						//result = MIN(result, (Type)0);
	//					}
	//				}
	//			}
	//		}

	//		// Write back result
	//		output[y*WIDTH + x] = result;
	//	}
	//}
}

/***************************************************************************************************************************************************/
template <typename Type, const vx_uint16 WIDTH, const vx_uint16 HEIGHT, const vx_uint16 KERN_SIZE, const vx_border_e BORDER_TYPE, Type THRESH_LOWER, Type THRESH_UPPER>
void SwHysteresis(Type *src, Type *dst)
{

	// Constants
	const vx_int32 KERN_RAD = KERN_SIZE / 2;
	const Type max_value = ComputeMax<Type>();

	// Compute  function
	for (vx_int32 y = 0; y < HEIGHT; y++)
	{
		for (vx_int32 x = 0; x < WIDTH; x++)
		{

			// Data is passed through if filter exceeds border
			if (BORDER_TYPE == VX_BORDER_UNDEFINED)
			{
				if (x < KERN_RAD || x >= WIDTH - KERN_RAD || y < KERN_RAD || y >= HEIGHT - KERN_RAD)
				{
					dst[y * WIDTH + x] = src[y * WIDTH + x];
					continue;
				}
			}

			// Variables
			vx_int32 yi = 0, xj = 0;
			Type input = 0;

			// Input
			Type pixel = src[y * WIDTH + x];

			// Check the strength of the input
			bool strong = (pixel >= THRESH_UPPER);
			bool weak = (pixel >= THRESH_LOWER);

			// Compute  value
			for (vx_int32 i = (-1) * KERN_RAD; i <= KERN_RAD; i++)
			{
				for (vx_int32 j = (-1) * KERN_RAD; j <= KERN_RAD; j++)
				{

					// Update  value
					if (BORDER_TYPE == VX_BORDER_REPLICATE)
					{
						yi = MIN(MAX(y + i, static_cast<vx_int32>(0)), (vx_int32)(HEIGHT - 1));
						xj = MIN(MAX(x + j, static_cast<vx_int32>(0)), (vx_int32)(WIDTH - 1));
						input = src[yi * WIDTH + xj];
					}
					else if (BORDER_TYPE == VX_BORDER_UNDEFINED)
					{
						yi = i + y;
						xj = j + x;
						input = src[yi * WIDTH + xj];
					}
					else if (BORDER_TYPE == VX_BORDER_CONSTANT)
					{
						yi = i + y;
						xj = j + x;
						if (yi >= 0 && xj >= 0 && yi < HEIGHT && xj < WIDTH)
						{
							input = src[yi * WIDTH + xj];
						}
						else
						{
							input = 0;
						}
					}

					if ((y != 0) && (x != 0))
					{
						if ((input >= THRESH_UPPER) && (weak == true))
						{
							strong = true;
						}
					}
				}
			}

			// Write back result
			dst[y * WIDTH + x] = (strong == true) ? (max_value) : ((Type)0);
		}
	}
}

/***************************************************************************************************************************************************/
template <typename Type, const vx_uint16 WIDTH, const vx_uint16 HEIGHT, const vx_border_e BORDER_TYPE>
void SwSegmentTestDetector(Type *src, Type *dst)
{

	// Constants
	const vx_int32 KERN_RAD = 3;
	const Type max_value = std::numeric_limits<Type>::max();
	const Type min_value = std::numeric_limits<Type>::min();

	// Bresham circle
	Type circle[16] = {0};
	const vx_int8 coordinates[16][2] = {
		{-3, 0}, {-3, 1}, {-2, 2}, {-1, 3}, {0, 3}, {1, 3}, {2, 2}, {3, 1}, {3, 0}, {3, -1}, {2, -2}, {1, -3}, {0, -3}, {-1, -3}, {-2, -2}, {-3, -1}};

	// Compute  function
	for (vx_int32 y = 0; y < HEIGHT; y++)
	{
		for (vx_int32 x = 0; x < WIDTH; x++)
		{

			// Data is passed through if filter exceeds border
			if (BORDER_TYPE == VX_BORDER_UNDEFINED)
			{
				if (x < KERN_RAD || x >= WIDTH - KERN_RAD || y < KERN_RAD || y >= HEIGHT - KERN_RAD)
				{
					dst[y * WIDTH + x] = src[y * WIDTH + x];
					continue;
				}
			}

			// input/output
			vx_float32 pixel = (vx_float32)src[y * WIDTH + x];
			vx_float32 response = 0;

			// Get input data
			for (vx_int32 i = 0; i < 16; ++i)
			{
				vx_int32 yi = coordinates[i][0] + y;
				vx_int32 xj = coordinates[i][1] + x;
				Type value = 0;

				if (BORDER_TYPE == VX_BORDER_REPLICATE)
				{
					yi = MIN(MAX(yi, static_cast<vx_int32>(0)), (vx_int32)(HEIGHT - 1));
					xj = MIN(MAX(xj, static_cast<vx_int32>(0)), (vx_int32)(WIDTH - 1));
					value = src[yi * WIDTH + xj];
				}
				else if (BORDER_TYPE == VX_BORDER_UNDEFINED)
				{
					value = src[yi * WIDTH + xj];
				}
				else if (BORDER_TYPE == VX_BORDER_CONSTANT)
				{
					if (yi >= 0 && xj >= 0 && yi < HEIGHT && xj < WIDTH)
					{
						value = src[yi * WIDTH + xj];
					}
					else
					{
						value = 0;
					}
				}
				circle[i] = value;
			}

			// Compute
			for (vx_int32 i = 0; i < 16; ++i)
			{
				vx_float32 min_diff = FLT_MAX;
				bool bigger = true;
				bool smaller = true;
				for (vx_int32 j = i; j < (i + 9); ++j)
				{
					vx_uint8 ptr = j % 16;
					vx_float32 value = (vx_float32)circle[ptr];
					vx_float32 diff = ABS(value - pixel);
					min_diff = MIN(diff, min_diff);
					if (pixel <= value)
						bigger = false;
					if (pixel >= value)
						smaller = false;
				}
				if (bigger == true || smaller == true)
					response = MAX(response, min_diff);
			}

			// Write back result
			dst[y * WIDTH + x] = (Type)response; // MAX(MIN(response, max_value), min_value);
		}
	}
}

/***************************************************************************************************************************************************/
/* SW Test Functions */
/***************************************************************************************************************************************************/

/*! \brief Check if pixelwise function was correct */
template <typename Intype, typename AcType, vx_uint32 PIXELS>
void TestPixel(Intype *inputA, AcType *inputB, AcType *outputA, AcType *outputB, std::string &name)
{
	vx_int64 absDifMax = 0;
	for (vx_uint32 i = 0; i < PIXELS; i++)
	{
		vx_int64 absDif = abs(static_cast<vx_int64>(outputA[i]) - static_cast<vx_int64>(outputB[i]));
		absDifMax = max(absDifMax, absDif);
		if (absDif > 8)
		{
			vx_int64 A = static_cast<vx_int64>(inputA[i]);
			vx_int64 B = static_cast<vx_int64>(inputB[i]);
			vx_int64 C = static_cast<vx_int64>(outputA[i]);
			vx_int64 D = static_cast<vx_int64>(outputB[i]);
			printf("%4d: (%10lld, %10lld) - (%10lld, %10lld) - (%10lld), \n", i, A, B, C, D, absDif);
			//			int a = getchar();
		}
	}
	// if(absDifMax > 0)
	std::cout << "    " << name.c_str() << "Max. absolut error: " << absDifMax << std::endl;
}

/*! \brief Check if pixelwise function was correct (also checks for overflow) */
template <typename Intype, typename AcType, vx_uint32 PIXELS, vx_uint32 MAX_VAL>
void TestPixelMax(Intype *inputA, AcType *inputB, AcType *outputA, AcType *outputB, std::string &name)
{
	vx_int64 absDifMax = 0;
	for (vx_uint32 i = 0; i < PIXELS; i++)
	{
		vx_int64 in1 = static_cast<vx_int64>(outputA[i]);
		vx_int64 in2 = static_cast<vx_int64>(outputB[i]);
		vx_int64 absDif = abs(in1 - in2);
		if (absDif > (MAX_VAL / 2))
			absDif = MAX_VAL - absDif;
		absDifMax = MAX(absDifMax, absDif);
		if (absDif > 8)
		{
			vx_int64 A = static_cast<vx_int64>(inputA[i]);
			vx_int64 B = static_cast<vx_int64>(inputB[i]);
			vx_int64 C = static_cast<vx_int64>(outputA[i]);
			vx_int64 D = static_cast<vx_int64>(outputB[i]);
			printf("%4d: (%10lld, %10lld) - (%10lld, %10lld) - (%10lld), \n", i, A, B, C, D, absDif);
			int a = getchar();
		}
	}
	// if(absDifMax > 0)
	std::cout << "    " << name.c_str() << "Max. absolut error: " << absDifMax << std::endl;
}

/*! \brief Test pixelwise function */
template <typename ScalarType, vx_uint32 PIXELS, vx_uint8 VEC_SIZE, HIFLIPVX::PixelwiseOperationA OPERATION_TYPE, vx_convert_policy_e CONV_POLICY,
		  vx_round_policy_e ROUND_POLICY, vx_uint32 SCALE, vx_threshold_type_e THRESH_TYPE, ScalarType THRESH_VALUE, ScalarType THRESH_UPPER,
		  ScalarType THRESH_LOWER, vx_uint32 ALPHA, vx_uint8 ORIENT_QUANTIZATION>
void TestPixelwiseA(ScalarType *inputA, ScalarType *inputB, ScalarType *outputA, ScalarType *outputB, std::string &name)
{

	// Check if signed
	const bool IS_SIGNED = std::numeric_limits<ScalarType>::is_signed;

	// Get (Max and Min)
	const double sat_min = static_cast<double>(ComputeMin<ScalarType>());
	const double sat_max = static_cast<double>(ComputeMax<ScalarType>());

	// Get (Max and Min)
	const vx_int64 MIN_VAL = static_cast<vx_int64>(ComputeMin<ScalarType>());
	const vx_int64 MAX_VAL = static_cast<vx_int64>(ComputeMax<ScalarType>());

	// Compute Software
	for (vx_uint32 i = 0; i < PIXELS; i++)
	{
		vx_int64 A = static_cast<vx_int64>(inputA[i]);
		vx_int64 B = static_cast<vx_int64>(inputB[i]);
		vx_float64 C = 0.0;
		vx_int64 D = 0, E = 0;

		// Computation including rounding
		if (OPERATION_TYPE == HIFLIPVX::COPY_DATA)
		{
			D = A;
		}
		else if (OPERATION_TYPE == HIFLIPVX::MAX)
		{
			D = max(A, B);
		}
		else if (OPERATION_TYPE == HIFLIPVX::MIN)
		{
			D = min(A, B);
		}
		else if (OPERATION_TYPE == HIFLIPVX::ABSOLUTE_DIFFERENCE)
		{
			D = llabs(A - B);
		}
		else if (OPERATION_TYPE == HIFLIPVX::ARITHMETIC_ADDITION)
		{
			D = A + B;
		}
		else if (OPERATION_TYPE == HIFLIPVX::ARITHMETIC_SUBTRACTION)
		{
			D = A - B;
		}
		else if (OPERATION_TYPE == HIFLIPVX::MAGNITUDE)
		{
			vx_uint64 A1 = static_cast<vx_uint64>(abs(A));
			vx_uint64 B1 = static_cast<vx_uint64>(abs(B));
			vx_float64 A2 = static_cast<vx_float64>(A1 * A1);
			vx_float64 B2 = static_cast<vx_float64>(B1 * B1);
			C = sqrt(A2 + B2);
			if (ROUND_POLICY == VX_ROUND_POLICY_TO_NEAREST_EVEN)
				C += 0.5;
			D = static_cast<vx_int64>(C);
		}
		else if (OPERATION_TYPE == HIFLIPVX::MULTIPLY)
		{
			C = static_cast<vx_float64>(A) * static_cast<vx_float64>(B) * (static_cast<vx_float64>(SCALE) / pow(2, 16));
			if (ROUND_POLICY == VX_ROUND_POLICY_TO_NEAREST_EVEN)
				C += 0.5;
			D = static_cast<vx_int64>(C);
		}
		else if (OPERATION_TYPE == HIFLIPVX::THRESHOLD)
		{
			if (IS_SIGNED == true)
			{
				if (THRESH_TYPE == VX_THRESHOLD_TYPE_BINARY)
					D = (A > THRESH_VALUE) ? (-1) : (0);
				else if (THRESH_TYPE == VX_THRESHOLD_TYPE_RANGE)
					D = ((A > THRESH_UPPER) || (A < THRESH_LOWER)) ? (0) : (-1);
			}
			else
			{
				if (THRESH_TYPE == VX_THRESHOLD_TYPE_BINARY)
					D = (A > THRESH_VALUE) ? (MAX_VAL) : (0);
				else if (THRESH_TYPE == VX_THRESHOLD_TYPE_RANGE)
					D = ((A > THRESH_UPPER) || (A < THRESH_LOWER)) ? (0) : (MAX_VAL);
			}
		}
		else if (OPERATION_TYPE == HIFLIPVX::WEIGHTED_AVERAGE)
		{
			vx_float64 alpha = (vx_float64)ALPHA / (vx_float64)(1 << 16);
			if (ROUND_POLICY == VX_ROUND_POLICY_TO_ZERO)
			{
				C = ((1.0 - alpha) * (vx_float64)B + alpha * (vx_float64)A);
				D = static_cast<vx_int64>(C);
			}
			else if (ROUND_POLICY == VX_ROUND_POLICY_TO_NEAREST_EVEN)
			{
				C = ((1.0 - alpha) * (vx_float64)B + alpha * (vx_float64)A);
				D = static_cast<vx_int64>(C + 0.5);
			}
		}
		else if (OPERATION_TYPE == HIFLIPVX::PHASE)
		{
			const vx_int32 ACCURACY = 16;
			const vx_float64 SHIFT = (vx_int32)1 << ACCURACY;
			const vx_float64 TURN_POS = SHIFT / (vx_float64)(2 << (vx_int32)ORIENT_QUANTIZATION);
			const vx_float64 TURN_NEG = SHIFT - TURN_POS;
			const vx_int32 QUANTIZATION = ACCURACY - (vx_int32)ORIENT_QUANTIZATION;
			const vx_float64 ROUNDING = (vx_int32)1 << (QUANTIZATION - (vx_int32)1);

			// vx_float64 a1 = std::atan2((vx_int32)B, (vx_int32)A) / (2 * M_PI);
			// vx_float64 a2 = a1 * SHIFT;
			vx_float64 a1 = atan2CordicAccurate(A, B);							 // Compute angle
			vx_float64 a2 = (a1 / pow(2, (32 - ACCURACY))) - ROUNDING;			 // Reduce Precision and round
			vx_float64 a3 = (a2 < 0.0) ? (a2 + SHIFT) : (a2);					 // Convert negative degree to positiv
			vx_float64 a4 = (a3 > TURN_NEG) ? (a3 - TURN_NEG) : (a3 + TURN_POS); // Setting 0 degree to east
			vx_float64 a5 = (a4 >= SHIFT) ? (0.0) : (a4);						 // Setting 360 degree to 0
			D = (vx_int64)((a5) / pow(2, QUANTIZATION));						 // Do quantization
		}

		// Conversion Policy
		if (CONV_POLICY == VX_CONVERT_POLICY_SATURATE)
		{
			if (D > MAX_VAL)
				E = MAX_VAL;
			else if (D < MIN_VAL)
				E = MIN_VAL;
			else
				E = D;
		}
		else
		{
			E = D;
		}
		outputA[i] = static_cast<ScalarType>(E);
	}

	// Compute Hardware
	if (OPERATION_TYPE == HIFLIPVX::COPY_DATA)
	{
		ImgCopy<ScalarType, VEC_SIZE, PIXELS>((vx_image_data<ScalarType, VEC_SIZE> *)inputA, (vx_image_data<ScalarType, VEC_SIZE> *)outputB);
	}
	else if (OPERATION_TYPE == HIFLIPVX::MAX)
	{
		ImgMax<ScalarType, VEC_SIZE, PIXELS>((vx_image_data<ScalarType, VEC_SIZE> *)inputA, (vx_image_data<ScalarType, VEC_SIZE> *)inputB,
											 (vx_image_data<ScalarType, VEC_SIZE> *)outputB);
	}
	else if (OPERATION_TYPE == HIFLIPVX::MIN)
	{
		ImgMin<ScalarType, VEC_SIZE, PIXELS>((vx_image_data<ScalarType, VEC_SIZE> *)inputA, (vx_image_data<ScalarType, VEC_SIZE> *)inputB,
											 (vx_image_data<ScalarType, VEC_SIZE> *)outputB);
	}
	else if (OPERATION_TYPE == HIFLIPVX::ABSOLUTE_DIFFERENCE)
	{
		ImgAbsDiff<ScalarType, VEC_SIZE, PIXELS, CONV_POLICY>((vx_image_data<ScalarType, VEC_SIZE> *)inputA,
															  (vx_image_data<ScalarType, VEC_SIZE> *)inputB, (vx_image_data<ScalarType, VEC_SIZE> *)outputB);
	}
	else if (OPERATION_TYPE == HIFLIPVX::ARITHMETIC_ADDITION)
	{
		ImgAdd<ScalarType, VEC_SIZE, PIXELS, CONV_POLICY>((vx_image_data<ScalarType, VEC_SIZE> *)inputA,
														  (vx_image_data<ScalarType, VEC_SIZE> *)inputB, (vx_image_data<ScalarType, VEC_SIZE> *)outputB);
	}
	else if (OPERATION_TYPE == HIFLIPVX::ARITHMETIC_SUBTRACTION)
	{
		ImgSubtract<ScalarType, VEC_SIZE, PIXELS, CONV_POLICY>((vx_image_data<ScalarType, VEC_SIZE> *)inputA,
															   (vx_image_data<ScalarType, VEC_SIZE> *)inputB, (vx_image_data<ScalarType, VEC_SIZE> *)outputB);
	}
	else if (OPERATION_TYPE == HIFLIPVX::MAGNITUDE)
	{
		ImgMagnitude<ScalarType, VEC_SIZE, PIXELS, ROUND_POLICY>((vx_image_data<ScalarType, VEC_SIZE> *)inputA,
																 (vx_image_data<ScalarType, VEC_SIZE> *)inputB, (vx_image_data<ScalarType, VEC_SIZE> *)outputB);
	}
	else if (OPERATION_TYPE == HIFLIPVX::MULTIPLY)
	{
		ImgMultiply<ScalarType, VEC_SIZE, PIXELS, CONV_POLICY, ROUND_POLICY, SCALE>((vx_image_data<ScalarType, VEC_SIZE> *)inputA,
																					(vx_image_data<ScalarType, VEC_SIZE> *)inputB, (vx_image_data<ScalarType, VEC_SIZE> *)outputB);
	}
	else if (OPERATION_TYPE == HIFLIPVX::THRESHOLD)
	{
		ImgThreshold<ScalarType, VEC_SIZE, PIXELS, THRESH_TYPE, THRESH_VALUE, THRESH_UPPER, THRESH_LOWER>(
			(vx_image_data<ScalarType, VEC_SIZE> *)inputA, (vx_image_data<ScalarType, VEC_SIZE> *)outputB);
	}
	else if (OPERATION_TYPE == HIFLIPVX::WEIGHTED_AVERAGE)
	{
		ImgWeightedAverage<ScalarType, VEC_SIZE, PIXELS, ALPHA, ROUND_POLICY>((vx_image_data<ScalarType, VEC_SIZE> *)inputA,
																			  (vx_image_data<ScalarType, VEC_SIZE> *)inputB, (vx_image_data<ScalarType, VEC_SIZE> *)outputB);
	}
	else if (OPERATION_TYPE == HIFLIPVX::PHASE)
	{
		ImgPhase<ScalarType, VEC_SIZE, PIXELS, ORIENT_QUANTIZATION>((vx_image_data<ScalarType, VEC_SIZE> *)inputA,
																	(vx_image_data<ScalarType, VEC_SIZE> *)inputB, (vx_image_data<ScalarType, VEC_SIZE> *)outputB);
	}

	// Test result
	if (OPERATION_TYPE == HIFLIPVX::PHASE)
	{
		const vx_uint32 MAX_VAL = 1 << ORIENT_QUANTIZATION;
		TestPixelMax<ScalarType, ScalarType, PIXELS, MAX_VAL>(inputA, inputB, outputA, outputB, name);
	}
	else
	{
		TestPixel<ScalarType, ScalarType, PIXELS>(inputA, inputB, outputA, outputB, name);
	}
}

/*! \brief Test all pixelwise functions dependent on policy */
template <typename ScalarType, vx_uint32 PIXELS, vx_uint8 VEC_SIZE, vx_convert_policy_e CONV_POLICY, vx_round_policy_e ROUND_POLICY, vx_uint32 SCALE,
		  vx_threshold_type_e THRESH_TYPE, ScalarType THRESH_VALUE, ScalarType THRESH_UPPER, ScalarType THRESH_LOWER, vx_uint32 ALPHA,
		  vx_uint8 ORIENT_QUANTIZATION>
void TestPolicyA(ScalarType *inputA, ScalarType *inputB, ScalarType *outputA, ScalarType *outputB, std::string &name)
{

	// Write name of upper test case
	std::cout << "  " << name.c_str() << std::endl;

	// Function test scenarios
	string name0 = "Copy: ";
	string name1 = "Max:  ";
	string name2 = "Min:  ";
	string name3 = "Abs:  ";
	string name4 = "Add:  ";
	string name5 = "Sub:  ";
	string name6 = "Mag:  ";
	string name7 = "Mul:  ";
	string name8 = "Thre: ";
	string name9 = "Weig: ";
	string name10 = "Orie: ";

	// Test functions for possible policies
	if ((ROUND_POLICY == VX_ROUND_POLICY_TO_ZERO) && (CONV_POLICY == VX_CONVERT_POLICY_WRAP))
	{
		TestPixelwiseA<ScalarType, PIXELS, VEC_SIZE, HIFLIPVX::COPY_DATA, CONV_POLICY, ROUND_POLICY, SCALE, THRESH_TYPE, THRESH_VALUE, THRESH_UPPER,
					   THRESH_LOWER, ALPHA, ORIENT_QUANTIZATION>(inputA, inputB, outputA, outputB, name0);
		TestPixelwiseA<ScalarType, PIXELS, VEC_SIZE, HIFLIPVX::MAX, CONV_POLICY, ROUND_POLICY, SCALE, THRESH_TYPE, THRESH_VALUE, THRESH_UPPER,
					   THRESH_LOWER, ALPHA, ORIENT_QUANTIZATION>(inputA, inputB, outputA, outputB, name1);
		TestPixelwiseA<ScalarType, PIXELS, VEC_SIZE, HIFLIPVX::MIN, CONV_POLICY, ROUND_POLICY, SCALE, THRESH_TYPE, THRESH_VALUE, THRESH_UPPER,
					   THRESH_LOWER, ALPHA, ORIENT_QUANTIZATION>(inputA, inputB, outputA, outputB, name2);
		TestPixelwiseA<ScalarType, PIXELS, VEC_SIZE, HIFLIPVX::THRESHOLD, CONV_POLICY, ROUND_POLICY, SCALE, THRESH_TYPE, THRESH_VALUE, THRESH_UPPER,
					   THRESH_LOWER, ALPHA, ORIENT_QUANTIZATION>(inputA, inputB, outputA, outputB, name8);
		TestPixelwiseA<ScalarType, PIXELS, VEC_SIZE, HIFLIPVX::WEIGHTED_AVERAGE, CONV_POLICY, ROUND_POLICY, SCALE, THRESH_TYPE, THRESH_VALUE,
					   THRESH_UPPER, THRESH_LOWER, ALPHA, ORIENT_QUANTIZATION>(inputA, inputB, outputA, outputB, name9);
		TestPixelwiseA<ScalarType, PIXELS, VEC_SIZE, HIFLIPVX::PHASE, CONV_POLICY, ROUND_POLICY, SCALE, THRESH_TYPE, THRESH_VALUE, THRESH_UPPER,
					   THRESH_LOWER, ALPHA, ORIENT_QUANTIZATION>(inputA, inputB, outputA, outputB, name10);
	}
	if (ROUND_POLICY == VX_ROUND_POLICY_TO_ZERO)
	{
		TestPixelwiseA<ScalarType, PIXELS, VEC_SIZE, HIFLIPVX::ABSOLUTE_DIFFERENCE, CONV_POLICY, ROUND_POLICY, SCALE, THRESH_TYPE, THRESH_VALUE,
					   THRESH_UPPER, THRESH_LOWER, ALPHA, ORIENT_QUANTIZATION>(inputA, inputB, outputA, outputB, name3);
		TestPixelwiseA<ScalarType, PIXELS, VEC_SIZE, HIFLIPVX::ARITHMETIC_ADDITION, CONV_POLICY, ROUND_POLICY, SCALE, THRESH_TYPE, THRESH_VALUE,
					   THRESH_UPPER, THRESH_LOWER, ALPHA, ORIENT_QUANTIZATION>(inputA, inputB, outputA, outputB, name4);
		TestPixelwiseA<ScalarType, PIXELS, VEC_SIZE, HIFLIPVX::ARITHMETIC_SUBTRACTION, CONV_POLICY, ROUND_POLICY, SCALE, THRESH_TYPE, THRESH_VALUE,
					   THRESH_UPPER, THRESH_LOWER, ALPHA, ORIENT_QUANTIZATION>(inputA, inputB, outputA, outputB, name5);
	}
	if (CONV_POLICY == VX_CONVERT_POLICY_SATURATE)
	{
		TestPixelwiseA<ScalarType, PIXELS, VEC_SIZE, HIFLIPVX::MAGNITUDE, CONV_POLICY, ROUND_POLICY, SCALE, THRESH_TYPE, THRESH_VALUE, THRESH_UPPER,
					   THRESH_LOWER, ALPHA, ORIENT_QUANTIZATION>(inputA, inputB, outputA, outputB, name6);
	}
	TestPixelwiseA<ScalarType, PIXELS, VEC_SIZE, HIFLIPVX::MULTIPLY, CONV_POLICY, ROUND_POLICY, SCALE, THRESH_TYPE, THRESH_VALUE, THRESH_UPPER,
				   THRESH_LOWER, ALPHA, ORIENT_QUANTIZATION>(inputA, inputB, outputA, outputB, name7);
}

/*! \brief Test all pixelwise functions for all possible policies for 1 data type */
template <typename ScalarType, vx_uint32 PIXELS, vx_uint8 VEC_SIZE, vx_uint32 SCALE, vx_threshold_type_e THRESH_TYPE,
		  ScalarType THRESH_VALUE, ScalarType THRESH_UPPER, ScalarType THRESH_LOWER, vx_uint32 ALPHA, vx_uint8 ORIENT_QUANTIZATION>
void TestDataTypeA(std::string &name)
{

	// Test images
	ScalarType *inputA = new ScalarType[PIXELS];
	ScalarType *inputB = new ScalarType[PIXELS];
	ScalarType *outputA = new ScalarType[PIXELS];
	ScalarType *outputB = new ScalarType[PIXELS];

	// Write test image data
	const vx_int64 MIN_VAL = static_cast<vx_int64>(ComputeMin<ScalarType>());
	const vx_int64 MAX_VAL = static_cast<vx_int64>(ComputeMax<ScalarType>());
	const double max_rand = static_cast<double>(RAND_MAX);
	const double min_val = static_cast<double>(MIN_VAL);
	const double max_val = static_cast<double>(MAX_VAL);
	double A, B, C, D;
	vx_int64 E, F;
	vx_int64 maximun = MAX_VAL;
	vx_int64 minimum = MIN_VAL;

	for (vx_uint32 i = 0; i < PIXELS; i++)
	{
		A = static_cast<double>(rand());
		B = A / max_rand;
		C = B * (max_val - min_val);
		D = C + min_val;
		E = static_cast<vx_int64>(D + 0.5);
		F = MAX(MIN(E, MAX_VAL), MIN_VAL);
		inputA[i] = static_cast<ScalarType>(F);
		maximun = MAX(F, maximun);
		minimum = MIN(F, minimum);
		A = static_cast<double>(rand());
		B = A / max_rand;
		C = B * (max_val - min_val);
		D = C + min_val;
		E = static_cast<vx_int64>(D + 0.5);
		F = MAX(MIN(E, MAX_VAL), MIN_VAL);
		inputB[i] = static_cast<ScalarType>(F);
		maximun = MAX(F, maximun);
		minimum = MIN(F, minimum);
	}

	// Write name of upper test case
	std::cout << "" << name.c_str();
	std::cout << " | input data range: [" << minimum << ".." << maximun << "]" << std::endl;

	// Policy test scenarios
	string name1 = "CONVERT_POLICY_WRAP and ROUND_POLICY_TO_ZERO:             ";
	string name2 = "CONVERT_POLICY_WRAP and ROUND_POLICY_TO_NEAREST_EVEN:     ";
	string name3 = "CONVERT_POLICY_SATURATE and ROUND_POLICY_TO_ZERO:         ";
	string name4 = "CONVERT_POLICY_SATURATE and ROUND_POLICY_TO_NEAREST_EVEN: ";

	// Test all policies for a data type
	TestPolicyA<ScalarType, PIXELS, VEC_SIZE, VX_CONVERT_POLICY_WRAP, VX_ROUND_POLICY_TO_ZERO, SCALE, THRESH_TYPE, THRESH_VALUE, THRESH_UPPER,
				THRESH_LOWER, ALPHA, ORIENT_QUANTIZATION>(inputA, inputB, outputA, outputB, name1);
	TestPolicyA<ScalarType, PIXELS, VEC_SIZE, VX_CONVERT_POLICY_WRAP, VX_ROUND_POLICY_TO_NEAREST_EVEN, SCALE, THRESH_TYPE, THRESH_VALUE, THRESH_UPPER,
				THRESH_LOWER, ALPHA, ORIENT_QUANTIZATION>(inputA, inputB, outputA, outputB, name2);
	TestPolicyA<ScalarType, PIXELS, VEC_SIZE, VX_CONVERT_POLICY_SATURATE, VX_ROUND_POLICY_TO_ZERO, SCALE, THRESH_TYPE, THRESH_VALUE, THRESH_UPPER,
				THRESH_LOWER, ALPHA, ORIENT_QUANTIZATION>(inputA, inputB, outputA, outputB, name3);
	TestPolicyA<ScalarType, PIXELS, VEC_SIZE, VX_CONVERT_POLICY_SATURATE, VX_ROUND_POLICY_TO_NEAREST_EVEN, SCALE, THRESH_TYPE, THRESH_VALUE,
				THRESH_UPPER, THRESH_LOWER, ALPHA, ORIENT_QUANTIZATION>(inputA, inputB, outputA, outputB, name4);

	// Delete memory
	delete[] inputA;
	delete[] inputB;
	delete[] outputA;
	delete[] outputB;

	// Newline
	std::cout << std::endl;
}

/*! \brief Calls all Software Test Functions */
void SwTestPixelopMain(void)
{

	// Image Size
	const vx_uint32 COLS = 256;
	const vx_uint32 ROWS = 256;
	const vx_uint32 PIXELS = COLS * ROWS;
	const vx_uint8 VEC_SIZE = 1;
	const vx_uint32 SCALE = static_cast<vx_uint32>(256);
	const vx_uint8 SHIFT = static_cast<vx_uint32>(8);				  // 0 .. 15
	const vx_uint32 ALPHA = static_cast<vx_uint32>(1000);			  // 0 .. 65536
	const vx_threshold_type_e THRESH_TYPE = VX_THRESHOLD_TYPE_BINARY; // VX_THRESHOLD_TYPE_BINARY, VX_THRESHOLD_TYPE_RANGE
	const vx_uint32 THRESH_VALUE = 50;
	const vx_uint32 THRESH_UPPER = 100;
	const vx_uint32 THRESH_LOWER = 20;
	const vx_uint8 ORIENT_QUANTIZATION = 8;

	std::cout << "Resolution:   " << COLS << " x " << ROWS << std::endl;
	std::cout << "Vector Size:  " << static_cast<vx_uint16>(VEC_SIZE) << std::endl;
	std::cout << "Scale (mult): " << SCALE << std::endl
			  << std::endl;

	std::string name01 = "UNSIGNED INTEGER 8-Bit:  ";
	std::string name02 = "UNSIGNED INTEGER 16-Bit: ";
	std::string name03 = "UNSIGNED INTEGER 32-Bit: ";
	std::string name04 = "SIGNED INTEGER 8-Bit:    ";
	std::string name05 = "SIGNED INTEGER 16-Bit:   ";
	std::string name06 = "SIGNED INTEGER 32-Bit:   ";

#if !defined(__LAST__) && !defined(__LAST__)
	TestDataTypeA<vx_uint8, PIXELS, VEC_SIZE, SCALE, THRESH_TYPE, THRESH_VALUE, THRESH_UPPER, THRESH_LOWER, ALPHA, ORIENT_QUANTIZATION>(name01);
	TestDataTypeA<vx_uint16, PIXELS, VEC_SIZE, SCALE, THRESH_TYPE, THRESH_VALUE, THRESH_UPPER, THRESH_LOWER, ALPHA, ORIENT_QUANTIZATION>(name02);
	TestDataTypeA<vx_uint32, PIXELS, VEC_SIZE, SCALE, THRESH_TYPE, THRESH_VALUE, THRESH_UPPER, THRESH_LOWER, ALPHA, ORIENT_QUANTIZATION>(name03);
	TestDataTypeA<vx_int8, PIXELS, VEC_SIZE, SCALE, THRESH_TYPE, THRESH_VALUE, THRESH_UPPER, THRESH_LOWER, ALPHA, ORIENT_QUANTIZATION>(name04);
	TestDataTypeA<vx_int16, PIXELS, VEC_SIZE, SCALE, THRESH_TYPE, THRESH_VALUE, THRESH_UPPER, THRESH_LOWER, ALPHA, ORIENT_QUANTIZATION>(name05);
	TestDataTypeA<vx_int32, PIXELS, VEC_SIZE, SCALE, THRESH_TYPE, THRESH_VALUE, THRESH_UPPER, THRESH_LOWER, ALPHA, ORIENT_QUANTIZATION>(name06);
#endif
}

/*****************************************************************************/
/* Macros */
#define HI(num) (((num)&0x0000FF00) << 8)
#define LO(num) ((num)&0x000000FF)

/*****************************************************************************/
/* PGM data structure */
typedef struct PgmImage
{
	vx_int32 row;
	vx_int32 col;
	vx_int32 max_gray;
	vx_uint8 *matrix;
} PgmData;

/*****************************************************************************/
/* Skip comments */
void SkipComments(FILE *fp)
{
	vx_int32 ch;
	vx_char line[100];

	while ((ch = fgetc(fp)) != EOF && isspace(ch))
		;
	if (ch == '#')
	{
		fgets(line, sizeof(line), fp);
		SkipComments(fp);
	}
	else
	{
		fseek(fp, -1, SEEK_CUR);
	}
}

/*****************************************************************************/
/* Read image */
PgmData *ReadPgm(const char *file_name, PgmData *data)
{
	FILE *pgm_file;
	vx_char version[3];
	vx_int32 i = 0, j = 0;
	vx_int32 lo = 0, hi = 0;
	vx_int32 dat = 0, count = 0;

	// Open file
	pgm_file = fopen(file_name, "rb");
	if (pgm_file == NULL)
	{
		perror("Cannot open file to read!");
		return nullptr;
	}

	// Check file type
	fgets(version, sizeof(version), pgm_file);
	if (strcmp(version, "P5"))
	{
		perror("Wrong file type!");
		return nullptr;
	}

	// Read column amount
	SkipComments(pgm_file);
	count = fscanf(pgm_file, "%d", &(data->col));
	if (feof(pgm_file) || ferror(pgm_file))
	{
		perror("File read error!");
		return nullptr;
	}

	// Read row amount
	SkipComments(pgm_file);
	count = fscanf(pgm_file, "%d", &(data->row));
	if (feof(pgm_file) || ferror(pgm_file))
	{
		perror("File read error!");
		return nullptr;
	}

	// Read max value
	SkipComments(pgm_file);
	count = fscanf(pgm_file, "%d", &(data->max_gray));
	if (feof(pgm_file) || ferror(pgm_file))
	{
		perror("File read error!");
		return nullptr;
	}

	// Read image data
	fgetc(pgm_file);
	if (data->max_gray > 255)
	{
		for (i = 0; i < data->row; ++i)
		{
			for (j = 0; j < data->col; ++j)
			{
				hi = fgetc(pgm_file);
				lo = fgetc(pgm_file);
				data->matrix[i * (data->col) + j] = (hi << 8) + lo;
			}
		}
	}
	else
	{
		for (i = 0; i < data->row; ++i)
		{
			for (j = 0; j < data->col; ++j)
			{
				lo = fgetc(pgm_file);
				data->matrix[i * (data->col) + j] = lo;
			}
		}
	}

	// Close file
	fclose(pgm_file);
	return data;
}

/*****************************************************************************/
/* Write image */
void WritePgm(const char *filename, const PgmData *data)
{
	FILE *pgm_file;
	vx_int32 i = 0, j = 0;
	vx_int32 hi = 0, lo = 0;

	// Open file
	pgm_file = fopen(filename, "wb");
	if (pgm_file == NULL)
	{
		perror("Cannot open file to write");
		return;
	}

	// Write file type
	fprintf(pgm_file, "P5 ");
	if (ferror(pgm_file))
	{
		perror("Write file error!");
		return;
	}

	// Write column & row amount
	fprintf(pgm_file, "%d %d ", data->col, data->row);
	if (ferror(pgm_file))
	{
		perror("Write file error!");
		return;
	}

	// Write max value
	fprintf(pgm_file, "%d ", data->max_gray);
	if (ferror(pgm_file))
	{
		perror("Write file error!");
		return;
	}

	// Write image data
	if (data->max_gray > 255)
	{
		for (i = 0; i < data->row; ++i)
		{
			for (j = 0; j < data->col; ++j)
			{
				hi = HI(data->matrix[i * (data->col) + j]);
				lo = LO(data->matrix[i * (data->col) + j]);
				fputc(hi, pgm_file);
				fputc(lo, pgm_file);
			}
		}
	}
	else
	{
		for (i = 0; i < data->row; ++i)
		{
			for (j = 0; j < data->col; ++j)
			{
				lo = LO(data->matrix[i * (data->col) + j]);
				fputc(lo, pgm_file);
			}
		}
	}

	// Close file
	fclose(pgm_file);
}

/*****************************************************************************/
/* Copy the MetaData for the Pgm Image */
void CopyImageMetaData(struct PgmImage *src, struct PgmImage *dst)
{
	dst->col = src->col;
	dst->row = src->row;
	dst->max_gray = src->max_gray;
}

#endif

/***************************************************************************************************************************************************/
/* Global System configurations */
/***************************************************************************************************************************************************/

// Image Size
#define COLS_FHD 1920
#define ROWS_FHD 1080
#define PIXELS_FHD COLS_FHD *ROWS_FHD
#define COLS_HD 1280
#define ROWS_HD 720
#define PIXELS_HD COLS_HD *ROWS_HD

// Vectorization
#define VEC_NUM 1
#define VEC_PIX (PIXELS_FHD / VEC_NUM)
//#define __SDSCC__

/***************************************************************************************************************************************************/
/* Accelerated Pixelwise Functions */
/***************************************************************************************************************************************************/

// Defines
#define PIXELWISE_CONV_TYPE VX_CONVERT_POLICY_WRAP	 // VX_CONVERT_POLICY_SATURATE, VX_CONVERT_POLICY_WRAP
#define PIXELWISE_ROUND_TYPE VX_ROUND_POLICY_TO_ZERO // VX_ROUND_POLICY_TO_NEAREST_EVEN, VX_ROUND_POLICY_TO_ZERO
#define MULT_SCALE static_cast<vx_uint32>(0x4000)	 // 0x4000=0.25 ... 0x3333=0.2
#define ALPHA static_cast<vx_uint32>(0x3333)
#define THRESH_TYPE VX_THRESHOLD_TYPE_BINARY // VX_THRESHOLD_TYPE_BINARY, VX_THRESHOLD_TYPE_RANGE
#define THRESH_VALUE static_cast<vx_int64>(50)
#define THRESH_UPPER static_cast<vx_int64>(100)
#define THRESH_LOWER static_cast<vx_int64>(20)
#define PHASE_QUANTIZATION static_cast<vx_uint8>(3)

// Typedefs
typedef vx_uint32 pixelwise_type_1;
#if (VEC_NUM == 1 && defined(__SDSCC__))
typedef pixelwise_type_1 pixelwise_image_1;
#else
typedef vx_image_data<pixelwise_type_1, VEC_NUM> pixelwise_image_1;
#endif

// Copy a data object to another.
void HwTestCopy(pixelwise_image_1 input[VEC_PIX], pixelwise_image_1 output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
	ImgCopy<pixelwise_type_1, VEC_NUM, PIXELS_FHD>(input, output);
}

// Performs a bitwise NOT operation on a input images.
void HwTestNot(pixelwise_image_1 input[VEC_PIX], pixelwise_image_1 output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
	ImgNot<pixelwise_type_1, VEC_NUM, PIXELS_FHD>(input, output);
}

// Performs a bitwise AND operation between two unsigned images.
void HwTestAnd(pixelwise_image_1 input1[VEC_PIX], pixelwise_image_1 input2[VEC_PIX], pixelwise_image_1 output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input1
#pragma HLS INTERFACE axis port = input2
#pragma HLS INTERFACE axis port = output
	ImgAnd<pixelwise_type_1, VEC_NUM, PIXELS_FHD>(input1, input2, output);
}

// Performs a bitwise INCLUSIVE OR operation between two unsigned images.
void HwTestOr(pixelwise_image_1 input1[VEC_PIX], pixelwise_image_1 input2[VEC_PIX], pixelwise_image_1 output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input1
#pragma HLS INTERFACE axis port = input2
#pragma HLS INTERFACE axis port = output
	ImgOr<pixelwise_type_1, VEC_NUM, PIXELS_FHD>(input1, input2, output);
}

// Performs a bitwise EXCLUSIVE OR (XOR) operation between two unsigned images.
void HwTestXor(pixelwise_image_1 input1[VEC_PIX], pixelwise_image_1 input2[VEC_PIX], pixelwise_image_1 output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input1
#pragma HLS INTERFACE axis port = input2
#pragma HLS INTERFACE axis port = output
	ImgXor<pixelwise_type_1, VEC_NUM, PIXELS_FHD>(input1, input2, output);
}

// Implements a pixel-wise maximum kernel.
void HwTestMax(pixelwise_image_1 input1[VEC_PIX], pixelwise_image_1 input2[VEC_PIX], pixelwise_image_1 output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input1
#pragma HLS INTERFACE axis port = input2
#pragma HLS INTERFACE axis port = output
	ImgMax<pixelwise_type_1, VEC_NUM, PIXELS_FHD>(input1, input2, output);
}

// Implements a pixel-wise minimum kernel.
void HwTestMin(pixelwise_image_1 input1[VEC_PIX], pixelwise_image_1 input2[VEC_PIX], pixelwise_image_1 output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input1
#pragma HLS INTERFACE axis port = input2
#pragma HLS INTERFACE axis port = output
	ImgMin<pixelwise_type_1, VEC_NUM, PIXELS_FHD>(input1, input2, output);
}

// Computes the absolute difference between two images
void HwTestAbsDiff(pixelwise_image_1 input1[VEC_PIX], pixelwise_image_1 input2[VEC_PIX], pixelwise_image_1 output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input1
#pragma HLS INTERFACE axis port = input2
#pragma HLS INTERFACE axis port = output
	ImgAbsDiff<pixelwise_type_1, VEC_NUM, PIXELS_FHD, PIXELWISE_CONV_TYPE>(input1, input2, output);
}

// Performs addition between two images
void HwTestAdd(pixelwise_image_1 input1[VEC_PIX], pixelwise_image_1 input2[VEC_PIX], pixelwise_image_1 output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input1
#pragma HLS INTERFACE axis port = input2
#pragma HLS INTERFACE axis port = output
	ImgAdd<pixelwise_type_1, VEC_NUM, PIXELS_FHD, PIXELWISE_CONV_TYPE>(input1, input2, output);
}

// Performs subtraction between two images
void HwTestSub(pixelwise_image_1 input1[VEC_PIX], pixelwise_image_1 input2[VEC_PIX], pixelwise_image_1 output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input1
#pragma HLS INTERFACE axis port = input2
#pragma HLS INTERFACE axis port = output
	ImgSubtract<pixelwise_type_1, VEC_NUM, PIXELS_FHD, PIXELWISE_CONV_TYPE>(input1, input2, output);
}

// Implements the Gradient Magnitude Computation Kernel
void HwTestMagnitude(pixelwise_image_1 input1[VEC_PIX], pixelwise_image_1 input2[VEC_PIX], pixelwise_image_1 output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input1
#pragma HLS INTERFACE axis port = input2
#pragma HLS INTERFACE axis port = output
	ImgMagnitude<pixelwise_type_1, VEC_NUM, PIXELS_FHD, PIXELWISE_ROUND_TYPE>(input1, input2, output);
}

// Performs element-wise multiplication between two images and a scalar value
void HwTestMultiply(pixelwise_image_1 input1[VEC_PIX], pixelwise_image_1 input2[VEC_PIX], pixelwise_image_1 output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input1
#pragma HLS INTERFACE axis port = input2
#pragma HLS INTERFACE axis port = output
	ImgMultiply<pixelwise_type_1, VEC_NUM, PIXELS_FHD, PIXELWISE_CONV_TYPE, PIXELWISE_ROUND_TYPE, MULT_SCALE>(input1, input2, output);
}

// Weighted average value from two input images to an output image.
void HwTestWeightedAverage(pixelwise_image_1 input1[VEC_PIX], pixelwise_image_1 input2[VEC_PIX], pixelwise_image_1 output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input1
#pragma HLS INTERFACE axis port = input2
#pragma HLS INTERFACE axis port = output
	ImgWeightedAverage<pixelwise_type_1, VEC_NUM, PIXELS_FHD, ALPHA, PIXELWISE_ROUND_TYPE>(input1, input2, output);
}

// Thresholds an input image and produces an output Boolean image.
void HwTestThreshold(pixelwise_image_1 input[VEC_PIX], pixelwise_image_1 output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
	ImgThreshold<pixelwise_type_1, VEC_NUM, PIXELS_FHD, THRESH_TYPE, THRESH_VALUE, THRESH_UPPER, THRESH_LOWER>(input, output);
}

// Weighted average value from two input images to an output image.
void HwTestPhase(pixelwise_image_1 input1[VEC_PIX], pixelwise_image_1 input2[VEC_PIX], pixelwise_image_1 output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input1
#pragma HLS INTERFACE axis port = input2
#pragma HLS INTERFACE axis port = output
	ImgPhase<pixelwise_type_1, VEC_NUM, PIXELS_FHD, PHASE_QUANTIZATION>(input1, input2, output);
}

/*********************************************************************************************************************/
// Test the pixelwise algorithms
void TestPixelwiseFunctions()
{

	// Buffers for Pixelwise Functions
	pixelwise_image_1 *inputA = CreateImage<pixelwise_image_1, PIXELS_FHD, VEC_NUM>();
	pixelwise_image_1 *inputB = CreateImage<pixelwise_image_1, PIXELS_FHD, VEC_NUM>();
	pixelwise_image_1 *outputA = CreateImage<pixelwise_image_1, PIXELS_FHD, VEC_NUM>();

	// Create random data
	for (vx_uint32 i = 0; i < PIXELS_FHD; i++)
	{
		vx_uint8 a = rand() % 256;
		vx_uint8 b = rand() % 256;
		((pixelwise_type_1 *)(inputA))[i] = a;
		((pixelwise_type_1 *)(inputB))[i] = b;
	}

	// Pixelwise operations
	HwTestAbsDiff(inputA, inputB, outputA);
	HwTestAdd(inputA, inputB, outputA);
	HwTestSub(inputA, inputB, outputA);
	HwTestAnd(inputA, inputB, outputA);
	HwTestXor(inputA, inputB, outputA);
	HwTestOr(inputA, inputB, outputA);
	HwTestNot(inputA, outputA);
	HwTestCopy(inputA, outputA);
	HwTestMagnitude(inputA, inputB, outputA);
	HwTestMax(inputA, inputB, outputA);
	HwTestMin(inputA, inputB, outputA);
	HwTestPhase(inputA, inputB, outputA);
	HwTestMultiply(inputA, inputB, outputA);
	HwTestThreshold(inputA, outputA);
	HwTestWeightedAverage(inputA, inputB, outputA);

	// Free memory
	DestroyImage<pixelwise_image_1>(inputA);
	DestroyImage<pixelwise_image_1>(inputB);
	DestroyImage<pixelwise_image_1>(outputA);
}

/***************************************************************************************************************************************************/
/* Accelerated Filter functions */
/***************************************************************************************************************************************************/

// Defines
#define FILTER_SIZE static_cast<vx_int32>(3)
#define FILTER_BORDER VX_BORDER_CONSTANT
#define SEPARABLE_FILTER (vx_bool) vx_true_e
#define FIXED_FILTER_SIZE static_cast<vx_int32>(3)
#define HYSTERESIS_UPPER static_cast<vx_int32>(100)
#define HYSTERESIS_LOWER static_cast<vx_int32>(20)
#define NMS_QUANTIZATION static_cast<vx_uint32>(3)

// Typedefs
typedef vx_uint8 filter_u_type;
typedef vx_int8 filter_s_type;
#if (VEC_NUM == 1 && defined(__SDSCC__))
typedef filter_u_type filter_u_image;
typedef filter_s_type filter_s_image;
#else
typedef vx_image_data<filter_u_type, VEC_NUM> filter_u_image;
typedef vx_image_data<filter_s_type, VEC_NUM> filter_s_image;
#endif

// Convolution kernel for the HwConvolve filter
const filter_u_type convolve_kernel[FIXED_FILTER_SIZE][FIXED_FILTER_SIZE] = {
	{191, 185, 157},
	{237, 171, 245},
	{219, 235, 173}};
// Mask for Non-Max_supression. If mask entry unequal zereo, pixel will be ignored
const filter_u_type nms_mask[FIXED_FILTER_SIZE][FIXED_FILTER_SIZE] = {
	{0, 0, 0},
	{0, 0, 0},
	{0, 0, 0}};

// Computes a Box filter over a window of the input image.
void TestHwBox(filter_u_image input[VEC_PIX], filter_u_image output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
	ImgBox<filter_u_type, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_SIZE, FILTER_BORDER, SEPARABLE_FILTER>(input, output);
}

// Convolves the input with the client supplied convolution matrix.
void TestHwConvolve(filter_u_image input[VEC_PIX], filter_u_image output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
	ImgConvolve<filter_u_type, VEC_NUM, COLS_FHD, ROWS_FHD, FIXED_FILTER_SIZE, FILTER_BORDER>(input, output, convolve_kernel);
}

// Implements Dilation, which grows the white space in an image.
void TestHwDilate(filter_u_image input[VEC_PIX], filter_u_image output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
	ImgDilate<filter_u_type, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_SIZE, FILTER_BORDER>(input, output);
}

// Implements Erosion, which shrinks the white space in an image.
void TestHwErode(filter_u_image input[VEC_PIX], filter_u_image output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
	ImgErode<filter_u_type, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_SIZE, FILTER_BORDER>(input, output);
}

// Computes a Gaussian filter over a window of the input image.
void TestHwGaussian(filter_u_image input[VEC_PIX], filter_u_image output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
	ImgGaussian<filter_u_type, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_SIZE, FILTER_BORDER, SEPARABLE_FILTER>(input, output);
}

// Computes a median pixel value over a window of the input image.
void TestHwMedian(filter_u_image input[VEC_PIX], filter_u_image output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
	ImgMedian<filter_u_type, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_SIZE, FILTER_BORDER>(input, output);
}

// Implements the Scharr Image Filter Kernel.
void TestHwScharr3x3(filter_u_image input[VEC_PIX], filter_s_image output1[VEC_PIX], filter_s_image output2[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output1
#pragma HLS INTERFACE axis port = output2
	ImgScharr3x3<filter_u_type, filter_s_type, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_BORDER>(input, output1, output2);
}

// Implements the Sobel Image Filter Kernel.
#pragma SDS data access_pattern(input                 \
								: SEQUENTIAL, output1 \
								: SEQUENTIAL, output2 \
								: SEQUENTIAL)
void TestHwSobel(filter_u_image input[VEC_PIX], filter_s_image output1[VEC_PIX], filter_s_image output2[VEC_PIX])
{
	ImgSobel<filter_u_type, filter_s_type, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_SIZE, FILTER_BORDER>(input, output1, output2);
}

// Find local maxima in an image, or otherwise suppress pixels that are not local maxima.
void TestNonMaxSupression(filter_u_image input[VEC_PIX], filter_u_image output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
	ImgNonMaxSuppression<filter_u_type, VEC_NUM, COLS_FHD, ROWS_FHD, FIXED_FILTER_SIZE, FILTER_BORDER>(input, output, nms_mask);
}

// Implements the segment test detector that outputs an image of response values for corners
void TestHwSegmentTestDetector(filter_u_image input[VEC_PIX], filter_u_image output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
	ImgSegmentTestDetector<filter_u_type, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_BORDER>(input, output);
}

// Implements the hysteres of an image
void TestHysteresis(filter_u_image input[VEC_PIX], filter_u_image output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
	ImgHysteresis<filter_u_type, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_SIZE, FILTER_BORDER, HYSTERESIS_LOWER, HYSTERESIS_UPPER>(input, output);
}

// Find local maxima in an image depending on the phase, or otherwise suppress pixels that are not local maxima.
void TestOrientedNonMaxSuppression(filter_u_image input1[VEC_PIX], filter_u_image input2[VEC_PIX], filter_u_image output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input1
#pragma HLS INTERFACE axis port = input2
#pragma HLS INTERFACE axis port = output
	ImgOrientedNonMaxSuppression<filter_u_type, VEC_NUM, COLS_FHD, ROWS_FHD, FILTER_BORDER, NMS_QUANTIZATION>(input1, input2, output);
}

/*********************************************************************************************************************/
// Test the windowed algorithms
void TestFilterFunctions()
{

	// Buffers for Filter Functions
	filter_u_image *srcA = CreateImage<filter_u_image, PIXELS_FHD, VEC_NUM>();
	filter_u_image *srcB = CreateImage<filter_u_image, PIXELS_FHD, VEC_NUM>();
	filter_u_image *dstA = CreateImage<filter_u_image, PIXELS_FHD, VEC_NUM>();
	filter_s_image *dstX = CreateImage<filter_s_image, PIXELS_FHD, VEC_NUM>();
	filter_s_image *dstY = CreateImage<filter_s_image, PIXELS_FHD, VEC_NUM>();

	// Create random data
	for (vx_uint32 i = 0; i < PIXELS_FHD; i++)
	{
		vx_uint8 a = rand() % 256;
		vx_uint8 b = rand() % 256;
		((filter_u_type *)(srcA))[i] = a;
		((filter_u_type *)(srcB))[i] = b;
	}

	// Filter Functions
	TestHwBox(srcA, dstA);
	TestHwConvolve(srcA, dstA);
	TestHwDilate(srcA, dstA);
	TestHwErode(srcA, dstA);
	TestHwGaussian(srcA, dstA);
	TestHwMedian(srcA, dstA);
	TestHwScharr3x3(srcA, dstX, dstY);
	TestHwSobel(srcA, dstX, dstY);
	TestNonMaxSupression(srcA, dstA);
	TestHwSegmentTestDetector(srcA, dstA);
	TestHysteresis(srcA, dstA);
	TestOrientedNonMaxSuppression(srcA, srcB, dstA);

	// Free memory
	DestroyImage<filter_u_image>(srcA);
	DestroyImage<filter_u_image>(srcB);
	DestroyImage<filter_u_image>(dstA);
	DestroyImage<filter_s_image>(dstX);
	DestroyImage<filter_s_image>(dstY);
}

/***************************************************************************************************************************************************/
/* Accelerated Conversion functions */
/***************************************************************************************************************************************************/

// Defines
#define COMBINE_AMOUNT 3																	   // 2, 3, 4
#define EXTRACT_CHANNEL 0																	   // 0, 1, 2, 3
#define CHANNEL_TYPE VX_DF_IMAGE_RGBX														   // VX_DF_IMAGE_U16, VX_DF_IMAGE_U32, VX_DF_IMAGE_RGB, VX_DF_IMAGE_RGBX
#define BIT_DEPTH_CONVERSION VX_CONVERT_POLICY_SATURATE										   // VX_CONVERT_POLICY_SATURATE, VX_CONVERT_POLICY_WRAP
#define BIT_DEPTH_SHIFT 8																	   //
#define SCALE_INTERPOLATION VX_INTERPOLATION_BILINEAR										   // VX_INTERPOLATION_BILINEAR, VX_INTERPOLATION_NEAREST_NEIGHBOR
#define DW_CONV_SRC_PARALLEL 3																   //
#define DW_CONV_DST_PARALLEL 2																   //
#define CHANNEL_SIZE (CHANNEL_TYPE == VX_DF_IMAGE_RGB) ? ((PIXELS_FHD * 3) / 4) : (PIXELS_FHD) // TODO: alignement not correct

// Typedefs
typedef vx_uint32 channel_type;		 // vx_uint16, vx_uint32
typedef vx_int16 bit_depth_src_type; // vx_uint8, vx_int8, vx_uint16, vx_int16, vx_uint32, vx_int32
typedef vx_uint8 bit_depth_dst_type; // vx_uint8, vx_int8, vx_uint16, vx_int16, vx_uint32, vx_int32
typedef vx_uint8 dw_conv_type;		 // all
typedef vx_uint8 multicast_type;	 // all
#ifdef __SDSCC__
typedef channel_type channel_image;
typedef vx_uint8 conversion_u8_image;
#else
typedef vx_image_data<channel_type, 1> channel_image;
typedef vx_image_data<vx_uint8, 1> conversion_u8_image;
#endif
#if (VEC_NUM == 1 && defined(__SDSCC__))
typedef bit_depth_src_type bit_depth_src_image;
typedef bit_depth_dst_type bit_depth_dst_image;
typedef multicast_type multicast_image;
#else
typedef vx_image_data<bit_depth_src_type, VEC_NUM> bit_depth_src_image;
typedef vx_image_data<bit_depth_dst_type, VEC_NUM> bit_depth_dst_image;
typedef vx_image_data<multicast_type, VEC_NUM> multicast_image;
#endif
#if (DW_CONV_SRC_PARALLEL == 1 && defined(__SDSCC__))
typedef dw_conv_type dw_conv_image_src;
#else
typedef vx_image_data<dw_conv_type, DW_CONV_SRC_PARALLEL> dw_conv_image_src;
#endif
#if (DW_CONV_DST_PARALLEL == 1 && defined(__SDSCC__))
typedef dw_conv_type dw_conv_image_dst;
#else
typedef vx_image_data<dw_conv_type, DW_CONV_DST_PARALLEL> dw_conv_image_dst;
#endif

// Implements the Channel Combine Kernel.
void HwChannelCombine(conversion_u8_image input1[PIXELS_FHD], conversion_u8_image input2[PIXELS_FHD], conversion_u8_image input3[PIXELS_FHD], conversion_u8_image input4[PIXELS_FHD], channel_image output[CHANNEL_SIZE])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input1
#pragma HLS INTERFACE axis port = input2
#pragma HLS INTERFACE axis port = input3
#pragma HLS INTERFACE axis port = input4
#pragma HLS INTERFACE axis port = output
	ImgChannelCombine<channel_type, COMBINE_AMOUNT, PIXELS_FHD, CHANNEL_SIZE, CHANNEL_TYPE>(input1, input2, input3, input4, output);
}

//  Implements the Channel Extraction Kernel.
void HwChannelExtract(channel_image input[CHANNEL_SIZE], conversion_u8_image output[PIXELS_FHD])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
	ImgChannelExtract<channel_type, EXTRACT_CHANNEL, CHANNEL_SIZE, PIXELS_FHD, CHANNEL_TYPE>(input, output);
}

// Converts the Color of an image between RGB/RGBX/Gray
void HwColourConversion(channel_image input[CHANNEL_SIZE], conversion_u8_image output[PIXELS_FHD])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
	ImgConvertColor<channel_type, vx_uint8, CHANNEL_SIZE, PIXELS_FHD, CHANNEL_TYPE, VX_DF_IMAGE_U8>(input, output);
}

// Converts image bit depth.
void HwConvertBitDepth(bit_depth_src_image input[VEC_PIX], bit_depth_dst_image output[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
	ImgConvertBitDepth<bit_depth_src_type, bit_depth_dst_type, VEC_NUM, PIXELS_FHD, BIT_DEPTH_CONVERSION, BIT_DEPTH_SHIFT>(input, output);
}

// Scale an image down using bilinear or nearest neighbor interpolation
void HwScaleImage(conversion_u8_image input[PIXELS_FHD], conversion_u8_image output[PIXELS_HD])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
	ImgScaleImage<COLS_FHD, ROWS_FHD, COLS_HD, ROWS_HD, SCALE_INTERPOLATION>(input, output);
}

//  Converts converts between two buffers with a different vector sizes (parallelization degree). If needed: bigger image needs to be aligned.
void HwDataWidthConverter(dw_conv_image_src input[PIXELS_FHD / DW_CONV_SRC_PARALLEL], dw_conv_image_dst output[PIXELS_FHD / DW_CONV_DST_PARALLEL])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
	ImgDataWidthConverter<dw_conv_type, 1, PIXELS_FHD, PIXELS_FHD, DW_CONV_SRC_PARALLEL, DW_CONV_DST_PARALLEL>(input, output);
}

// Copies the input image to multiple output images
void HwMulticast(multicast_image input[VEC_PIX], multicast_image output1[VEC_PIX], multicast_image output2[VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output1
#pragma HLS INTERFACE axis port = output2
	ImgMulticast<multicast_type, PIXELS_FHD, VEC_NUM>(input, output1, output2);
}

/*********************************************************************************************************************/
// Test the conversion algorithms
void TestConversionFunctions()
{

	// Allocate memory
	conversion_u8_image *src_fhd_u8_a = CreateImage<conversion_u8_image, PIXELS_FHD, 1>();
	conversion_u8_image *src_fhd_u8_b = CreateImage<conversion_u8_image, PIXELS_FHD, 1>();
	conversion_u8_image *src_fhd_u8_c = CreateImage<conversion_u8_image, PIXELS_FHD, 1>();
	conversion_u8_image *src_fhd_u8_d = CreateImage<conversion_u8_image, PIXELS_FHD, 1>();
	conversion_u8_image *dst_fhd_u8_a = CreateImage<conversion_u8_image, PIXELS_FHD, 1>();
	conversion_u8_image *dst_hd_u8_a = CreateImage<conversion_u8_image, PIXELS_HD, 1>();
	channel_image *src_channel = CreateImage<channel_image, CHANNEL_SIZE, 1>();
	channel_image *dst_channel = CreateImage<channel_image, PIXELS_FHD, 1>();
	bit_depth_src_image *src_bitdepth = CreateImage<bit_depth_src_image, PIXELS_FHD, VEC_NUM>();
	bit_depth_dst_image *dst_bitdepth = CreateImage<bit_depth_dst_image, PIXELS_FHD, VEC_NUM>();
	multicast_image *src_multicast = CreateImage<multicast_image, PIXELS_FHD, VEC_NUM>();
	multicast_image *dst1_multicast = CreateImage<multicast_image, PIXELS_FHD, VEC_NUM>();
	multicast_image *dst2_multicast = CreateImage<multicast_image, PIXELS_FHD, VEC_NUM>();
	dw_conv_image_src *src_dw_conv = CreateImage<dw_conv_image_src, PIXELS_FHD, DW_CONV_SRC_PARALLEL>();
	dw_conv_image_dst *dst_dw_conv = CreateImage<dw_conv_image_dst, PIXELS_FHD, DW_CONV_DST_PARALLEL>();

	// Create random data
	for (vx_uint32 i = 0; i < PIXELS_FHD; i++)
	{
		vx_uint8 a = rand() % 256;
		vx_uint8 b = rand() % 256;
		vx_uint8 c = rand() % 256;
		vx_uint8 d = rand() % 256;
		((vx_uint8 *)(src_fhd_u8_a))[i] = a;
		((vx_uint8 *)(src_fhd_u8_b))[i] = b;
		((vx_uint8 *)(src_fhd_u8_c))[i] = c;
		((vx_uint8 *)(src_fhd_u8_d))[i] = d;
		((bit_depth_src_type *)(src_bitdepth))[i] = a;
		((multicast_type *)(src_multicast))[i] = a;
		((dw_conv_type *)(src_dw_conv))[i] = d;
		if (i < CHANNEL_SIZE)
			((channel_type *)(src_channel))[i] = a;
	}

	// Compute
	HwChannelCombine(src_fhd_u8_a, src_fhd_u8_b, src_fhd_u8_c, src_fhd_u8_d, dst_channel);
	HwChannelExtract(src_channel, dst_fhd_u8_a);
	HwColourConversion(src_channel, dst_fhd_u8_a);
	HwConvertBitDepth(src_bitdepth, dst_bitdepth);
	HwDataWidthConverter(src_dw_conv, dst_dw_conv);
	HwScaleImage(src_fhd_u8_a, dst_hd_u8_a);
	HwMulticast(src_multicast, dst1_multicast, dst2_multicast);

	// Free memory
	DestroyImage<conversion_u8_image>(src_fhd_u8_a);
	DestroyImage<conversion_u8_image>(src_fhd_u8_b);
	DestroyImage<conversion_u8_image>(src_fhd_u8_c);
	DestroyImage<conversion_u8_image>(src_fhd_u8_d);
	DestroyImage<conversion_u8_image>(dst_fhd_u8_a);
	DestroyImage<conversion_u8_image>(dst_hd_u8_a);
	DestroyImage<channel_image>(src_channel);
	DestroyImage<channel_image>(dst_channel);
	DestroyImage<bit_depth_src_image>(src_bitdepth);
	DestroyImage<bit_depth_dst_image>(dst_bitdepth);
	DestroyImage<multicast_image>(src_multicast);
	DestroyImage<multicast_image>(dst1_multicast);
	DestroyImage<multicast_image>(dst2_multicast);
	DestroyImage<dw_conv_image_src>(src_dw_conv);
	DestroyImage<dw_conv_image_dst>(dst_dw_conv);
}

/***************************************************************************************************************************************************/
/* Accelerated Analysis functions */
/***************************************************************************************************************************************************/

// Defines
#define CONTROL_FLOW_OP (vx_scalar_operation_e) VX_SCALAR_OP_GREATER
#define HIST_BINS 256
#define HIST_OFFSET 0
#define HIST_RANGE (1 << 8) // (1 << 8), (1 << 16)
#define MIN_MAX_CAPACITY 32

// Typedefs
typedef vx_uint8 controlflow_src_type; // all
typedef vx_uint8 controlflow_dst_type; // all
typedef vx_uint8 hist_type;			   // vx_uint8, vx_uint16
typedef vx_uint8 analysis_type;		   // vx_uint8, vx_uint16, vx_int8, vx_int16
#if (VEC_NUM == 1 && defined(__SDSCC__))
typedef vx_uint8 analysis_u8_image;
typedef vx_uint16 analysis_u16_image;
typedef vx_uint32 analysis_u32_image;
typedef vx_float32 analysis_f32_image;
typedef controlflow_src_type controlflow_src_image;
typedef controlflow_dst_type controlflow_dst_image;
typedef hist_type hist_image;
typedef analysis_type analysis_image;
#else
typedef vx_image_data<vx_uint8, 1> analysis_u8_image;
typedef vx_image_data<vx_uint16, 1> analysis_u16_image;
typedef vx_image_data<vx_uint32, 1> analysis_u32_image;
typedef vx_image_data<vx_float32, 1> analysis_f32_image;
typedef vx_image_data<controlflow_src_type, 1> controlflow_src_image;
typedef vx_image_data<controlflow_dst_type, 1> controlflow_dst_image;
typedef vx_image_data<hist_type, 1> hist_image;
typedef vx_image_data<analysis_type, 1> analysis_image;
#endif
typedef vx_image_data<vx_uint16, 2> coordinates_image;

// These features allow for conditional graph flow in OpenVX, via support for a variety of operations between two scalars.
void HwControlFlow(controlflow_src_image a[1], controlflow_src_image b[1], controlflow_dst_image output[1])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = a
#pragma HLS INTERFACE axis port = b
#pragma HLS INTERFACE axis port = output
	ImgControlFlow<controlflow_src_type, controlflow_dst_type, CONTROL_FLOW_OP>(a, b, output);
}

// Equalizes the histogram of a grayscale image. The output image dimensions should be the same as the dimensions of the input image.
void HwEqualizeHist(analysis_u8_image input1[PIXELS_FHD], analysis_u8_image input2[PIXELS_FHD], analysis_u32_image output[PIXELS_FHD])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input1
#pragma HLS INTERFACE axis port = input2
#pragma HLS INTERFACE axis port = output
	ImgEqualizeHist<PIXELS_FHD>(input1, input2, output);
}

// Generates a distribution from an image.
void HwHistogram(hist_image input[PIXELS_FHD], analysis_u32_image output[HIST_BINS])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
	ImgHistogram<hist_type, PIXELS_FHD, HIST_BINS, HIST_RANGE, HIST_OFFSET>(input, output);
}

// Computes the integral image of the input.
void HwIntegral(analysis_u8_image input[PIXELS_FHD], analysis_u32_image output[PIXELS_FHD])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
	ImgIntegral<COLS_FHD, ROWS_FHD>(input, output);
}

// Computes the mean pixel value and the standard deviation of the pixels in the input image (which has a dimension width and height).
void HwMeanStdDev1(analysis_image input1[PIXELS_FHD], analysis_f32_image mean[1], analysis_image input2[PIXELS_FHD], analysis_f32_image stddev[1])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input1
#pragma HLS INTERFACE axis port = mean
#pragma HLS INTERFACE axis port = input2
#pragma HLS INTERFACE axis port = stddev
	ImgMeanStdDev<analysis_type, COLS_FHD, ROWS_FHD>(input1, mean, input2, stddev);
}

// Computes the mean pixel value and the standard deviation of the pixels in the input image (which has a dimension width and height).
void HwMeanStdDev2(analysis_image input1[PIXELS_FHD], analysis_f32_image mean[1])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input1
#pragma HLS INTERFACE axis port = mean
	ImgMeanStdDev<analysis_type, COLS_FHD, ROWS_FHD>(input1, mean);
}

// Finds the minimum and maximum values in an image and a location for each. If the input image has several minimums/maximums, the kernel returns all of them.
void HwMinMaxLocation1(analysis_image input[PIXELS_FHD], analysis_image min_val[1], analysis_image max_val[1], coordinates_image min_loc[MIN_MAX_CAPACITY], coordinates_image max_loc[MIN_MAX_CAPACITY], analysis_u16_image min_count[1], analysis_u16_image max_count[1])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = min_val
#pragma HLS INTERFACE axis port = max_val
#pragma HLS INTERFACE axis port = min_loc
#pragma HLS INTERFACE axis port = max_loc
#pragma HLS INTERFACE axis port = min_count
#pragma HLS INTERFACE axis port = max_count
	ImgMinMaxLocation<analysis_type, COLS_FHD, ROWS_FHD, MIN_MAX_CAPACITY>(input, min_val, max_val, min_loc, max_loc, min_count, max_count);
}

// Finds the minimum and maximum values in an image and a location for each. If the input image has several minimums/maximums, the kernel returns all of them.
void HwMinMaxLocation2(analysis_image input[PIXELS_FHD], analysis_image min_val[1], analysis_image max_val[1])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = min_val
#pragma HLS INTERFACE axis port = max_val
	ImgMinMaxLocation<analysis_type, COLS_FHD, ROWS_FHD>(input, min_val, max_val);
}

// Implements the Table Lookup Image Kernel.
void HwTableLookup(hist_image input[PIXELS_FHD], hist_image lut[HIST_BINS], hist_image output[PIXELS_FHD])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#endif
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = lut
#pragma HLS INTERFACE axis port = output
	ImgTableLookup<hist_type, PIXELS_FHD, HIST_BINS, HIST_OFFSET>(input, lut, output);
}

/*********************************************************************************************************************/
// Test the conversion algorithms
void TestAnalysisFunctions()
{

	// Allocate memory
	controlflow_src_image *src1_controlflow = CreateImage<controlflow_src_image, 1, 1>();
	controlflow_src_image *src2_controlflow = CreateImage<controlflow_src_image, 1, 1>();
	controlflow_dst_image *dst1_controlflow = CreateImage<controlflow_dst_image, 1, 1>();
	analysis_u8_image *src1_analysis_u8 = CreateImage<analysis_u8_image, PIXELS_FHD, 1>();
	analysis_u8_image *src2_analysis_u8 = CreateImage<analysis_u8_image, PIXELS_FHD, 1>();
	hist_image *src1_histogram = CreateImage<hist_image, PIXELS_FHD, 1>();
	hist_image *src2_histogram = CreateImage<hist_image, HIST_BINS, 1>();
	hist_image *dst1_histogram = CreateImage<hist_image, PIXELS_FHD, 1>();
	analysis_u32_image *dst1_analysis_u32 = CreateImage<analysis_u32_image, PIXELS_FHD, 1>();
	analysis_u32_image *dst2_analysis_u32 = CreateImage<analysis_u32_image, HIST_BINS, 1>();
	analysis_image *src1_analysis = CreateImage<analysis_image, PIXELS_FHD, 1>();
	analysis_image *dst1_analysis = CreateImage<analysis_image, 1, 1>();
	analysis_image *dst2_analysis = CreateImage<analysis_image, 1, 1>();
	coordinates_image *dst1_coordinates = CreateImage<coordinates_image, MIN_MAX_CAPACITY, 1>();
	coordinates_image *dst2_coordinates = CreateImage<coordinates_image, MIN_MAX_CAPACITY, 1>();
	analysis_u16_image *dst1_analysis_u16 = CreateImage<analysis_u16_image, MIN_MAX_CAPACITY, 1>();
	analysis_u16_image *dst2_analysis_u16 = CreateImage<analysis_u16_image, MIN_MAX_CAPACITY, 1>();
	analysis_f32_image *dst1_analysis_f32 = CreateImage<analysis_f32_image, 1, 1>();
	analysis_f32_image *dst2_analysis_f32 = CreateImage<analysis_f32_image, 1, 1>();

	// Create random data
	for (vx_uint32 i = 0; i < PIXELS_FHD; i++)
	{
		vx_uint8 a = rand() % 256;
		vx_uint8 b = rand() % 256;
		if (i == 0)
		{
			((controlflow_src_type *)(src1_controlflow))[i] = a;
			((controlflow_src_type *)(src2_controlflow))[i] = b;
		}
		((vx_uint8 *)(src1_analysis_u8))[i] = a;
		((vx_uint8 *)(src2_analysis_u8))[i] = b;
		((hist_type *)(src1_histogram))[i] = a;
		if (i < HIST_BINS)
		{
			((hist_type *)(src2_histogram))[i] = b;
		}
	}

	// Compute
	HwControlFlow(src1_controlflow, src2_controlflow, dst1_controlflow);
	HwEqualizeHist(src1_analysis_u8, src1_analysis_u8, dst1_analysis_u32);
	HwHistogram(src1_histogram, dst2_analysis_u32);
	HwIntegral(src1_analysis_u8, dst1_analysis_u32);
	HwMeanStdDev1(src1_analysis, dst1_analysis_f32, src1_analysis, dst2_analysis_f32);
	HwMeanStdDev2(src1_analysis, dst1_analysis_f32);
	HwMinMaxLocation1(src1_analysis, dst1_analysis, dst2_analysis, dst1_coordinates, dst2_coordinates, dst1_analysis_u16, dst2_analysis_u16);
	HwMinMaxLocation2(src1_analysis, dst1_analysis, dst2_analysis);
	HwTableLookup(src1_histogram, src2_histogram, dst1_histogram);

	// Free memory
	DestroyImage<controlflow_src_image>(src1_controlflow);
	DestroyImage<controlflow_src_image>(src2_controlflow);
	DestroyImage<controlflow_dst_image>(dst1_controlflow);
	DestroyImage<analysis_u8_image>(src1_analysis_u8);
	DestroyImage<analysis_u8_image>(src2_analysis_u8);
	DestroyImage<hist_image>(src1_histogram);
	DestroyImage<hist_image>(src2_histogram);
	DestroyImage<hist_image>(dst1_histogram);
	DestroyImage<analysis_u32_image>(dst1_analysis_u32);
	DestroyImage<analysis_u32_image>(dst2_analysis_u32);
	DestroyImage<analysis_image>(src1_analysis);
	DestroyImage<analysis_image>(dst1_analysis);
	DestroyImage<analysis_image>(dst2_analysis);
	DestroyImage<coordinates_image>(dst1_coordinates);
	DestroyImage<coordinates_image>(dst2_coordinates);
	DestroyImage<analysis_u16_image>(dst1_analysis_u16);
	DestroyImage<analysis_u16_image>(dst2_analysis_u16);
	DestroyImage<analysis_f32_image>(dst1_analysis_f32);
	DestroyImage<analysis_f32_image>(dst2_analysis_f32);
}

/***************************************************************************************************************************************************/
/* Example Applications. (including loop level parallelism) */
/***************************************************************************************************************************************************/

/*********************************************************/
// Image Structure & Data Types
const vx_uint32 APP_COLS = 850;
const vx_uint32 APP_ROWS = 680;
const vx_uint32 APP_PIXELS = APP_COLS * APP_ROWS;
const vx_uint32 APP_VEC_NUM = 1;
const vx_uint32 APP_VEC_PIX = APP_PIXELS / APP_VEC_NUM;
const vx_border_e APP_BORDER_TYPE = VX_BORDER_CONSTANT;
const vx_uint32 APP_GAUSSIAN_KERNEL = 7;
typedef vx_uint8 app_u_type;
typedef vx_int8 app_s_type;

#if (APP_VEC_NUM == 1 && defined(__SDSCC__))
typedef app_u_type app_u_image;
typedef app_s_type app_s_image;
#else
typedef vx_image_data<app_u_type, APP_VEC_NUM> app_u_image;
typedef vx_image_data<app_s_type, APP_VEC_NUM> app_s_image;
#endif

/*********************************************************/
// 5x5 Median Filter
#pragma SDS data access_pattern(input                \
								: SEQUENTIAL, output \
								: SEQUENTIAL)
void ExampleApp0(app_u_image input[APP_VEC_PIX], app_u_image output[APP_VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
#endif
	ImgMedian<app_u_type, APP_VEC_NUM, APP_COLS, APP_ROWS, 5, APP_BORDER_TYPE>(input, output);
}

/*********************************************************/
// 7x7 Gaussian Filter
#pragma SDS data access_pattern(input                \
								: SEQUENTIAL, output \
								: SEQUENTIAL)
void ExampleApp1(app_u_image input[APP_VEC_PIX], app_u_image output[APP_VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
#endif
	ImgGaussian<app_u_type, APP_VEC_NUM, APP_COLS, APP_ROWS, APP_GAUSSIAN_KERNEL, APP_BORDER_TYPE, vx_true_e>(input, output);
}

/*********************************************************/
// Smoothed Gradient Magnitude
#pragma SDS data access_pattern(input                \
								: SEQUENTIAL, output \
								: SEQUENTIAL)
void ExampleApp2(app_u_image input[APP_VEC_PIX], app_u_image output[APP_VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
#endif

	// FIFOs to stream data between functions
#ifdef __XILINX__
	app_u_image ls[APP_VEC_PIX];
#pragma HLS STREAM variable = ls depth = 16
#pragma HLS data_pack variable = ls
	app_s_image lx[APP_VEC_PIX];
#pragma HLS STREAM variable = lx depth = 16
#pragma HLS data_pack variable = lx
	app_s_image ly[APP_VEC_PIX];
#pragma HLS STREAM variable = ly depth = 16
#pragma HLS data_pack variable = ly
	app_s_image lm[APP_VEC_PIX];
#pragma HLS STREAM variable = lm depth = 16
#pragma HLS data_pack variable = lm
#else
	app_u_image *ls = new app_u_image[APP_VEC_PIX];
	app_s_image *lx = new app_s_image[APP_VEC_PIX];
	app_s_image *ly = new app_s_image[APP_VEC_PIX];
	app_s_image *lm = new app_s_image[APP_VEC_PIX];
#endif

	// Computation
#pragma HLS DATAFLOW
	ImgGaussian<app_u_type, APP_VEC_NUM, APP_COLS, APP_ROWS, APP_GAUSSIAN_KERNEL, APP_BORDER_TYPE, vx_true_e>(input, ls);
	ImgSobel<app_u_type, app_s_type, APP_VEC_NUM, APP_COLS, APP_ROWS, 3, APP_BORDER_TYPE>(ls, lx, ly);
	ImgMagnitude<app_s_type, APP_VEC_NUM, APP_PIXELS, VX_ROUND_POLICY_TO_ZERO>(lx, ly, lm);
	ImgConvertBitDepth<app_s_type, app_u_type, APP_VEC_NUM, APP_PIXELS, VX_CONVERT_POLICY_SATURATE, (vx_uint16)0>(lm, output);

	// Free Memory
#ifndef __XILINX__
	delete[] ls;
	delete[] lx;
	delete[] ly;
	delete[] lm;
#endif
}

/*********************************************************/
// Edge Detector
#pragma SDS data access_pattern(input                \
								: SEQUENTIAL, output \
								: SEQUENTIAL)
void ExampleApp3(app_u_image input[APP_VEC_PIX], app_u_image output[APP_VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
#endif

	// FIFOs to stream data between functions
#ifdef __XILINX__
	app_u_image ls[APP_VEC_PIX];
#pragma HLS STREAM variable = ls depth = 16
#pragma HLS data_pack variable = ls
	app_s_image lx[APP_VEC_PIX];
#pragma HLS STREAM variable = lx depth = 16
#pragma HLS data_pack variable = lx
	app_s_image ly[APP_VEC_PIX];
#pragma HLS STREAM variable = ly depth = 16
#pragma HLS data_pack variable = ly
	app_s_image lm[APP_VEC_PIX];
#pragma HLS STREAM variable = lm depth = 16
#pragma HLS data_pack variable = lm
	app_u_image lb[APP_VEC_PIX];
#pragma HLS STREAM variable = lb depth = 16
#pragma HLS data_pack variable = lb
#else
	app_u_image *ls = new app_u_image[APP_VEC_PIX];
	app_s_image *lx = new app_s_image[APP_VEC_PIX];
	app_s_image *ly = new app_s_image[APP_VEC_PIX];
	app_s_image *lm = new app_s_image[APP_VEC_PIX];
	app_u_image *lb = new app_u_image[APP_VEC_PIX];
#endif

	// Computation
#pragma HLS DATAFLOW
	ImgGaussian<app_u_type, APP_VEC_NUM, APP_COLS, APP_ROWS, APP_GAUSSIAN_KERNEL, APP_BORDER_TYPE, vx_true_e>(input, ls);
	ImgSobel<app_u_type, app_s_type, APP_VEC_NUM, APP_COLS, APP_ROWS, 3, APP_BORDER_TYPE>(ls, lx, ly);
	ImgMagnitude<app_s_type, APP_VEC_NUM, APP_PIXELS, VX_ROUND_POLICY_TO_ZERO>(lx, ly, lm);
	ImgConvertBitDepth<app_s_type, app_u_type, APP_VEC_NUM, APP_PIXELS, VX_CONVERT_POLICY_SATURATE, (vx_uint16)0>(lm, lb);
	ImgHysteresis<app_u_type, APP_VEC_NUM, APP_COLS, APP_ROWS, 3, APP_BORDER_TYPE, 25, 35>(lb, output);

	// Free Memory
#ifndef __XILINX__
	delete[] ls;
	delete[] lx;
	delete[] ly;
	delete[] lm;
	delete[] lb;
#endif
}

/*********************************************************/
// Corner Detector
#pragma SDS data access_pattern(input                \
								: SEQUENTIAL, output \
								: SEQUENTIAL)
void ExampleApp4(app_u_image input[APP_VEC_PIX], app_u_image output[APP_VEC_PIX])
{
#ifndef __SDSCC__
#pragma HLS interface ap_ctrl_none port = return
#pragma HLS INTERFACE axis port = input
#pragma HLS INTERFACE axis port = output
#endif

	// FIFOs to stream data between functions
#ifdef __XILINX__
	app_u_image ls[APP_VEC_PIX];
#pragma HLS STREAM variable = ls depth = 16
#pragma HLS data_pack variable = ls
	app_u_image lf[APP_VEC_PIX];
#pragma HLS STREAM variable = lf depth = 1
#pragma HLS data_pack variable = lf
#else
	app_u_image *ls = new app_u_image[APP_VEC_PIX];
	app_u_image *lf = new app_u_image[APP_VEC_PIX];
#endif

	// Computation
#pragma HLS DATAFLOW
	ImgGaussian<app_u_type, APP_VEC_NUM, APP_COLS, APP_ROWS, APP_GAUSSIAN_KERNEL, APP_BORDER_TYPE, vx_true_e>(input, ls);
	ImgSegmentTestDetector<app_u_type, APP_VEC_NUM, APP_COLS, APP_ROWS, APP_BORDER_TYPE>(ls, lf);
	ImgHysteresis<app_u_type, APP_VEC_NUM, APP_COLS, APP_ROWS, 3, APP_BORDER_TYPE, 10, 40>(lf, output);

	// Free Memory
#ifndef __XILINX__
	delete[] ls;
	delete[] lf;
#endif
}

/*********************************************************/
// Test all example applications with an image
void TestExampleApplications()
{
#ifndef __XILINX__

	// Create data structures
	struct PgmImage *image1 = new PgmImage;
	struct PgmImage *image2 = new PgmImage;

	// Allocate
	image1->matrix = new app_u_type[APP_COLS * APP_ROWS];
	image2->matrix = new app_u_type[APP_COLS * APP_ROWS];

	// Read input
	if (APP_COLS == 850 && APP_ROWS == 680)
		ReadPgm("img1.pgm", image1);

	// Set image data
	CopyImageMetaData(image1, image2);

	// Test all applications and write output to file
	for (vx_uint16 i = 0; i < 6; ++i)
	{
		if (i == 0)
		{
			ExampleApp0((app_u_image *)(image1->matrix), (app_u_image *)(image2->matrix));
			if (APP_COLS == 850 && APP_ROWS == 680)
				WritePgm("out1.pgm", image2);
		}
		else if (i == 1)
		{
			ExampleApp1((app_u_image *)(image1->matrix), (app_u_image *)(image2->matrix));
			if (APP_COLS == 850 && APP_ROWS == 680)
				WritePgm("out2.pgm", image2);
		}
		else if (i == 2)
		{
			ExampleApp2((app_u_image *)(image1->matrix), (app_u_image *)(image2->matrix));
			if (APP_COLS == 850 && APP_ROWS == 680)
				WritePgm("out3.pgm", image2);
		}
		else if (i == 3)
		{
			ExampleApp3((app_u_image *)(image1->matrix), (app_u_image *)(image2->matrix));
			if (APP_COLS == 850 && APP_ROWS == 680)
				WritePgm("out4.pgm", image2);
		}
		else if (i == 4)
		{
			ExampleApp4((app_u_image *)(image1->matrix), (app_u_image *)(image2->matrix));
			if (APP_COLS == 850 && APP_ROWS == 680)
				WritePgm("out5.pgm", image2);
		}
	}

	// Deallocate
	delete[] image1->matrix;
	delete[] image2->matrix;
#endif
}

/*********************************************************************************************************************/
/* Main function */
/*********************************************************************************************************************/
int main(void)
{

	// Verification
#ifndef __SDSCC__
	// SwTestPixelopMain();
	// TestFilterMain();
#endif

	// Simple testing
	TestPixelwiseFunctions();
	TestFilterFunctions();
	TestConversionFunctions(),
		TestAnalysisFunctions();
	TestExampleApplications();

	printf("Finished\n");
	return 0;
}
