/*============================================================================*/
/*                        IMAQ Vision                                         */
/*----------------------------------------------------------------------------*/
/*    Copyright (c) National Instruments 2001.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Title:       NIVision.h                                                    */
/*                                                                            */
/*============================================================================*/
#if !defined(NiVision_h)
#define NiVision_h

//============================================================================
//  Control Defines
//============================================================================
#if !defined(IMAQ_FUNC)
    #if !defined(__cplusplus)
        #define IMAQ_FUNC __declspec(dllimport)
    #else
        #define IMAQ_FUNC extern "C" __declspec(dllimport)
    #endif
#endif

#ifdef _CVI_
#pragma EnableLibraryRuntimeChecking
#endif

#define IMAQ_CALLBACK __cdecl

//============================================================================
//  Manifest Constants
//============================================================================
#ifndef NULL
    #ifdef __cplusplus
        #define NULL    0
    #else
        #define NULL    ((void *)0)
    #endif
#endif

#ifndef FALSE
    #define FALSE               0
#endif

#ifndef TRUE
    #define TRUE                1
#endif

#define IMAQ_DEFAULT_SHOW_COORDINATES TRUE
#define IMAQ_DEFAULT_MAX_ICONS_PER_LINE 4
#define IMAQ_DEFAULT_LEARNING_MODE IMAQ_LEARN_SHIFT_INFORMATION
#define IMAQ_DEFAULT_BMP_COMPRESS FALSE
#define IMAQ_DEFAULT_PNG_QUALITY 750
#define IMAQ_DEFAULT_JPEG_QUALITY 750
#define IMAQ_ALL_CONTOURS -1
#define IMAQ_ALL_WINDOWS -1
#define IMAQ_SHIFT      1
#define IMAQ_ALT        2
#define IMAQ_CTRL       4
#define IMAQ_CAPS_LOCK  8
#define IMAQ_MODAL_DIALOG -1
#define IMAQ_INIT_RGB_TRANSPARENT {   0,   0,   0, 1 }
#define IMAQ_INIT_RGB_RED         {   0,   0, 255, 0 }
#define IMAQ_INIT_RGB_BLUE        { 255,   0,   0, 0 }
#define IMAQ_INIT_RGB_GREEN       {   0, 255,   0, 0 }
#define IMAQ_INIT_RGB_YELLOW      {   0, 255, 255, 0 }
#define IMAQ_INIT_RGB_WHITE       { 255, 255, 255, 0 }
#define IMAQ_INIT_RGB_BLACK       {   0,   0,   0, 0 }
#define IMAQ_USE_DEFAULT_QUALITY  -1
#define IMAQ_ALL_SAMPLES          -1
#define IMAQ_ALL_OBJECTS          -1
#define IMAQ_ALL_CHARACTERS       -1

//============================================================================
//  Predefined Valid Characters
//============================================================================
#define IMAQ_ANY_CHARACTER          ""                                                                  //Any Character
#define IMAQ_ALPHABETIC             "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"              //Alphabetic
#define IMAQ_ALPHANUMERIC           "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"    //Alphanumeric
#define IMAQ_UPPERCASE_LETTERS      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"                                        //Uppercase Letters
#define IMAQ_LOWERCASE_LETTERS      "abcdefghijklmnopqrstuvwxyz"                                        //Lowercase Letters
#define IMAQ_DECIMAL_DIGITS         "0123456789"                                                        //Decimal Digits
#define IMAQ_HEXADECIMAL_DIGITS     "0123456789ABCDEFabcdef"                                            //Hexadecimal Digits
#define IMAQ_PATTERN                "\xFF"                                                              //Pattern (A single character string with the character value set to 255)
#define IMAQ_FORCE_SPACE            " "                                                                 //Force Space

//============================================================================
//  Macros
//============================================================================
#define IMAQ_NO_RECT imaqMakeRect( 0, 0, 0x7FFFFFFF, 0x7FFFFFFF)
#define IMAQ_NO_ROTATED_RECT imaqMakeRotatedRect( 0, 0, 0x7FFFFFFF, 0x7FFFFFFF, 0)
#define IMAQ_NO_POINT imaqMakePoint( -1, -1)
#define IMAQ_NO_POINT_FLOAT imaqMakePointFloat( -1.0, -1.0 )
#define IMAQ_NO_OFFSET imaqMakePointFloat( 0.0, 0.0 )



//============================================================================
//  When in Borland, some functions must be mapped to different names.
//  This accomplishes said task.
//============================================================================
#if defined(__BORLANDC__) || (defined(_CVI_) && defined(_NI_BC_))
    #define imaqMakePoint imaqMakePoint_BC
    #define imaqMakePointFloat imaqMakePointFloat_BC
#endif


//============================================================================
//  When in Watcom, some functions must be mapped to different names.
//  This accomplishes said task.
//============================================================================
#if defined(__WATCOMC__) || (defined(_CVI_) && defined(_NI_WC_))
    #define imaqMakePoint imaqMakePoint_BC
    #define imaqMakePointFloat imaqMakePointFloat_BC
#endif

//============================================================================
//  If using Visual C++, force startup & shutdown code to run.
//============================================================================
#if defined(_MSC_VER) && !defined(_CVI_) && !defined(__BORLANDC__)
    #pragma comment(linker, "/INCLUDE:_nivision_startup_shutdown")
    #pragma comment(linker, "/DEFAULTLIB:nivision.lib")
#endif

//============================================================================
//  Error Codes
//============================================================================
#define ERR_SUCCESS                                                  0 // No error.
#define ERR_SYSTEM_ERROR                                             -1074396160 // System error.
#define ERR_OUT_OF_MEMORY                                            -1074396159 // Not enough memory for requested operation.
#define ERR_MEMORY_ERROR                                             -1074396158 // Memory error.
#define ERR_UNREGISTERED                                             -1074396157 // Unlicensed copy of NI Vision.
#define ERR_NEED_FULL_VERSION                                        -1074396156 // The function requires an NI Vision 5.0 Advanced license.
#define ERR_UNINIT                                                   -1074396155 // NI Vision did not initialize properly.
#define ERR_IMAGE_TOO_SMALL                                          -1074396154 // The image is not large enough for the operation.
#define ERR_BARCODE_CODABAR                                          -1074396153 // The barcode is not a valid Codabar barcode.
#define ERR_BARCODE_CODE39                                           -1074396152 // The barcode is not a valid Code 3 of 9 barcode.
#define ERR_BARCODE_CODE93                                           -1074396151 // The barcode is not a valid Code93 barcode.
#define ERR_BARCODE_CODE128                                          -1074396150 // The barcode is not a valid Code128 barcode.
#define ERR_BARCODE_EAN8                                             -1074396149 // The barcode is not a valid EAN8 barcode.
#define ERR_BARCODE_EAN13                                            -1074396148 // The barcode is not a valid EAN13 barcode.
#define ERR_BARCODE_I25                                              -1074396147 // The barcode is not a valid Interleaved 2 of 5 barcode.
#define ERR_BARCODE_MSI                                              -1074396146 // The barcode is not a valid MSI barcode.
#define ERR_BARCODE_UPCA                                             -1074396145 // The barcode is not a valid UPCA barcode.
#define ERR_BARCODE_CODE93_SHIFT                                     -1074396144 // The Code93 barcode contains invalid shift encoding.
#define ERR_BARCODE_TYPE                                             -1074396143 // The barcode type is invalid.
#define ERR_BARCODE_INVALID                                          -1074396142 // The image does not represent a valid linear barcode.
#define ERR_BARCODE_CODE128_FNC                                      -1074396141 // The FNC value in the Code128 barcode is not located before the first data value.
#define ERR_BARCODE_CODE128_SET                                      -1074396140 // The starting code set in the Code128 barcode is not valid.
#define ERR_ROLLBACK_RESOURCE_OUT_OF_MEMORY                          -1074396139 // Not enough reserved memory in the timed environment for the requested operation.
#define ERR_ROLLBACK_NOT_SUPPORTED                                   -1074396138 // The function is not supported when a time limit is active.
#define ERR_DIRECTX_DLL_NOT_FOUND                                    -1074396137 // Quartz.dll not found.  Install DirectX 8.1 or later.
#define ERR_DIRECTX_INVALID_FILTER_QUALITY                           -1074396136 // The filter quality you provided is invalid. Valid quality values range from -1 to 1000.
#define ERR_INVALID_BUTTON_LABEL                                     -1074396135 // Invalid button label.
#define ERR_THREAD_INITIALIZING                                      -1074396134 // Could not execute the function in the separate thread because the thread has not completed initialization.
#define ERR_THREAD_COULD_NOT_INITIALIZE                              -1074396133 // Could not execute the function in the separate thread because the thread could not initialize.
#define ERR_NOT_RECT_OR_ROTATED_RECT                                 -1074396130 // The ROI must only have either a single Rectangle contour or a single Rotated Rectangle contour.
#define ERR_ROLLBACK_UNBOUNDED_INTERFACE                             -1074396129 // During timed execution, you must use the preallocated version of this operation.
#define ERR_ROLLBACK_RESOURCE_CONFLICT_3                             -1074396128 // An image being modified by one process cannot be requested by another process while a time limit is active.
#define ERR_ROLLBACK_RESOURCE_CONFLICT_2                             -1074396127 // An image with pattern matching, calibration, or overlay information cannot be manipulated while a time limit is active.
#define ERR_ROLLBACK_RESOURCE_CONFLICT_1                             -1074396126 // An image created before a time limit is started cannot be resized while a time limit is active.
#define ERR_INVALID_CONTRAST_THRESHOLD                               -1074396125 // Invalid contrast threshold. The threshold value must be greater than 0. 
#define ERR_INVALID_CALIBRATION_ROI_MODE                             -1074396124 // NI Vision does not support the calibration ROI mode you supplied.
#define ERR_INVALID_CALIBRATION_MODE                                 -1074396123 // NI Vision does not support the calibration mode you supplied.
#define ERR_DRAWTEXT_COLOR_MUST_BE_GRAYSCALE                         -1074396122 // Set the foreground and background text colors to grayscale to draw on a U8 image.
#define ERR_SATURATION_THRESHOLD_OUT_OF_RANGE                        -1074396121 // The value of the saturation threshold must be from 0 to 255.
#define ERR_NOT_IMAGE                                                -1074396120 // Not an image.
#define ERR_MATRIX_SIZE                                              -1074396117 // Invalid matrix size in the structuring element.
#define ERR_CALIBRATION_INSF_POINTS                                  -1074396116 // Insufficient number of calibration feature points.
#define ERR_CALIBRATION_IMAGE_CORRECTED                              -1074396115 // The operation is invalid in a corrected image.
#define ERR_CALIBRATION_INVALID_ROI                                  -1074396114 // The ROI contains an invalid contour type or is not contained in the ROI learned for calibration.
#define ERR_CALIBRATION_IMAGE_UNCALIBRATED                           -1074396113 // The source/input image has not been calibrated.
#define ERR_INCOMP_MATRIX_SIZE                                       -1074396112 // The number of pixel and real-world coordinates must be equal.
#define ERR_CALIBRATION_FAILED_TO_FIND_GRID                          -1074396111 // Unable to automatically detect grid because the image is too distorted.
#define ERR_CALIBRATION_INFO_VERSION                                 -1074396110 // Invalid calibration information version.
#define ERR_CALIBRATION_INVALID_SCALING_FACTOR                       -1074396109 // Invalid calibration scaling factor.
#define ERR_CALIBRATION_ERRORMAP                                     -1074396108 // The calibration error map cannot be computed.
#define ERR_CALIBRATION_INFO_1                                       -1074396107 // Invalid calibration template image.
#define ERR_CALIBRATION_INFO_2                                       -1074396106 // Invalid calibration template image.
#define ERR_CALIBRATION_INFO_3                                       -1074396105 // Invalid calibration template image.
#define ERR_CALIBRATION_INFO_4                                       -1074396104 // Invalid calibration template image.
#define ERR_CALIBRATION_INFO_5                                       -1074396103 // Invalid calibration template image.
#define ERR_CALIBRATION_INFO_6                                       -1074396102 // Invalid calibration template image.
#define ERR_CALIBRATION_INFO_MICRO_PLANE                             -1074396101 // Invalid calibration template image.
#define ERR_CALIBRATION_INFO_PERSPECTIVE_PROJECTION                  -1074396100 // Invalid calibration template image.
#define ERR_CALIBRATION_INFO_SIMPLE_TRANSFORM                        -1074396099 // Invalid calibration template image.
#define ERR_RESERVED_MUST_BE_NULL                                    -1074396098 // You must pass NULL for the reserved parameter.
#define ERR_INVALID_PARTICLE_PARAMETER_VALUE                         -1074396097 // You entered an invalid selection in the particle parameter.
#define ERR_NOT_AN_OBJECT                                            -1074396096 // Not an object.
#define ERR_CALIBRATION_DUPLICATE_REFERENCE_POINT                    -1074396095 // The reference points passed are inconsistent.  At least two similar pixel coordinates correspond to different real-world coordinates.
#define ERR_ROLLBACK_RESOURCE_CANNOT_UNLOCK                          -1074396094 // A resource conflict occurred in the timed environment. Two processes cannot manage the same resource and be time bounded.
#define ERR_ROLLBACK_RESOURCE_LOCKED                                 -1074396093 // A resource conflict occurred in the timed environment. Two processes cannot access the same resource and be time bounded.
#define ERR_ROLLBACK_RESOURCE_NON_EMPTY_INITIALIZE                   -1074396092 // Multiple timed environments are not supported.
#define ERR_ROLLBACK_RESOURCE_UNINITIALIZED_ENABLE                   -1074396091 // A time limit cannot be started until the timed environment is initialized.
#define ERR_ROLLBACK_RESOURCE_ENABLED                                -1074396090 // Multiple timed environments are not supported.
#define ERR_ROLLBACK_RESOURCE_REINITIALIZE                           -1074396089 // The timed environment is already initialized.
#define ERR_ROLLBACK_RESIZE                                          -1074396088 // The results of the operation exceeded the size limits on the output data arrays.
#define ERR_ROLLBACK_STOP_TIMER                                      -1074396087 // No time limit is available to stop.
#define ERR_ROLLBACK_START_TIMER                                     -1074396086 // A time limit could not be set.
#define ERR_ROLLBACK_INIT_TIMER                                      -1074396085 // The timed environment could not be initialized.
#define ERR_ROLLBACK_DELETE_TIMER                                    -1074396084 // No initialized timed environment is available to close.
#define ERR_ROLLBACK_TIMEOUT                                         -1074396083 // The time limit has expired.
#define ERR_PALETTE_NOT_SUPPORTED                                    -1074396082 // Only 8-bit images support the use of palettes.  Either do not use a palette, or convert your image to an 8-bit image before using a palette.
#define ERR_BAD_PASSWORD                                             -1074396081 // Incorrect password.
#define ERR_INVALID_IMAGE_TYPE                                       -1074396080 // Invalid image type.
#define ERR_INVALID_METAFILE_HANDLE                                  -1074396079 // Invalid metafile handle.
#define ERR_INCOMP_TYPE                                              -1074396077 // Incompatible image type.
#define ERR_INCOMP_SIZE                                              -1074396074 // Incompatible image size.
#define ERR_INVALID_BORDER                                           -1074396072 // Invalid image border.
#define ERR_INVALID_FUNCTION                                         -1074396070 // Unsupported function.
#define ERR_INVALID_COLOR_MODE                                       -1074396069 // NI Vision does not support the color mode you specified.
#define ERR_INVALID_ACTION                                           -1074396068 // The function does not support the requested action.
#define ERR_IMAGES_NOT_DIFF                                          -1074396067 // The source image and destination image must be different.
#define ERR_INVALID_POINTSYMBOL                                      -1074396066 // Invalid point symbol.
#define ERR_CANT_RESIZE_EXTERNAL                                     -1074396065 // Cannot resize an image in an acquisition buffer.
#define ERR_EXTERNAL_NOT_SUPPORTED                                   -1074396064 // This operation is not supported for images in an acquisition buffer.
#define ERR_EXTERNAL_ALIGNMENT                                       -1074396063 // The external buffer must be aligned on a 4-byte boundary. The line width and border pixels must be 4-byte aligned, as well.
#define ERR_INVALID_TOLERANCE                                        -1074396062 // The tolerance parameter must be greater than or equal to 0.
#define ERR_INVALID_WINDOW_SIZE                                      -1074396061 // The size of each dimension of the window must be greater than 2 and less than or equal to the size of the image in the corresponding dimension.
#define ERR_JPEG2000_LOSSLESS_WITH_FLOATING_POINT                    -1074396060 // Lossless compression cannot be used with the floating point wavelet transform mode. Either set the wavelet transform mode to integer, or use lossy compression.
#define ERR_INVALID_MAX_ITERATIONS                                   -1074396059 // Invalid maximum number of iterations. Maximum number of iterations must be greater than zero.
#define ERR_INVALID_ROTATION_MODE                                    -1074396058 // Invalid rotation mode.
#define ERR_INVALID_SEARCH_VECTOR_WIDTH                              -1074396057 // Invalid search vector width. The width must be an odd number greater than zero.
#define ERR_INVALID_MATRIX_MIRROR_MODE                               -1074396056 // Invalid matrix mirror mode.
#define ERR_INVALID_ASPECT_RATIO                                     -1074396055 // Invalid aspect ratio. Valid aspect ratios must be greater than or equal to zero.
#define ERR_INVALID_CELL_FILL_TYPE                                   -1074396054 // Invalid cell fill type.
#define ERR_INVALID_BORDER_INTEGRITY                                 -1074396053 // Invalid borden integrity. Valid values range from 0 to 100.
#define ERR_INVALID_DEMODULATION_MODE                                -1074396052 // Invalid demodulation mode.
#define ERR_INVALID_CELL_FILTER_MODE                                 -1074396051 // Invalid cell filter mode.
#define ERR_INVALID_ECC_TYPE                                         -1074396050 // Invalid ECC type.
#define ERR_INVALID_MATRIX_POLARITY                                  -1074396049 // Invalid matrix polarity.
#define ERR_INVALID_CELL_SAMPLE_SIZE                                 -1074396048 // Invalid cell sample size.
#define ERR_INVALID_LINEAR_AVERAGE_MODE                              -1074396047 // Invalid linear average mode.
#define ERR_INVALID_2D_BARCODE_CONTRAST_FOR_ROI                      -1074396046 // When using a region of interest that is not a rectangle, you must specify the contrast mode of the barcode as either black on white or white on black.
#define ERR_INVALID_2D_BARCODE_SUBTYPE                               -1074396045 // Invalid 2-D barcode Data Matrix subtype.
#define ERR_INVALID_2D_BARCODE_SHAPE                                 -1074396044 // Invalid 2-D barcode shape.
#define ERR_INVALID_2D_BARCODE_CELL_SHAPE                            -1074396043 // Invalid 2-D barcode cell shape.
#define ERR_INVALID_2D_BARCODE_CONTRAST                              -1074396042 // Invalid 2-D barcode contrast.
#define ERR_INVALID_2D_BARCODE_TYPE                                  -1074396041 // Invalid 2-D barcode type.
#define ERR_DRIVER                                                   -1074396040 // Cannot access NI-IMAQ driver.
#define ERR_IO_ERROR                                                 -1074396039 // I/O error.
#define ERR_TIMEOUT                                                  -1074396037 // Trigger timeout.
#define ERR_INVALID_SKELETONMODE                                     -1074396036 // The Skeleton mode you specified is invalid.
#define ERR_TEMPLATEIMAGE_NOCIRCLE                                   -1074396035 // The template image does not contain enough information for learning the aggressive search strategy.
#define ERR_TEMPLATEIMAGE_EDGEINFO                                   -1074396034 // The template image does not contain enough edge information for the sample size(s) requested.
#define ERR_TEMPLATEDESCRIPTOR_LEARNSETUPDATA                        -1074396033 // Invalid template descriptor.
#define ERR_TEMPLATEDESCRIPTOR_ROTATION_SEARCHSTRATEGY               -1074396032 // The template descriptor does not contain data required for the requested search strategy in rotation-invariant matching.
#define ERR_INVALID_KERNEL_SIZE_FOR_EDGE_DETECTION                   -1074396021 // Invalid kernel size for edge detection. The minimum kernel size is 2.
#define ERR_INVALID_GRADING_MODE                                     -1074396020 // Invalid grading mode.
#define ERR_INVALID_THRESHOLD_PERCENTAGE                             -1074396019 // Invalid threshold percentage. Valid values range from 0 to 100.
#define ERR_INVALID_EDGE_POLARITY_SEARCH_MODE                        -1074396018 // Invalid edge polarity search mode.
#define ERR_OPENING_NEWER_AIM_GRADING_DATA                           -1074396017 // The AIM grading data attached to the image you tried to open was created with a newer version of NI Vision. Upgrade to the latest version of NI Vision to read this file.
#define ERR_NO_VIDEO_DRIVER                                          -1074396016 // No video driver is installed.
#define ERR_RPC_EXECUTE_IVB                                          -1074396015 // Unable to establish network connection with remote system.
#define ERR_INVALID_VIDEO_BLIT                                       -1074396014 // RT Video Out does not support displaying the supplied image type at the selected color depth.
#define ERR_INVALID_VIDEO_MODE                                       -1074396013 // Invalid video mode.
#define ERR_RPC_EXECUTE                                              -1074396012 // Unable to display remote image on network connection.
#define ERR_RPC_BIND                                                 -1074396011 // Unable to establish network connection.
#define ERR_INVALID_FRAME_NUMBER                                     -1074396010 // Invalid frame number.
#define ERR_DIRECTX                                                  -1074396009 // An internal DirectX error has occurred.  Try upgrading to the latest version of DirectX.
#define ERR_DIRECTX_NO_FILTER                                        -1074396008 // An appropriate DirectX filter to process this file could not be found.  Install the filter that was used to create this AVI. Upgrading to the latest version of DirectX may correct this error.  NI Vision requires DirectX 8.1 or higher.
#define ERR_DIRECTX_INCOMPATIBLE_COMPRESSION_FILTER                  -1074396007 // Incompatible compression filter.
#define ERR_DIRECTX_UNKNOWN_COMPRESSION_FILTER                       -1074396006 // Unknown compression filter.
#define ERR_INVALID_AVI_SESSION                                      -1074396005 // Invalid AVI session.
#define ERR_DIRECTX_CERTIFICATION_FAILURE                            -1074396004 // A software key is restricting the use of this compression filter.
#define ERR_AVI_DATA_EXCEEDS_BUFFER_SIZE                             -1074396003 // The data for this frame exceeds the data buffer size specified when creating the AVI file.
#define ERR_INVALID_LINEGAUGEMETHOD                                  -1074396002 // Invalid line gauge method.
#define ERR_TOO_MANY_AVI_SESSIONS                                    -1074396001 // There are too many AVI sessions open.  You must close a session before you can open another one.
#define ERR_FILE_FILE_HEADER                                         -1074396000 // Invalid file header.
#define ERR_FILE_FILE_TYPE                                           -1074395999 // Invalid file type.
#define ERR_FILE_COLOR_TABLE                                         -1074395998 // Invalid color table.
#define ERR_FILE_ARGERR                                              -1074395997 // Invalid parameter.
#define ERR_FILE_OPEN                                                -1074395996 // File is already open for writing.
#define ERR_FILE_NOT_FOUND                                           -1074395995 // File not found.
#define ERR_FILE_TOO_MANY_OPEN                                       -1074395994 // Too many files open.
#define ERR_FILE_IO_ERR                                              -1074395993 // File I/O error.
#define ERR_FILE_PERMISSION                                          -1074395992 // File access denied.
#define ERR_FILE_INVALID_TYPE                                        -1074395991 // NI Vision does not support the file type you specified.
#define ERR_FILE_GET_INFO                                            -1074395990 // Could not read Vision info from file.
#define ERR_FILE_READ                                                -1074395989 // Unable to read data.
#define ERR_FILE_WRITE                                               -1074395988 // Unable to write data.
#define ERR_FILE_EOF                                                 -1074395987 // Premature end of file.
#define ERR_FILE_FORMAT                                              -1074395986 // Invalid file format.
#define ERR_FILE_OPERATION                                           -1074395985 // Invalid file operation.
#define ERR_FILE_INVALID_DATA_TYPE                                   -1074395984 // NI Vision does not support the file data type you specified.
#define ERR_FILE_NO_SPACE                                            -1074395983 // Disk full.
#define ERR_INVALID_FRAMES_PER_SECOND                                -1074395982 // The frames per second in an AVI must be greater than zero.
#define ERR_INSUFFICIENT_BUFFER_SIZE                                 -1074395981 // The buffer that was passed in is not big enough to hold all of the data.
#define ERR_COM_INITIALIZE                                           -1074395980 // Error initializing COM.
#define ERR_INVALID_PARTICLE_INFO                                    -1074395979 // The image has invalid particle information.  Call imaqCountParticles on the image to create particle information.
#define ERR_INVALID_PARTICLE_NUMBER                                  -1074395978 // Invalid particle number.
#define ERR_AVI_VERSION                                              -1074395977 // The AVI file was created in a newer version of NI Vision. Upgrade to the latest version of NI Vision to read this AVI file.
#define ERR_NUMBER_OF_PALETTE_COLORS                                 -1074395976 // The color palette must have exactly 0 or 256 entries.
#define ERR_AVI_TIMEOUT                                              -1074395975 // DirectX has timed out reading or writing the AVI file.  When closing an AVI file, try adding an additional delay.  When reading an AVI file, try reducing CPU and disk load.
#define ERR_UNSUPPORTED_JPEG2000_COLORSPACE_METHOD                   -1074395974 // NI Vision does not support reading JPEG2000 files with this colorspace method.
#define ERR_JPEG2000_UNSUPPORTED_MULTIPLE_LAYERS                     -1074395973 // NI Vision does not support reading JPEG2000 files with more than one layer.
#define ERR_DIRECTX_ENUMERATE_FILTERS                                -1074395972 // DirectX is unable to enumerate the compression filters. This is caused by a third-party compression filter that is either improperly installed or is preventing itself from being enumerated. Remove any recently installed compression filters and try again.
#define ERR_INIT                                                     -1074395960 // Initialization error.
#define ERR_CREATE_WINDOW                                            -1074395959 // Unable to create window.
#define ERR_WINDOW_ID                                                -1074395958 // Invalid window ID.
#define ERR_ARRAY_SIZE_MISMATCH                                      -1074395957 // The array sizes are not compatible.
#define ERR_INVALID_QUALITY                                          -1074395956 // The quality you provided is invalid. Valid quality values range from -1 to 1000.
#define ERR_INVALID_MAX_WAVELET_TRANSFORM_LEVEL                      -1074395955 // Invalid maximum wavelet transform level.  Valid values range from 0 to 255.
#define ERR_INVALID_QUANTIZATION_STEP_SIZE                           -1074395954 // The quantization step size must be greater than or equal to 0.
#define ERR_INVALID_WAVELET_TRANSFORM_MODE                           -1074395953 // Invalid wavelet transform mode.
#define ERR_NUMBER_CLASS                                             -1074395920 // Invalid number of classes.
#define ERR_PARTICLE                                                 -1074395880 // Invalid particle.
#define ERR_BAD_MEASURE                                              -1074395879 // Invalid measure number.
#define ERR_PROP_NODE_WRITE_NOT_SUPPORTED                            -1074395878 // The Image Display control does not support writing this property node.
#define ERR_COLORMODE_REQUIRES_CHANGECOLORSPACE2                     -1074395877 // The specified color mode requires the use of imaqChangeColorSpace2.
#define ERR_UNSUPPORTED_COLOR_MODE                                   -1074395876 // This function does not currently support the color mode you specified.
#define ERR_BAD_INDEX                                                -1074395840 // Invalid handle table index.
#define ERR_INVALID_COMPRESSION_RATIO                                -1074395837 // The compression ratio must be greater than or equal to 1.
#define ERR_TOO_MANY_CONTOURS                                        -1074395801 // The ROI contains too many contours.
#define ERR_PROTECTION                                               -1074395800 // Protection error.
#define ERR_INTERNAL                                                 -1074395799 // Internal error.
#define ERR_INVALID_CUSTOM_SAMPLE                                    -1074395798 // The size of the feature vector in the custom sample must match the size of those you have already added.
#define ERR_INVALID_CLASSIFIER_SESSION                               -1074395797 // Not a valid classifier session.
#define ERR_INVALID_KNN_METHOD                                       -1074395796 // You requested an invalid Nearest Neighbor classifier method.
#define ERR_K_TOO_LOW                                                -1074395795 // The k parameter must be greater than two.
#define ERR_K_TOO_HIGH                                               -1074395794 // The k parameter must be <= the number of samples in each class.
#define ERR_INVALID_OPERATION_ON_COMPACT_SESSION_ATTEMPTED           -1074395793 // This classifier session is compact. Only the Classify and Dispose functions may be called on a compact classifier session.
#define ERR_CLASSIFIER_SESSION_NOT_TRAINED                           -1074395792 // This classifier session is not trained. You may only call this function on a trained classifier session.
#define ERR_CLASSIFIER_INVALID_SESSION_TYPE                          -1074395791 // This classifier function cannot be called on this type of classifier session.
#define ERR_INVALID_DISTANCE_METRIC                                  -1074395790 // You requested an invalid distance metric.
#define ERR_OPENING_NEWER_CLASSIFIER_SESSION                         -1074395789 // The classifier session you tried to open was created with a newer version of NI Vision. Upgrade to the latest version of NI Vision to read this file.
#define ERR_NO_SAMPLES                                               -1074395788 // This operation cannot be performed because you have not added any samples.
#define ERR_INVALID_CLASSIFIER_TYPE                                  -1074395787 // You requested an invalid classifier type.
#define ERR_INVALID_PARTICLE_OPTIONS                                 -1074395786 // The sum of Scale Dependence and Symmetry Dependence must be less than 1000.
#define ERR_NO_PARTICLE                                              -1074395785 // The image yielded no particles.
#define ERR_INVALID_LIMITS                                           -1074395784 // The limits you supplied are not valid.
#define ERR_BAD_SAMPLE_INDEX                                         -1074395783 // The Sample Index fell outside the range of Samples.
#define ERR_DESCRIPTION_TOO_LONG                                     -1074395782 // The description must be <= 255 characters.
#define ERR_CLASSIFIER_INVALID_ENGINE_TYPE                           -1074395781 // The engine for this classifier session does not support this operation.
#define ERR_INVALID_PARTICLE_TYPE                                    -1074395780 // You requested an invalid particle type.
#define ERR_CANNOT_COMPACT_UNTRAINED                                 -1074395779 // You may only save a session in compact form if it is trained.
#define ERR_INVALID_KERNEL_SIZE                                      -1074395778 // The Kernel size must be smaller than the image size.
#define ERR_INCOMPATIBLE_CLASSIFIER_TYPES                            -1074395777 // The session you read from file must be the same type as the session you passed in.
#define ERR_INVALID_USE_OF_COMPACT_SESSION_FILE                      -1074395776 // You can not use a compact classification file with read options other than Read All.
#define ERR_ROI_HAS_OPEN_CONTOURS                                    -1074395775 // The ROI you passed in may only contain closed contours.
#define ERR_NO_LABEL                                                 -1074395774 // You must pass in a label.
#define ERR_NO_DEST_IMAGE                                            -1074395773 // You must provide a destination image.
#define ERR_INVALID_REGISTRATION_METHOD                              -1074395772 // You provided an invalid registration method.
#define ERR_OPENING_NEWER_INSPECTION_TEMPLATE                        -1074395771 // The golden template you tried to open was created with a newer version of NI Vision. Upgrade to the latest version of NI Vision to read this file.
#define ERR_INVALID_INSPECTION_TEMPLATE                              -1074395770 // Invalid golden template.
#define ERR_INVALID_EDGE_THICKNESS                                   -1074395769 // Edge Thickness to Ignore must be greater than zero.
#define ERR_INVALID_SCALE                                            -1074395768 // Scale must be greater than zero.
#define ERR_INVALID_ALIGNMENT                                        -1074395767 // The supplied scale is too small for your template.
#define ERR_INVALID_NORMALIZATION_METHOD                             -1074395763 // You must provide a valid normalization method.
#define ERR_INVALID_NIBLACK_DEVIATION_FACTOR                         -1074395762 // The deviation factor for Niblack local threshold must be between 0 and 1.
#define ERR_BOARD_NOT_FOUND                                          -1074395760 // Board not found.
#define ERR_BOARD_NOT_OPEN                                           -1074395758 // Board not opened.
#define ERR_DLL_NOT_FOUND                                            -1074395757 // DLL not found.
#define ERR_DLL_FUNCTION_NOT_FOUND                                   -1074395756 // DLL function not found.
#define ERR_TRIG_TIMEOUT                                             -1074395754 // Trigger timeout.
#define ERR_INVALID_2D_BARCODE_SEARCH_MODE                           -1074395728 // NI Vision does not support the search mode you provided.
#define ERR_UNSUPPORTED_2D_BARCODE_SEARCH_MODE                       -1074395727 // NI Vision does not support the search mode you provided for the type of 2D barcode for which you are searching.
#define ERR_MATCHFACTOR_OBSOLETE                                     -1074395726 // matchFactor has been obsoleted. Instead, set the initialMatchListLength and matchListReductionFactor in the MatchPatternAdvancedOptions structure.
#define ERR_DATA_VERSION                                             -1074395725 // The data was stored with a newer version of NI Vision. Upgrade to the latest version of NI Vision to read this data.
#define ERR_CUSTOMDATA_INVALID_SIZE                                  -1074395724 // The size you specified is out of the valid range.
#define ERR_CUSTOMDATA_KEY_NOT_FOUND                                 -1074395723 // The key you specified cannot be found in the image.
#define ERR_CLASSIFIER_CLASSIFY_IMAGE_WITH_CUSTOM_SESSION            -1074395722 // Custom classifier sessions only classify feature vectors. They do not support classifying images.
#define ERR_INVALID_BIT_DEPTH                                        -1074395721 // NI Vision does not support the bit depth you supplied for the image you supplied.
#define ERR_BAD_ROI                                                  -1074395720 // Invalid ROI.
#define ERR_BAD_ROI_BOX                                              -1074395719 // Invalid ROI global rectangle.
#define ERR_LAB_VERSION                                              -1074395718 // The version of LabVIEW or BridgeVIEW you are running does not support this operation.
#define ERR_INVALID_RANGE                                            -1074395717 // The range you supplied is invalid.
#define ERR_INVALID_SCALING_METHOD                                   -1074395716 // NI Vision does not support the scaling method you provided.
#define ERR_INVALID_CALIBRATION_UNIT                                 -1074395715 // NI Vision does not support the calibration unit you supplied.
#define ERR_INVALID_AXIS_ORIENTATION                                 -1074395714 // NI Vision does not support the axis orientation you supplied.
#define ERR_VALUE_NOT_IN_ENUM                                        -1074395713 // Value not in enumeration.
#define ERR_WRONG_REGION_TYPE                                        -1074395712 // You selected a region that is not of the right type.
#define ERR_NOT_ENOUGH_REGIONS                                       -1074395711 // You specified a viewer that does not contain enough regions.
#define ERR_TOO_MANY_PARTICLES                                       -1074395710 // The image has too many particles for this process.
#define ERR_AVI_UNOPENED_SESSION                                     -1074395709 // The AVI session has not been opened.
#define ERR_AVI_READ_SESSION_REQUIRED                                -1074395708 // The AVI session is a write session, but this operation requires a read session.
#define ERR_AVI_WRITE_SESSION_REQUIRED                               -1074395707 // The AVI session is a read session, but this operation requires a write session.
#define ERR_AVI_SESSION_ALREADY_OPEN                                 -1074395706 // This AVI session is already open. You must close it before calling the Create or Open functions.
#define ERR_DATA_CORRUPTED                                           -1074395705 // The data is corrupted and cannot be read.
#define ERR_INVALID_COMPRESSION_TYPE                                 -1074395704 // Invalid compression type.
#define ERR_INVALID_TYPE_OF_FLATTEN                                  -1074395703 // Invalid type of flatten.
#define ERR_INVALID_LENGTH                                           -1074395702 // The length of the edge detection line must be greater than zero.
#define ERR_INVALID_MATRIX_SIZE_RANGE                                -1074395701 // The maximum Data Matrix barcode size must be equal to or greater than the minimum Data Matrix barcode size.
#define ERR_SMOOTH_CONTOURS_MUST_BE_SAME                             -1074395656 // You must specify the same value for the smooth contours advanced match option for all templates you want to match.
#define ERR_ENABLE_CALIBRATION_SUPPORT_MUST_BE_SAME                  -1074395655 // You must specify the same value for the enable calibration support advanced match option for all templates you want to match.
#define ERR_GRADING_INFORMATION_NOT_FOUND                            -1074395654 // The source image does not contain grading information. You must prepare the source image for grading when reading the Data Matrix, and you cannot change the contents of the source image between reading and grading the Data Matrix.
#define ERR_OPENING_NEWER_MULTIPLE_GEOMETRIC_TEMPLATE                -1074395653 // The multiple geometric matching template you tried to open was created with a newer version of NI Vision. Upgrade to the latest version of NI Vision to read this file.
#define ERR_OPENING_NEWER_GEOMETRIC_MATCHING_TEMPLATE                -1074395652 // The geometric matching template you tried to open was created with a newer version of NI Vision. Upgrade to the latest version of NI Vision to read this file.
#define ERR_EDGE_FILTER_SIZE_MUST_BE_SAME                            -1074395651 // You must specify the same edge filter size for all the templates you want to match.
#define ERR_CURVE_EXTRACTION_MODE_MUST_BE_SAME                       -1074395650 // You must specify the same curve extraction mode for all the templates you want to match.
#define ERR_INVALID_GEOMETRIC_FEATURE_TYPE                           -1074395649 // The geometric feature type specified is invalid.
#define ERR_TEMPLATE_NOT_LEARNED                                     -1074395648 // You supplied a template that was not learned.
#define ERR_INVALID_MULTIPLE_GEOMETRIC_TEMPLATE                      -1074395647 // Invalid multiple geometric template.
#define ERR_NO_TEMPLATE_TO_LEARN                                     -1074395646 // Need at least one template to learn.
#define ERR_INVALID_NUMBER_OF_LABELS                                 -1074395645 // You supplied an invalid number of labels.
#define ERR_LABEL_TOO_LONG                                           -1074395644 // Labels must be <= 255 characters.
#define ERR_INVALID_NUMBER_OF_MATCH_OPTIONS                          -1074395643 // You supplied an invalid number of match options.
#define ERR_LABEL_NOT_FOUND                                          -1074395642 // Cannot find a label that matches the one you specified.
#define ERR_DUPLICATE_LABEL                                          -1074395641 // Duplicate labels are not allowed.
#define ERR_TOO_MANY_ZONES                                           -1074395640 // The number of zones found exceeded the capacity of the algorithm.
#define ERR_INVALID_HATCH_STYLE                                      -1074395639 // The hatch style for the window background is invalid.
#define ERR_INVALID_FILL_STYLE                                       -1074395638 // The fill style for the window background is invalid.
#define ERR_HARDWARE_DOESNT_SUPPORT_NONTEARING                       -1074395637 // Your hardware is not supported by DirectX and cannot be put into NonTearing mode.
#define ERR_DIRECTX_NOT_FOUND                                        -1074395636 // DirectX is required for this feature.  Please install the latest version..
#define ERR_INVALID_SHAPE_DESCRIPTOR                                 -1074395635 // The passed shape descriptor is invalid.
#define ERR_INVALID_MAX_MATCH_OVERLAP                                -1074395634 // Invalid max match overlap.  Values must be between -1 and 100.
#define ERR_INVALID_MIN_MATCH_SEPARATION_SCALE                       -1074395633 // Invalid minimum match separation scale.  Values must be greater than or equal to -1.
#define ERR_INVALID_MIN_MATCH_SEPARATION_ANGLE                       -1074395632 // Invalid minimum match separation angle.  Values must be between -1 and 360.
#define ERR_INVALID_MIN_MATCH_SEPARATION_DISTANCE                    -1074395631 // Invalid minimum match separation distance.  Values must be greater than or equal to -1.
#define ERR_INVALID_MAXIMUM_FEATURES_LEARNED                         -1074395630 // Invalid maximum number of features learn. Values must be integers greater than zero.
#define ERR_INVALID_MAXIMUM_PIXEL_DISTANCE_FROM_LINE                 -1074395629 // Invalid maximum pixel distance from line. Values must be positive real numbers.
#define ERR_INVALID_GEOMETRIC_MATCHING_TEMPLATE                      -1074395628 // Invalid geometric matching template image.
#define ERR_NOT_ENOUGH_TEMPLATE_FEATURES_1                           -1074395627 // The template does not contain enough features for geometric matching.
#define ERR_NOT_ENOUGH_TEMPLATE_FEATURES                             -1074395626 // The template does not contain enough features for geometric matching.
#define ERR_INVALID_MATCH_CONSTRAINT_TYPE                            -1074395625 // You specified an invalid value for the match constraint value of the  range settings.
#define ERR_INVALID_OCCLUSION_RANGE                                  -1074395624 // Invalid occlusion range. Valid values for the bounds range from 0 to 100 and the upper bound must be greater than or equal to the lower bound.
#define ERR_INVALID_SCALE_RANGE                                      -1074395623 // Invalid scale range. Values for the lower bound must be a positive real numbers and the upper bound must be greater than or equal to the lower bound.
#define ERR_INVALID_MATCH_GEOMETRIC_PATTERN_SETUP_DATA               -1074395622 // Invalid match geometric pattern setup data.
#define ERR_INVALID_LEARN_GEOMETRIC_PATTERN_SETUP_DATA               -1074395621 // Invalid learn geometric pattern setup data.
#define ERR_INVALID_CURVE_EXTRACTION_MODE                            -1074395620 // Invalid curve extraction mode.
#define ERR_TOO_MANY_OCCLUSION_RANGES                                -1074395619 // You can specify only one occlusion range.
#define ERR_TOO_MANY_SCALE_RANGES                                    -1074395618 // You can specify only one scale range.
#define ERR_INVALID_NUMBER_OF_FEATURES_RANGE                         -1074395617 // The minimum number of features must be less than or equal to the maximum number of features.
#define ERR_INVALID_EDGE_FILTER_SIZE                                 -1074395616 // Invalid edge filter size.
#define ERR_INVALID_MINIMUM_FEATURE_STRENGTH                         -1074395615 // Invalid minimum strength for features. Values must be positive real numbers.
#define ERR_INVALID_MINIMUM_FEATURE_ASPECT_RATIO                     -1074395614 // Invalid aspect ratio for rectangular features. Values must be positive real numbers in the range 0.01 to 1.0.
#define ERR_INVALID_MINIMUM_FEATURE_LENGTH                           -1074395613 // Invalid minimum length for linear features. Values must be integers greater than 0.
#define ERR_INVALID_MINIMUM_FEATURE_RADIUS                           -1074395612 // Invalid minimum radius for circular features. Values must be integers greater than 0.
#define ERR_INVALID_MINIMUM_RECTANGLE_DIMENSION                      -1074395611 // Invalid minimum rectangle dimension. Values must be integers greater than 0.
#define ERR_INVALID_INITIAL_MATCH_LIST_LENGTH                        -1074395610 // Invalid initial match list length. Values must be integers greater than 5.
#define ERR_INVALID_SUBPIXEL_TOLERANCE                               -1074395609 // Invalid subpixel tolerance. Values must be positive real numbers.
#define ERR_INVALID_SUBPIXEL_ITERATIONS                              -1074395608 // Invalid number of subpixel iterations. Values must be integers greater 10.
#define ERR_INVALID_MAXIMUM_FEATURES_PER_MATCH                       -1074395607 // Invalid maximum number of features used per match. Values must be integers greater than or equal to zero.
#define ERR_INVALID_MINIMUM_FEATURES_TO_MATCH                        -1074395606 // Invalid minimum number of features used for matching. Values must be integers greater than zero.
#define ERR_INVALID_MAXIMUM_END_POINT_GAP                            -1074395605 // Invalid maximum end point gap. Valid values range from 0 to 32767.
#define ERR_INVALID_COLUMN_STEP                                      -1074395604 // Invalid column step. Valid range is 1 to 255.
#define ERR_INVALID_ROW_STEP                                         -1074395603 // Invalid row step. Valid range is 1 to 255.
#define ERR_INVALID_MINIMUM_CURVE_LENGTH                             -1074395602 // Invalid minimum length. Valid values must be greater than or equal to zero.
#define ERR_INVALID_EDGE_THRESHOLD                                   -1074395601 // Invalid edge threshold. Valid values range from 1 to 360.
#define ERR_INFO_NOT_FOUND                                           -1074395600 // You must provide information about the subimage within the browser.
#define ERR_NIOCR_INVALID_ACCEPTANCE_LEVEL                           -1074395598 // The acceptance level is outside the valid range of  0 to 1000.
#define ERR_NIOCR_NOT_A_VALID_SESSION                                -1074395597 // Not a valid OCR session.
#define ERR_NIOCR_INVALID_CHARACTER_SIZE                             -1074395596 // Invalid character size. Character size must be >= 1.
#define ERR_NIOCR_INVALID_THRESHOLD_MODE                             -1074395595 // Invalid threshold mode value.
#define ERR_NIOCR_INVALID_SUBSTITUTION_CHARACTER                     -1074395594 // Invalid substitution character. Valid substitution characters are ASCII values that range from 1 to 254.
#define ERR_NIOCR_INVALID_NUMBER_OF_BLOCKS                           -1074395593 // Invalid number of blocks. Number of blocks must be >= 4 and <= 50.
#define ERR_NIOCR_INVALID_READ_STRATEGY                              -1074395592 // Invalid read strategy.
#define ERR_NIOCR_INVALID_CHARACTER_INDEX                            -1074395591 // Invalid character index.
#define ERR_NIOCR_INVALID_NUMBER_OF_VALID_CHARACTER_POSITIONS        -1074395590 // Invalid number of character positions. Valid values range from 0 to 255.
#define ERR_NIOCR_INVALID_LOW_THRESHOLD_VALUE                        -1074395589 // Invalid low threshold value. Valid threshold values range from 0 to 255.
#define ERR_NIOCR_INVALID_HIGH_THRESHOLD_VALUE                       -1074395588 // Invalid high threshold value. Valid threshold values range from 0 to 255.
#define ERR_NIOCR_INVALID_THRESHOLD_RANGE                            -1074395587 // The low threshold must be less than the high threshold.
#define ERR_NIOCR_INVALID_LOWER_THRESHOLD_LIMIT                      -1074395586 // Invalid lower threshold limit. Valid lower threshold limits range from 0 to 255.
#define ERR_NIOCR_INVALID_UPPER_THRESHOLD_LIMIT                      -1074395585 // Invalid upper threshold limit. Valid upper threshold limits range from 0 to 255.
#define ERR_NIOCR_INVALID_THRESHOLD_LIMITS                           -1074395584 // The lower threshold limit must be less than the upper threshold limit.
#define ERR_NIOCR_INVALID_MIN_CHAR_SPACING                           -1074395583 // Invalid minimum character spacing value. Character spacing must be >= 0 pixels.
#define ERR_NIOCR_INVALID_MAX_HORIZ_ELEMENT_SPACING                  -1074395582 // Invalid maximum horizontal element spacing value. Maximum horizontal element spacing must be >= 0.
#define ERR_NIOCR_INVALID_MAX_VERT_ELEMENT_SPACING                   -1074395581 // Invalid maximum vertical element spacing value. Maximum vertical element spacing must be >= 0.
#define ERR_NIOCR_INVALID_MIN_BOUNDING_RECT_WIDTH                    -1074395580 // Invalid minimum bounding rectangle width. Minimum bounding rectangle width must be >= 1.
#define ERR_NIOCR_INVALID_ASPECT_RATIO                               -1074395579 // Invalid aspect ratio value. The aspect ratio must be zero or >= 100.
#define ERR_NIOCR_INVALID_CHARACTER_SET_FILE                         -1074395578 // Invalid or corrupt character set file.
#define ERR_NIOCR_CHARACTER_VALUE_CANNOT_BE_EMPTYSTRING              -1074395577 // The character value must not be an empty string.
#define ERR_NIOCR_CHARACTER_VALUE_TOO_LONG                           -1074395576 // Character values must be <=255 characters.
#define ERR_NIOCR_INVALID_NUMBER_OF_EROSIONS                         -1074395575 // Invalid number of erosions. The number of erosions must be >= 0.
#define ERR_NIOCR_CHARACTER_SET_DESCRIPTION_TOO_LONG                 -1074395574 // The character set description must be <=255 characters.
#define ERR_NIOCR_INVALID_CHARACTER_SET_FILE_VERSION                 -1074395573 // The character set file was created by a newer version of NI Vision. Upgrade to the latest version of NI Vision to read the character set file.
#define ERR_NIOCR_INTEGER_VALUE_FOR_STRING_ATTRIBUTE                 -1074395572 // You must specify characters for a string. A string cannot contain integers.
#define ERR_NIOCR_GET_ONLY_ATTRIBUTE                                 -1074395571 // This attribute is read-only.
#define ERR_NIOCR_INTEGER_VALUE_FOR_BOOLEAN_ATTRIBUTE                -1074395570 // This attribute requires a Boolean value.
#define ERR_NIOCR_INVALID_ATTRIBUTE                                  -1074395569 // Invalid attribute.
#define ERR_NIOCR_STRING_VALUE_FOR_INTEGER_ATTRIBUTE                 -1074395568 // This attribute requires integer values.
#define ERR_NIOCR_STRING_VALUE_FOR_BOOLEAN_ATTRIBUTE                 -1074395567 // String values are invalid for this attribute. Enter a boolean value.
#define ERR_NIOCR_BOOLEAN_VALUE_FOR_INTEGER_ATTRIBUTE                -1074395566 // Boolean values are not valid for this attribute. Enter an integer value.
#define ERR_NIOCR_MUST_BE_SINGLE_CHARACTER                           -1074395565 // Requires a single-character string.
#define ERR_NIOCR_INVALID_PREDEFINED_CHARACTER                       -1074395564 // Invalid predefined character value.
#define ERR_NIOCR_UNLICENSED                                         -1074395563 // This copy of NI OCR is unlicensed.
#define ERR_NIOCR_BOOLEAN_VALUE_FOR_STRING_ATTRIBUTE                 -1074395562 // String values are not valid for this attribute. Enter a Boolean value.
#define ERR_NIOCR_INVALID_NUMBER_OF_CHARACTERS                       -1074395561 // The number of characters in the character value must match the number of objects in the image.
#define ERR_NIOCR_INVALID_OBJECT_INDEX                               -1074395560 // Invalid object index.
#define ERR_NIOCR_INVALID_READ_OPTION                                -1074395559 // Invalid read option.
#define ERR_NIOCR_INVALID_CHARACTER_SIZE_RANGE                       -1074395558 // The minimum character size must be less than the maximum character size.
#define ERR_NIOCR_INVALID_BOUNDING_RECT_WIDTH_RANGE                  -1074395557 // The minimum character bounding rectangle width must be less than the maximum character bounding rectangle width.
#define ERR_NIOCR_INVALID_BOUNDING_RECT_HEIGHT_RANGE                 -1074395556 // The minimum character bounding rectangle height must be less than the maximum character bounding rectangle height.
#define ERR_NIOCR_INVALID_SPACING_RANGE                              -1074395555 // The maximum horizontal element spacing value must not exceed the minimum character spacing value.
#define ERR_NIOCR_INVALID_READ_RESOLUTION                            -1074395554 // Invalid read resolution.
#define ERR_NIOCR_INVALID_MIN_BOUNDING_RECT_HEIGHT                   -1074395553 // Invalid minimum bounding rectangle height. The minimum bounding rectangle height must be >= 1.
#define ERR_NIOCR_NOT_A_VALID_CHARACTER_SET                          -1074395552 // Not a valid character set.
#define ERR_NIOCR_RENAME_REFCHAR                                     -1074395551 // A trained OCR character cannot be renamed while it is a reference character.
#define ERR_NIOCR_INVALID_CHARACTER_VALUE                            -1074395550 // A character cannot have an ASCII value of 255.
#define ERR_NIOCR_INVALID_NUMBER_OF_OBJECTS_TO_VERIFY                -1074395549 // The number of objects found does not match the number of expected characters or patterns to verify.
#define ERR_INVALID_ICONS_PER_LINE                                   -1074395410 // NI Vision does not support less than one icon per line.
#define ERR_INVALID_SUBPIXEL_DIVISIONS                               -1074395409 // Invalid subpixel divisions.
#define ERR_INVALID_DETECTION_MODE                                   -1074395408 // Invalid detection mode.
#define ERR_INVALID_CONTRAST                                         -1074395407 // Invalid contrast value. Valid contrast values range from 0 to 255.
#define ERR_COORDSYS_NOT_FOUND                                       -1074395406 // The coordinate system could not be found on this image.
#define ERR_INVALID_TEXTORIENTATION                                  -1074395405 // NI Vision does not support the text orientation value you supplied.
#define ERR_INVALID_INTERPOLATIONMETHOD_FOR_UNWRAP                   -1074395404 // UnwrapImage does not support the interpolation method value you supplied.  Valid interpolation methods are zero order and bilinear. 
#define ERR_EXTRAINFO_VERSION                                        -1074395403 // The image was created in a newer version of NI Vision. Upgrade to the latest version of NI Vision to use this image.
#define ERR_INVALID_MAXPOINTS                                        -1074395402 // The function does not support the maximum number of points that you specified.
#define ERR_INVALID_MATCHFACTOR                                      -1074395401 // The function does not support the matchFactor that you specified.
#define ERR_COMPLEX_IMAGE_REQUIRED                                   -1074395397 // A complex image is required.
#define ERR_COLOR_IMAGE_REQUIRED                                     -1074395395 // The input image must be a color image.
#define ERR_COLOR_SPECTRUM_MASK                                      -1074395394 // The color mask removes too much color information.
#define ERR_COLOR_TEMPLATE_IMAGE_TOO_SMALL                           -1074395393 // The color template image is too small.
#define ERR_COLOR_TEMPLATE_IMAGE_TOO_LARGE                           -1074395392 // The color template image is too large.
#define ERR_COLOR_TEMPLATE_IMAGE_HUE_CONTRAST_TOO_LOW                -1074395391 // The contrast in the hue plane of the image is too low for learning shape features.
#define ERR_COLOR_TEMPLATE_IMAGE_LUMINANCE_CONTRAST_TOO_LOW          -1074395390 // The contrast in the luminance plane of the image is too low to learn shape features.
#define ERR_COLOR_LEARN_SETUP_DATA                                   -1074395389 // Invalid color learn setup data.
#define ERR_COLOR_LEARN_SETUP_DATA_SHAPE                             -1074395388 // Invalid color learn setup data.
#define ERR_COLOR_MATCH_SETUP_DATA                                   -1074395387 // Invalid color match setup data.
#define ERR_COLOR_MATCH_SETUP_DATA_SHAPE                             -1074395386 // Invalid color match setup data.
#define ERR_COLOR_ROTATION_REQUIRES_SHAPE_FEATURE                    -1074395385 // Rotation-invariant color pattern matching requires a feature mode including shape.
#define ERR_COLOR_TEMPLATE_DESCRIPTOR                                -1074395384 // Invalid color template image.
#define ERR_COLOR_TEMPLATE_DESCRIPTOR_1                              -1074395383 // Invalid color template image.
#define ERR_COLOR_TEMPLATE_DESCRIPTOR_2                              -1074395382 // Invalid color template image.
#define ERR_COLOR_TEMPLATE_DESCRIPTOR_3                              -1074395381 // Invalid color template image.
#define ERR_COLOR_TEMPLATE_DESCRIPTOR_4                              -1074395380 // Invalid color template image.
#define ERR_COLOR_TEMPLATE_DESCRIPTOR_5                              -1074395379 // Invalid color template image.
#define ERR_COLOR_TEMPLATE_DESCRIPTOR_6                              -1074395378 // Invalid color template image.
#define ERR_COLOR_TEMPLATE_DESCRIPTOR_SHIFT                          -1074395377 // Invalid color template image.
#define ERR_COLOR_TEMPLATE_DESCRIPTOR_NOSHIFT                        -1074395376 // The color template image does not contain data required for shift-invariant color matching.
#define ERR_COLOR_TEMPLATE_DESCRIPTOR_SHIFT_1                        -1074395375 // Invalid color template image.
#define ERR_COLOR_TEMPLATE_DESCRIPTOR_SHIFT_2                        -1074395374 // Invalid color template image.
#define ERR_COLOR_TEMPLATE_DESCRIPTOR_ROTATION                       -1074395373 // Invalid color template image.
#define ERR_COLOR_TEMPLATE_DESCRIPTOR_NOROTATION                     -1074395372 // The color template image does not contain data required for rotation-invariant color matching.
#define ERR_COLOR_TEMPLATE_DESCRIPTOR_ROTATION_1                     -1074395371 // Invalid color template image.
#define ERR_COLOR_TEMPLATE_DESCRIPTOR_ROTATION_2                     -1074395370 // Invalid color template image.
#define ERR_COLOR_TEMPLATE_DESCRIPTOR_ROTATION_3                     -1074395369 // Invalid color template image.
#define ERR_COLOR_TEMPLATE_DESCRIPTOR_ROTATION_4                     -1074395368 // Invalid color template image.
#define ERR_COLOR_TEMPLATE_DESCRIPTOR_ROTATION_5                     -1074395367 // Invalid color template image.
#define ERR_COLOR_TEMPLATE_DESCRIPTOR_NOSHAPE                        -1074395366 // The color template image does not contain data required for color matching in shape feature mode.
#define ERR_COLOR_TEMPLATE_DESCRIPTOR_NOSPECTRUM                     -1074395365 // The color template image does not contain data required for color matching in color feature mode.
#define ERR_IGNORE_COLOR_SPECTRUM_SET                                -1074395364 // The ignore color spectra array is invalid.
#define ERR_INVALID_SUBSAMPLING_RATIO                                -1074395363 // Invalid subsampling ratio.
#define ERR_INVALID_WIDTH                                            -1074395362 // Invalid pixel width.
#define ERR_INVALID_STEEPNESS                                        -1074395361 // Invalid steepness.
#define ERR_COMPLEX_PLANE                                            -1074395360 // Invalid complex plane.
#define ERR_INVALID_COLOR_IGNORE_MODE                                -1074395357 // Invalid color ignore mode.
#define ERR_INVALID_MIN_MATCH_SCORE                                  -1074395356 // Invalid minimum match score. Acceptable values range from 0 to 1000.
#define ERR_INVALID_NUM_MATCHES_REQUESTED                            -1074395355 // Invalid number of matches requested. You must request a minimum of one match.
#define ERR_INVALID_COLOR_WEIGHT                                     -1074395354 // Invalid color weight. Acceptable values range from 0 to 1000.
#define ERR_INVALID_SEARCH_STRATEGY                                  -1074395353 // Invalid search strategy.
#define ERR_INVALID_FEATURE_MODE                                     -1074395352 // Invalid feature mode.
#define ERR_INVALID_RECT                                             -1074395351 // NI Vision does not support rectangles with negative widths or negative heights.
#define ERR_INVALID_VISION_INFO                                      -1074395350 // NI Vision does not support the vision information type you supplied.
#define ERR_INVALID_SKELETONMETHOD                                   -1074395349 // NI Vision does not support the SkeletonMethod value you supplied.
#define ERR_INVALID_3DPLANE                                          -1074395348 // NI Vision does not support the 3DPlane value you supplied.
#define ERR_INVALID_3DDIRECTION                                      -1074395347 // NI Vision does not support the 3DDirection value you supplied.
#define ERR_INVALID_INTERPOLATIONMETHOD_FOR_ROTATE                   -1074395346 // imaqRotate does not support the InterpolationMethod value you supplied.
#define ERR_INVALID_FLIPAXIS                                         -1074395345 // NI Vision does not support the FlipAxis value you supplied.
#define ERR_FILE_FILENAME_NULL                                       -1074395343 // You must pass a valid file name. Do not pass in NULL.
#define ERR_INVALID_SIZETYPE                                         -1074395340 // NI Vision does not support the SizeType value you supplied.
#define ERR_INVALID_CONVERSIONSTYLE                                  -1074395334 // NI Vision does not support the Conversion Method value you supplied.
#define ERR_INVALID_VERTICAL_TEXT_ALIGNMENT                          -1074395333 // NI Vision does not support the VerticalTextAlignment value you supplied.
#define ERR_INVALID_COMPAREFUNCTION                                  -1074395332 // NI Vision does not support the CompareFunction value you supplied.
#define ERR_INVALID_BORDERMETHOD                                     -1074395331 // NI Vision does not support the BorderMethod value you supplied.
#define ERR_INVALID_BORDER_SIZE                                      -1074395330 // Invalid border size. Acceptable values range from 0 to 50.
#define ERR_INVALID_OUTLINEMETHOD                                    -1074395329 // NI Vision does not support the OutlineMethod value you supplied.
#define ERR_INVALID_INTERPOLATIONMETHOD                              -1074395328 // NI Vision does not support the InterpolationMethod value you supplied.
#define ERR_INVALID_SCALINGMODE                                      -1074395327 // NI Vision does not support the ScalingMode value you supplied.
#define ERR_INVALID_DRAWMODE_FOR_LINE                                -1074395326 // imaqDrawLineOnImage does not support the DrawMode value you supplied.
#define ERR_INVALID_DRAWMODE                                         -1074395325 // NI Vision does not support the DrawMode value you supplied.
#define ERR_INVALID_SHAPEMODE                                        -1074395324 // NI Vision does not support the ShapeMode value you supplied.
#define ERR_INVALID_FONTCOLOR                                        -1074395323 // NI Vision does not support the FontColor value you supplied.
#define ERR_INVALID_TEXTALIGNMENT                                    -1074395322 // NI Vision does not support the TextAlignment value you supplied.
#define ERR_INVALID_MORPHOLOGYMETHOD                                 -1074395321 // NI Vision does not support the MorphologyMethod value you supplied.
#define ERR_TEMPLATE_EMPTY                                           -1074395320 // The template image is empty.
#define ERR_INVALID_SUBPIX_TYPE                                      -1074395319 // NI Vision does not support the interpolation type you supplied.
#define ERR_INSF_POINTS                                              -1074395318 // You supplied an insufficient number of points to perform this operation.
#define ERR_UNDEF_POINT                                              -1074395317 // You specified a point that lies outside the image.
#define ERR_INVALID_KERNEL_CODE                                      -1074395316 // Invalid kernel code.
#define ERR_INVALID_PALETTE_TYPE                                     -1074395310 // NI Vision does not support the PaletteType value you supplied.
#define ERR_INVALID_WINDOW_THREAD_POLICY                             -1074395309 // NI Vision does not support the WindowThreadPolicy value you supplied.
#define ERR_INVALID_COLORSENSITIVITY                                 -1074395308 // NI Vision does not support the ColorSensitivity value you supplied.
#define ERR_PRECISION_NOT_GTR_THAN_0                                 -1074395307 // The precision parameter must be greater than 0.
#define ERR_INVALID_TOOL                                             -1074395306 // NI Vision does not support the Tool value you supplied.
#define ERR_INVALID_REFERENCEMODE                                    -1074395305 // NI Vision does not support the ReferenceMode value you supplied.
#define ERR_INVALID_MATHTRANSFORMMETHOD                              -1074395304 // NI Vision does not support the MathTransformMethod value you supplied.
#define ERR_INVALID_NUM_OF_CLASSES                                   -1074395303 // Invalid number of classes for auto threshold. Acceptable values range from 2 to 256.
#define ERR_INVALID_THRESHOLDMETHOD                                  -1074395302 // NI Vision does not support the threshold method value you supplied.
#define ERR_ROI_NOT_2_LINES                                          -1074395301 // The ROI you passed into imaqGetMeterArc must consist of two lines.
#define ERR_INVALID_METERARCMODE                                     -1074395300 // NI Vision does not support the MeterArcMode value you supplied.
#define ERR_INVALID_COMPLEXPLANE                                     -1074395299 // NI Vision does not support the ComplexPlane value you supplied.
#define ERR_COMPLEXPLANE_NOT_REAL_OR_IMAGINARY                       -1074395298 // You can perform this operation on a real or an imaginary ComplexPlane only.
#define ERR_INVALID_PARTICLEINFOMODE                                 -1074395297 // NI Vision does not support the ParticleInfoMode value you supplied.
#define ERR_INVALID_BARCODETYPE                                      -1074395296 // NI Vision does not support the BarcodeType value you supplied.
#define ERR_INVALID_INTERPOLATIONMETHOD_INTERPOLATEPOINTS            -1074395295 // imaqInterpolatePoints does not support the InterpolationMethod value you supplied.
#define ERR_CONTOUR_INDEX_OUT_OF_RANGE                               -1074395294 // The contour index you supplied is larger than the number of contours in the ROI.
#define ERR_CONTOURID_NOT_FOUND                                      -1074395293 // The supplied ContourID did not correlate to a contour inside the ROI.
#define ERR_POINTS_ARE_COLLINEAR                                     -1074395292 // Do not supply collinear points for this operation.
#define ERR_SHAPEMATCH_BADIMAGEDATA                                  -1074395291 // Shape Match requires the image to contain only pixel values of 0 or 1.
#define ERR_SHAPEMATCH_BADTEMPLATE                                   -1074395290 // The template you supplied for ShapeMatch contains no shape information.
#define ERR_INVALID_CONCENTRIC_RAKE_DIRECTION                        -1074395286 // Invalid concentric rake direction.
#define ERR_INVALID_SPOKE_DIRECTION                                  -1074395285 // Invalid spoke direction.
#define ERR_INVALID_EDGE_PROCESS                                     -1074395284 // Invalid edge process.
#define ERR_INVALID_RAKE_DIRECTION                                   -1074395283 // Invalid rake direction.
#define ERR_CANT_DRAW_INTO_VIEWER                                    -1074395282 // Unable to draw to viewer. You must have the latest version of the control.
#define ERR_IMAGE_SMALLER_THAN_BORDER                                -1074395281 // Your image must be larger than its border size for this operation.
#define ERR_ROI_NOT_RECT                                             -1074395280 // ROI is not a rectangle.
#define ERR_ROI_NOT_POLYGON                                          -1074395279 // ROI is not a polygon.
#define ERR_LCD_NOT_NUMERIC                                          -1074395278 // LCD image is not a number.
#define ERR_BARCODE_CHECKSUM                                         -1074395277 // The decoded barcode information did not pass the checksum test.
#define ERR_LINES_PARALLEL                                           -1074395276 // You specified parallel lines for the meter ROI.
#define ERR_INVALID_BROWSER_IMAGE                                    -1074395275 // Invalid browser image.
#define ERR_DIV_BY_ZERO                                              -1074395270 // Cannot divide by zero.
#define ERR_NULL_POINTER                                             -1074395269 // Null pointer.
#define ERR_LINEAR_COEFF                                             -1074395268 // The linear equations are not independent.
#define ERR_COMPLEX_ROOT                                             -1074395267 // The roots of the equation are complex.
#define ERR_BARCODE                                                  -1074395265 // The barcode does not match the type you specified.
#define ERR_LCD_NO_SEGMENTS                                          -1074395263 // No lit segment.
#define ERR_LCD_BAD_MATCH                                            -1074395262 // The LCD does not form a known digit.
#define ERR_GIP_RANGE                                                -1074395261 // An internal error occurred while attempting to access an invalid coordinate on an image.
#define ERR_HEAP_TRASHED                                             -1074395260 // An internal memory error occurred.
#define ERR_BAD_FILTER_WIDTH                                         -1074395258 // The filter width must be odd for the Canny operator.
#define ERR_INVALID_EDGE_DIR                                         -1074395257 // You supplied an invalid edge direction in the Canny operator.
#define ERR_EVEN_WINDOW_SIZE                                         -1074395256 // The window size must be odd for the Canny operator. 
#define ERR_INVALID_LEARN_MODE                                       -1074395253 // Invalid learn mode.
#define ERR_LEARN_SETUP_DATA                                         -1074395252 // Invalid learn setup data.
#define ERR_INVALID_MATCH_MODE                                       -1074395251 // Invalid match mode.
#define ERR_MATCH_SETUP_DATA                                         -1074395250 // Invalid match setup data.
#define ERR_ROTATION_ANGLE_RANGE_TOO_LARGE                           -1074395249 // At least one range in the array of rotation angle ranges exceeds 360 degrees.
#define ERR_TOO_MANY_ROTATION_ANGLE_RANGES                           -1074395248 // The array of rotation angle ranges contains too many ranges.
#define ERR_TEMPLATE_DESCRIPTOR                                      -1074395247 // Invalid template descriptor.
#define ERR_TEMPLATE_DESCRIPTOR_1                                    -1074395246 // Invalid template descriptor.
#define ERR_TEMPLATE_DESCRIPTOR_2                                    -1074395245 // Invalid template descriptor.
#define ERR_TEMPLATE_DESCRIPTOR_3                                    -1074395244 // Invalid template descriptor.
#define ERR_TEMPLATE_DESCRIPTOR_4                                    -1074395243 // The template descriptor was created with a newer version of NI Vision. Upgrade to the latest version of NI Vision to use this template.
#define ERR_TEMPLATE_DESCRIPTOR_ROTATION                             -1074395242 // Invalid template descriptor.
#define ERR_TEMPLATE_DESCRIPTOR_NOROTATION                           -1074395241 // The template descriptor does not contain data required for rotation-invariant matching.
#define ERR_TEMPLATE_DESCRIPTOR_ROTATION_1                           -1074395240 // Invalid template descriptor.
#define ERR_TEMPLATE_DESCRIPTOR_SHIFT                                -1074395239 // Invalid template descriptor.
#define ERR_TEMPLATE_DESCRIPTOR_NOSHIFT                              -1074395238 // The template descriptor does not contain data required for shift-invariant matching.
#define ERR_TEMPLATE_DESCRIPTOR_SHIFT_1                              -1074395237 // Invalid template descriptor.
#define ERR_TEMPLATE_IMAGE_CONTRAST_TOO_LOW                          -1074395235 // The template image does not contain enough contrast.
#define ERR_TEMPLATE_IMAGE_TOO_SMALL                                 -1074395234 // The template image is too small.
#define ERR_TEMPLATE_IMAGE_TOO_LARGE                                 -1074395233 // The template image is too large.
#define ERR_OCR_TEMPLATE_WRONG_SIZE                                  -1074395212 // The size of the template string must match the size of the string you are trying to correct.
#define ERR_OCR_BAD_TEXT_TEMPLATE                                    -1074395211 // The supplied text template contains nonstandard characters that cannot be generated by OCR.
#define ERR_OCR_CANNOT_MATCH_TEXT_TEMPLATE                           -1074395210 // At least one character in the text template was of a lexical class that did not match the supplied character reports.
#define ERR_OCR_LIB_INIT                                             -1074395203 // The OCR library cannot be initialized correctly.
#define ERR_OCR_LOAD_LIBRARY                                         -1074395201 // There was a failure when loading one of the internal OCR engine or LabView libraries.
#define ERR_OCR_INVALID_PARAMETER                                    -1074395200 // One of the parameters supplied to the OCR function that generated this error is invalid.
#define ERR_OCR_PREPROCESSING_FAILED                                 -1074395179 // The OCR engine failed during the preprocessing stage.
#define ERR_OCR_RECOGNITION_FAILED                                   -1074395178 // The OCR engine failed during the recognition stage.
#define ERR_OCR_BAD_USER_DICTIONARY                                  -1074395175 // The provided filename is not valid user dictionary filename.
#define ERR_OCR_INVALID_AUTOORIENTMODE                               -1074395174 // NI Vision does not support the AutoOrientMode value you supplied.
#define ERR_OCR_INVALID_LANGUAGE                                     -1074395173 // NI Vision does not support the Language value you supplied.
#define ERR_OCR_INVALID_CHARACTERSET                                 -1074395172 // NI Vision does not support the CharacterSet value you supplied.
#define ERR_OCR_INI_FILE_NOT_FOUND                                   -1074395171 // The system could not locate the initialization file required for OCR initialization.
#define ERR_OCR_INVALID_CHARACTERTYPE                                -1074395170 // NI Vision does not support the CharacterType value you supplied.
#define ERR_OCR_INVALID_RECOGNITIONMODE                              -1074395169 // NI Vision does not support the RecognitionMode value you supplied.
#define ERR_OCR_INVALID_AUTOCORRECTIONMODE                           -1074395168 // NI Vision does not support the AutoCorrectionMode value you supplied.
#define ERR_OCR_INVALID_OUTPUTDELIMITER                              -1074395167 // NI Vision does not support the OutputDelimiter value you supplied.
#define ERR_OCR_BIN_DIR_NOT_FOUND                                    -1074395166 // The system could not locate the OCR binary directory required for OCR initialization.
#define ERR_OCR_WTS_DIR_NOT_FOUND                                    -1074395165 // The system could not locate the OCR weights directory required for OCR initialization.
#define ERR_OCR_ADD_WORD_FAILED                                      -1074395164 // The supplied word could not be added to the user dictionary.
#define ERR_OCR_INVALID_CHARACTERPREFERENCE                          -1074395163 // NI Vision does not support the CharacterPreference value you supplied.
#define ERR_OCR_INVALID_CORRECTIONMODE                               -1074395162 // NI Vision does not support the CorrectionMethod value you supplied.
#define ERR_OCR_INVALID_CORRECTIONLEVEL                              -1074395161 // NI Vision does not support the CorrectionLevel value you supplied.
#define ERR_OCR_INVALID_MAXPOINTSIZE                                 -1074395160 // NI Vision does not support the maximum point size you supplied.  Valid values range from 4 to 72.
#define ERR_OCR_INVALID_TOLERANCE                                    -1074395159 // NI Vision does not support the tolerance value you supplied.  Valid values are non-negative.
#define ERR_OCR_INVALID_CONTRASTMODE                                 -1074395158 // NI Vision does not support the ContrastMode value you supplied.
#define ERR_OCR_SKEW_DETECT_FAILED                                   -1074395156 // The OCR attempted to detected the text skew and failed.
#define ERR_OCR_ORIENT_DETECT_FAILED                                 -1074395155 // The OCR attempted to detected the text orientation and failed.
#define ERR_OCR_CORRECTION_FAILED                                    -1074395151 // The OCR engine failed during the correction stage.
#define ERR_OCR_NO_TEXT_FOUND                                        -1074395141 // The OCR engine could not find any text in the supplied region.
#define ERR_OCR_CHAR_REPORT_CORRUPTED                                -1074395140 // One of the character reports is no longer usable by the system.
#define ERR_OCR_REGION_TOO_SMALL                                     -1074395138 // The OCR region provided was too small to have contained any characters.
#define _FIRST_ERR  ERR_SYSTEM_ERROR
#define _LAST_ERR   ERR_OCR_REGION_TOO_SMALL

//============================================================================
//  Enumerated Types
//============================================================================
typedef enum Plane3D_enum {
    IMAQ_3D_REAL             = 0,           //The function shows the real part of complex images.
    IMAQ_3D_IMAGINARY        = 1,           //The function shows the imaginary part of complex images.
    IMAQ_3D_MAGNITUDE        = 2,           //The function shows the magnitude part of complex images.
    IMAQ_3D_PHASE            = 3,           //The function shows the phase part of complex images.
    IMAQ_PLANE_3D_SIZE_GUARD = 0xFFFFFFFF   
} Plane3D;

typedef enum LineGaugeMethod_enum {
    IMAQ_EDGE_TO_EDGE                 = 0,           //Measures from the first edge on the line to the last edge on the line.
    IMAQ_EDGE_TO_POINT                = 1,           //Measures from the first edge on the line to the end point of the line.
    IMAQ_POINT_TO_EDGE                = 2,           //Measures from the start point of the line to the first edge on the line.
    IMAQ_POINT_TO_POINT               = 3,           //Measures from the start point of the line to the end point of the line.
    IMAQ_LINE_GAUGE_METHOD_SIZE_GUARD = 0xFFFFFFFF   
} LineGaugeMethod;

typedef enum MappingMethod_enum {
    IMAQ_FULL_DYNAMIC              = 0,           //The function maps the full dynamic range of the 16-bit image to an 8-bit scale.
    IMAQ_DOWNSHIFT                 = 1,           //The function shifts the 16-bit image pixels to the right the number of times specified by the shiftCount element of the DisplayMapping structure.
    IMAQ_RANGE                     = 2,           //The function maps the pixel values in the range specified by the minimumValue and maximumValue elements of the DisplayMapping structure to an 8-bit scale.
    IMAQ_90_PCT_DYNAMIC            = 3,           //The function maps the dynamic range containing the middle 90 percent of the cumulated histogram of the image to an 8-bit (256 grayscale values) scale.
    IMAQ_PERCENT_RANGE             = 4,           //The function maps the pixel values in the relative percentage range (0 to 100) of the cumulated histogram specified by minimumValue and maximumValue to an 8-bit scale.
    IMAQ_MAPPING_METHOD_SIZE_GUARD = 0xFFFFFFFF   
} MappingMethod;

typedef enum MatchingMode_enum {
    IMAQ_MATCH_SHIFT_INVARIANT    = 1,           //Searches for occurrences of the template image anywhere in the searchRect, assuming that the pattern is not rotated more than plus or minus 4 degrees.
    IMAQ_MATCH_ROTATION_INVARIANT = 2,           //Searches for occurrences of the pattern in the image with no restriction on the rotation of the pattern.
    IMAQ_MATCHING_MODE_SIZE_GUARD = 0xFFFFFFFF   
} MatchingMode;

typedef enum MathTransformMethod_enum {
    IMAQ_TRANSFORM_LINEAR                 = 0,           //The function uses linear remapping.
    IMAQ_TRANSFORM_LOG                    = 1,           //The function uses logarithmic remapping.
    IMAQ_TRANSFORM_EXP                    = 2,           //The function uses exponential remapping.
    IMAQ_TRANSFORM_SQR                    = 3,           //The function uses square remapping.
    IMAQ_TRANSFORM_SQRT                   = 4,           //The function uses square root remapping.
    IMAQ_TRANSFORM_POWX                   = 5,           //The function uses power X remapping.
    IMAQ_TRANSFORM_POW1X                  = 6,           //The function uses power 1/X remapping.
    IMAQ_MATH_TRANSFORM_METHOD_SIZE_GUARD = 0xFFFFFFFF   
} MathTransformMethod;

typedef enum MeasurementValue_enum {
    IMAQ_AREA                         = 0,           //Surface area of the particle in pixels.
    IMAQ_AREA_CALIBRATED              = 1,           //Surface area of the particle in calibrated units.
    IMAQ_NUM_HOLES                    = 2,           //Number of holes in the particle.
    IMAQ_AREA_OF_HOLES                = 3,           //Surface area of the holes in calibrated units.
    IMAQ_TOTAL_AREA                   = 4,           //Total surface area (holes and particle) in calibrated units.
    IMAQ_IMAGE_AREA                   = 5,           //Surface area of the entire image in calibrated units.
    IMAQ_PARTICLE_TO_IMAGE            = 6,           //Ratio, expressed as a percentage, of the surface area of a particle in relation to the total area of the particle.
    IMAQ_PARTICLE_TO_TOTAL            = 7,           //Ratio, expressed as a percentage, of the surface area of a particle in relation to the total area of the particle.
    IMAQ_CENTER_MASS_X                = 8,           //X-coordinate of the center of mass.
    IMAQ_CENTER_MASS_Y                = 9,           //Y-coordinate of the center of mass.
    IMAQ_LEFT_COLUMN                  = 10,          //Left edge of the bounding rectangle.
    IMAQ_TOP_ROW                      = 11,          //Top edge of the bounding rectangle.
    IMAQ_RIGHT_COLUMN                 = 12,          //Right edge of the bounding rectangle.
    IMAQ_BOTTOM_ROW                   = 13,          //Bottom edge of bounding rectangle.
    IMAQ_WIDTH                        = 14,          //Width of bounding rectangle in calibrated units.
    IMAQ_HEIGHT                       = 15,          //Height of bounding rectangle in calibrated units.
    IMAQ_MAX_SEGMENT_LENGTH           = 16,          //Length of longest horizontal line segment.
    IMAQ_MAX_SEGMENT_LEFT_COLUMN      = 17,          //Leftmost x-coordinate of longest horizontal line segment.
    IMAQ_MAX_SEGMENT_TOP_ROW          = 18,          //Y-coordinate of longest horizontal line segment.
    IMAQ_PERIMETER                    = 19,          //Outer perimeter of the particle.
    IMAQ_PERIMETER_OF_HOLES           = 20,          //Perimeter of all holes within the particle.
    IMAQ_SIGMA_X                      = 21,          //Sum of the particle pixels on the x-axis.
    IMAQ_SIGMA_Y                      = 22,          //Sum of the particle pixels on the y-axis.
    IMAQ_SIGMA_XX                     = 23,          //Sum of the particle pixels on the x-axis squared.
    IMAQ_SIGMA_YY                     = 24,          //Sum of the particle pixels on the y-axis squared.
    IMAQ_SIGMA_XY                     = 25,          //Sum of the particle pixels on the x-axis and y-axis.
    IMAQ_PROJ_X                       = 26,          //Projection corrected in X.
    IMAQ_PROJ_Y                       = 27,          //Projection corrected in Y.
    IMAQ_INERTIA_XX                   = 28,          //Inertia matrix coefficient in XX.
    IMAQ_INERTIA_YY                   = 29,          //Inertia matrix coefficient in YY.
    IMAQ_INERTIA_XY                   = 30,          //Inertia matrix coefficient in XY.
    IMAQ_MEAN_H                       = 31,          //Mean length of horizontal segments.
    IMAQ_MEAN_V                       = 32,          //Mean length of vertical segments.
    IMAQ_MAX_INTERCEPT                = 33,          //Length of longest segment of the convex hull.
    IMAQ_MEAN_INTERCEPT               = 34,          //Mean length of the chords in an object perpendicular to its max intercept.
    IMAQ_ORIENTATION                  = 35,          //The orientation based on the inertia of the pixels in the particle.
    IMAQ_EQUIV_ELLIPSE_MINOR          = 36,          //Total length of the axis of the ellipse having the same area as the particle and a major axis equal to half the max intercept.
    IMAQ_ELLIPSE_MAJOR                = 37,          //Total length of major axis having the same area and perimeter as the particle in calibrated units.
    IMAQ_ELLIPSE_MINOR                = 38,          //Total length of minor axis having the same area and perimeter as the particle in calibrated units.
    IMAQ_ELLIPSE_RATIO                = 39,          //Fraction of major axis to minor axis.
    IMAQ_RECT_LONG_SIDE               = 40,          //Length of the long side of a rectangle having the same area and perimeter as the particle in calibrated units.
    IMAQ_RECT_SHORT_SIDE              = 41,          //Length of the short side of a rectangle having the same area and perimeter as the particle in calibrated units.
    IMAQ_RECT_RATIO                   = 42,          //Ratio of rectangle long side to rectangle short side.
    IMAQ_ELONGATION                   = 43,          //Max intercept/mean perpendicular intercept.
    IMAQ_COMPACTNESS                  = 44,          //Particle area/(height x width).
    IMAQ_HEYWOOD                      = 45,          //Particle perimeter/perimeter of the circle having the same area as the particle.
    IMAQ_TYPE_FACTOR                  = 46,          //A complex factor relating the surface area to the moment of inertia.
    IMAQ_HYDRAULIC                    = 47,          //Particle area/particle perimeter.
    IMAQ_WADDLE_DISK                  = 48,          //Diameter of the disk having the same area as the particle in user units.
    IMAQ_DIAGONAL                     = 49,          //Diagonal of an equivalent rectangle in user units.
    IMAQ_MEASUREMENT_VALUE_SIZE_GUARD = 0xFFFFFFFF   
} MeasurementValue;

typedef enum MeterArcMode_enum {
    IMAQ_METER_ARC_ROI             = 0,           //The function uses the roi parameter and ignores the base, start, and end parameters.
    IMAQ_METER_ARC_POINTS          = 1,           //The function uses the base,start, and end parameters and ignores the roi parameter.
    IMAQ_METER_ARC_MODE_SIZE_GUARD = 0xFFFFFFFF   
} MeterArcMode;

typedef enum MorphologyMethod_enum {
    IMAQ_AUTOM                        = 0,           //The function uses a transformation that generates simpler particles that contain fewer details.
    IMAQ_CLOSE                        = 1,           //The function uses a transformation that fills tiny holes and smooths boundaries.
    IMAQ_DILATE                       = 2,           //The function uses a transformation that eliminates tiny holes isolated in particles and expands the contour of the particles according to the template defined by the structuring element.
    IMAQ_ERODE                        = 3,           //The function uses a transformation that eliminates pixels isolated in the background and erodes the contour of particles according to the template defined by the structuring element.
    IMAQ_GRADIENT                     = 4,           //The function uses a transformation that leaves only the pixels that would be added by the dilation process or eliminated by the erosion process.
    IMAQ_GRADIENTOUT                  = 5,           //The function uses a transformation that leaves only the pixels that would be added by the dilation process.
    IMAQ_GRADIENTIN                   = 6,           //The function uses a transformation that leaves only the pixels that would be eliminated by the erosion process.
    IMAQ_HITMISS                      = 7,           //The function uses a transformation that extracts each pixel located in a neighborhood exactly matching the template defined by the structuring element.
    IMAQ_OPEN                         = 8,           //The function uses a transformation that removes small particles and smooths boundaries.
    IMAQ_PCLOSE                       = 9,           //The function uses a transformation that fills tiny holes and smooths the inner contour of particles according to the template defined by the structuring element.
    IMAQ_POPEN                        = 10,          //The function uses a transformation that removes small particles and smooths the contour of particles according to the template defined by the structuring element.
    IMAQ_THICK                        = 11,          //The function uses a transformation that adds to an image those pixels located in a neighborhood that matches a template specified by the structuring element.
    IMAQ_THIN                         = 12,          //The function uses a transformation that eliminates pixels that are located in a neighborhood matching a template specified by the structuring element.
    IMAQ_MORPHOLOGY_METHOD_SIZE_GUARD = 0xFFFFFFFF   
} MorphologyMethod;

typedef enum ObjectType_enum {
    IMAQ_BRIGHT_OBJECTS         = 0,           //The function detects bright objects.
    IMAQ_DARK_OBJECTS           = 1,           //The function detects dark objects.
    IMAQ_OBJECT_TYPE_SIZE_GUARD = 0xFFFFFFFF   
} ObjectType;

typedef enum OutlineMethod_enum {
    IMAQ_EDGE_DIFFERENCE           = 0,           //The function uses a method that produces continuous contours by highlighting each pixel where an intensity variation occurs between itself and its three upper-left neighbors.
    IMAQ_EDGE_GRADIENT             = 1,           //The function uses a method that outlines contours where an intensity variation occurs along the vertical axis.
    IMAQ_EDGE_PREWITT              = 2,           //The function uses a method that extracts the outer contours of objects.
    IMAQ_EDGE_ROBERTS              = 3,           //The function uses a method that outlines the contours that highlight pixels where an intensity variation occurs along the diagonal axes.
    IMAQ_EDGE_SIGMA                = 4,           //The function uses a method that outlines contours and details by setting pixels to the mean value found in their neighborhood, if their deviation from this value is not significant.
    IMAQ_EDGE_SOBEL                = 5,           //The function uses a method that extracts the outer contours of objects.
    IMAQ_OUTLINE_METHOD_SIZE_GUARD = 0xFFFFFFFF   
} OutlineMethod;

typedef enum PaletteType_enum {
    IMAQ_PALETTE_GRAY            = 0,           //The function uses a palette that has a gradual gray-level variation from black to white.
    IMAQ_PALETTE_BINARY          = 1,           //The function uses a palette of 16 cycles of 16 different colors that is useful with binary images.
    IMAQ_PALETTE_GRADIENT        = 2,           //The function uses a palette that has a gradation from red to white with a prominent range of light blue in the upper value range.
    IMAQ_PALETTE_RAINBOW         = 3,           //The function uses a palette that has a gradation from blue to red with a prominent range of greens in the middle value range.
    IMAQ_PALETTE_TEMPERATURE     = 4,           //The function uses a palette that has a gradation from light brown to dark brown.
    IMAQ_PALETTE_USER            = 5,           //The function uses a palette defined by the user.
    IMAQ_PALETTE_TYPE_SIZE_GUARD = 0xFFFFFFFF   
} PaletteType;

typedef enum AttenuateMode_enum {
    IMAQ_ATTENUATE_LOW             = 0,           //The function attenuates low frequencies.
    IMAQ_ATTENUATE_HIGH            = 1,           //The function attenuates high frequencies.
    IMAQ_ATTENUATE_MODE_SIZE_GUARD = 0xFFFFFFFF   
} AttenuateMode;

typedef enum PhotometricMode_enum {
    IMAQ_WHITE_IS_ZERO               = 0,           //The function interprets zero-value pixels as white.
    IMAQ_BLACK_IS_ZERO               = 1,           //The function interprets zero-value pixels as black.
    IMAQ_PHOTOMETRIC_MODE_SIZE_GUARD = 0xFFFFFFFF   
} PhotometricMode;

typedef enum KernelFamily_enum {
    IMAQ_GRADIENT_FAMILY          = 0,           //The kernel is in the gradient family.
    IMAQ_LAPLACIAN_FAMILY         = 1,           //The kernel is in the Laplacian family.
    IMAQ_SMOOTHING_FAMILY         = 2,           //The kernel is in the smoothing family.
    IMAQ_GAUSSIAN_FAMILY          = 3,           //The kernel is in the Gaussian family.
    IMAQ_KERNEL_FAMILY_SIZE_GUARD = 0xFFFFFFFF   
} KernelFamily;

typedef enum PointSymbol_enum {
    IMAQ_POINT_AS_PIXEL          = 0,           //A single pixel represents a point in the overlay.
    IMAQ_POINT_AS_CROSS          = 1,           //A cross represents a point in the overlay.
    IMAQ_POINT_USER_DEFINED      = 2,           //The pattern supplied by the user represents a point in the overlay.
    IMAQ_POINT_SYMBOL_SIZE_GUARD = 0xFFFFFFFF   
} PointSymbol;

typedef enum PolarityType_enum {
    IMAQ_EDGE_RISING              = 1,           //The edge is a rising edge.
    IMAQ_EDGE_FALLING             = -1,          //The edge is a falling edge.
    IMAQ_POLARITY_TYPE_SIZE_GUARD = 0xFFFFFFFF   
} PolarityType;

typedef enum RakeDirection_enum {
    IMAQ_LEFT_TO_RIGHT             = 0,           //The function searches from the left side of the search area to the right side of the search area.
    IMAQ_RIGHT_TO_LEFT             = 1,           //The function searches from the right side of the search area to the left side of the search area.
    IMAQ_TOP_TO_BOTTOM             = 2,           //The function searches from the top side of the search area to the bottom side of the search area.
    IMAQ_BOTTOM_TO_TOP             = 3,           //The function searches from the bottom side of the search area to the top side of the search area.
    IMAQ_RAKE_DIRECTION_SIZE_GUARD = 0xFFFFFFFF   
} RakeDirection;

typedef enum RectOrientation_enum {
    IMAQ_BASE_INSIDE                 = 0,           //Specifies that the base of the rectangular image lies along the inside edge of the annulus.
    IMAQ_BASE_OUTSIDE                = 1,           //Specifies that the base of the rectangular image lies along the outside edge of the annulus.
    IMAQ_TEXT_ORIENTATION_SIZE_GUARD = 0xFFFFFFFF   
} RectOrientation;

typedef enum ReferenceMode_enum {
    IMAQ_COORD_X_Y                 = 0,           //This method requires three elements in the points array.
    IMAQ_COORD_ORIGIN_X            = 1,           //This method requires two elements in the points array.
    IMAQ_REFERENCE_MODE_SIZE_GUARD = 0xFFFFFFFF   
} ReferenceMode;

typedef enum ScalingMethod_enum {
    IMAQ_SCALE_TO_PRESERVE_AREA    = 0,           //Correction functions scale the image such that the features in the corrected image have the same area as the features in the input image.
    IMAQ_SCALE_TO_FIT              = 1,           //Correction functions scale the image such that the corrected image is the same size as the input image.
    IMAQ_SCALING_METHOD_SIZE_GUARD = 0xFFFFFFFF   
} ScalingMethod;

typedef enum ScalingMode_enum {
    IMAQ_SCALE_LARGER            = 0,           //The function duplicates pixels to make the image larger.
    IMAQ_SCALE_SMALLER           = 1,           //The function subsamples pixels to make the image smaller.
    IMAQ_SCALING_MODE_SIZE_GUARD = 0xFFFFFFFF   
} ScalingMode;

typedef enum SearchStrategy_enum {
    IMAQ_CONSERVATIVE               = 1,           //Instructs the pattern matching algorithm to use the largest possible amount of information from the image at the expense of slowing down the speed of the algorithm.
    IMAQ_BALANCED                   = 2,           //Instructs the pattern matching algorithm to balance the amount of information from the image it uses with the speed of the algorithm.
    IMAQ_AGGRESSIVE                 = 3,           //Instructs the pattern matching algorithm to use a lower amount of information from the image, which allows the algorithm to run quickly but at the expense of accuracy.
    IMAQ_VERY_AGGRESSIVE            = 4,           //Instructs the pattern matching algorithm to use the smallest possible amount of information from the image, which allows the algorithm to run at the highest speed possible but at the expense of accuracy.
    IMAQ_SEARCH_STRATEGY_SIZE_GUARD = 0xFFFFFFFF   
} SearchStrategy;

typedef enum ShapeMode_enum {
    IMAQ_SHAPE_RECT            = 1,           //The function draws a rectangle.
    IMAQ_SHAPE_OVAL            = 2,           //The function draws an oval.
    IMAQ_SHAPE_MODE_SIZE_GUARD = 0xFFFFFFFF   
} ShapeMode;

typedef enum SizeType_enum {
    IMAQ_KEEP_LARGE           = 0,           //The function keeps large particles remaining after the erosion.
    IMAQ_KEEP_SMALL           = 1,           //The function keeps small particles eliminated by the erosion.
    IMAQ_SIZE_TYPE_SIZE_GUARD = 0xFFFFFFFF   
} SizeType;

typedef enum SkeletonMethod_enum {
    IMAQ_SKELETON_L                 = 0,           //Uses an L-shaped structuring element in the skeleton function.
    IMAQ_SKELETON_M                 = 1,           //Uses an M-shaped structuring element in the skeleton function.
    IMAQ_SKELETON_INVERSE           = 2,           //Uses an L-shaped structuring element on an inverse of the image in the skeleton function.
    IMAQ_SKELETON_METHOD_SIZE_GUARD = 0xFFFFFFFF   
} SkeletonMethod;

typedef enum ParticleInfoMode_enum {
    IMAQ_BASIC_INFO                    = 0,           //The function returns only the following elements of each report: area, calibratedArea, boundingRect.
    IMAQ_ALL_INFO                      = 1,           //The function returns all the information about each particle.
    IMAQ_PARTICLE_INFO_MODE_SIZE_GUARD = 0xFFFFFFFF   
} ParticleInfoMode;

typedef enum ConcentricRakeDirection_enum {
    IMAQ_COUNTER_CLOCKWISE                    = 0,           //The function searches the search area in a counter-clockwise direction.
    IMAQ_CLOCKWISE                            = 1,           //The function searches the search area in a clockwise direction.
    IMAQ_CONCENTRIC_RAKE_DIRECTION_SIZE_GUARD = 0xFFFFFFFF   
} ConcentricRakeDirection;

typedef enum AxisOrientation_enum {
    IMAQ_DIRECT                      = 0,           //The y-axis direction corresponds to the y-axis direction of the Cartesian coordinate system.
    IMAQ_INDIRECT                    = 1,           //The y-axis direction corresponds to the y-axis direction of an image.
    IMAQ_AXIS_ORIENTATION_SIZE_GUARD = 0xFFFFFFFF   
} AxisOrientation;

typedef enum BarcodeType_enum {
    IMAQ_INVALID                 = -1,          //The barcode is not of a type known by NI Vision.
    IMAQ_CODABAR                 = 1,           //The barcode is of type Codabar.
    IMAQ_CODE39                  = 2,           //The barcode is of type Code 39.
    IMAQ_CODE93                  = 4,           //The barcode is of type Code 93.
    IMAQ_CODE128                 = 8,           //The barcode is of type Code 128.
    IMAQ_EAN8                    = 16,          //The barcode is of type EAN 8.
    IMAQ_EAN13                   = 32,          //The barcode is of type EAN 13.
    IMAQ_I2_OF_5                 = 64,          //The barcode is of type Code 25.
    IMAQ_MSI                     = 128,         //The barcode is of type MSI code.
    IMAQ_UPCA                    = 256,         //The barcode is of type UPC A.
    IMAQ_BARCODE_TYPE_SIZE_GUARD = 0xFFFFFFFF   
} BarcodeType;

typedef enum BorderMethod_enum {
    IMAQ_BORDER_MIRROR            = 0,           //Symmetrically copies pixel values from the image into the border.
    IMAQ_BORDER_COPY              = 1,           //Copies the value of the pixel closest to the edge of the image into the border.
    IMAQ_BORDER_CLEAR             = 2,           //Sets all pixels in the border to 0.
    IMAQ_BORDER_METHOD_SIZE_GUARD = 0xFFFFFFFF   
} BorderMethod;

typedef enum BrowserFrameStyle_enum {
    IMAQ_RAISED_FRAME                   = 0,           //Each thumbnail has a raised frame.
    IMAQ_BEVELLED_FRAME                 = 1,           //Each thumbnail has a beveled frame.
    IMAQ_OUTLINE_FRAME                  = 2,           //Each thumbnail has an outlined frame.
    IMAQ_HIDDEN_FRAME                   = 3,           //Each thumbnail has a hidden frame.
    IMAQ_STEP_FRAME                     = 4,           //Each thumbnail has a stepped frame.
    IMAQ_RAISED_OUTLINE_FRAME           = 5,           //Each thumbnail has a raised, outlined frame.
    IMAQ_BROWSER_FRAME_STYLE_SIZE_GUARD = 0xFFFFFFFF   
} BrowserFrameStyle;

typedef enum BrowserLocation_enum {
    IMAQ_INSERT_FIRST_FREE           = 0,           //Inserts the thumbnail in the first available cell.
    IMAQ_INSERT_END                  = 1,           //Inserts the thumbnail after the last occupied cell.
    IMAQ_BROWSER_LOCATION_SIZE_GUARD = 0xFFFFFFFF   
} BrowserLocation;

typedef enum CalibrationMode_enum {
    IMAQ_PERSPECTIVE                = 0,           //Functions correct for distortion caused by the camera's perspective.
    IMAQ_NONLINEAR                  = 1,           //Functions correct for distortion caused by the camera's lens.
    IMAQ_SIMPLE_CALIBRATION         = 2,           //Functions do not correct for distortion.
    IMAQ_CORRECTED_IMAGE            = 3,           //The image is already corrected.
    IMAQ_DISTORTION_MODE_SIZE_GUARD = 0xFFFFFFFF   
} CalibrationMode;

typedef enum CalibrationROI_enum {
    IMAQ_FULL_IMAGE                 = 0,           //The correction function corrects the whole image, regardless of the user-defined or calibration-defined ROIs.
    IMAQ_CALIBRATION_ROI            = 1,           //The correction function corrects the area defined by the calibration ROI.
    IMAQ_USER_ROI                   = 2,           //The correction function corrects the area defined by the user-defined ROI.
    IMAQ_CALIBRATION_AND_USER_ROI   = 3,           //The correction function corrects the area defined by the intersection of the user-defined ROI and the calibration ROI.
    IMAQ_CALIBRATION_OR_USER_ROI    = 4,           //The correction function corrects the area defined by the union of the user-defined ROI and the calibration ROI.
    IMAQ_CALIBRATION_ROI_SIZE_GUARD = 0xFFFFFFFF   
} CalibrationROI;

typedef enum CalibrationUnit_enum {
    IMAQ_UNDEFINED                   = 0,           //The image does not have a defined unit of measurement.
    IMAQ_ANGSTROM                    = 1,           //The unit of measure for the image is angstroms.
    IMAQ_MICROMETER                  = 2,           //The unit of measure for the image is micrometers.
    IMAQ_MILLIMETER                  = 3,           //The unit of measure for the image is millimeters.
    IMAQ_CENTIMETER                  = 4,           //The unit of measure for the image is centimeters.
    IMAQ_METER                       = 5,           //The unit of measure for the image is meters.
    IMAQ_KILOMETER                   = 6,           //The unit of measure for the image is kilometers.
    IMAQ_MICROINCH                   = 7,           //The unit of measure for the image is microinches.
    IMAQ_INCH                        = 8,           //The unit of measure for the image is inches.
    IMAQ_FOOT                        = 9,           //The unit of measure for the image is feet.
    IMAQ_NAUTICMILE                  = 10,          //The unit of measure for the image is nautical miles.
    IMAQ_GROUNDMILE                  = 11,          //The unit of measure for the image is ground miles.
    IMAQ_STEP                        = 12,          //The unit of measure for the image is steps.
    IMAQ_CALIBRATION_UNIT_SIZE_GUARD = 0xFFFFFFFF   
} CalibrationUnit;

typedef enum ColorIgnoreMode_enum {
    IMAQ_IGNORE_NONE                        = 0,           //Specifies that the function does not ignore any pixels.
    IMAQ_IGNORE_BLACK                       = 1,           //Specifies that the function ignores black pixels.
    IMAQ_IGNORE_WHITE                       = 2,           //Specifies that the function ignores white pixels.
    IMAQ_IGNORE_BLACK_AND_WHITE             = 3,           //Specifies that the function ignores black pixels and white pixels.
    IMAQ_BLACK_WHITE_IGNORE_MODE_SIZE_GUARD = 0xFFFFFFFF   
} ColorIgnoreMode;

typedef enum ColorMode_enum {
    IMAQ_RGB                   = 0,           //The function operates in the RGB (Red, Blue, Green) color space.
    IMAQ_HSL                   = 1,           //The function operates in the HSL (Hue, Saturation, Luminance) color space.
    IMAQ_HSV                   = 2,           //The function operates in the HSV (Hue, Saturation, Value) color space.
    IMAQ_HSI                   = 3,           //The function operates in the HSI (Hue, Saturation, Intensity) color space.
    IMAQ_CIE                   = 4,           //The function operates in the CIE L*a*b* color space.
    IMAQ_CIEXYZ                = 5,           //The function operates in the CIE XYZ color space.
    IMAQ_COLOR_MODE_SIZE_GUARD = 0xFFFFFFFF   
} ColorMode;

typedef enum ColorSensitivity_enum {
    IMAQ_SENSITIVITY_LOW              = 0,           //Instructs the algorithm to divide the hue plane into a low number of sectors, allowing for simple color analysis.
    IMAQ_SENSITIVITY_MED              = 1,           //Instructs the algorithm to divide the hue plane into a medium number of sectors, allowing for color analysis that balances sensitivity and complexity.
    IMAQ_SENSITIVITY_HIGH             = 2,           //Instructs the algorithm to divide the hue plane into a high number of sectors, allowing for complex, sensitive color analysis.
    IMAQ_COLOR_SENSITIVITY_SIZE_GUARD = 0xFFFFFFFF   
} ColorSensitivity;

typedef enum LevelType_enum {
    IMAQ_ABSOLUTE              = 0,           //The function evaluates the threshold and hysteresis values as absolute values.
    IMAQ_RELATIVE              = 1,           //The function evaluates the threshold and hysteresis values relative to the dynamic range of the given path.
    IMAQ_LEVEL_TYPE_SIZE_GUARD = 0xFFFFFFFF   
} LevelType;

typedef enum ComplexPlane_enum {
    IMAQ_REAL                     = 0,           //The function operates on the real plane of the complex image.
    IMAQ_IMAGINARY                = 1,           //The function operates on the imaginary plane of the complex image.
    IMAQ_MAGNITUDE                = 2,           //The function operates on the magnitude plane of the complex image.
    IMAQ_PHASE                    = 3,           //The function operates on the phase plane of the complex image.
    IMAQ_COMPLEX_PLANE_SIZE_GUARD = 0xFFFFFFFF   
} ComplexPlane;

typedef enum LearningMode_enum {
    IMAQ_LEARN_ALL                  = 0,           //The function extracts information for shift- and rotation-invariant matching.
    IMAQ_LEARN_SHIFT_INFORMATION    = 1,           //The function extracts information for shift-invariant matching.
    IMAQ_LEARN_ROTATION_INFORMATION = 2,           //The function extracts information for rotation-invariant matching.
    IMAQ_LEARNING_MODE_SIZE_GUARD   = 0xFFFFFFFF   
} LearningMode;

typedef enum ContourType_enum {
    IMAQ_EMPTY_CONTOUR           = 0,           //The contour is empty.
    IMAQ_POINT                   = 1,           //The contour represents a point.
    IMAQ_LINE                    = 2,           //The contour represents a line.
    IMAQ_RECT                    = 3,           //The contour represents a rectangle.
    IMAQ_OVAL                    = 4,           //The contour represents an oval.
    IMAQ_CLOSED_CONTOUR          = 5,           //The contour represents a series of connected points where the last point connects to the first.
    IMAQ_OPEN_CONTOUR            = 6,           //The contour represents a series of connected points where the last point does not connect to the first.
    IMAQ_ANNULUS                 = 7,           //The contour represents an annulus.
    IMAQ_ROTATED_RECT            = 8,           //The contour represents a rotated rectangle.
    IMAQ_CONTOUR_TYPE_SIZE_GUARD = 0xFFFFFFFF   
} ContourType;

typedef enum DetectionMode_enum {
    IMAQ_DETECT_PEAKS              = 0,           //The function detects peaks.
    IMAQ_DETECT_VALLEYS            = 1,           //The function detects valleys.
    IMAQ_DETECTION_MODE_SIZE_GUARD = 0xFFFFFFFF   
} DetectionMode;

typedef enum Direction3D_enum {
    IMAQ_3D_NW                   = 0,           //The viewing angle for the 3D image is from the northwest.
    IMAQ_3D_SW                   = 1,           //The viewing angle for the 3D image is from the southwest.
    IMAQ_3D_SE                   = 2,           //The viewing angle for the 3D image is from the southeast.
    IMAQ_3D_NE                   = 3,           //The viewing angle for the 3D image is from the northeast.
    IMAQ_DIRECTION_3D_SIZE_GUARD = 0xFFFFFFFF   
} Direction3D;

typedef enum DrawMode_enum {
    IMAQ_DRAW_VALUE           = 0,           //Draws the boundary of the object with the specified pixel value.
    IMAQ_DRAW_INVERT          = 2,           //Inverts the pixel values of the boundary of the object.
    IMAQ_PAINT_VALUE          = 1,           //Fills the object with the given pixel value.
    IMAQ_PAINT_INVERT         = 3,           //Inverts the pixel values of the object.
    IMAQ_HIGHLIGHT_VALUE      = 4,           //The function fills the object by highlighting the enclosed pixels with the color of the object.
    IMAQ_DRAW_MODE_SIZE_GUARD = 0xFFFFFFFF   
} DrawMode;

typedef enum EdgeProcess_enum {
    IMAQ_FIRST                   = 0,           //The function looks for the first edge.
    IMAQ_FIRST_AND_LAST          = 1,           //The function looks for the first and last edge.
    IMAQ_ALL                     = 2,           //The function looks for all edges.
    IMAQ_EDGE_PROCESS_SIZE_GUARD = 0xFFFFFFFF   
} EdgeProcess;

typedef enum FlipAxis_enum {
    IMAQ_HORIZONTAL_AXIS      = 0,           //Flips the image over the central horizontal axis.
    IMAQ_VERTICAL_AXIS        = 1,           //Flips the image over the central vertical axis.
    IMAQ_CENTER_AXIS          = 2,           //Flips the image over both the central vertical and horizontal axes.
    IMAQ_DIAG_L_TO_R_AXIS     = 3,           //Flips the image over an axis from the upper left corner to lower right corner.
    IMAQ_DIAG_R_TO_L_AXIS     = 4,           //Flips the image over an axis from the upper right corner to lower left corner.
    IMAQ_FLIP_AXIS_SIZE_GUARD = 0xFFFFFFFF   
} FlipAxis;

typedef enum FontColor_enum {
    IMAQ_WHITE                 = 0,           //Draws text in white.
    IMAQ_BLACK                 = 1,           //Draws text in black.
    IMAQ_INVERT                = 2,           //Inverts the text pixels.
    IMAQ_BLACK_ON_WHITE        = 3,           //Draws text in black with a white background.
    IMAQ_WHITE_ON_BLACK        = 4,           //Draws text in white with a black background.
    IMAQ_FONT_COLOR_SIZE_GUARD = 0xFFFFFFFF   
} FontColor;

typedef enum ImageFeatureMode_enum {
    IMAQ_COLOR_AND_SHAPE_FEATURES = 0,           //Instructs the function to use the color and the shape features of the color pattern.
    IMAQ_COLOR_FEATURES           = 1,           //Instructs the function to use the color features of the color pattern.
    IMAQ_SHAPE_FEATURES           = 2,           //Instructs the function to use the shape features of the color pattern.
    IMAQ_FEATURE_MODE_SIZE_GUARD  = 0xFFFFFFFF   
} ImageFeatureMode;

typedef enum ImageType_enum {
    IMAQ_IMAGE_U8              = 0,           //The image type is 8-bit unsigned integer grayscale.
    IMAQ_IMAGE_I16             = 1,           //The image type is 16-bit signed integer grayscale.
    IMAQ_IMAGE_SGL             = 2,           //The image type is 32-bit floating-point grayscale.
    IMAQ_IMAGE_COMPLEX         = 3,           //The image type is complex.
    IMAQ_IMAGE_RGB             = 4,           //The image type is RGB color.
    IMAQ_IMAGE_HSL             = 5,           //The image type is HSL color.
    IMAQ_IMAGE_RGB_U64         = 6,           //The image type is 64-bit unsigned RGB color.
    IMAQ_IMAGE_TYPE_SIZE_GUARD = 0xFFFFFFFF   
} ImageType;

typedef enum InterpolationMethod_enum {
    IMAQ_ZERO_ORDER                      = 0,           //The function uses an interpolation method that interpolates new pixel values using the nearest valid neighboring pixel.
    IMAQ_BILINEAR                        = 1,           //The function uses an interpolation method that interpolates new pixel values using a bidirectional average of the neighboring pixels.
    IMAQ_QUADRATIC                       = 2,           //The function uses an interpolation method that interpolates new pixel values using a quadratic approximating polynomial.
    IMAQ_CUBIC_SPLINE                    = 3,           //The function uses an interpolation method that interpolates new pixel values by fitting them to a cubic spline curve, where the curve is based on known pixel values from the image.
    IMAQ_INTERPOLATION_METHOD_SIZE_GUARD = 0xFFFFFFFF   
} InterpolationMethod;

typedef enum ThresholdMethod_enum {
    IMAQ_THRESH_CLUSTERING           = 0,           //The function uses a method that sorts the histogram of the image within a discrete number of classes corresponding to the number of phases perceived in an image.
    IMAQ_THRESH_ENTROPY              = 1,           //The function uses a method that is best for detecting particles that are present in minuscule proportions on the image.
    IMAQ_THRESH_METRIC               = 2,           //The function uses a method that is well-suited for images in which classes are not too disproportionate.
    IMAQ_THRESH_MOMENTS              = 3,           //The function uses a method that is suited for images that have poor contrast.
    IMAQ_THRESH_INTERCLASS           = 4,           //The function uses a method that is well-suited for images in which classes have well separated pixel value distributions.
    IMAQ_THRESHOLD_METHOD_SIZE_GUARD = 0xFFFFFFFF   
} ThresholdMethod;

typedef enum ComparisonFunction_enum {
    IMAQ_CLEAR_LESS                  = 0,           //The comparison is true if the source pixel value is less than the comparison image pixel value.
    IMAQ_CLEAR_LESS_OR_EQUAL         = 1,           //The comparison is true if the source pixel value is less than or equal to the comparison image pixel value.
    IMAQ_CLEAR_EQUAL                 = 2,           //The comparison is true if the source pixel value is equal to the comparison image pixel value.
    IMAQ_CLEAR_GREATER_OR_EQUAL      = 3,           //The comparison is true if the source pixel value is greater than or equal to the comparison image pixel value.
    IMAQ_CLEAR_GREATER               = 4,           //The comparison is true if the source pixel value is greater than the comparison image pixel value.
    IMAQ_COMPARE_FUNCTION_SIZE_GUARD = 0xFFFFFFFF   
} ComparisonFunction;

typedef enum WindowOptions_enum {
    IMAQ_WIND_RESIZABLE            = 1,           //When present, the user may resize the window interactively.
    IMAQ_WIND_TITLEBAR             = 2,           //When present, the title bar on the window is visible.
    IMAQ_WIND_CLOSEABLE            = 4,           //When present, the close box is available.
    IMAQ_WIND_TOPMOST              = 8,           //When present, the window is always on top.
    IMAQ_WINDOW_OPTIONS_SIZE_GUARD = 0xFFFFFFFF   
} WindowOptions;

typedef enum TextAlignment_enum {
    IMAQ_LEFT                      = 0,           //Left aligns the text at the reference point.
    IMAQ_CENTER                    = 1,           //Centers the text around the reference point.
    IMAQ_RIGHT                     = 2,           //Right aligns the text at the reference point.
    IMAQ_TEXT_ALIGNMENT_SIZE_GUARD = 0xFFFFFFFF   
} TextAlignment;

typedef enum SpokeDirection_enum {
    IMAQ_OUTSIDE_TO_INSIDE          = 0,           //The function searches from the outside of the search area to the inside of the search area.
    IMAQ_INSIDE_TO_OUTSIDE          = 1,           //The function searches from the inside of the search area to the outside of the search area.
    IMAQ_SPOKE_DIRECTION_SIZE_GUARD = 0xFFFFFFFF   
} SpokeDirection;

typedef enum WindowThreadPolicy_enum {
    IMAQ_CALLING_THREAD                  = 0,           //Using this policy, NI Vision creates windows in the thread that makes the first display function call for a given window number.
    IMAQ_SEPARATE_THREAD                 = 1,           //Using this policy, NI Vision creates windows in a separate thread and processes messages for the windows automatically.
    IMAQ_WINDOW_THREAD_POLICY_SIZE_GUARD = 0xFFFFFFFF   
} WindowThreadPolicy;

typedef enum WindowEventType_enum {
    IMAQ_NO_EVENT                     = 0,           //No event occurred since the last call to imaqGetLastEvent().
    IMAQ_CLICK_EVENT                  = 1,           //The user clicked on a window.
    IMAQ_DRAW_EVENT                   = 2,           //The user drew an ROI in a window.
    IMAQ_MOVE_EVENT                   = 3,           //The user moved a window.
    IMAQ_SIZE_EVENT                   = 4,           //The user sized a window.
    IMAQ_SCROLL_EVENT                 = 5,           //The user scrolled a window.
    IMAQ_ACTIVATE_EVENT               = 6,           //The user activated a window.
    IMAQ_CLOSE_EVENT                  = 7,           //The user closed a window.
    IMAQ_DOUBLE_CLICK_EVENT           = 8,           //The user double-clicked in a window.
    IMAQ_WINDOW_EVENT_TYPE_SIZE_GUARD = 0xFFFFFFFF   
} WindowEventType;

typedef enum VisionInfoType_enum {
    IMAQ_ANY_VISION_INFO             = 0,           //The function checks if any extra vision information is associated with the image.
    IMAQ_PATTERN_MATCHING_INFO       = 1,           //The function checks if any pattern matching template information is associated with the image.
    IMAQ_CALIBRATION_INFO            = 2,           //The function checks if any calibration information is associated with the image.
    IMAQ_OVERLAY_INFO                = 3,           //The function checks if any overlay information is associated with the image.
    IMAQ_VISION_INFO_TYPE_SIZE_GUARD = 0xFFFFFFFF   
} VisionInfoType;

typedef enum VerticalTextAlignment_enum {
    IMAQ_BOTTOM                             = 0,           //Aligns the bottom of the text at the reference point.
    IMAQ_TOP                                = 1,           //Aligns the top of the text at the reference point.
    IMAQ_BASELINE                           = 2,           //Aligns the baseline of the text at the reference point.
    IMAQ_VERTICAL_TEXT_ALIGNMENT_SIZE_GUARD = 0xFFFFFFFF   
} VerticalTextAlignment;

typedef enum TwoEdgePolarityType_enum {
    IMAQ_NONE                              = 0,           //The function ignores the polarity of the edges.
    IMAQ_RISING_FALLING                    = 1,           //The polarity of the first edge is rising (dark to light) and the polarity of the second edge is falling (light to dark).
    IMAQ_FALLING_RISING                    = 2,           //The polarity of the first edge is falling (light to dark) and the polarity of the second edge is rising (dark to light).
    IMAQ_RISING_RISING                     = 3,           //The polarity of the first edge is rising (dark to light) and the polarity of the second edge is rising (dark to light).
    IMAQ_FALLING_FALLING                   = 4,           //The polarity of the first edge is falling (light to dark) and the polarity of the second edge is falling (light to dark).
    IMAQ_TWO_EDGE_POLARITY_TYPE_SIZE_GUARD = 0xFFFFFFFF   
} TwoEdgePolarityType;

typedef enum TruncateMode_enum {
    IMAQ_TRUNCATE_LOW             = 0,           //The function truncates low frequencies.
    IMAQ_TRUNCATE_HIGH            = 1,           //The function truncates high frequencies.
    IMAQ_TRUNCATE_MODE_SIZE_GUARD = 0xFFFFFFFF   
} TruncateMode;

typedef enum Tool_enum {
    IMAQ_NO_TOOL              = -1,          //No tool is in the selected state.
    IMAQ_SELECTION_TOOL       = 0,           //The selection tool selects an existing ROI in an image.
    IMAQ_POINT_TOOL           = 1,           //The point tool draws a point on the image.
    IMAQ_LINE_TOOL            = 2,           //The line tool draws a line on the image.
    IMAQ_RECTANGLE_TOOL       = 3,           //The rectangle tool draws a rectangle on the image.
    IMAQ_OVAL_TOOL            = 4,           //The oval tool draws an oval on the image.
    IMAQ_POLYGON_TOOL         = 5,           //The polygon tool draws a polygon on the image.
    IMAQ_CLOSED_FREEHAND_TOOL = 6,           //The closed freehand tool draws closed freehand shapes on the image.
    IMAQ_ANNULUS_TOOL         = 7,           //The annulus tool draws annuluses on the image.
    IMAQ_ZOOM_TOOL            = 8,           //The zoom tool controls the zoom of an image.
    IMAQ_PAN_TOOL             = 9,           //The pan tool shifts the view of the image.
    IMAQ_POLYLINE_TOOL        = 10,          //The polyline tool draws a series of connected straight lines on the image.
    IMAQ_FREEHAND_TOOL        = 11,          //The freehand tool draws freehand lines on the image.
    IMAQ_ROTATED_RECT_TOOL    = 12,          //The rotated rectangle tool draws rotated rectangles on the image.
    IMAQ_TOOL_SIZE_GUARD      = 0xFFFFFFFF   
} Tool;

typedef enum TIFFCompressionType_enum {
    IMAQ_NO_COMPRESSION                   = 0,           //The function does not compress the TIFF file.
    IMAQ_JPEG                             = 1,           //The function uses the JPEG compression algorithm to compress the TIFF file.
    IMAQ_RUN_LENGTH                       = 2,           //The function uses a run length compression algorithm to compress the TIFF file.
    IMAQ_ZIP                              = 3,           //The function uses the ZIP compression algorithm to compress the TIFF file.
    IMAQ_TIFF_COMPRESSION_TYPE_SIZE_GUARD = 0xFFFFFFFF   
} TIFFCompressionType;

typedef enum DataMatrixCellSampleSize_enum {
    IMAQ_AUTO_DETECT_CELL_SAMPLE_SIZE            = -2,          //The function will try each sample size and use the one which decodes the Data Matrix barcode within the fewest iterations and utilizing the least amount of error correction.
    IMAQ_1x1                                     = 1,           //The function will use a 1x1 sized sample from each cell.
    IMAQ_2x2                                     = 2,           //The function will use a 2x2 sized sample from each cell.
    IMAQ_3x3                                     = 3,           //The function will use a 3x3 sized sample from each cell.
    IMAQ_4x4                                     = 4,           //The function will use a 4x4 sized sample from each cell.
    IMAQ_5x5                                     = 5,           //The function will use a 5x5 sized sample from each cell.
    IMAQ_6x6                                     = 6,           //The function will use a 6x6 sized sample from each cell.
    IMAQ_7x7                                     = 7,           //The function will use a 7x7 sized sample from each cell.
    IMAQ_DATA_MATRIX_CELL_SAMPLE_SIZE_SIZE_GUARD = 0xFFFFFFFF   
} DataMatrixCellSampleSize;

typedef enum RegistrationMethod_enum {
    IMAQ_REGISTRATION_NONE        = 0,           //No registration.
    IMAQ_REGISTRATION_PERSPECTIVE = 1,           //Adjust image to correct for minor variations in alignment or perspective.
    IMAQ_REGISTRATION_SIZE_GUARD  = 0xFFFFFFFF   
} RegistrationMethod;

typedef enum FeatureType_enum {
    IMAQ_NOT_FOUND_FEATURE                   = 0,   //Specifies the feature is not found.
    IMAQ_CIRCLE_FEATURE                      = 1,   //Specifies the feature is a circle.
    IMAQ_ELLIPSE_FEATURE                     = 2,   //Specifies the feature is an ellipse.
    IMAQ_CONST_CURVE_FEATURE                 = 3,   //Specifies the features is a constant curve.
    IMAQ_RECTANGLE_FEATURE                   = 4,   //Specifies the feature is a rectangle.
    IMAQ_LEG_FEATURE                         = 5,   //Specifies the feature is a leg.
    IMAQ_CORNER_FEATURE                      = 6,   //Specifies the feature is a corner.
    IMAQ_PARALLEL_LINE_PAIR_FEATURE          = 7,   //Specifies the feature is a parallel line pair.
    IMAQ_PAIR_OF_PARALLEL_LINE_PAIRS_FEATURE = 8,   //Specifies the feature is a pair of parallel line pairs.
    IMAQ_LINE_FEATURE                        = 9,   //Specifies the feature is a line.
    IMAQ_CLOSED_CURVE_FEATURE                = 10,  //Specifies the feature is a closed curve.
} FeatureType;

typedef enum WindowBackgroundFillStyle_enum {
    IMAQ_FILL_STYLE_SOLID      = 0,           //Fill the display window with a solid color.
    IMAQ_FILL_STYLE_HATCH      = 2,           //Fill the display window with a pattern defined by WindowBackgroundHatchStyle.
    IMAQ_FILL_STYLE_DEFAULT    = 3,           //Fill the display window with the NI Vision default pattern.
    IMAQ_FILL_STYLE_SIZE_GUARD = 0xFFFFFFFF   
} WindowBackgroundFillStyle;

typedef enum LocalThresholdMethod_enum {
    IMAQ_NIBLACK                           = 0,           //The function computes thresholds for each pixel based on its local statistics using the Niblack local thresholding algorithm.
    IMAQ_BACKGROUND_CORRECTION             = 1,           //The function performs background correction first to eliminate non-uniform lighting effects, then performs thresholding usind the Otsu thresholding algorithm.
    IMAQ_LOCAL_THRESHOLD_METHOD_SIZE_GUARD = 0xFFFFFFFF   
} LocalThresholdMethod;

typedef enum FlattenType_enum {
    IMAQ_FLATTEN_IMAGE                 = 0,           //Flattens just the image data.
    IMAQ_FLATTEN_IMAGE_AND_VISION_INFO = 1,           //Flattens the image data and any Vision information associated with the image.
    IMAQ_FLATTEN_TYPE_SIZE_GUARD       = 0xFFFFFFFF   
} FlattenType;

typedef enum CompressionType_enum {
    IMAQ_COMPRESSION_NONE            = 0,           //Specifies that the function should not compress the image.
    IMAQ_COMPRESSION_JPEG            = 1,           //Specifies that the function should use lossy JPEG compression on the image.
    IMAQ_COMPRESSION_PACKED_BINARY   = 2,           //Specifies that the function should use lossless binary packing on the image.
    IMAQ_COMPRESSION_TYPE_SIZE_GUARD = 0xFFFFFFFF   
} CompressionType;

typedef enum LinearAveragesMode_enum {
    IMAQ_COLUMN_AVERAGES                 = 1,           //Specifies that the function calculates the mean pixel value of each column.
    IMAQ_ROW_AVERAGES                    = 2,           //Specifies that the function calculates the mean pixel value of each row.
    IMAQ_RISING_DIAGONAL_AVERAGES        = 4,           //Specifies that the function calculates the mean pixel value of each diagonal running from the lower left to the upper right of the inspected area of the image.
    IMAQ_FALLING_DIAGONAL_AVERAGES       = 8,           //Specifies that the function calculates the mean pixel value of each diagonal running from the upper left to the lower right of the inspected area of the image.
    IMAQ_ALL_LINEAR_AVERAGES             = 15,          //Specifies that the function calculates all four linear mean pixel values.
    IMAQ_LINEAR_AVERAGES_MODE_SIZE_GUARD = 0xFFFFFFFF   
} LinearAveragesMode;

typedef enum WindowBackgroundHatchStyle_enum {
    IMAQ_HATCH_STYLE_HORIZONTAL        = 0,           //The background of the display window will be horizontal bars.
    IMAQ_HATCH_STYLE_VERTICAL          = 1,           //The background of the display window will be vertical bars.
    IMAQ_HATCH_STYLE_FORWARD_DIAGONAL  = 2,           //The background of the display window will be diagonal bars.
    IMAQ_HATCH_STYLE_BACKWARD_DIAGONAL = 3,           //The background of the display window will be diagonal bars.
    IMAQ_HATCH_STYLE_CROSS             = 4,           //The background of the display window will be intersecting horizontal and vertical bars.
    IMAQ_HATCH_STYLE_CROSS_HATCH       = 5,           //The background of the display window will be intersecting forward and backward diagonal bars.
    IMAQ_HATCH_STYLE_SIZE_GUARD        = 0xFFFFFFFF   
} WindowBackgroundHatchStyle;

typedef enum NormalizationMethod_enum {
    IMAQ_NORMALIZATION_NONE               = 0,           //No normalization.
    IMAQ_NORMALIZATION_HISTOGRAM_MATCHING = 1,           //Adjust image so its histogram is similar to the golden template's histogram.
    IMAQ_NORMALIZATION_AVERAGE_MATCHING   = 2,           //Adjust image so its mean pixel value equals the golden template's mean pixel value.
    IMAQ_NORMALIZATION_SIZE_GUARD         = 0xFFFFFFFF   
} NormalizationMethod;

typedef enum WaveletTransformMode_enum {
    IMAQ_WAVELET_TRANSFORM_INTEGER         = 0,           //Uses a 5-3 reversible integer transform.
    IMAQ_WAVELET_TRANSFORM_FLOATING_POINT  = 1,           //Performs a 9-7 irreversible floating-point transform.
    IMAQ_WAVELET_TRANSFORM_MODE_SIZE_GUARD = 0xFFFFFFFF   
} WaveletTransformMode;

typedef enum DataMatrixGradingMode_enum {
    IMAQ_NO_GRADING                          = 0,           //The function does not make any preparatory calculations.
    IMAQ_PREPARE_FOR_AIM                     = 1,           //The function prepares the image for grading using the AIM Print Quality metrics.
    IMAQ_DATA_MATRIX_GRADING_MODE_SIZE_GUARD = 0xFFFFFFFF   
} DataMatrixGradingMode;

typedef enum ExtractionMode_enum {
    IMAQ_NORMAL_IMAGE               = 0,           //Specifies that the function makes no assumptions about the uniformity of objects in the image or the image background.
    IMAQ_UNIFORM_REGIONS            = 1,           //Specifies that the function assumes that either the objects in the image or the image background consists of uniform pixel values.
    IMAQ_EXTRACTION_MODE_SIZE_GUARD = 0xFFFFFFFF   
} ExtractionMode;

typedef enum DataMatrixMirrorMode_enum {
    IMAQ_AUTO_DETECT_MIRROR                 = -2,          //Specifies that the function should determine if the Data Matrix barcode is mirrored.
    IMAQ_APPEARS_NORMAL                     = 0,           //Specifies that the function should expect the Data Matrix barcode to appear normal.
    IMAQ_APPEARS_MIRRORED                   = 1,           //Specifies that the function should expect the Data Matrix barcode to appear mirrored.
    IMAQ_DATA_MATRIX_MIRROR_MODE_SIZE_GUARD = 0xFFFFFFFF   
} DataMatrixMirrorMode;

typedef enum Barcode2DType_enum {
    IMAQ_PDF417                     = 0,           //The 2D barcode is of type PDF417.
    IMAQ_DATA_MATRIX_ECC_000        = 1,           //The 2D barcode is of type Data Matrix ECC 000.
    IMAQ_DATA_MATRIX_ECC_050        = 2,           //The 2D barcode is of type Data Matrix ECC 050.
    IMAQ_DATA_MATRIX_ECC_080        = 3,           //The 2D barcode is of type Data Matrix ECC 080.
    IMAQ_DATA_MATRIX_ECC_100        = 4,           //The 2D barcode is of type Data Matrix ECC 100.
    IMAQ_DATA_MATRIX_ECC_140        = 5,           //The 2D barcode is of type Data Matrix ECC 140.
    IMAQ_DATA_MATRIX_ECC_200        = 6,           //The 2D barcode is of type Data Matrix ECC 200.
    IMAQ_BARCODE_2D_TYPE_SIZE_GUARD = 0xFFFFFFFF   
} Barcode2DType;

typedef enum DataMatrixCellFilterMode_enum {
    IMAQ_AUTO_DETECT_CELL_FILTER_MODE            = -2,          //The function will try all filter modes and uses the one that decodes the Data Matrix barcode within the fewest iterations and utilizing the least amount of error correction.
    IMAQ_AVERAGE_FILTER                          = 0,           //The function sets the pixel value for the cell to the average of the sampled pixels.
    IMAQ_MEDIAN_FILTER                           = 1,           //The function sets the pixel value for the cell to the median of the sampled pixels.
    IMAQ_CENTRAL_AVERAGE_FILTER                  = 2,           //The function sets the pixel value for the cell to the average of the pixels in the center of the cell sample.
    IMAQ_HIGH_AVERAGE_FILTER                     = 3,           //The function sets the pixel value for the cell to the average value of the half of the sampled pixels with the highest pixel values.
    IMAQ_LOW_AVERAGE_FILTER                      = 4,           //The function sets the pixel value for the cell to the average value of the half of the sampled pixels with the lowest pixel values.
    IMAQ_VERY_HIGH_AVERAGE_FILTER                = 5,           //The function sets the pixel value for the cell to the average value of the ninth of the sampled pixels with the highest pixel values.
    IMAQ_VERY_LOW_AVERAGE_FILTER                 = 6,           //The function sets the pixel value for the cell to the average value of the ninth of the sampled pixels with the lowest pixel values.
    IMAQ_ALL_CELL_FILTERS                        = 8,           //The function tries each filter mode, starting with IMAQ_AVERAGE_FILTER and ending with IMAQ_VERY_LOW_AVERAGE_FILTER, stopping once a filter mode decodes correctly.
    IMAQ_DATA_MATRIX_CELL_FILTER_MODE_SIZE_GUARD = 0xFFFFFFFF   
} DataMatrixCellFilterMode;

typedef enum DataMatrixPolarity_enum {
    IMAQ_AUTO_DETECT_POLARITY            = -2,          //Sets the function to determine the Data Matrix barcode polarity automatically.
    IMAQ_BLACK_DATA_ON_WHITE_BACKGROUND  = 0,           //Sets the function to read Data Matrix barcodes with dark data on a bright background.
    IMAQ_WHITE_DATA_ON_BLACK_BACKGROUND  = 1,           //Sets the function to read Data Matrix barcodes with bright data on a dark background.
    IMAQ_DATA_MATRIX_POLARITY_SIZE_GUARD = 0xFFFFFFFF   
} DataMatrixPolarity;

typedef enum DataMatrixECC_enum {
    IMAQ_AUTO_DETECT_ECC            = -2,          //Sets the function to determine the Data Matrix barcode ECC automatically.
    IMAQ_ECC_000                    = 0,           //Sets the function to read Data Matrix barcodes of ECC 000 only.
    IMAQ_ECC_050                    = 50,          //Sets the function to read Data Matrix barcodes of ECC 050 only.
    IMAQ_ECC_080                    = 80,          //Sets the function to read Data Matrix barcodes of ECC 080 only.
    IMAQ_ECC_100                    = 100,         //Sets the function to read Data Matrix barcodes of ECC 100 only.
    IMAQ_ECC_140                    = 140,         //Sets the function to read Data Matrix barcodes of ECC 140 only.
    IMAQ_ECC_000_140                = 190,         //Sets the function to read Data Matrix barcodes of ECC 000, ECC 050, ECC 080, ECC 100, and ECC 140 only.
    IMAQ_ECC_200                    = 200,         //Sets the function to read Data Matrix barcodes of ECC 200 only.
    IMAQ_DATA_MATRIX_ECC_SIZE_GUARD = 0xFFFFFFFF   
} DataMatrixECC;

typedef enum DataMatrixDemodulationMode_enum {
    IMAQ_AUTO_DETECT_DEMODULATION_MODE            = -2,          //The function will try each demodulation mode and use the one which decodes the Data Matrix barcode within the fewest iterations and utilizing the least amount of error correction.
    IMAQ_HISTOGRAM                                = 0,           //The function uses a histogram of all of the Data Matrix cells to calculate a threshold.
    IMAQ_LOCAL_CONTRAST                           = 1,           //The function examines each of the cell's neighbors to determine if the cell is on or off.
    IMAQ_COMBINED                                 = 2,           //The function uses the histogram of the Data Matrix barcode to calculate a threshold.
    IMAQ_ALL_DEMODULATION_MODES                   = 3,           //The function tries IMAQ_HISTOGRAM, then IMAQ_LOCAL_CONTRAST and then IMAQ_COMBINATION, stopping once one mode is successful.
    IMAQ_DATA_MATRIX_DEMODULATION_MODE_SIZE_GUARD = 0xFFFFFFFF   
} DataMatrixDemodulationMode;

typedef enum DataMatrixCellFillMode_enum {
    IMAQ_AUTO_DETECT_CELL_FILL_MODE            = -2,          //Sets the function to determine the Data Matrix barcode cell fill percentage automatically.
    IMAQ_LOW_FILL                              = 0,           //Sets the function to read Data Matrix barcodes with a cell fill percentage of less than 30 percent.
    IMAQ_NORMAL_FILL                           = 1,           //Sets the function to read Data Matrix barcodes with a cell fill percentage greater than or equal to 30 percent.
    IMAQ_DATA_MATRIX_CELL_FILL_MODE_SIZE_GUARD = 0xFFFFFFFF   
} DataMatrixCellFillMode;

typedef enum DataMatrixRotationMode_enum {
    IMAQ_UNLIMITED_ROTATION                   = 0,           //The function allows for unlimited rotation.
    IMAQ_0_DEGREES                            = 1,           //The function allows for between -5 and 5 degrees of rotation.
    IMAQ_90_DEGREES                           = 2,           //The function allows for between 85 and 95 degrees of rotation.
    IMAQ_180_DEGREES                          = 3,           //The function allows for between 175 and 185 degrees of rotation.
    IMAQ_270_DEGREES                          = 4,           //The function allows for between 265 and 275 degrees of rotation.
    IMAQ_DATA_MATRIX_ROTATION_MODE_SIZE_GUARD = 0xFFFFFFFF   
} DataMatrixRotationMode;

typedef enum WriteClassifierFileMode_enum {
    IMAQ_CLASSIFIER_WRITE_ALL                   = 0,           //Writes all information to the classifier file.
    IMAQ_CLASSIFIER_WRITE_CLASSIFY_ONLY         = 1,           //Write only the information needed to classify to the classifier file.
    IMAQ_WRITE_CLASSIFIER_FILE_MODES_SIZE_GUARD = 0xFFFFFFFF   
} WriteClassifierFileMode;

typedef enum AIMGrade_enum {
    IMAQ_AIM_GRADE_F                      = 0,           //The Data Matrix barcode received a grade of F.
    IMAQ_AIM_GRADE_D                      = 1,           //The Data Matrix barcode received a grade of D.
    IMAQ_AIM_GRADE_C                      = 2,           //The Data Matrix barcode received a grade of C.
    IMAQ_AIM_GRADE_B                      = 3,           //The Data Matrix barcode received a grade of B.
    IMAQ_AIM_GRADE_A                      = 4,           //The Data Matrix barcode received a grade of A.
    IMAQ_DATA_MATRIX_AIM_GRADE_SIZE_GUARD = 0xFFFFFFFF   
} AIMGrade;

typedef enum ReadResolution_enum {
    IMAQ_LOW_RESOLUTION    = 0,  //Configures NI Vision to use low resolution during the read process.
    IMAQ_MEDIUM_RESOLUTION = 1,  //Configures NI Vision to use medium resolution during the read process.
    IMAQ_HIGH_RESOLUTION   = 2,  //Configures NI Vision to use high resolution during the read process.
} ReadResolution;

typedef enum ThresholdMode_enum {
    IMAQ_FIXED_RANGE        = 0,  //Performs thresholding using the values you provide in the lowThreshold and highThreshold elements of OCRProcessingOptions.
    IMAQ_COMPUTED_UNIFORM   = 1,  //Calculates a single threshold value for the entire ROI.
    IMAQ_COMPUTED_LINEAR    = 2,  //Calculates a value on the left side of the ROI, calculates a value on the right side of the ROI, and linearly fills the middle values from left to right.
    IMAQ_COMPUTED_NONLINEAR = 3,  //Divides the ROI into the number of blocks specified by the blockCount element of OCRProcessingOptions and calculates a threshold value for each block.
} ThresholdMode;

typedef enum ReadStrategy_enum {
    IMAQ_READ_AGGRESSIVE   = 0,  //Configures NI Vision to perform fewer checks when analyzing objects to determine if they match trained characters.
    IMAQ_READ_CONSERVATIVE = 1,  //Configures NI Vision to perform more checks to determine if an object matches a trained character.
} ReadStrategy;

typedef enum MeasurementType_enum {
    IMAQ_MT_CENTER_OF_MASS_X                    = 0,           //X-coordinate of the point representing the average position of the total particle mass, assuming every point in the particle has a constant density.
    IMAQ_MT_CENTER_OF_MASS_Y                    = 1,           //Y-coordinate of the point representing the average position of the total particle mass, assuming every point in the particle has a constant density.
    IMAQ_MT_FIRST_PIXEL_X                       = 2,           //X-coordinate of the highest, leftmost particle pixel.
    IMAQ_MT_FIRST_PIXEL_Y                       = 3,           //Y-coordinate of the highest, leftmost particle pixel.
    IMAQ_MT_BOUNDING_RECT_LEFT                  = 4,           //X-coordinate of the leftmost particle point.
    IMAQ_MT_BOUNDING_RECT_TOP                   = 5,           //Y-coordinate of highest particle point.
    IMAQ_MT_BOUNDING_RECT_RIGHT                 = 6,           //X-coordinate of the rightmost particle point.
    IMAQ_MT_BOUNDING_RECT_BOTTOM                = 7,           //Y-coordinate of the lowest particle point.
    IMAQ_MT_MAX_FERET_DIAMETER_START_X          = 8,           //X-coordinate of the start of the line segment connecting the two perimeter points that are the furthest apart.
    IMAQ_MT_MAX_FERET_DIAMETER_START_Y          = 9,           //Y-coordinate of the start of the line segment connecting the two perimeter points that are the furthest apart.
    IMAQ_MT_MAX_FERET_DIAMETER_END_X            = 10,          //X-coordinate of the end of the line segment connecting the two perimeter points that are the furthest apart.
    IMAQ_MT_MAX_FERET_DIAMETER_END_Y            = 11,          //Y-coordinate of the end of the line segment connecting the two perimeter points that are the furthest apart.
    IMAQ_MT_MAX_HORIZ_SEGMENT_LENGTH_LEFT       = 12,          //X-coordinate of the leftmost pixel in the longest row of contiguous pixels in the particle.
    IMAQ_MT_MAX_HORIZ_SEGMENT_LENGTH_RIGHT      = 13,          //X-coordinate of the rightmost pixel in the longest row of contiguous pixels in the particle.
    IMAQ_MT_MAX_HORIZ_SEGMENT_LENGTH_ROW        = 14,          //Y-coordinate of all of the pixels in the longest row of contiguous pixels in the particle.
    IMAQ_MT_BOUNDING_RECT_WIDTH                 = 16,          //Distance between the x-coordinate of the leftmost particle point and the x-coordinate of the rightmost particle point.
    IMAQ_MT_BOUNDING_RECT_HEIGHT                = 17,          //Distance between the y-coordinate of highest particle point and the y-coordinate of the lowest particle point.
    IMAQ_MT_BOUNDING_RECT_DIAGONAL              = 18,          //Distance between opposite corners of the bounding rectangle.
    IMAQ_MT_PERIMETER                           = 19,          //Length of the outer boundary of the particle.
    IMAQ_MT_CONVEX_HULL_PERIMETER               = 20,          //Perimeter of the smallest convex polygon containing all points in the particle.
    IMAQ_MT_HOLES_PERIMETER                     = 21,          //Sum of the perimeters of each hole in the particle.
    IMAQ_MT_MAX_FERET_DIAMETER                  = 22,          //Distance between the start and end of the line segment connecting the two perimeter points that are the furthest apart.
    IMAQ_MT_EQUIVALENT_ELLIPSE_MAJOR_AXIS       = 23,          //Length of the major axis of the ellipse with the same perimeter and area as the particle.
    IMAQ_MT_EQUIVALENT_ELLIPSE_MINOR_AXIS       = 24,          //Length of the minor axis of the ellipse with the same perimeter and area as the particle.
    IMAQ_MT_EQUIVALENT_ELLIPSE_MINOR_AXIS_FERET = 25,          //Length of the minor axis of the ellipse with the same area as the particle, and Major Axis equal in length to the Max Feret Diameter.
    IMAQ_MT_EQUIVALENT_RECT_LONG_SIDE           = 26,          //Longest side of the rectangle with the same perimeter and area as the particle.
    IMAQ_MT_EQUIVALENT_RECT_SHORT_SIDE          = 27,          //Shortest side of the rectangle with the same perimeter and area as the particle.
    IMAQ_MT_EQUIVALENT_RECT_DIAGONAL            = 28,          //Distance between opposite corners of the rectangle with the same perimeter and area as the particle.
    IMAQ_MT_EQUIVALENT_RECT_SHORT_SIDE_FERET    = 29,          //Shortest side of the rectangle with the same area as the particle, and longest side equal in length to the Max Feret Diameter.
    IMAQ_MT_AVERAGE_HORIZ_SEGMENT_LENGTH        = 30,          //Average length of a horizontal segment in the particle.
    IMAQ_MT_AVERAGE_VERT_SEGMENT_LENGTH         = 31,          //Average length of a vertical segment in the particle.
    IMAQ_MT_HYDRAULIC_RADIUS                    = 32,          //The particle area divided by the particle perimeter.
    IMAQ_MT_WADDEL_DISK_DIAMETER                = 33,          //Diameter of a disk with the same area as the particle.
    IMAQ_MT_AREA                                = 35,          //Area of the particle.
    IMAQ_MT_HOLES_AREA                          = 36,          //Sum of the areas of each hole in the particle.
    IMAQ_MT_PARTICLE_AND_HOLES_AREA             = 37,          //Area of a particle that completely covers the image.
    IMAQ_MT_CONVEX_HULL_AREA                    = 38,          //Area of the smallest convex polygon containing all points in the particle.
    IMAQ_MT_IMAGE_AREA                          = 39,          //Area of the image.
    IMAQ_MT_NUMBER_OF_HOLES                     = 41,          //Number of holes in the particle.
    IMAQ_MT_NUMBER_OF_HORIZ_SEGMENTS            = 42,          //Number of horizontal segments in the particle.
    IMAQ_MT_NUMBER_OF_VERT_SEGMENTS             = 43,          //Number of vertical segments in the particle.
    IMAQ_MT_ORIENTATION                         = 45,          //The angle of the line that passes through the particle Center of Mass about which the particle has the lowest moment of inertia.
    IMAQ_MT_MAX_FERET_DIAMETER_ORIENTATION      = 46,          //The angle of the line segment connecting the two perimeter points that are the furthest apart.
    IMAQ_MT_AREA_BY_IMAGE_AREA                  = 48,          //Percentage of the particle Area covering the Image Area.
    IMAQ_MT_AREA_BY_PARTICLE_AND_HOLES_AREA     = 49,          //Percentage of the particle Area in relation to its Particle and Holes Area.
    IMAQ_MT_RATIO_OF_EQUIVALENT_ELLIPSE_AXES    = 50,          //Equivalent Ellipse Major Axis divided by Equivalent Ellipse Minor Axis.
    IMAQ_MT_RATIO_OF_EQUIVALENT_RECT_SIDES      = 51,          //Equivalent Rect Long Side divided by Equivalent Rect Short Side.
    IMAQ_MT_ELONGATION_FACTOR                   = 53,          //Max Feret Diameter divided by Equivalent Rect Short Side (Feret).
    IMAQ_MT_COMPACTNESS_FACTOR                  = 54,          //Area divided by the product of Bounding Rect Width and Bounding Rect Height.
    IMAQ_MT_HEYWOOD_CIRCULARITY_FACTOR          = 55,          //Perimeter divided by the circumference of a circle with the same area.
    IMAQ_MT_TYPE_FACTOR                         = 56,          //Factor relating area to moment of inertia.
    IMAQ_MT_SUM_X                               = 58,          //The sum of all x-coordinates in the particle.
    IMAQ_MT_SUM_Y                               = 59,          //The sum of all y-coordinates in the particle.
    IMAQ_MT_SUM_XX                              = 60,          //The sum of all x-coordinates squared in the particle.
    IMAQ_MT_SUM_XY                              = 61,          //The sum of all x-coordinates times y-coordinates in the particle.
    IMAQ_MT_SUM_YY                              = 62,          //The sum of all y-coordinates squared in the particle.
    IMAQ_MT_SUM_XXX                             = 63,          //The sum of all x-coordinates cubed in the particle.
    IMAQ_MT_SUM_XXY                             = 64,          //The sum of all x-coordinates squared times y-coordinates in the particle.
    IMAQ_MT_SUM_XYY                             = 65,          //The sum of all x-coordinates times y-coordinates squared in the particle.
    IMAQ_MT_SUM_YYY                             = 66,          //The sum of all y-coordinates cubed in the particle.
    IMAQ_MT_MOMENT_OF_INERTIA_XX                = 68,          //The moment of inertia in the x-direction twice.
    IMAQ_MT_MOMENT_OF_INERTIA_XY                = 69,          //The moment of inertia in the x and y directions.
    IMAQ_MT_MOMENT_OF_INERTIA_YY                = 70,          //The moment of inertia in the y-direction twice.
    IMAQ_MT_MOMENT_OF_INERTIA_XXX               = 71,          //The moment of inertia in the x-direction three times.
    IMAQ_MT_MOMENT_OF_INERTIA_XXY               = 72,          //The moment of inertia in the x-direction twice and the y-direction once.
    IMAQ_MT_MOMENT_OF_INERTIA_XYY               = 73,          //The moment of inertia in the x-direction once and the y-direction twice.
    IMAQ_MT_MOMENT_OF_INERTIA_YYY               = 74,          //The moment of inertia in the y-direction three times.
    IMAQ_MT_NORM_MOMENT_OF_INERTIA_XX           = 75,          //The normalized moment of inertia in the x-direction twice.
    IMAQ_MT_NORM_MOMENT_OF_INERTIA_XY           = 76,          //The normalized moment of inertia in the x- and y-directions.
    IMAQ_MT_NORM_MOMENT_OF_INERTIA_YY           = 77,          //The normalized moment of inertia in the y-direction twice.
    IMAQ_MT_NORM_MOMENT_OF_INERTIA_XXX          = 78,          //The normalized moment of inertia in the x-direction three times.
    IMAQ_MT_NORM_MOMENT_OF_INERTIA_XXY          = 79,          //The normalized moment of inertia in the x-direction twice and the y-direction once.
    IMAQ_MT_NORM_MOMENT_OF_INERTIA_XYY          = 80,          //The normalized moment of inertia in the x-direction once and the y-direction twice.
    IMAQ_MT_NORM_MOMENT_OF_INERTIA_YYY          = 81,          //The normalized moment of inertia in the y-direction three times.
    IMAQ_MT_HU_MOMENT_1                         = 82,          //The first Hu moment.
    IMAQ_MT_HU_MOMENT_2                         = 83,          //The second Hu moment.
    IMAQ_MT_HU_MOMENT_3                         = 84,          //The third Hu moment.
    IMAQ_MT_HU_MOMENT_4                         = 85,          //The fourth Hu moment.
    IMAQ_MT_HU_MOMENT_5                         = 86,          //The fifth Hu moment.
    IMAQ_MT_HU_MOMENT_6                         = 87,          //The sixth Hu moment.
    IMAQ_MT_HU_MOMENT_7                         = 88,          //The seventh Hu moment.
    IMAQ_MEASUREMENT_TYPE_SIZE_GUARD            = 0xFFFFFFFF   
} MeasurementType;

typedef enum GeometricMatchingMode_enum {
    IMAQ_GEOMETRIC_MATCH_SHIFT_INVARIANT     = 0,           //Searches for occurrences of the pattern in the image, assuming that the pattern is not rotated more than plus or minus 5 degrees.
    IMAQ_GEOMETRIC_MATCH_ROTATION_INVARIANT  = 1,           //Searches for occurrences of the pattern in the image with reduced restriction on the rotation of the pattern.
    IMAQ_GEOMETRIC_MATCH_SCALE_INVARIANT     = 2,           //Searches for occurrences of the pattern in the image with reduced restriction on the size of the pattern.
    IMAQ_GEOMETRIC_MATCH_OCCLUSION_INVARIANT = 4,           //Searches for occurrences of the pattern in the image, allowing for a specified percentage of the pattern to be occluded.
    IMAQ_GEOMETRIC_MATCHING_MODE_SIZE_GUARD  = 0xFFFFFFFF   
} GeometricMatchingMode;

typedef enum ButtonLabel_enum {
    IMAQ_BUTTON_OK               = 0,           //The label "OK".
    IMAQ_BUTTON_SAVE             = 1,           //The label "Save".
    IMAQ_BUTTON_SELECT           = 2,           //The label "Select".
    IMAQ_BUTTON_LOAD             = 3,           //The label "Load".
    IMAQ_BUTTON_LABEL_SIZE_GUARD = 0xFFFFFFFF   
} ButtonLabel;

typedef enum ParticleClassifierType_enum {
    IMAQ_PARTICLE_LARGEST                    = 0,           //Use only the largest particle in the image.
    IMAQ_PARTICLE_ALL                        = 1,           //Use all particles in the image.
    IMAQ_PARTICLE_CLASSIFIER_TYPE_SIZE_GUARD = 0xFFFFFFFF   
} ParticleClassifierType;

typedef enum Barcode2DCellShape_enum {
    IMAQ_SQUARE_CELLS                     = 0,           //The function uses an algorithm for decoding the 2D barcode that works with square data cells.
    IMAQ_ROUND_CELLS                      = 1,           //The function uses an algorithm for decoding the 2D barcode that works with round data cells.
    IMAQ_BARCODE_2D_CELL_SHAPE_SIZE_GUARD = 0xFFFFFFFF   
} Barcode2DCellShape;

typedef enum NearestNeighborMetric_enum {
    IMAQ_METRIC_MAXIMUM                     = 0,           //The maximum metric.
    IMAQ_METRIC_SUM                         = 1,           //The sum metric.
    IMAQ_METRIC_EUCLIDEAN                   = 2,           //The Euclidean metric.
    IMAQ_NEAREST_NEIGHBOR_METRIC_SIZE_GUARD = 0xFFFFFFFF   
} NearestNeighborMetric;

typedef enum EdgeFilterSize_enum {
    IMAQ_FINE                        = 0,           //Specifies that the function uses a fine (narrow) edge filter.
    IMAQ_NORMAL                      = 1,           //Specifies that the function uses a normal edge filter.
    IMAQ_EDGE_FILTER_SIZE_SIZE_GUARD = 0xFFFFFFFF   
} EdgeFilterSize;

typedef enum ReadClassifierFileMode_enum {
    IMAQ_CLASSIFIER_READ_ALL                   = 0,           //Read all information from the classifier file.
    IMAQ_CLASSIFIER_READ_SAMPLES               = 1,           //Read only the samples from the classifier file.
    IMAQ_CLASSIFIER_READ_PROPERTIES            = 2,           //Read only the properties from the classifier file.
    IMAQ_READ_CLASSIFIER_FILE_MODES_SIZE_GUARD = 0xFFFFFFFF   
} ReadClassifierFileMode;

typedef enum VisionInfoType2_enum {
    IMAQ_VISIONINFO_CALIBRATION       = 0x01,        //Used to indicate interaction with the Calibration information in an image.
    IMAQ_VISIONINFO_OVERLAY           = 0x02,        //Used to indicate interaction with the Overlay information in an image.
    IMAQ_VISIONINFO_GRAYTEMPLATE      = 0x04,        //Used to indicate interaction with the grayscale template information in an image.
    IMAQ_VISIONINFO_COLORTEMPLATE     = 0x08,        //Used to indicate interaction with the color template information in an image.
    IMAQ_VISIONINFO_GEOMETRICTEMPLATE = 0x10,        //Used to indicate interaction with the geometric template information in an image.
    IMAQ_VISIONINFO_CUSTOMDATA        = 0x20,        //Used to indicate interaction with the binary or text Custom Data in an image.
    IMAQ_VISIONINFO_GOLDENTEMPLATE    = 0x40,        //Used to indicate interaction with the golden template information in an image.
    IMAQ_VISIONINFO_ALL               = 0xFFFFFFFF,  //Removes, checks for, or indicates the presence of all types of extra information in an image.
} VisionInfoType2;

typedef enum ParticleType_enum {
    IMAQ_PARTICLE_BRIGHT          = 0,           //Bright particles.
    IMAQ_PARTICLE_DARK            = 1,           //Dark particles.
    IMAQ_PARTICLE_TYPE_SIZE_GUARD = 0xFFFFFFFF   
} ParticleType;

typedef enum ClassifierType_enum {
    IMAQ_CLASSIFIER_CUSTOM          = 0,           //The classifier session classifies vectors of doubles.
    IMAQ_CLASSIFIER_PARTICLE        = 1,           //The classifier session classifies particles in binary images.
    IMAQ_CLASSIFIER_TYPE_SIZE_GUARD = 0xFFFFFFFF   
} ClassifierType;

typedef enum ClassifierEngineType_enum {
    IMAQ_ENGINE_NONE                       = 0,           //No engine has been set on this classifier session.
    IMAQ_ENGINE_NEAREST_NEIGHBOR           = 1,           //Nearest neighbor engine.
    IMAQ_CLASSIFIER_ENGINE_TYPE_SIZE_GUARD = 0xFFFFFFFF   
} ClassifierEngineType;

typedef enum Barcode2DContrast_enum {
    IMAQ_ALL_BARCODE_2D_CONTRASTS       = 0,           //The function searches for barcodes of each contrast type.
    IMAQ_BLACK_ON_WHITE_BARCODE_2D      = 1,           //The function searches for 2D barcodes containing black data on a white background.
    IMAQ_WHITE_ON_BLACK_BARCODE_2D      = 2,           //The function searches for 2D barcodes containing white data on a black background.
    IMAQ_BARCODE_2D_CONTRAST_SIZE_GUARD = 0xFFFFFFFF   
} Barcode2DContrast;

typedef enum Barcode2DShape_enum {
    IMAQ_SQUARE_BARCODE_2D           = 0,           //The function searches for square 2D barcodes.
    IMAQ_RECTANGULAR_BARCODE_2D      = 1,           //The function searches for rectangular 2D barcodes.
    IMAQ_BARCODE_2D_SHAPE_SIZE_GUARD = 0xFFFFFFFF   
} Barcode2DShape;

typedef enum DataMatrixSubtype_enum {
    IMAQ_ALL_DATA_MATRIX_SUBTYPES             = 0,           //The function searches for Data Matrix barcodes of all subtypes.
    IMAQ_DATA_MATRIX_SUBTYPES_ECC_000_ECC_140 = 1,           //The function searches for Data Matrix barcodes of subtypes ECC 000, ECC 050, ECC 080, ECC 100 and ECC 140.
    IMAQ_DATA_MATRIX_SUBTYPE_ECC_200          = 2,           //The function searches for Data Matrix ECC 200 barcodes.
    IMAQ_DATA_MATRIX_SUBTYPE_SIZE_GUARD       = 0xFFFFFFFF   
} DataMatrixSubtype;

typedef enum Barcode2DSearchMode_enum {
    IMAQ_SEARCH_MULTIPLE                   = 0,           //The function searches for multiple 2D barcodes.
    IMAQ_SEARCH_SINGLE_CONSERVATIVE        = 1,           //The function searches for 2D barcodes using the same searching algorithm as IMAQ_SEARCH_MULTIPLE but stops searching after locating one valid barcode.
    IMAQ_SEARCH_SINGLE_AGGRESSIVE          = 2,           //The function searches for a single 2D barcode using a method that assumes the barcode occupies a majority of the search region.
    IMAQ_BARCODE_2D_SEARCH_MODE_SIZE_GUARD = 0xFFFFFFFF   
} Barcode2DSearchMode;

typedef enum NearestNeighborMethod_enum {
    IMAQ_MINIMUM_MEAN_DISTANCE              = 0,           //The minimum mean distance method.
    IMAQ_K_NEAREST_NEIGHBOR                 = 1,           //The k-nearest neighbor method.
    IMAQ_NEAREST_PROTOTYPE                  = 2,           //The nearest prototype method.
    IMAQ_NEAREST_NEIGHBOR_METHOD_SIZE_GUARD = 0xFFFFFFFF   
} NearestNeighborMethod;


//============================================================================
//  Forward Declare Data Structures
//============================================================================
typedef struct Image_struct Image;
typedef struct ROI_struct ROI;
typedef struct Overlay_struct Overlay;
typedef struct ClassifierSession_struct ClassifierSession;
typedef struct MultipleGeometricPattern_struct MultipleGeometricPattern;
typedef int ContourID;
typedef unsigned long SESSION_ID;
typedef int	AVISession;
typedef char* FilterName;
typedef char String255[256];
typedef struct CharSet_struct CharSet;
typedef struct OCRSpacingOptions_struct OCRSpacingOptions;
typedef struct OCRProcessingOptions_struct OCRProcessingOptions;
typedef struct ReadTextOptions_struct ReadTextOptions;
typedef struct CharInfo_struct CharInfo;
typedef struct CharReport_struct CharReport;
typedef struct ReadTextReport_struct ReadTextReport;
typedef struct AIMGradeReport_struct AIMGradeReport;
typedef struct DataMatrixSizeOptions_struct DataMatrixSizeOptions;
typedef struct DataMatrixDescriptionOptions_struct DataMatrixDescriptionOptions;
typedef struct DataMatrixSearchOptions_struct DataMatrixSearchOptions;
typedef struct PointFloat_struct PointFloat;
typedef struct DataMatrixReport_struct DataMatrixReport;
typedef struct JPEG2000FileAdvancedOptions_struct JPEG2000FileAdvancedOptions;
typedef struct MatchGeometricPatternAdvancedOptions2_struct MatchGeometricPatternAdvancedOptions2;
typedef struct InspectionAlignment_struct InspectionAlignment;
typedef struct InspectionOptions_struct InspectionOptions;
typedef struct CharReport2_struct CharReport2;
typedef struct CharInfo2_struct CharInfo2;
typedef struct ReadTextReport2_struct ReadTextReport2;
typedef struct EllipseFeature_struct EllipseFeature;
typedef struct CircleFeature_struct CircleFeature;
typedef struct ConstCurveFeature_struct ConstCurveFeature;
typedef struct RectangleFeature_struct RectangleFeature;
typedef struct LegFeature_struct LegFeature;
typedef struct CornerFeature_struct CornerFeature;
typedef struct LineFeature_struct LineFeature;
typedef struct ParallelLinePairFeature_struct ParallelLinePairFeature;
typedef struct PairOfParallelLinePairsFeature_struct PairOfParallelLinePairsFeature;
typedef union GeometricFeature_union GeometricFeature;
typedef struct FeatureData_struct FeatureData;
typedef struct GeometricPatternMatch2_struct GeometricPatternMatch2;
typedef struct ClosedCurveFeature_struct ClosedCurveFeature;
typedef struct LineMatch_struct LineMatch;
typedef struct LineDescriptor_struct LineDescriptor;
typedef struct RectangleDescriptor_struct RectangleDescriptor;
typedef struct RectangleMatch_struct RectangleMatch;
typedef struct EllipseDescriptor_struct EllipseDescriptor;
typedef struct EllipseMatch_struct EllipseMatch;
typedef struct CircleMatch_struct CircleMatch;
typedef struct CircleDescriptor_struct CircleDescriptor;
typedef struct RangeFloat_struct RangeFloat;
typedef struct ShapeDetectionOptions_struct ShapeDetectionOptions;
typedef struct Curve_struct Curve;
typedef struct CurveOptions_struct CurveOptions;
typedef struct Barcode2DInfo_struct Barcode2DInfo;
typedef struct DataMatrixOptions_struct DataMatrixOptions;
typedef struct ClassifierAccuracyReport_struct ClassifierAccuracyReport;
typedef struct NearestNeighborClassResult_struct NearestNeighborClassResult;
typedef struct NearestNeighborTrainingReport_struct NearestNeighborTrainingReport;
typedef struct ParticleClassifierPreprocessingOptions_struct ParticleClassifierPreprocessingOptions;
typedef struct ClassifierSampleInfo_struct ClassifierSampleInfo;
typedef struct ClassScore_struct ClassScore;
typedef struct ClassifierReport_struct ClassifierReport;
typedef struct NearestNeighborOptions_struct NearestNeighborOptions;
typedef struct ParticleClassifierOptions_struct ParticleClassifierOptions;
typedef struct RGBU64Value_struct RGBU64Value;
typedef struct GeometricPatternMatch_struct GeometricPatternMatch;
typedef struct MatchGeometricPatternAdvancedOptions_struct MatchGeometricPatternAdvancedOptions;
typedef struct MatchGeometricPatternOptions_struct MatchGeometricPatternOptions;
typedef struct LearnGeometricPatternAdvancedOptions_struct LearnGeometricPatternAdvancedOptions;
typedef struct FitEllipseOptions_struct FitEllipseOptions;
typedef struct FitCircleOptions_struct FitCircleOptions;
typedef struct ConstructROIOptions2_struct ConstructROIOptions2;
typedef struct RGBValue_struct RGBValue;
typedef struct HSLValue_struct HSLValue;
typedef struct HSVValue_struct HSVValue;
typedef struct HSIValue_struct HSIValue;
typedef struct CIELabValue_struct CIELabValue;
typedef struct CIEXYZValue_struct CIEXYZValue;
typedef union Color2_union Color2;
typedef struct BestEllipse2_struct BestEllipse2;
typedef struct LearnPatternAdvancedOptions_struct LearnPatternAdvancedOptions;
typedef struct AVIInfo_struct AVIInfo;
typedef struct LearnPatternAdvancedShiftOptions_struct LearnPatternAdvancedShiftOptions;
typedef struct LearnPatternAdvancedRotationOptions_struct LearnPatternAdvancedRotationOptions;
typedef struct MatchPatternAdvancedOptions_struct MatchPatternAdvancedOptions;
typedef struct ParticleFilterCriteria2_struct ParticleFilterCriteria2;
typedef struct BestCircle2_struct BestCircle2;
typedef struct OCRSpacingOptions_struct OCRSpacingOptions;
typedef struct OCRProcessingOptions_struct OCRProcessingOptions;
typedef struct ReadTextOptions_struct ReadTextOptions;
typedef struct CharInfo_struct CharInfo;
#if !defined(USERINT_HEADER) && !defined(_CVI_RECT_DEFINED)
typedef struct Rect_struct Rect;
#endif
typedef struct CharReport_struct CharReport;
typedef struct ReadTextReport_struct ReadTextReport;
#if !defined(USERINT_HEADER) && !defined(_CVI_POINT_DEFINED)
typedef struct Point_struct Point;
#endif
typedef struct Annulus_struct Annulus;
typedef struct EdgeLocationReport_struct EdgeLocationReport;
typedef struct EdgeOptions_struct EdgeOptions;
typedef struct EdgeReport_struct EdgeReport;
typedef struct ExtremeReport_struct ExtremeReport;
typedef struct FitLineOptions_struct FitLineOptions;
typedef struct GridDescriptor_struct GridDescriptor;
typedef struct DisplayMapping_struct DisplayMapping;
typedef struct DetectExtremesOptions_struct DetectExtremesOptions;
typedef struct ImageInfo_struct ImageInfo;
typedef struct LCDOptions_struct LCDOptions;
typedef struct LCDReport_struct LCDReport;
typedef struct LCDSegments_struct LCDSegments;
typedef struct LearnCalibrationOptions_struct LearnCalibrationOptions;
typedef struct LearnColorPatternOptions_struct LearnColorPatternOptions;
typedef struct Line_struct Line;
typedef struct LinearAverages_struct LinearAverages;
typedef struct LineEquation_struct LineEquation;
typedef struct LineFloat_struct LineFloat;
typedef struct LineProfile_struct LineProfile;
typedef struct MatchColorPatternOptions_struct MatchColorPatternOptions;
typedef struct HistogramReport_struct HistogramReport;
typedef struct ArcInfo_struct ArcInfo;
typedef struct BarcodeInfo_struct BarcodeInfo;
typedef struct BCGOptions_struct BCGOptions;
typedef struct BestCircle_struct BestCircle;
typedef struct BestEllipse_struct BestEllipse;
typedef struct BestLine_struct BestLine;
typedef struct BrowserOptions_struct BrowserOptions;
typedef struct CoordinateSystem_struct CoordinateSystem;
typedef struct CalibrationInfo_struct CalibrationInfo;
typedef struct CalibrationPoints_struct CalibrationPoints;
typedef struct CaliperOptions_struct CaliperOptions;
typedef struct CaliperReport_struct CaliperReport;
typedef struct DrawTextOptions_struct DrawTextOptions;
typedef struct CircleReport_struct CircleReport;
typedef struct ClosedContour_struct ClosedContour;
typedef struct ColorHistogramReport_struct ColorHistogramReport;
typedef struct ColorInformation_struct ColorInformation;
typedef struct Complex_struct Complex;
typedef struct ConcentricRakeReport_struct ConcentricRakeReport;
typedef struct ConstructROIOptions_struct ConstructROIOptions;
typedef struct ContourInfo_struct ContourInfo;
typedef union ContourUnion_union ContourUnion;
typedef struct ContourInfo2_struct ContourInfo2;
typedef struct ContourPoint_struct ContourPoint;
typedef struct CoordinateTransform_struct CoordinateTransform;
typedef struct CoordinateTransform2_struct CoordinateTransform2;
typedef struct CannyOptions_struct CannyOptions;
typedef struct Range_struct Range;
typedef struct UserPointSymbol_struct UserPointSymbol;
typedef struct View3DOptions_struct View3DOptions;
typedef struct MatchPatternOptions_struct MatchPatternOptions;
typedef struct TIFFFileOptions_struct TIFFFileOptions;
typedef union Color_union Color;
typedef union PixelValue_union PixelValue;
typedef struct OpenContour_struct OpenContour;
typedef struct OverlayTextOptions_struct OverlayTextOptions;
typedef struct ParticleFilterCriteria_struct ParticleFilterCriteria;
typedef struct ParticleReport_struct ParticleReport;
typedef struct PatternMatch_struct PatternMatch;
typedef struct QuantifyData_struct QuantifyData;
typedef struct QuantifyReport_struct QuantifyReport;
typedef struct RakeOptions_struct RakeOptions;
typedef struct RakeReport_struct RakeReport;
typedef struct TransformReport_struct TransformReport;
typedef struct ShapeReport_struct ShapeReport;
typedef struct MeterArc_struct MeterArc;
typedef struct ThresholdData_struct ThresholdData;
typedef struct StructuringElement_struct StructuringElement;
typedef struct SpokeReport_struct SpokeReport;
typedef struct SimpleEdgeOptions_struct SimpleEdgeOptions;
typedef struct SelectParticleCriteria_struct SelectParticleCriteria;
typedef struct SegmentInfo_struct SegmentInfo;
typedef struct RotationAngleRange_struct RotationAngleRange;
typedef struct RotatedRect_struct RotatedRect;
typedef struct ROIProfile_struct ROIProfile;
typedef struct ToolWindowOptions_struct ToolWindowOptions;
typedef struct SpokeOptions_struct SpokeOptions;

//============================================================================
// Data Structures
//============================================================================
#pragma pack(push,1)
typedef struct AIMGradeReport_struct {
    AIMGrade overallGrade;               //The overall letter grade, which is equal to the lowest of the other five letter grades.
    AIMGrade decodingGrade;              //The letter grade assigned to a Data Matrix barcode based on the success of the function in decoding the Data Matrix barcode.
    AIMGrade symbolContrastGrade;        //The letter grade assigned to a Data Matrix barcode based on the symbol contrast raw score.
    float    symbolContrast;             //The symbol contrast raw score representing the percentage difference between the mean of the reflectance of the darkest 10 percent and lightest 10 percent of the Data Matrix barcode.
    AIMGrade printGrowthGrade;           //The print growth letter grade for the Data Matrix barcode.
    float    printGrowth;                //The print growth raw score for the barcode, which is based on the extent to which dark or light markings appropriately fill their module boundaries.
    AIMGrade axialNonuniformityGrade;    //The axial nonuniformity grade for the Data Matrix barcode.
    float    axialNonuniformity;         //The axial nonuniformity raw score for the barcode, which is based on how much the sampling point spacing differs from one axis to another.
    AIMGrade unusedErrorCorrectionGrade; //The unused error correction letter grade for the Data Matrix barcode.
    float    unusedErrorCorrection;      //The unused error correction raw score for the Data Matrix barcode, which is based on the extent to which regional or spot damage in the Data Matrix barcode has eroded the reading safety margin provided by the error correction.
} AIMGradeReport;

typedef struct DataMatrixSizeOptions_struct {
    unsigned int minSize;        //Specifies the minimum size (in pixels) of the Data Matrix barcode in the image.
    unsigned int maxSize;        //Specifies the maximum size (in pixels) of the Data Matrix barcode in the image.
    unsigned int quietZoneWidth; //Specifies the expected minimum size of the quiet zone, in pixels.
} DataMatrixSizeOptions;

typedef struct DataMatrixDescriptionOptions_struct {
    float                  aspectRatio;        //Specifies the ratio of the width of each Data Matrix barcode cell (in pixels) to the height of the Data Matrix barcode (in pixels).
    unsigned int           rows;               //Specifies the number of rows in the Data Matrix barcode.
    unsigned int           columns;            //Specifies the number of columns in the Data Matrix barcode.
    int                    rectangle;          //Set this element to TRUE to specify that the Data Matrix barcode is rectangular.
    DataMatrixECC          ecc;                //Specifies the ECC used for this Data Matrix barcode.
    DataMatrixPolarity     polarity;           //Specifies the data-to-background contrast for the Data Matrix barcode.
    DataMatrixCellFillMode cellFill;           //Specifies the fill percentage for a cell of the Data Matrix barcode that is in the "ON" state.
    float                  minBorderIntegrity; //Specifies the minimum percentage of the border (locator pattern and timing pattern) the function should expect in the Data Matrix barcode.
    DataMatrixMirrorMode   mirrorMode;         //Specifies if the Data Matrix barcode appears normally in the image or if the barcode appears mirrored in the image.
} DataMatrixDescriptionOptions;

typedef struct DataMatrixSearchOptions_struct {
    DataMatrixRotationMode     rotationMode;             //Specifies the amount of Data Matrix barcode rotation the function should allow for.
    int                        skipLocation;             //If set to TRUE, specifies that the function should assume that the Data Matrix barcode occupies the entire image (or the entire search region).
    unsigned int               edgeThreshold;            //Specifies the minimum contrast a pixel must have in order to be considered part of a matrix cell edge.
    DataMatrixDemodulationMode demodulationMode;         //Specifies the mode the function should use to demodulate (determine which cells are on and which cells are off) the Data Matrix barcode.
    DataMatrixCellSampleSize   cellSampleSize;           //Specifies the sample size, in pixels, the function should take to determine if each cell is on or off.
    DataMatrixCellFilterMode   cellFilterMode;           //Specifies the mode the function uses to determine the pixel value for each cell.
    unsigned int               skewDegreesAllowed;       //Specifies the amount of skew in the Data Matrix barcode the function should allow for.
    unsigned int               maxIterations;            //Specifies the maximum number of iterations before the function stops looking for the Data Matrix barcode.
    unsigned int               initialSearchVectorWidth; //Specifies the number of pixels the function should average together to determine the location of an edge.
} DataMatrixSearchOptions;

typedef struct PointFloat_struct {
    float x; //The x-coordinate of the point.
    float y; //The y-coordinate of the point.
} PointFloat;

typedef struct DataMatrixReport_struct {
    int                        found;                //This element is TRUE if the function located and decoded a Data Matrix barcode and FALSE if the function failed to locate and decode a Data Matrix barcode.
    int                        binary;               //This element is TRUE if the Data Matrix barcode contains binary data and FALSE if the Data Matrix barcode contains text data.
    unsigned char*             data;                 //The data encoded in the Data Matrix barcode.
    unsigned int               dataLength;           //The length of the data array.
    PointFloat                 boundingBox[4];       //An array of four points describing the rectangle surrounding the Data Matrix barcode.
    unsigned int               numErrorsCorrected;   //The number of errors the function corrected when decoding the Data Matrix barcode.
    unsigned int               numErasuresCorrected; //The number of erasures the function corrected when decoding the Data Matrix barcode.
    float                      aspectRatio;          //Specifies the aspect ratio of the Data Matrix barcode in the image, which equals the ratio of the width of a Data Matrix barcode cell (in pixels) to the height of a Data Matrix barcode cell (in pixels).
    unsigned int               rows;                 //The number of rows in the Data Matrix barcode.
    unsigned int               columns;              //The number of columns in the Data Matrix barcode.
    DataMatrixECC              ecc;                  //The Error Correction Code (ECC) used by the Data Matrix barcode.
    DataMatrixPolarity         polarity;             //The polarity of the Data Matrix barcode.
    DataMatrixCellFillMode     cellFill;             //The cell fill percentage of the Data Matrix barcode.
    float                      borderIntegrity;      //The percentage of the Data Matrix barcode border that appears correctly in the image.
    int                        mirrored;             //This element is TRUE if the Data Matrix barcode appears mirrored in the image and FALSE if the Data Matrix barcode appears normally in the image.
    unsigned int               minimumEdgeStrength;  //The strength of the weakest edge the function used to find the coarse location of the Data Matrix barcode in the image.
    DataMatrixDemodulationMode demodulationMode;     //The demodulation mode the function used to locate the Data Matrix barcode.
    DataMatrixCellSampleSize   cellSampleSize;       //The cell sample size the function used to locate the Data Matrix barcode.
    DataMatrixCellFilterMode   cellFilterMode;       //The cell filter mode the function used to locate the Data Matrix barcode.
    unsigned int               iterations;           //The number of iterations the function took in attempting to locate the Data Matrix barcode.
} DataMatrixReport;

typedef struct JPEG2000FileAdvancedOptions_struct {
    WaveletTransformMode waveletMode;                //Determines which wavelet transform to use when writing the file.
    int                  useMultiComponentTransform; //Set this parameter to TRUE to use an additional transform on RGB images.
    unsigned int         maxWaveletTransformLevel;   //Specifies the maximum allowed level of wavelet transform.
    float                quantizationStepSize;       //Specifies the absolute base quantization step size for derived quantization mode.
} JPEG2000FileAdvancedOptions;

typedef struct MatchGeometricPatternAdvancedOptions2_struct {
    int    minFeaturesUsed;            //Specifies the minimum number of features the function uses when matching.
    int    maxFeaturesUsed;            //Specifies the maximum number of features the function uses when matching.
    int    subpixelIterations;         //Specifies the maximum number of incremental improvements used to refine matches with subpixel information.
    double subpixelTolerance;          //Specifies the maximum amount of change, in pixels, between consecutive incremental improvements in the match position before the function stops refining the match position.
    int    initialMatchListLength;     //Specifies the maximum size of the match list.
    float  matchTemplateCurveScore;    //The accuracy of the match obtained by comparing the curves in the match region to the template curves.
    int    correlationScore;           //Set this element to TRUE to specify that the function should calculate the correlation score and return it for each match result.
    double minMatchSeparationDistance; //Specifies the minimum separation distance, in pixels, between the origins of two matches that have unique positions.
    double minMatchSeparationAngle;    //Specifies the minimum angular difference, in degrees, between two matches that have unique angles.
    double minMatchSeparationScale;    //Specifies the minimum difference in scale, expressed as a percentage, between two matches that have unique scales.
    double maxMatchOverlap;            //Specifies the maximum amount of overlap, expressed as a percentage, allowed between the bounding rectangles of two unique matches.
    int    coarseResult;               //Specifies whether you want the function to spend less time accurately estimating the location of a match.
    int    smoothContours;             //Set this element to TRUE to specify smoothing be done on the contours of the inspection image before feature extraction.
    int    enableCalibrationSupport;   //Set this element to TRUE to specify the algorithm treat the inspection image as a calibrated image.
} MatchGeometricPatternAdvancedOptions2;

typedef struct InspectionAlignment_struct {
    PointFloat position; //The location of the center of the golden template in the image under inspection.
    float      rotation; //The rotation of the golden template in the image under inspection, in degrees.
    float      scale;    //The percentage of the size of the area under inspection compared to the size of the golden template.
} InspectionAlignment;

typedef struct InspectionOptions_struct {
    RegistrationMethod  registrationMethod;    //Specifies how the function registers the golden template and the target image.
    NormalizationMethod normalizationMethod;   //Specifies how the function normalizes the golden template to the target image.
    int                 edgeThicknessToIgnore; //Specifies desired thickness of edges to be ignored.
    float               brightThreshold;       //Specifies the threshold for areas where the target image is brighter than the golden template.
    float               darkThreshold;         //Specifies the threshold for areas where the target image is darker than the golden template.
    int                 binary;                //Specifies whether the function should return a binary image giving the location of defects, or a grayscale image giving the intensity of defects.
} InspectionOptions;

typedef struct CharReport2_struct {
    const char* character;           //The character value.
    PointFloat  corner[4];           //An array of four points that describes the rectangle that surrounds the character.
    int         lowThreshold;        //The minimum value of the threshold range used for this character.
    int         highThreshold;       //The maximum value of the threshold range used for this character.
    int         classificationScore; //The degree to which the assigned character class represents the object better than the other character classes in the character set.
    int         verificationScore;   //The similarity of the character and the reference character for the character class.
    int         verified;            //This element is TRUE if a reference character was found for the character class and FALSE if a reference character was not found.
} CharReport2;

typedef struct CharInfo2_struct {
    const char*  charValue;       //Retrieves the character value of the corresponding character in the character set.
    const Image* charImage;       //The image you used to train this character.
    const Image* internalImage;   //The internal representation that NI Vision uses to match objects to this character.
    int          isReferenceChar; //This element is TRUE if the character is the reference character for the character class.
} CharInfo2;

typedef struct ReadTextReport2_struct {
    const char*  readString;          //The read string.
    CharReport2* characterReport;     //An array of reports describing the properties of each identified character.
    int          numCharacterReports; //The number of identified characters.
} ReadTextReport2;

typedef struct EllipseFeature_struct {
    PointFloat position;    //The location of the center of the ellipse.
    double     rotation;    //The orientation of the semi-major axis of the ellipse with respect to the horizontal.
    double     minorRadius; //The length of the semi-minor axis of the ellipse.
    double     majorRadius; //The length of the semi-major axis of the ellipse.
} EllipseFeature;

typedef struct CircleFeature_struct {
    PointFloat position; //The location of the center of the circle.
    double     radius;   //The radius of the circle.
} CircleFeature;

typedef struct ConstCurveFeature_struct {
    PointFloat position;   //The center of the circle that this constant curve lies upon.
    double     radius;     //The radius of the circle that this constant curve lies upon.
    double     startAngle; //When traveling along the constant curve from one endpoint to the next in a counterclockwise manner, this is the angular component of the vector originating at the center of the constant curve and pointing towards the first endpoint of the constant curve.
    double     endAngle;   //When traveling along the constant curve from one endpoint to the next in a counterclockwise manner, this is the angular component of the vector originating at the center of the constant curve and pointing towards the second endpoint of the constant curve.
} ConstCurveFeature;

typedef struct RectangleFeature_struct {
    PointFloat position;  //The center of the rectangle.
    PointFloat corner[4]; //The four corners of the rectangle.
    double     rotation;  //The orientation of the rectangle with respect to the horizontal.
    double     width;     //The width of the rectangle.
    double     height;    //The height of the rectangle.
} RectangleFeature;

typedef struct LegFeature_struct {
    PointFloat position;  //The location of the leg feature.
    PointFloat corner[4]; //The four corners of the leg feature.
    double     rotation;  //The orientation of the leg with respect to the horizontal.
    double     width;     //The width of the leg.
    double     height;    //The height of the leg.
} LegFeature;

typedef struct CornerFeature_struct {
    PointFloat position;      //The location of the corner feature.
    double     rotation;      //The angular component of the vector bisecting the corner from position.
    double     enclosedAngle; //The measure of the enclosed angle of the corner.
    int        isVirtual;     
} CornerFeature;

typedef struct LineFeature_struct {
    PointFloat startPoint; //The starting point of the line.
    PointFloat endPoint;   //The ending point of the line.
    double     length;     //The length of the line measured in pixels from the start point to the end point.
    double     rotation;   //The orientation of the line with respect to the horizontal.
} LineFeature;

typedef struct ParallelLinePairFeature_struct {
    PointFloat firstStartPoint;  //The starting point of the first line of the pair.
    PointFloat firstEndPoint;    //The ending point of the first line of the pair.
    PointFloat secondStartPoint; //The starting point of the second line of the pair.
    PointFloat secondEndPoint;   //The ending point of the second line of the pair.
    double     rotation;         //The orientation of the feature with respect to the horizontal.
    double     distance;         //The distance from the first line to the second line.
} ParallelLinePairFeature;

typedef struct PairOfParallelLinePairsFeature_struct {
    ParallelLinePairFeature firstParallelLinePair;  //The first parallel line pair.
    ParallelLinePairFeature secondParallelLinePair; //The second parallel line pair.
    double                  rotation;               //The orientation of the feature with respect to the horizontal.
    double                  distance;               //The distance from the midline of the first parallel line pair to the midline of the second parallel line pair.
} PairOfParallelLinePairsFeature;

typedef union GeometricFeature_union {
    CircleFeature*                  circle;                  //A pointer to a CircleFeature.
    EllipseFeature*                 ellipse;                 //A pointer to an EllipseFeature.
    ConstCurveFeature*              constCurve;              //A pointer to a ConstCurveFeature.
    RectangleFeature*               rectangle;               //A pointer to a RectangleFeature.
    LegFeature*                     leg;                     //A pointer to a LegFeature.
    CornerFeature*                  corner;                  //A pointer to a CornerFeature.
    ParallelLinePairFeature*        parallelLinePair;        //A pointer to a ParallelLinePairFeature.
    PairOfParallelLinePairsFeature* pairOfParallelLinePairs; //A pointer to a PairOfParallelLinePairsFeature.
    LineFeature*                    line;                    //A pointer to a LineFeature.
    ClosedCurveFeature*             closedCurve;             //A pointer to a ClosedCurveFeature.
} GeometricFeature;

typedef struct FeatureData_struct {
    FeatureType      type;             //An enumeration representing the type of the feature.
    PointFloat*      contourPoints;    //A set of points describing the contour of the feature.
    int              numContourPoints; //The number of points in the contourPoints array.
    GeometricFeature feature;          //The feature data specific to this type of feature.
} FeatureData;

typedef struct GeometricPatternMatch2_struct {
    PointFloat   position;                //The location of the origin of the template in the match.
    float        rotation;                //The rotation of the match relative to the template image, in degrees.
    float        scale;                   //The size of the match relative to the size of the template image, expressed as a percentage.
    float        score;                   //The accuracy of the match.
    PointFloat   corner[4];               //An array of four points describing the rectangle surrounding the template image.
    int          inverse;                 //This element is TRUE if the match is an inverse of the template image.
    float        occlusion;               //The percentage of the match that is occluded.
    float        templateMatchCurveScore; //The accuracy of the match obtained by comparing the template curves to the curves in the match region.
    float        matchTemplateCurveScore; //The accuracy of the match obtained by comparing the curves in the match region to the template curves.
    float        correlationScore;        //The accuracy of the match obtained by comparing the template image to the match region using a correlation metric that compares the two regions as a function of their pixel values.
    String255    label;                   //The label corresponding to this match when the match is returned by imaqMatchMultipleGeometricPatterns().
    FeatureData* featureData;             //The features used in this match.
    int          numFeatureData;          //The size of the featureData array.
    PointFloat   calibratedPosition;      //The location of the origin of the template in the match.
    float        calibratedRotation;      //The rotation of the match relative to the template image, in degrees.
    PointFloat   calibratedCorner[4];     //An array of four points describing the rectangle surrounding the template image.
} GeometricPatternMatch2;

typedef struct ClosedCurveFeature_struct {
    PointFloat position;  //The center of the closed curve feature.
    double     arcLength; //The arc length of the closed curve feature.
} ClosedCurveFeature;

typedef struct LineMatch_struct {
    PointFloat startPoint; //The starting point of the matched line.
    PointFloat endPoint;   //The ending point of the matched line.
    double     length;     //The length of the line measured in pixels from the start point to the end point.
    double     rotation;   //The orientation of the matched line.
    double     score;      //The score of the matched line.
} LineMatch;

typedef struct LineDescriptor_struct {
    double minLength; //Specifies the minimum length of a line the function will return.
    double maxLength; //Specifies the maximum length of a line the function will return.
} LineDescriptor;

typedef struct RectangleDescriptor_struct {
    double minWidth;  //Specifies the minimum width of a rectangle the algorithm will return.
    double maxWidth;  //Specifies the maximum width of a rectangle the algorithm will return.
    double minHeight; //Specifies the minimum height of a rectangle the algorithm will return.
    double maxHeight; //Specifies the maximum height of a rectangle the algorithm will return.
} RectangleDescriptor;

typedef struct RectangleMatch_struct {
    PointFloat corner[4]; //The corners of the matched rectangle.
    double     rotation;  //The orientation of the matched rectangle.
    double     width;     //The width of the matched rectangle.
    double     height;    //The height of the matched rectangle.
    double     score;     //The score of the matched rectangle.
} RectangleMatch;

typedef struct EllipseDescriptor_struct {
    double minMajorRadius; //Specifies the minimum length of the semi-major axis of an ellipse the function will return.
    double maxMajorRadius; //Specifies the maximum length of the semi-major axis of an ellipse the function will return.
    double minMinorRadius; //Specifies the minimum length of the semi-minor axis of an ellipse the function will return.
    double maxMinorRadius; //Specifies the maximum length of the semi-minor axis of an ellipse the function will return.
} EllipseDescriptor;

typedef struct EllipseMatch_struct {
    PointFloat position;    //The location of the center of the matched ellipse.
    double     rotation;    //The orientation of the matched ellipse.
    double     majorRadius; //The length of the semi-major axis of the matched ellipse.
    double     minorRadius; //The length of the semi-minor axis of the matched ellipse.
    double     score;       //The score of the matched ellipse.
} EllipseMatch;

typedef struct CircleMatch_struct {
    PointFloat position; //The location of the center of the matched circle.
    double     radius;   //The radius of the matched circle.
    double     score;    //The score of the matched circle.
} CircleMatch;

typedef struct CircleDescriptor_struct {
    double minRadius; //Specifies the minimum radius of a circle the function will return.
    double maxRadius; //Specifies the maximum radius of a circle the function will return.
} CircleDescriptor;

typedef struct RangeFloat_struct {
    float minValue; //The minimum value of the range.
    float maxValue; //The maximum value of the range.
} RangeFloat;

typedef struct ShapeDetectionOptions_struct {
    unsigned int mode;           //Specifies the method used when looking for the shape in the image.
    RangeFloat*  angleRanges;    //An array of angle ranges, in degrees, where each range specifies how much you expect the shape to be rotated in the image.
    int          numAngleRanges; //The size of the orientationRanges array.
    RangeFloat   scaleRange;     //A range that specifies the sizes of the shapes you expect to be in the image, expressed as a ratio percentage representing the size of the pattern in the image divided by size of the original pattern multiplied by 100.
    double       minMatchScore;  
} ShapeDetectionOptions;

typedef struct Curve_struct {
    PointFloat*  points;              //The points on the curve.
    unsigned int numPoints;           //The number of points in the curve.
    int          closed;              //This element is TRUE if the curve is closed and FALSE if the curve is open.
    double       curveLength;         //The length of the curve.
    double       minEdgeStrength;     //The lowest edge strength detected on the curve.
    double       maxEdgeStrength;     //The highest edge strength detected on the curve.
    double       averageEdgeStrength; //The average of all edge strengths detected on the curve.
} Curve;

typedef struct CurveOptions_struct {
    ExtractionMode extractionMode;   //Specifies the method the function uses to identify curves in the image.
    int            threshold;        //Specifies the minimum contrast a seed point must have in order to begin a curve.
    EdgeFilterSize filterSize;       //Specifies the width of the edge filter the function uses to identify curves in the image.
    int            minLength;        //Specifies the length, in pixels, of the smallest curve the function will extract.
    int            rowStepSize;      //Specifies the distance, in the y direction, between lines the function inspects for curve seed points.
    int            columnStepSize;   //Specifies the distance, in the x direction, between columns the function inspects for curve seed points.
    int            maxEndPointGap;   //Specifies the maximum gap, in pixels, between the endpoints of a curve that the function identifies as a closed curve.
    int            onlyClosed;       //Set this element to TRUE to specify that the function should only identify closed curves in the image.
    int            subpixelAccuracy; //Set this element to TRUE to specify that the function identifies the location of curves with subpixel accuracy by interpolating between points to find the crossing of threshold.
} CurveOptions;

typedef struct Barcode2DInfo_struct {
    Barcode2DType  type;                 //The type of the 2D barcode.
    int            binary;               //This element is TRUE if the 2D barcode contains binary data and FALSE if the 2D barcode contains text data.
    unsigned char* data;                 //The data encoded in the 2D barcode.
    unsigned int   dataLength;           //The length of the data array.
    PointFloat     boundingBox[4];       //An array of four points describing the rectangle surrounding the 2D barcode.
    unsigned int   numErrorsCorrected;   //The number of errors the function corrected when decoding the 2D barcode.
    unsigned int   numErasuresCorrected; //The number of erasures the function corrected when decoding the 2D barcode.
    unsigned int   rows;                 //The number of rows in the 2D barcode.
    unsigned int   columns;              //The number of columns in the 2D barcode.
} Barcode2DInfo;

typedef struct DataMatrixOptions_struct {
    Barcode2DSearchMode searchMode;   //Specifies the mode the function uses to search for barcodes.
    Barcode2DContrast   contrast;     //Specifies the contrast of the barcodes that the function searches for.
    Barcode2DCellShape  cellShape;    //Specifies the shape of the barcode data cells, which affects how the function decodes the barcode.
    Barcode2DShape      barcodeShape; //Specifies the shape of the barcodes that the function searches for.
    DataMatrixSubtype   subtype;      //Specifies the Data Matrix subtypes of the barcodes that the function searches for.
} DataMatrixOptions;

typedef struct ClassifierAccuracyReport_struct {
    int     size;                       //The size of the arrays in this structure.
    float   accuracy;                   //The overall accuracy of the classifier, from 0 to 1000.
    char**  classNames;                 //The names of the classes of this classifier.
    double* classAccuracy;              //An array of size elements that contains accuracy information for each class.
    double* classPredictiveValue;       //An array containing size elements that contains the predictive values of each class.
    int**   classificationDistribution; //A two-dimensional array containing information about how the classifier classifies its samples.
} ClassifierAccuracyReport;

typedef struct NearestNeighborClassResult_struct {
    char* className;         //The name of the class.
    float standardDeviation; //The standard deviation of the members of this class.
    int   count;             //The number of samples in this class.
} NearestNeighborClassResult;

typedef struct NearestNeighborTrainingReport_struct {
    float**                     classDistancesTable; //The confidence in the training.
    NearestNeighborClassResult* allScores;           //All classes and their scores.
    int                         allScoresSize;       //The number of entries in allScores.
} NearestNeighborTrainingReport;

typedef struct ParticleClassifierPreprocessingOptions_struct {
    int             manualThreshold;      //Set this element to TRUE to specify the threshold range manually.
    RangeFloat      manualThresholdRange; //If a manual threshold is being done, the range of pixels to keep.
    ThresholdMethod autoThresholdMethod;  //If an automatic threshold is being done, the method used to calculate the threshold range.
    RangeFloat      limits;               //The limits on the automatic threshold range.
    ParticleType    particleType;         //What kind of particles to look for.
    int             rejectBorder;         //Set this element to TRUE to reject border particles.
    int             numErosions;          //The number of erosions to perform.
} ParticleClassifierPreprocessingOptions;

typedef struct ClassifierSampleInfo_struct {
    char*   className;         //The name of the class this sample is in.
    double* featureVector;     //The feature vector of this sample, or NULL if this is not a custom classifier session.
    int     featureVectorSize; //The number of elements in the feature vector.
    Image*  thumbnail;         //A thumbnail image of this sample, or NULL if no image was specified.
} ClassifierSampleInfo;

typedef struct ClassScore_struct {
    char* className; //The name of the class.
    float distance;  //The distance from the item to this class.
} ClassScore;

typedef struct ClassifierReport_struct {
    char*       bestClassName;       //The name of the best class for the sample.
    float       classificationScore; //The similarity of the sample and the two closest classes in the classifier.
    float       identificationScore; //The similarity of the sample and the assigned class.
    ClassScore* allScores;           //All classes and their scores.
    int         allScoresSize;       //The number of entries in allScores.
} ClassifierReport;

typedef struct NearestNeighborOptions_struct {
    NearestNeighborMethod method; //The method to use.
    NearestNeighborMetric metric; //The metric to use.
    int                   k;      //The value of k, if the IMAQ_K_NEAREST_NEIGHBOR method is used.
} NearestNeighborOptions;

typedef struct ParticleClassifierOptions_struct {
    float scaleDependence;  //The relative importance of scale when classifying particles.
    float mirrorDependence; //The relative importance of mirror symmetry when classifying particles.
} ParticleClassifierOptions;

typedef struct RGBU64Value_struct {
    unsigned short B;     //The blue value of the color.
    unsigned short G;     //The green value of the color.
    unsigned short R;     //The red value of the color.
    unsigned short alpha; //The alpha value of the color, which represents extra information about a color image, such as gamma correction.
} RGBU64Value;

typedef struct GeometricPatternMatch_struct {
    PointFloat position;                //The location of the origin of the template in the match.
    float      rotation;                //The rotation of the match relative to the template image, in degrees.
    float      scale;                   //The size of the match relative to the size of the template image, expressed as a percentage.
    float      score;                   //The accuracy of the match.
    PointFloat corner[4];               //An array of four points describing the rectangle surrounding the template image.
    int        inverse;                 //This element is TRUE if the match is an inverse of the template image.
    float      occlusion;               //The percentage of the match that is occluded.
    float      templateMatchCurveScore; //The accuracy of the match obtained by comparing the template curves to the curves in the match region.
    float      matchTemplateCurveScore; //The accuracy of the match obtained by comparing the curves in the match region to the template curves.
    float      correlationScore;        //The accuracy of the match obtained by comparing the template image to the match region using a correlation metric that compares the two regions as a function of their pixel values.
} GeometricPatternMatch;

typedef struct MatchGeometricPatternAdvancedOptions_struct {
    int    minFeaturesUsed;            //Specifies the minimum number of features the function uses when matching.
    int    maxFeaturesUsed;            //Specifies the maximum number of features the function uses when matching.
    int    subpixelIterations;         //Specifies the maximum number of incremental improvements used to refine matches with subpixel information.
    double subpixelTolerance;          //Specifies the maximum amount of change, in pixels, between consecutive incremental improvements in the match position before the function stops refining the match position.
    int    initialMatchListLength;     //Specifies the maximum size of the match list.
    int    matchTemplateCurveScore;    //Set this element to TRUE to specify that the function should calculate the match curve to template curve score and return it for each match result.
    int    correlationScore;           //Set this element to TRUE to specify that the function should calculate the correlation score and return it for each match result.
    double minMatchSeparationDistance; //Specifies the minimum separation distance, in pixels, between the origins of two matches that have unique positions.
    double minMatchSeparationAngle;    //Specifies the minimum angular difference, in degrees, between two matches that have unique angles.
    double minMatchSeparationScale;    //Specifies the minimum difference in scale, expressed as a percentage, between two matches that have unique scales.
    double maxMatchOverlap;            //Specifies the maximum amount of overlap, expressed as a percentage, allowed between the bounding rectangles of two unique matches.
    int    coarseResult;               //Specifies whether you want the function to spend less time accurately estimating the location of a match.
} MatchGeometricPatternAdvancedOptions;

typedef struct MatchGeometricPatternOptions_struct {
    unsigned int mode;                //Specifies the method imaqMatchGeometricPattern() uses when looking for the pattern in the image.
    int          subpixelAccuracy;    //Set this element to TRUE to specify that the function should calculate match locations with subpixel accuracy.
    RangeFloat*  angleRanges;         //An array of angle ranges, in degrees, where each range specifies how much you expect the template to be rotated in the image.
    int          numAngleRanges;      //Number of angle ranges in the angleRanges array.
    RangeFloat   scaleRange;          //A range that specifies the sizes of the pattern you expect to be in the image, expressed as a ratio percentage representing the size of the pattern in the image divided by size of the original pattern multiplied by 100.
    RangeFloat   occlusionRange;      //A range that specifies the percentage of the pattern you expect to be occluded in the image.
    int          numMatchesRequested; //Number of valid matches expected.
    float        minMatchScore;       //The minimum score a match can have for the function to consider the match valid.
} MatchGeometricPatternOptions;

typedef struct LearnGeometricPatternAdvancedOptions_struct {
    int    minRectLength;            //Specifies the minimum length for each side of a rectangular feature.
    double minRectAspectRatio;       //Specifies the minimum aspect ratio of a rectangular feature.
    int    minRadius;                //Specifies the minimum radius for a circular feature.
    int    minLineLength;            //Specifies the minimum length for a linear feature.
    double minFeatureStrength;       //Specifies the minimum strength for a feature.
    int    maxFeaturesUsed;          //Specifies the maximum number of features the function uses when learning.
    int    maxPixelDistanceFromLine; //Specifies the maximum number of pixels between an edge pixel and a linear feature for the function to consider that edge pixel as part of the linear feature.
} LearnGeometricPatternAdvancedOptions;

typedef struct FitEllipseOptions_struct {
    int    rejectOutliers; //Whether to use every given point or only a subset of the points to fit the ellipse.
    double minScore;       //Specifies the required quality of the fitted ellipse.
    double pixelRadius;    //The acceptable distance, in pixels, that a point determined to belong to the ellipse can be from the circumference of the ellipse.
    int    maxIterations;  //Specifies the number of refinement iterations you allow the function to perform on the initial subset of points.
} FitEllipseOptions;

typedef struct FitCircleOptions_struct {
    int    rejectOutliers; //Whether to use every given point or only a subset of the points to fit the circle.
    double minScore;       //Specifies the required quality of the fitted circle.
    double pixelRadius;    //The acceptable distance, in pixels, that a point determined to belong to the circle can be from the circumference of the circle.
    int    maxIterations;  //Specifies the number of refinement iterations you allow the function to perform on the initial subset of points.
} FitCircleOptions;

typedef struct ConstructROIOptions2_struct {
    int          windowNumber; //The window number of the image window.
    const char*  windowTitle;  //Specifies the message string that the function displays in the title bar of the window.
    PaletteType  type;         //The palette type to use.
    RGBValue*    palette;      //If type is IMAQ_PALETTE_USER, this array is the palette of colors to use with the window.
    int          numColors;    //If type is IMAQ_PALETTE_USER, this element is the number of colors in the palette array.
    unsigned int maxContours;  //The maximum number of contours the user will be able to select.
} ConstructROIOptions2;

typedef struct RGBValue_struct {
    unsigned char B;     //The blue value of the color.
    unsigned char G;     //The green value of the color.
    unsigned char R;     //The red value of the color.
    unsigned char alpha; //The alpha value of the color, which represents extra information about a color image, such as gamma correction.
} RGBValue;

typedef struct HSLValue_struct {
    unsigned char L;     //The color luminance.
    unsigned char S;     //The color saturation.
    unsigned char H;     //The color hue.
    unsigned char alpha; //The alpha value of the color, which represents extra information about a color image, such as gamma correction.
} HSLValue;

typedef struct HSVValue_struct {
    unsigned char V;     //The color value.
    unsigned char S;     //The color saturation.
    unsigned char H;     //The color hue.
    unsigned char alpha; //The alpha value of the color, which represents extra information about a color image, such as gamma correction.
} HSVValue;

typedef struct HSIValue_struct {
    unsigned char I;     //The color intensity.
    unsigned char S;     //The color saturation.
    unsigned char H;     //The color hue.
    unsigned char alpha; //The alpha value of the color, which represents extra information about a color image, such as gamma correction.
} HSIValue;

typedef struct CIELabValue_struct {
    double        b;     //The yellow/blue information of the color.
    double        a;     //The red/green information of the color.
    double        L;     //The color lightness.
    unsigned char alpha; //The alpha value of the color, which represents extra information about a color image, such as gamma correction.
} CIELabValue;

typedef struct CIEXYZValue_struct {
    double        Z;     //The Z color information.
    double        Y;     //The color luminance.
    double        X;     //The X color information.
    unsigned char alpha; //The alpha value of the color, which represents extra information about a color image, such as gamma correction.
} CIEXYZValue;

typedef union Color2_union {
    RGBValue    rgb;      //The information needed to describe a color in the RGB (Red, Green, and Blue) color space.
    HSLValue    hsl;      //The information needed to describe a color in the HSL (Hue, Saturation, and Luminance) color space.
    HSVValue    hsv;      //The information needed to describe a color in the HSI (Hue, Saturation, and Value) color space.
    HSIValue    hsi;      //The information needed to describe a color in the HSI (Hue, Saturation, and Intensity) color space.
    CIELabValue cieLab;   //The information needed to describe a color in the CIE L*a*b* (L, a, b) color space.
    CIEXYZValue cieXYZ;   //The information needed to describe a color in the CIE XYZ (X, Y, Z) color space.
    int         rawValue; //The integer value for the data in the color union.
} Color2;

typedef struct BestEllipse2_struct {
    PointFloat center;         //The coordinate location of the center of the ellipse.
    PointFloat majorAxisStart; //The coordinate location of the start of the major axis of the ellipse.
    PointFloat majorAxisEnd;   //The coordinate location of the end of the major axis of the ellipse.
    PointFloat minorAxisStart; //The coordinate location of the start of the minor axis of the ellipse.
    PointFloat minorAxisEnd;   //The coordinate location of the end of the minor axis of the ellipse.
    double     area;           //The area of the ellipse.
    double     perimeter;      //The length of the perimeter of the ellipse.
    double     error;          //Represents the least square error of the fitted ellipse to the entire set of points.
    int        valid;          //This element is TRUE if the function achieved the minimum score within the number of allowed refinement iterations and FALSE if the function did not achieve the minimum score.
    int*       pointsUsed;     //An array of the indexes for the points array indicating which points the function used to fit the ellipse.
    int        numPointsUsed;  //The number of points the function used to fit the ellipse.
} BestEllipse2;

typedef struct LearnPatternAdvancedOptions_struct {
    LearnPatternAdvancedShiftOptions*    shiftOptions;    //Use this element to control the behavior of imaqLearnPattern2() during the shift-invariant learning phase.
    LearnPatternAdvancedRotationOptions* rotationOptions; //Use this element to control the behavior of imaqLearnPattern2()during the rotation-invariant learning phase.
} LearnPatternAdvancedOptions;

typedef struct AVIInfo_struct {
    unsigned int width;           //The width of each frame.
    unsigned int height;          //The height of each frame.
    ImageType    imageType;       //The type of images this AVI contains.
    unsigned int numFrames;       //The number of frames in the AVI.
    unsigned int framesPerSecond; //The number of frames per second this AVI should be shown at.
    char*        filterName;      //The name of the compression filter used to create this AVI.
    int          hasData;         //Specifies whether this AVI has data attached to each frame or not.
    unsigned int maxDataSize;     //If this AVI has data, the maximum size of the data in each frame.
} AVIInfo;

typedef struct LearnPatternAdvancedShiftOptions_struct {
    int    initialStepSize;          //The largest number of image pixels to shift the sample across the inspection image during the initial phase of shift-invariant matching.
    int    initialSampleSize;        //Specifies the number of template pixels that you want to include in a sample for the initial phase of shift-invariant matching.
    double initialSampleSizeFactor;  //Specifies the size of the sample for the initial phase of shift-invariant matching as a percent of the template size, in pixels.
    int    finalSampleSize;          //Specifies the number of template pixels you want to add to initialSampleSize for the final phase of shift-invariant matching.
    double finalSampleSizeFactor;    //Specifies the size of the sample for the final phase of shift-invariant matching as a percent of the edge points in the template, in pixels.
    int    subpixelSampleSize;       //Specifies the number of template pixels that you want to include in a sample for the subpixel phase of shift-invariant matching.
    double subpixelSampleSizeFactor; //Specifies the size of the sample for the subpixel phase of shift-invariant matching as a percent of the template size, in pixels.
} LearnPatternAdvancedShiftOptions;

typedef struct LearnPatternAdvancedRotationOptions_struct {
    SearchStrategy searchStrategySupport;    //Specifies the aggressiveness of the rotation search strategy available during the matching phase.
    int            initialStepSize;          //The largest number of image pixels to shift the sample across the inspection image during the initial phase of matching.
    int            initialSampleSize;        //Specifies the number of template pixels that you want to include in a sample for the initial phase of rotation-invariant matching.
    double         initialSampleSizeFactor;  //Specifies the size of the sample for the initial phase of rotation-invariant matching as a percent of the template size, in pixels.
    int            initialAngularAccuracy;   //Sets the angle accuracy, in degrees, to use during the initial phase of rotation-invariant matching.
    int            finalSampleSize;          //Specifies the number of template pixels you want to add to initialSampleSize for the final phase of rotation-invariant matching.
    double         finalSampleSizeFactor;    //Specifies the size of the sample for the final phase of rotation-invariant matching as a percent of the edge points in the template, in pixels.
    int            finalAngularAccuracy;     //Sets the angle accuracy, in degrees, to use during the final phase of the rotation-invariant matching.
    int            subpixelSampleSize;       //Specifies the number of template pixels that you want to include in a sample for the subpixel phase of rotation-invariant matching.
    double         subpixelSampleSizeFactor; //Specifies the size of the sample for the subpixel phase of rotation-invariant matching as a percent of the template size, in pixels.
} LearnPatternAdvancedRotationOptions;

typedef struct MatchPatternAdvancedOptions_struct {
    int            subpixelIterations;          //Defines the maximum number of incremental improvements used to refine matching using subpixel information.
    double         subpixelTolerance;           //Defines the maximum amount of change, in pixels, between consecutive incremental improvements in the match position that you want to trigger the end of the refinement process.
    int            initialMatchListLength;      //Specifies the maximum size of the match list.
    int            matchListReductionFactor;    //Specifies the reduction of the match list as matches are refined.
    int            initialStepSize;             //Specifies the number of pixels to shift the sample across the inspection image during the initial phase of shift-invariant matching.
    SearchStrategy searchStrategy;              //Specifies the aggressiveness of the rotation search strategy.
    int            intermediateAngularAccuracy; //Specifies the accuracy to use during the intermediate phase of rotation-invariant matching.
} MatchPatternAdvancedOptions;

typedef struct ParticleFilterCriteria2_struct {
    MeasurementType parameter;  //The morphological measurement that the function uses for filtering.
    float           lower;      //The lower bound of the criteria range.
    float           upper;      //The upper bound of the criteria range.
    int             calibrated; //Set this element to TRUE to take calibrated measurements.
    int             exclude;    //Set this element to TRUE to indicate that a match occurs when the measurement is outside the criteria range.
} ParticleFilterCriteria2;

typedef struct BestCircle2_struct {
    PointFloat center;        //The coordinate location of the center of the circle.
    double     radius;        //The radius of the circle.
    double     area;          //The area of the circle.
    double     perimeter;     //The length of the perimeter of the circle.
    double     error;         //Represents the least square error of the fitted circle to the entire set of points.
    int        valid;         //This element is TRUE if the function achieved the minimum score within the number of allowed refinement iterations and FALSE if the function did not achieve the minimum score.
    int*       pointsUsed;    //An array of the indexes for the points array indicating which points the function used to fit the circle.
    int        numPointsUsed; //The number of points the function used to fit the circle.
} BestCircle2;

typedef struct OCRSpacingOptions_struct {
    int minCharSpacing;              //The minimum number of pixels that must be between two characters for NI Vision to train or read the characters separately.
    int minCharSize;                 //The minimum number of pixels required for an object to be a potentially identifiable character.
    int maxCharSize;                 //The maximum number of pixels required for an object to be a potentially identifiable character.
    int maxHorizontalElementSpacing; //The maximum horizontal spacing, in pixels, allowed between character elements to train or read the character elements as a single character.
    int maxVerticalElementSpacing;   //The maximum vertical element spacing in pixels.
    int minBoundingRectWidth;        //The minimum possible width, in pixels, for a character bounding rectangle.
    int maxBoundingRectWidth;        //The maximum possible width, in pixels, for a character bounding rectangle.
    int minBoundingRectHeight;       //The minimum possible height, in pixels, for a character bounding rectangle.
    int maxBoundingRectHeight;       //The maximum possible height, in pixels, for a character bounding rectangle.
    int autoSplit;                   //Set this element to TRUE to automatically adjust the location of the character bounding rectangle when characters overlap vertically.
} OCRSpacingOptions;

typedef struct OCRProcessingOptions_struct {
    ThresholdMode mode;                       //The thresholding mode.
    int           lowThreshold;               //The low threshold value when you set mode to IMAQ_FIXED_RANGE.
    int           highThreshold;              //The high threshold value when you set mode to IMAQ_FIXED_RANGE.
    int           blockCount;                 //The number of blocks for threshold calculation algorithms that require blocks.
    int           fastThreshold;              //Set this element to TRUE to use a faster, less accurate threshold calculation algorithm.
    int           biModalCalculation;         //Set this element to TRUE to calculate both the low and high threshold values when using the fast thresholding method.
    int           darkCharacters;             //Set this element to TRUE to read or train dark characters on a light background.
    int           removeParticlesTouchingROI; //Set this element to TRUE to remove the particles touching the ROI.
    int           erosionCount;               //The number of erosions to perform.
} OCRProcessingOptions;

typedef struct ReadTextOptions_struct {
    String255      validChars[255];  //An array of strings that specifies the valid characters.
    int            numValidChars;    //The number of strings in the validChars array that you have initialized.
    char           substitutionChar; //The character to substitute for objects that the function cannot match with any of the trained characters.
    ReadStrategy   readStrategy;     //The read strategy, which determines how closely the function analyzes images in the reading process to match objects with trained characters.
    int            acceptanceLevel;  //The minimum acceptance level at which an object is considered a trained character.
    int            aspectRatio;      //The maximum aspect ratio variance percentage for valid characters.
    ReadResolution readResolution;   //The read resolution, which determines how much of the trained character data the function uses to match objects to trained characters.
} ReadTextOptions;

typedef struct CharInfo_struct {
    const char*  charValue;     //Retrieves the character value of the corresponding character in the character set.
    const Image* charImage;     //The image you used to train this character.
    const Image* internalImage; //The internal representation that NI Vision uses to match objects to this character.
} CharInfo;

#if !defined(USERINT_HEADER) && !defined(_CVI_RECT_DEFINED)
typedef struct Rect_struct {
    int top;    //Location of the top edge of the rectangle.
    int left;   //Location of the left edge of the rectangle.
    int height; //Height of the rectangle.
    int width;  //Width of the rectangle.
} Rect;
#define _CVI_RECT_DEFINED
#endif

typedef struct CharReport_struct {
    const char* character;     //The character value.
    PointFloat  corner[4];     //An array of four points that describes the rectangle that surrounds the character.
    int         reserved;      //This element is reserved.
    int         lowThreshold;  //The minimum value of the threshold range used for this character.
    int         highThreshold; //The maximum value of the threshold range used for this character.
} CharReport;

typedef struct ReadTextReport_struct {
    const char*       readString;          //The read string.
    const CharReport* characterReport;     //An array of reports describing the properties of each identified character.
    int               numCharacterReports; //The number of identified characters.
} ReadTextReport;

#if !defined(USERINT_HEADER) && !defined(_CVI_POINT_DEFINED)
typedef struct Point_struct {
    int x; //The x-coordinate of the point.
    int y; //The y-coordinate of the point.
} Point;
#define _CVI_POINT_DEFINED
#endif

typedef struct Annulus_struct {
    Point  center;      //The coordinate location of the center of the annulus.
    int    innerRadius; //The internal radius of the annulus.
    int    outerRadius; //The external radius of the annulus.
    double startAngle;  //The start angle, in degrees, of the annulus.
    double endAngle;    //The end angle, in degrees, of the annulus.
} Annulus;

typedef struct EdgeLocationReport_struct {
    PointFloat* edges;    //The coordinate location of all edges detected by the search line.
    int         numEdges; //The number of points in the edges array.
} EdgeLocationReport;

typedef struct EdgeOptions_struct {
    unsigned            threshold;         //Specifies the threshold value for the contrast of the edge.
    unsigned            width;             //The number of pixels that the function averages to find the contrast at either side of the edge.
    unsigned            steepness;         //The span, in pixels, of the slope of the edge projected along the path specified by the input points.
    InterpolationMethod subpixelType;      //The method for interpolating.
    unsigned            subpixelDivisions; //The number of samples the function obtains from a pixel.
} EdgeOptions;

typedef struct EdgeReport_struct {
    float        location;   //The location of the edge from the first point in the points array.
    float        contrast;   //The contrast at the edge.
    PolarityType polarity;   //The polarity of the edge.
    float        reserved;   //This element is reserved.
    PointFloat   coordinate; //The coordinates of the edge.
} EdgeReport;

typedef struct ExtremeReport_struct {
    double location;         //The locations of the extreme.
    double amplitude;        //The amplitude of the extreme.
    double secondDerivative; //The second derivative of the extreme.
} ExtremeReport;

typedef struct FitLineOptions_struct {
    float minScore;       //Specifies the required quality of the fitted line.
    float pixelRadius;    //Specifies the neighborhood pixel relationship for the initial subset of points being used.
    int   numRefinements; //Specifies the number of refinement iterations you allow the function to perform on the initial subset of points.
} FitLineOptions;

typedef struct GridDescriptor_struct {
    float           xStep; //The distance in the x direction between two adjacent pixels in units specified by unit.
    float           yStep; //The distance in the y direction between two adjacent pixels in units specified by unit.
    CalibrationUnit unit;  //The unit of measure for the image.
} GridDescriptor;

typedef struct DisplayMapping_struct {
    MappingMethod method;       //Describes the method for converting 16-bit pixels to 8-bit pixels.
    int           minimumValue; //When method is IMAQ_RANGE, minimumValue represents the value that is mapped to 0.
    int           maximumValue; //When method is IMAQ_RANGE, maximumValue represents the value that is mapped to 255.
    int           shiftCount;   //When method is IMAQ_DOWNSHIFT, shiftCount represents the number of bits the function right-shifts the 16-bit pixel values.
} DisplayMapping;

typedef struct DetectExtremesOptions_struct {
    double threshold; //Defines which extremes are too small.
    int    width;     //Specifies the number of consecutive data points the function uses in the quadratic least-squares fit.
} DetectExtremesOptions;

typedef struct ImageInfo_struct {
    CalibrationUnit imageUnit;     //If you set calibration information with imaqSetSimpleCalibrationInfo(), imageUnit is the calibration unit.
    float           stepX;         //If you set calibration information with imaqSetCalibrationInfo(), stepX is the distance in the calibration unit between two pixels in the x direction.
    float           stepY;         //If you set calibration information with imaqSetCalibrationInfo(), stepY is the distance in the calibration unit between two pixels in the y direction.
    ImageType       imageType;     //The type of the image.
    int             xRes;          //The number of columns in the image.
    int             yRes;          //The number of rows in the image.
    int             xOffset;       //If you set mask offset information with imaqSetMaskOffset(), xOffset is the offset of the mask origin in the x direction.
    int             yOffset;       //If you set mask offset information with imaqSetMaskOffset(), yOffset is the offset of the mask origin in the y direction.
    int             border;        //The number of border pixels around the image.
    int             pixelsPerLine; //The number of pixels stored for each line of the image.
    void*           reserved0;     //This element is reserved.
    void*           reserved1;     //This element is reserved.
    void*           imageStart;    //A pointer to pixel (0,0).
} ImageInfo;

typedef struct LCDOptions_struct {
    int   litSegments;  //Set this parameter to TRUE if the segments are brighter than the background.
    float threshold;    //Determines whether a segment is ON or OFF.
    int   sign;         //Indicates whether the function must read the sign of the indicator.
    int   decimalPoint; //Determines whether to look for a decimal separator after each digit.
} LCDOptions;

typedef struct LCDReport_struct {
    const char*  text;          //A string of the characters of the LCD.
    LCDSegments* segmentInfo;   //An array of LCDSegment structures describing which segments of each digit are on.
    int          numCharacters; //The number of characters that the function reads.
    int          reserved;      //This element is reserved.
} LCDReport;

typedef struct LCDSegments_struct {
    unsigned a:1;         //True if the a segment is on.
    unsigned b:1;         //True if the b segment is on.
    unsigned c:1;         //True if the c segment is on.
    unsigned d:1;         //True if the d segment is on.
    unsigned e:1;         //True if the e segment is on.
    unsigned f:1;         //True if the f segment is on.
    unsigned g:1;         //True if the g segment is on.
    unsigned reserved:25; //This element is reserved.
} LCDSegments;

typedef struct LearnCalibrationOptions_struct {
    CalibrationMode mode;       //Specifies the type of algorithm you want to use to reduce distortion in your image.
    ScalingMethod   method;     //Defines the scaling method correction functions use to correct the image.
    CalibrationROI  roi;        //Specifies the ROI correction functions use when correcting an image.
    int             learnMap;   //Set this element to TRUE if you want the function to calculate and store an error map during the learning process.
    int             learnTable; //Set this element to TRUE if you want the function to calculate and store the correction table.
} LearnCalibrationOptions;

typedef struct LearnColorPatternOptions_struct {
    LearningMode      learnMode;         //Specifies the invariance mode the function uses when learning the pattern.
    ImageFeatureMode  featureMode;       //Specifies the features the function uses when learning the color pattern.
    int               threshold;         //Specifies the saturation threshold the function uses to distinguish between two colors that have the same hue values.
    ColorIgnoreMode   ignoreMode;        //Specifies whether the function excludes certain colors from the color features of the template image.
    ColorInformation* colorsToIgnore;    //An array of ColorInformation structures providing a set of colors to exclude from the color features of the template image.
    int               numColorsToIgnore; //The number of ColorInformation structures in the colorsToIgnore array.
} LearnColorPatternOptions;

typedef struct Line_struct {
    Point start; //The coordinate location of the start of the line.
    Point end;   //The coordinate location of the end of the line.
} Line;

typedef struct LinearAverages_struct {
    float* columnAverages;      //An array containing the mean pixel value of each column.
    int    columnCount;         //The number of elements in the columnAverages array.
    float* rowAverages;         //An array containing the mean pixel value of each row.
    int    rowCount;            //The number of elements in the rowAverages array.
    float* risingDiagAverages;  //An array containing the mean pixel value of each diagonal running from the lower left to the upper right of the inspected area of the image.
    int    risingDiagCount;     //The number of elements in the risingDiagAverages array.
    float* fallingDiagAverages; //An array containing the mean pixel value of each diagonal running from the upper left to the lower right of the inspected area of the image.
    int    fallingDiagCount;    //The number of elements in the fallingDiagAverages array.
} LinearAverages;

typedef struct LineEquation_struct {
    double a; //The a coefficient of the line equation.
    double b; //The b coefficient of the line equation.
    double c; //The c coefficient of the line equation.
} LineEquation;

typedef struct LineFloat_struct {
    PointFloat start; //The coordinate location of the start of the line.
    PointFloat end;   //The coordinate location of the end of the line.
} LineFloat;

typedef struct LineProfile_struct {
    float* profileData; //An array containing the value of each pixel in the line.
    Rect   boundingBox; //The bounding rectangle of the line.
    float  min;         //The smallest pixel value in the line profile.
    float  max;         //The largest pixel value in the line profile.
    float  mean;        //The mean value of the pixels in the line profile.
    float  stdDev;      //The standard deviation of the line profile.
    int    dataCount;   //The size of the profileData array.
} LineProfile;

typedef struct MatchColorPatternOptions_struct {
    MatchingMode        matchMode;           //Specifies the method to use when looking for the color pattern in the image.
    ImageFeatureMode    featureMode;         //Specifies the features to use when looking for the color pattern in the image.
    int                 minContrast;         //Specifies the minimum contrast expected in the image.
    int                 subpixelAccuracy;    //Set this parameter to TRUE to return areas in the image that match the pattern area with subpixel accuracy.
    RotationAngleRange* angleRanges;         //An array of angle ranges, in degrees, where each range specifies how much you expect the pattern to be rotated in the image.
    int                 numRanges;           //Number of valid matches expected.
    double              colorWeight;         //Determines the percent contribution of the color score to the final color pattern matching score.
    ColorSensitivity    sensitivity;         //Specifies the sensitivity of the color information in the image.
    SearchStrategy      strategy;            //Specifies how the color features of the image are used during the search phase.
    int                 numMatchesRequested; //Number of valid matches expected.
    float               minMatchScore;       //The minimum score a match can have for the function to consider the match valid.
} MatchColorPatternOptions;

typedef struct HistogramReport_struct {
    int*  histogram;      //An array describing the number of pixels that fell into each class.
    int   histogramCount; //The number of elements in the histogram array.
    float min;            //The smallest pixel value that the function classified.
    float max;            //The largest pixel value that the function classified.
    float start;          //The smallest pixel value that fell into the first class.
    float width;          //The size of each class.
    float mean;           //The mean value of the pixels that the function classified.
    float stdDev;         //The standard deviation of the pixels that the function classified.
    int   numPixels;      //The number of pixels that the function classified.
} HistogramReport;

typedef struct ArcInfo_struct {
    Rect   boundingBox; //The coordinate location of the bounding box of the arc.
    double startAngle;  //The counterclockwise angle from the x-axis in degrees to the start of the arc.
    double endAngle;    //The counterclockwise angle from the x-axis in degrees to the end of the arc.
} ArcInfo;

typedef struct BarcodeInfo_struct {
    const char* outputString;    //A string containing the decoded barcode data.
    int         size;            //The size of the output string.
    char        outputChar1;     //The contents of this character depend on the barcode type.
    char        outputChar2;     //The contents of this character depend on the barcode type.
    double      confidenceLevel; //A quality measure of the decoded barcode ranging from 0 to 100, with 100 being the best.
    BarcodeType type;            //The type of barcode.
} BarcodeInfo;

typedef struct BCGOptions_struct {
    float brightness; //Adjusts the brightness of the image.
    float contrast;   //Adjusts the contrast of the image.
    float gamma;      //Performs gamma correction.
} BCGOptions;

typedef struct BestCircle_struct {
    PointFloat center;    //The coordinate location of the center of the circle.
    double     radius;    //The radius of the circle.
    double     area;      //The area of the circle.
    double     perimeter; //The length of the perimeter of the circle.
    double     error;     //Represents the least square error of the fitted circle to the entire set of points.
} BestCircle;

typedef struct BestEllipse_struct {
    PointFloat center;         //The coordinate location of the center of the ellipse.
    PointFloat majorAxisStart; //The coordinate location of the start of the major axis of the ellipse.
    PointFloat majorAxisEnd;   //The coordinate location of the end of the major axis of the ellipse.
    PointFloat minorAxisStart; //The coordinate location of the start of the minor axis of the ellipse.
    PointFloat minorAxisEnd;   //The coordinate location of the end of the minor axis of the ellipse.
    double     area;           //The area of the ellipse.
    double     perimeter;      //The length of the perimeter of the ellipse.
} BestEllipse;

typedef struct BestLine_struct {
    PointFloat   start;         //The coordinate location of the start of the line.
    PointFloat   end;           //The coordinate location of the end of the line.
    LineEquation equation;      //Defines the three coefficients of the equation of the best fit line.
    int          valid;         //This element is TRUE if the function achieved the minimum score within the number of allowed refinement iterations and FALSE if the function did not achieve the minimum score.
    double       error;         //Represents the least square error of the fitted line to the entire set of points.
    int*         pointsUsed;    //An array of the indexes for the points array indicating which points the function used to fit the line.
    int          numPointsUsed; //The number of points the function used to fit the line.
} BestLine;

typedef struct BrowserOptions_struct {
    int               width;           //The width to make the browser.
    int               height;          //The height to make the browser image.
    int               imagesPerLine;   //The number of images to place on a single line.
    RGBValue          backgroundColor; //The background color of the browser.
    int               frameSize;       //Specifies the number of pixels with which to border each thumbnail.
    BrowserFrameStyle style;           //The style for the frame around each thumbnail.
    float             ratio;           //Specifies the width to height ratio of each thumbnail.
    RGBValue          focusColor;      //The color to use to display focused cells.
} BrowserOptions;

typedef struct CoordinateSystem_struct {
    PointFloat      origin;          //The origin of the coordinate system.
    float           angle;           //The angle, in degrees, of the x-axis of the coordinate system relative to the image x-axis.
    AxisOrientation axisOrientation; //The direction of the y-axis of the coordinate reference system.
} CoordinateSystem;

typedef struct CalibrationInfo_struct {
    float*                  errorMap;       //The error map for the calibration.
    int                     mapColumns;     //The number of columns in the error map.
    int                     mapRows;        //The number of rows in the error map.
    ROI*                    userRoi;        //Specifies the ROI the user provided when learning the calibration.
    ROI*                    calibrationRoi; //Specifies the ROI that corresponds to the region of the image where the calibration information is accurate.
    LearnCalibrationOptions options;        //Specifies the calibration options the user provided when learning the calibration.
    GridDescriptor          grid;           //Specifies the scaling constants for the image.
    CoordinateSystem        system;         //Specifies the coordinate system for the real world coordinates.
    RangeFloat              range;          //The range of the grayscale the function used to represent the circles in the grid image.
    float                   quality;        //The quality score of the learning process, which is a value between 0-1000.
} CalibrationInfo;

typedef struct CalibrationPoints_struct {
    PointFloat* pixelCoordinates;     //The array of pixel coordinates.
    PointFloat* realWorldCoordinates; //The array of corresponding real-world coordinates.
    int         numCoordinates;       //The number of coordinates in both of the arrays.
} CalibrationPoints;

typedef struct CaliperOptions_struct {
    TwoEdgePolarityType polarity;            //Specifies the edge polarity of the edge pairs.
    float               separation;          //The distance between edge pairs.
    float               separationDeviation; //Sets the range around the separation value.
} CaliperOptions;

typedef struct CaliperReport_struct {
    float      edge1Contrast; //The contrast of the first edge.
    PointFloat edge1Coord;    //The coordinates of the first edge.
    float      edge2Contrast; //The contrast of the second edge.
    PointFloat edge2Coord;    //The coordinates of the second edge.
    float      separation;    //The distance between the two edges.
    float      reserved;      //This element is reserved.
} CaliperReport;

typedef struct DrawTextOptions_struct {
    char          fontName[32];  //The font name to use.
    int           fontSize;      //The size of the font.
    int           bold;          //Set this parameter to TRUE to bold text.
    int           italic;        //Set this parameter to TRUE to italicize text.
    int           underline;     //Set this parameter to TRUE to underline text.
    int           strikeout;     //Set this parameter to TRUE to strikeout text.
    TextAlignment textAlignment; //Sets the alignment of text.
    FontColor     fontColor;     //Sets the font color.
} DrawTextOptions;

typedef struct CircleReport_struct {
    Point center; //The coordinate point of the center of the circle.
    int   radius; //The radius of the circle, in pixels.
    int   area;   //The area of the circle, in pixels.
} CircleReport;

typedef struct ClosedContour_struct {
    Point* points;    //The points that make up the closed contour.
    int    numPoints; //The number of points in the array.
} ClosedContour;

typedef struct ColorHistogramReport_struct {
    HistogramReport plane1; //The histogram report of the first color plane.
    HistogramReport plane2; //The histogram report of the second plane.
    HistogramReport plane3; //The histogram report of the third plane.
} ColorHistogramReport;

typedef struct ColorInformation_struct {
    int     infoCount;  //The size of the info array.
    int     saturation; //The saturation level the function uses to learn the color information.
    double* info;       //An array of color information that represents the color spectrum analysis of a region of an image in a compact form.
} ColorInformation;

typedef struct Complex_struct {
    float r; //The real part of the value.
    float i; //The imaginary part of the value.
} Complex;

typedef struct ConcentricRakeReport_struct {
    ArcInfo*            rakeArcs;          //An array containing the location of each concentric arc line used for edge detection.
    int                 numArcs;           //The number of arc lines in the rakeArcs array.
    PointFloat*         firstEdges;        //The coordinate location of all edges detected as first edges.
    int                 numFirstEdges;     //The number of points in the first edges array.
    PointFloat*         lastEdges;         //The coordinate location of all edges detected as last edges.
    int                 numLastEdges;      //The number of points in the last edges array.
    EdgeLocationReport* allEdges;          //An array of reports describing the location of the edges located by each concentric rake arc line.
    int*                linesWithEdges;    //An array of indices into the rakeArcs array indicating the concentric rake arc lines on which the function detected at least one edge.
    int                 numLinesWithEdges; //The number of concentric rake arc lines along which the function detected edges.
} ConcentricRakeReport;

typedef struct ConstructROIOptions_struct {
    int         windowNumber; //The window number of the image window.
    const char* windowTitle;  //Specifies the message string that the function displays in the title bar of the window.
    PaletteType type;         //The palette type to use.
    RGBValue*   palette;      //If type is IMAQ_PALETTE_USER, this array is the palette of colors to use with the window.
    int         numColors;    //If type is IMAQ_PALETTE_USER, this element is the number of colors in the palette array.
} ConstructROIOptions;

typedef struct ContourInfo_struct {
    ContourType type;         //The contour type.
    unsigned    numPoints;    //The number of points that make up the contour.
    Point*      points;       //The points describing the contour.
    RGBValue    contourColor; //The contour color.
} ContourInfo;

typedef union ContourUnion_union {
    Point*         point;           //Use this member when the contour is of type IMAQ_POINT.
    Line*          line;            //Use this member when the contour is of type IMAQ_LINE.
    Rect*          rect;            //Use this member when the contour is of type IMAQ_RECT.
    Rect*          ovalBoundingBox; //Use this member when the contour is of type IMAQ_OVAL.
    ClosedContour* closedContour;   //Use this member when the contour is of type IMAQ_CLOSED_CONTOUR.
    OpenContour*   openContour;     //Use this member when the contour is of type IMAQ_OPEN_CONTOUR.
    Annulus*       annulus;         //Use this member when the contour is of type IMAQ_ANNULUS.
    RotatedRect*   rotatedRect;     //Use this member when the contour is of type IMAQ_ROTATED_RECT.
} ContourUnion;

typedef struct ContourInfo2_struct {
    ContourType  type;      //The contour type.
    RGBValue     color;     //The contour color.
    ContourUnion structure; //The information necessary to describe the contour in coordinate space.
} ContourInfo2;

typedef struct ContourPoint_struct {
    double x;             //The x-coordinate value in the image.
    double y;             //The y-coordinate value in the image.
    double curvature;     //The change in slope at this edge point of the segment.
    double xDisplacement; //The x displacement of the current edge pixel from a cubic spline fit of the current edge segment.
    double yDisplacement; //The y displacement of the current edge pixel from a cubic spline fit of the current edge segment.
} ContourPoint;

typedef struct CoordinateTransform_struct {
    Point initialOrigin; //The origin of the initial coordinate system.
    float initialAngle;  //The angle, in degrees, of the x-axis of the initial coordinate system relative to the image x-axis.
    Point finalOrigin;   //The origin of the final coordinate system.
    float finalAngle;    //The angle, in degrees, of the x-axis of the final coordinate system relative to the image x-axis.
} CoordinateTransform;

typedef struct CoordinateTransform2_struct {
    CoordinateSystem referenceSystem;   //Defines the coordinate system for input coordinates.
    CoordinateSystem measurementSystem; //Defines the coordinate system in which the function should perform measurements.
} CoordinateTransform2;

typedef struct CannyOptions_struct {
    float sigma;          //The sigma of the Gaussian smoothing filter that the function applies to the image before edge detection.
    float upperThreshold; //The upper fraction of pixel values in the image from which the function chooses a seed or starting point of an edge segment.
    float lowerThreshold; //The function multiplies this value by upperThreshold to determine the lower threshold for all the pixels in an edge segment.
    int   windowSize;     //The window size of the Gaussian filter that the function applies to the image.
} CannyOptions;

typedef struct Range_struct {
    int minValue; //The minimum value of the range.
    int maxValue; //The maximum value of the range.
} Range;

typedef struct UserPointSymbol_struct {
    int  cols;   //Number of columns in the symbol.
    int  rows;   //Number of rows in the symbol.
    int* pixels; //The pixels of the symbol.
} UserPointSymbol;

typedef struct View3DOptions_struct {
    int         sizeReduction; //A divisor the function uses when determining the final height and width of the 3D image.
    int         maxHeight;     //Defines the maximum height of a pixel from the image source drawn in 3D.
    Direction3D direction;     //Defines the 3D orientation.
    float       alpha;         //Determines the angle between the horizontal and the baseline.
    float       beta;          //Determines the angle between the horizontal and the second baseline.
    int         border;        //Defines the border size.
    int         background;    //Defines the background color.
    Plane3D     plane;         //Indicates the view a function uses to show complex images.
} View3DOptions;

typedef struct MatchPatternOptions_struct {
    MatchingMode        mode;                //Specifies the method to use when looking for the pattern in the image.
    int                 minContrast;         //Specifies the minimum contrast expected in the image.
    int                 subpixelAccuracy;    //Set this element to TRUE to return areas in the image that match the pattern area with subpixel accuracy.
    RotationAngleRange* angleRanges;         //An array of angle ranges, in degrees, where each range specifies how much you expect the pattern to be rotated in the image.
    int                 numRanges;           //Number of angle ranges in the angleRanges array.
    int                 numMatchesRequested; //Number of valid matches expected.
    int                 matchFactor;         //Controls the number of potential matches that the function examines.
    float               minMatchScore;       //The minimum score a match can have for the function to consider the match valid.
} MatchPatternOptions;

typedef struct TIFFFileOptions_struct {
    int                 rowsPerStrip;    //Indicates the number of rows that the function writes per strip.
    PhotometricMode     photoInterp;     //Designates which photometric interpretation to use.
    TIFFCompressionType compressionType; //Indicates the type of compression to use on the TIFF file.
} TIFFFileOptions;

typedef union Color_union {
    RGBValue rgb;      //The information needed to describe a color in the RGB (Red, Green, and Blue) color space.
    HSLValue hsl;      //The information needed to describe a color in the HSL (Hue, Saturation, and Luminance) color space.
    HSVValue hsv;      //The information needed to describe a color in the HSI (Hue, Saturation, and Value) color space.
    HSIValue hsi;      //The information needed to describe a color in the HSI (Hue, Saturation, and Intensity) color space.
    int      rawValue; //The integer value for the data in the color union.
} Color;

typedef union PixelValue_union {
    float       grayscale; //A grayscale pixel value.
    RGBValue    rgb;       //A RGB pixel value.
    HSLValue    hsl;       //A HSL pixel value.
    Complex     complex;   //A complex pixel value.
    RGBU64Value rgbu64;    //An unsigned 64-bit RGB pixel value.
} PixelValue;

typedef struct OpenContour_struct {
    Point* points;    //The points that make up the open contour.
    int    numPoints; //The number of points in the array.
} OpenContour;

typedef struct OverlayTextOptions_struct {
    const char*           fontName;                //The name of the font to use.
    int                   fontSize;                //The size of the font.
    int                   bold;                    //Set this element to TRUE to bold the text.
    int                   italic;                  //Set this element to TRUE to italicize the text.
    int                   underline;               //Set this element to TRUE to underline the text.
    int                   strikeout;               //Set this element to TRUE to strikeout the text.
    TextAlignment         horizontalTextAlignment; //Sets the alignment of the text.
    VerticalTextAlignment verticalTextAlignment;   //Sets the vertical alignment for the text.
    RGBValue              backgroundColor;         //Sets the color for the text background pixels.
    double                angle;                   //The counterclockwise angle, in degrees, of the text relative to the x-axis.
} OverlayTextOptions;

typedef struct ParticleFilterCriteria_struct {
    MeasurementValue parameter; //The morphological measurement that the function uses for filtering.
    float            lower;     //The lower bound of the criteria range.
    float            upper;     //The upper bound of the criteria range.
    int              exclude;   //Set this element to TRUE to indicate that a match occurs when the value is outside the criteria range.
} ParticleFilterCriteria;

typedef struct ParticleReport_struct {
    int   area;             //The number of pixels in the particle.
    float calibratedArea;   //The size of the particle, calibrated to the calibration information of the image.
    float perimeter;        //The length of the perimeter, calibrated to the calibration information of the image.
    int   numHoles;         //The number of holes in the particle.
    int   areaOfHoles;      //The total surface area, in pixels, of all the holes in a particle.
    float perimeterOfHoles; //The length of the perimeter of all the holes in the particle calibrated to the calibration information of the image.
    Rect  boundingBox;      //The smallest rectangle that encloses the particle.
    float sigmaX;           //The sum of the particle pixels on the x-axis.
    float sigmaY;           //The sum of the particle pixels on the y-axis.
    float sigmaXX;          //The sum of the particle pixels on the x-axis, squared.
    float sigmaYY;          //The sum of the particle pixels on the y-axis, squared.
    float sigmaXY;          //The sum of the particle pixels on the x-axis and y-axis.
    int   longestLength;    //The length of the longest horizontal line segment.
    Point longestPoint;     //The location of the leftmost pixel of the longest segment in the particle.
    int   projectionX;      //The length of the particle when projected onto the x-axis.
    int   projectionY;      //The length of the particle when projected onto the y-axis.
    int   connect8;         //This element is TRUE if the function used connectivity-8 to determine if particles are touching.
} ParticleReport;

typedef struct PatternMatch_struct {
    PointFloat position;  //The location of the center of the match.
    float      rotation;  //The rotation of the match relative to the template image, in degrees.
    float      scale;     //The size of the match relative to the size of the template image, expressed as a percentage.
    float      score;     //The accuracy of the match.
    PointFloat corner[4]; //An array of four points describing the rectangle surrounding the template image.
} PatternMatch;

typedef struct QuantifyData_struct {
    float mean;           //The mean value of the pixel values.
    float stdDev;         //The standard deviation of the pixel values.
    float min;            //The smallest pixel value.
    float max;            //The largest pixel value.
    float calibratedArea; //The area, calibrated to the calibration information of the image.
    int   pixelArea;      //The area, in number of pixels.
    float relativeSize;   //The proportion, expressed as a percentage, of the associated region relative to the whole image.
} QuantifyData;

typedef struct QuantifyReport_struct {
    QuantifyData  global;      //Statistical data of the whole image.
    QuantifyData* regions;     //An array of QuantifyData structures containing statistical data of each region of the image.
    int           regionCount; //The number of regions.
} QuantifyReport;

typedef struct RakeOptions_struct {
    int                 threshold;         //Specifies the threshold value for the contrast of the edge.
    int                 width;             //The number of pixels that the function averages to find the contrast at either side of the edge.
    int                 steepness;         //The span, in pixels, of the slope of the edge projected along the path specified by the input points.
    int                 subsamplingRatio;  //Specifies the number of pixels that separate two consecutive search lines.
    InterpolationMethod subpixelType;      //The method for interpolating.
    int                 subpixelDivisions; //The number of samples the function obtains from a pixel.
} RakeOptions;

typedef struct RakeReport_struct {
    LineFloat*          rakeLines;         //The coordinate location of each of the rake lines used by the function.
    int                 numRakeLines;      //The number of lines in the rakeLines array.
    PointFloat*         firstEdges;        //The coordinate location of all edges detected as first edges.
    int                 numFirstEdges;     //The number of points in the firstEdges array.
    PointFloat*         lastEdges;         //The coordinate location of all edges detected as last edges.
    int                 numLastEdges;      //The number of points in the lastEdges array.
    EdgeLocationReport* allEdges;          //An array of reports describing the location of the edges located by each rake line.
    int*                linesWithEdges;    //An array of indices into the rakeLines array indicating the rake lines on which the function detected at least one edge.
    int                 numLinesWithEdges; //The number of rake lines along which the function detected edges.
} RakeReport;

typedef struct TransformReport_struct {
    PointFloat* points;      //An array of transformed coordinates.
    int*        validPoints; //An array of values that describe the validity of each of the coordinates according to the region of interest you calibrated using either imaqLearnCalibrationGrid() or imaqLearnCalibrationPoints().
    int         numPoints;   //The length of both the points array and the validPoints array.
} TransformReport;

typedef struct ShapeReport_struct {
    Rect   coordinates; //The bounding rectangle of the object.
    Point  centroid;    //The coordinate location of the centroid of the object.
    int    size;        //The size, in pixels, of the object.
    double score;       //A value ranging between 1 and 1,000 that specifies how similar the object in the image is to the template.
} ShapeReport;

typedef struct MeterArc_struct {
    PointFloat  needleBase;          //The coordinate location of the base of the meter needle.
    PointFloat* arcCoordPoints;      //An array of points describing the coordinate location of the meter arc.
    int         numOfArcCoordPoints; //The number of points in the arcCoordPoints array.
    int         needleColor;         //This element is TRUE when the meter has a light-colored needle on a dark background.
} MeterArc;

typedef struct ThresholdData_struct {
    float rangeMin;    //The lower boundary of the range to keep.
    float rangeMax;    //The upper boundary of the range to keep.
    float newValue;    //If useNewValue is TRUE, newValue is the replacement value for pixels within the range.
    int   useNewValue; //If TRUE, the function sets pixel values within [rangeMin, rangeMax] to the value specified in newValue.
} ThresholdData;

typedef struct StructuringElement_struct {
    int  matrixCols; //Number of columns in the matrix.
    int  matrixRows; //Number of rows in the matrix.
    int  hexa;       //Set this element to TRUE if you specify a hexagonal structuring element in kernel.
    int* kernel;     //The values of the structuring element.
} StructuringElement;

typedef struct SpokeReport_struct {
    LineFloat*          spokeLines;        //The coordinate location of each of the spoke lines used by the function.
    int                 numSpokeLines;     //The number of lines in the spokeLines array.
    PointFloat*         firstEdges;        //The coordinate location of all edges detected as first edges.
    int                 numFirstEdges;     //The number of points in the firstEdges array.
    PointFloat*         lastEdges;         //The coordinate location of all edges detected as last edges.
    int                 numLastEdges;      //The number of points in the lastEdges array.
    EdgeLocationReport* allEdges;          //An array of reports describing the location of the edges located by each spoke line.
    int*                linesWithEdges;    //An array of indices into the spokeLines array indicating the rake lines on which the function detected at least one edge.
    int                 numLinesWithEdges; //The number of spoke lines along which the function detects edges.
} SpokeReport;

typedef struct SimpleEdgeOptions_struct {
    LevelType   type;       //Determines how the function evaluates the threshold and hysteresis values.
    int         threshold;  //The pixel value at which an edge occurs.
    int         hysteresis; //A value that helps determine edges in noisy images.
    EdgeProcess process;    //Determines which edges the function looks for.
    int         subpixel;   //Set this element to TRUE to find edges with subpixel accuracy by interpolating between points to find the crossing of the given threshold.
} SimpleEdgeOptions;

typedef struct SelectParticleCriteria_struct {
    MeasurementValue parameter; //The morphological measurement that the function uses for filtering.
    float            lower;     //The lower boundary of the criteria range.
    float            upper;     //The upper boundary of the criteria range.
} SelectParticleCriteria;

typedef struct SegmentInfo_struct {
    int           numberOfPoints; //The number of points in the segment.
    int           isOpen;         //If TRUE, the contour is open.
    double        weight;         //The significance of the edge in terms of the gray values that constitute the edge.
    ContourPoint* points;         //The points of the segment.
} SegmentInfo;

typedef struct RotationAngleRange_struct {
    float lower; //The lowest amount of rotation, in degrees, a valid pattern can have.
    float upper; //The highest amount of rotation, in degrees, a valid pattern can have.
} RotationAngleRange;

typedef struct RotatedRect_struct {
    int    top;    //Location of the top edge of the rectangle before rotation.
    int    left;   //Location of the left edge of the rectangle before rotation.
    int    height; //Height of the rectangle.
    int    width;  //Width of the rectangle.
    double angle;  //The rotation, in degrees, of the rectangle.
} RotatedRect;

typedef struct ROIProfile_struct {
    LineProfile report; //Quantifying information about the points along the edge of each contour in the ROI.
    Point*      pixels; //An array of the points along the edge of each contour in the ROI.
} ROIProfile;

typedef struct ToolWindowOptions_struct {
    int showSelectionTool;        //If TRUE, the selection tool becomes visible.
    int showZoomTool;             //If TRUE, the zoom tool becomes visible.
    int showPointTool;            //If TRUE, the point tool becomes visible.
    int showLineTool;             //If TRUE, the line tool becomes visible.
    int showRectangleTool;        //If TRUE, the rectangle tool becomes visible.
    int showOvalTool;             //If TRUE, the oval tool becomes visible.
    int showPolygonTool;          //If TRUE, the polygon tool becomes visible.
    int showClosedFreehandTool;   //If TRUE, the closed freehand tool becomes visible.
    int showPolyLineTool;         //If TRUE, the polyline tool becomes visible.
    int showFreehandTool;         //If TRUE, the freehand tool becomes visible.
    int showAnnulusTool;          //If TRUE, the annulus becomes visible.
    int showRotatedRectangleTool; //If TRUE, the rotated rectangle tool becomes visible.
    int showPanTool;              //If TRUE, the pan tool becomes visible.
    int reserved1;                //This element is reserved and should be set to FALSE.
    int reserved2;                //This element is reserved and should be set to FALSE.
    int reserved3;                //This element is reserved and should be set to FALSE.
    int reserved4;                //This element is reserved and should be set to FALSE.
} ToolWindowOptions;

typedef struct SpokeOptions_struct {
    int                 threshold;         //Specifies the threshold value for the contrast of the edge.
    int                 width;             //The number of pixels that the function averages to find the contrast at either side of the edge.
    int                 steepness;         //The span, in pixels, of the slope of the edge projected along the path specified by the input points.
    double              subsamplingRatio;  //The angle, in degrees, between each radial search line in the spoke.
    InterpolationMethod subpixelType;      //The method for interpolating.
    int                 subpixelDivisions; //The number of samples the function obtains from a pixel.
} SpokeOptions;

#pragma pack(pop)

//============================================================================
// Callback Function Type
//============================================================================
typedef void (IMAQ_CALLBACK* EventCallback)(WindowEventType event, int windowNumber, Tool tool, Rect rect);

//============================================================================
//  Globals
//============================================================================
#pragma const_seg("IMAQVisionColorConstants")
static const RGBValue IMAQ_RGB_TRANSPARENT = {   0,   0,   0, 1 };
static const RGBValue IMAQ_RGB_RED         = {   0,   0, 255, 0 };
static const RGBValue IMAQ_RGB_BLUE        = { 255,   0,   0, 0 };
static const RGBValue IMAQ_RGB_GREEN       = {   0, 255,   0, 0 };
static const RGBValue IMAQ_RGB_YELLOW      = {   0, 255, 255, 0 };
static const RGBValue IMAQ_RGB_WHITE       = { 255, 255, 255, 0 };
static const RGBValue IMAQ_RGB_BLACK       = {   0,   0,   0, 0 };
#pragma const_seg()

//============================================================================
//  Backwards Compatibility
//============================================================================
typedef ColorSensitivity 		ColorComplexity;
#define IMAQ_COMPLEXITY_LOW 		IMAQ_SENSITIVITY_LOW
#define IMAQ_COMPLEXITY_MED 		IMAQ_SENSITIVITY_MED     
#define IMAQ_COMPLEXITY_HIGH 		IMAQ_SENSITIVITY_HIGH
#define ERR_INVALID_COLORCOMPLEXITY 	ERR_INVALID_COLORSENSITIVITY


//============================================================================
//  Display functions
//============================================================================
IMAQ_FUNC int   __stdcall imaqAreToolsContextSensitive(int* sensitive);
IMAQ_FUNC int   __stdcall imaqCloseWindow(int windowNumber);
IMAQ_FUNC int   __stdcall imaqDisplayImage(const Image* image, int windowNumber, int resize);
IMAQ_FUNC int   __stdcall imaqGetLastKey(char* keyPressed, int* windowNumber, int* modifiers);
IMAQ_FUNC void* __stdcall imaqGetSystemWindowHandle(int windowNumber);
IMAQ_FUNC int   __stdcall imaqGetWindowCenterPos(int windowNumber, Point* centerPosition);
IMAQ_FUNC int   __stdcall imaqSetToolContextSensitivity(int sensitive);
IMAQ_FUNC int   __stdcall imaqShowWindow(int windowNumber, int visible);

//============================================================================
//  Acquisition functions
//============================================================================
IMAQ_FUNC Image* __stdcall imaqCopyFromRing(SESSION_ID sessionID, Image* image, int imageToCopy, int* imageNumber, Rect rect);
IMAQ_FUNC Image* __stdcall imaqEasyAcquire(const char* interfaceName);
IMAQ_FUNC Image* __stdcall imaqExtractFromRing(SESSION_ID sessionID, int imageToExtract, int* imageNumber);
IMAQ_FUNC Image* __stdcall imaqGrab(SESSION_ID sessionID, Image* image, int immediate);
IMAQ_FUNC int    __stdcall imaqReleaseImage(SESSION_ID sessionID);
IMAQ_FUNC int    __stdcall imaqSetupGrab(SESSION_ID sessionID, Rect rect);
IMAQ_FUNC int    __stdcall imaqSetupRing(SESSION_ID sessionID, Image** images, int numImages, int skipCount, Rect rect);
IMAQ_FUNC int    __stdcall imaqSetupSequence(SESSION_ID sessionID, Image** images, int numImages, int skipCount, Rect rect);
IMAQ_FUNC Image* __stdcall imaqSnap(SESSION_ID sessionID, Image* image, Rect rect);
IMAQ_FUNC int    __stdcall imaqStartAcquisition(SESSION_ID sessionID);
IMAQ_FUNC int    __stdcall imaqStopAcquisition(SESSION_ID sessionID);

//============================================================================
//  Arithmetic functions
//============================================================================
IMAQ_FUNC int __stdcall imaqAbsoluteDifference(Image* dest, const Image* sourceA, const Image* sourceB);
IMAQ_FUNC int __stdcall imaqAbsoluteDifferenceConstant(Image* dest, const Image* source, PixelValue value);
IMAQ_FUNC int __stdcall imaqAdd(Image* dest, const Image* sourceA, const Image* sourceB);
IMAQ_FUNC int __stdcall imaqAddConstant(Image* dest, const Image* source, PixelValue value);
IMAQ_FUNC int __stdcall imaqAverage(Image* dest, const Image* sourceA, const Image* sourceB);
IMAQ_FUNC int __stdcall imaqAverageConstant(Image* dest, const Image* source, PixelValue value);
IMAQ_FUNC int __stdcall imaqDivide(Image* dest, const Image* sourceA, const Image* sourceB);
IMAQ_FUNC int __stdcall imaqDivideConstant(Image* dest, const Image* source, PixelValue value);
IMAQ_FUNC int __stdcall imaqMax(Image* dest, const Image* sourceA, const Image* sourceB);
IMAQ_FUNC int __stdcall imaqMaxConstant(Image* dest, const Image* source, PixelValue value);
IMAQ_FUNC int __stdcall imaqMin(Image* dest, const Image* sourceA, const Image* sourceB);
IMAQ_FUNC int __stdcall imaqMinConstant(Image* dest, const Image* source, PixelValue value);
IMAQ_FUNC int __stdcall imaqModulo(Image* dest, const Image* sourceA, const Image* sourceB);
IMAQ_FUNC int __stdcall imaqModuloConstant(Image* dest, const Image* source, PixelValue value);
IMAQ_FUNC int __stdcall imaqMulDiv(Image* dest, const Image* sourceA, const Image* sourceB, float value);
IMAQ_FUNC int __stdcall imaqMultiply(Image* dest, const Image* sourceA, const Image* sourceB);
IMAQ_FUNC int __stdcall imaqMultiplyConstant(Image* dest, const Image* source, PixelValue value);
IMAQ_FUNC int __stdcall imaqSubtract(Image* dest, const Image* sourceA, const Image* sourceB);
IMAQ_FUNC int __stdcall imaqSubtractConstant(Image* dest, const Image* source, PixelValue value);

//============================================================================
//  Caliper functions
//============================================================================
IMAQ_FUNC CaliperReport*        __stdcall imaqCaliperTool(const Image* image, const Point* points, int numPoints, const EdgeOptions* edgeOptions, const CaliperOptions* caliperOptions, int* numEdgePairs);
IMAQ_FUNC ConcentricRakeReport* __stdcall imaqConcentricRake(const Image* image, const ROI* roi, ConcentricRakeDirection direction, EdgeProcess process, const RakeOptions* options);
IMAQ_FUNC ExtremeReport*        __stdcall imaqDetectExtremes(const double* pixels, int numPixels, DetectionMode mode, const DetectExtremesOptions* options, int* numExtremes);
IMAQ_FUNC int                   __stdcall imaqDetectRotation(const Image* referenceImage, const Image* testImage, PointFloat referenceCenter, PointFloat testCenter, int radius, float precision, double* angle);
IMAQ_FUNC EdgeReport*           __stdcall imaqEdgeTool2(const Image* image, const Point* points, int numPoints, EdgeProcess process, const EdgeOptions* options, int* numEdges);
IMAQ_FUNC int                   __stdcall imaqLineGaugeTool2(const Image* image, Point start, Point end, LineGaugeMethod method, const EdgeOptions* edgeOptions, const CoordinateTransform2* transform, float* distance);
IMAQ_FUNC RakeReport*           __stdcall imaqRake(const Image* image, const ROI* roi, RakeDirection direction, EdgeProcess process, const RakeOptions* options);
IMAQ_FUNC PointFloat*           __stdcall imaqSimpleEdge(const Image* image, const Point* points, int numPoints, const SimpleEdgeOptions* options, int* numEdges);
IMAQ_FUNC SpokeReport*          __stdcall imaqSpoke(const Image* image, const ROI* roi, SpokeDirection direction, EdgeProcess process, const SpokeOptions* options);

//============================================================================
//  Spatial Filters functions
//============================================================================
IMAQ_FUNC int __stdcall imaqCannyEdgeFilter(Image* dest, const Image* source, const CannyOptions* options);
IMAQ_FUNC int __stdcall imaqConvolve(Image* dest, Image* source, const float* kernel, int matrixRows, int matrixCols, float normalize, const Image* mask);
IMAQ_FUNC int __stdcall imaqCorrelate(Image* dest, Image* source, const Image* templateImage, Rect rect);
IMAQ_FUNC int __stdcall imaqEdgeFilter(Image* dest, Image* source, OutlineMethod method, const Image* mask);
IMAQ_FUNC int __stdcall imaqLowPass(Image* dest, Image* source, int width, int height, float tolerance, const Image* mask);
IMAQ_FUNC int __stdcall imaqMedianFilter(Image* dest, Image* source, int width, int height, const Image* mask);
IMAQ_FUNC int __stdcall imaqNthOrderFilter(Image* dest, Image* source, int width, int height, int n, const Image* mask);

//============================================================================
//  Drawing functions
//============================================================================
IMAQ_FUNC int __stdcall imaqDrawLineOnImage(Image* dest, const Image* source, DrawMode mode, Point start, Point end, float newPixelValue);
IMAQ_FUNC int __stdcall imaqDrawShapeOnImage(Image* dest, const Image* source, Rect rect, DrawMode mode, ShapeMode shape, float newPixelValue);
IMAQ_FUNC int __stdcall imaqDrawTextOnImage(Image* dest, const Image* source, Point coord, const char* text, const DrawTextOptions* options, int* fontNameUsed);

//============================================================================
//  Interlacing functions
//============================================================================
IMAQ_FUNC int __stdcall imaqInterlaceCombine(Image* frame, const Image* odd, const Image* even);
IMAQ_FUNC int __stdcall imaqInterlaceSeparate(const Image* frame, Image* odd, Image* even);

//============================================================================
//  Image Information functions
//============================================================================
IMAQ_FUNC char** __stdcall imaqEnumerateCustomKeys(const Image* image, unsigned int* size);
IMAQ_FUNC int    __stdcall imaqGetBitDepth(const Image* image, unsigned int* bitDepth);
IMAQ_FUNC int    __stdcall imaqGetBytesPerPixel(const Image* image, int* byteCount);
IMAQ_FUNC int    __stdcall imaqGetImageInfo(const Image* image, ImageInfo* info);
IMAQ_FUNC int    __stdcall imaqGetImageSize(const Image* image, int* width, int* height);
IMAQ_FUNC int    __stdcall imaqGetImageType(const Image* image, ImageType* type);
IMAQ_FUNC int    __stdcall imaqGetMaskOffset(const Image* image, Point* offset);
IMAQ_FUNC void*  __stdcall imaqGetPixelAddress(const Image* image, Point pixel);
IMAQ_FUNC int    __stdcall imaqGetVisionInfoTypes(const Image* image, unsigned int* present);
IMAQ_FUNC int    __stdcall imaqIsImageEmpty(const Image* image, int* empty);
IMAQ_FUNC void*  __stdcall imaqReadCustomData(const Image* image, const char* key, unsigned int* size);
IMAQ_FUNC int    __stdcall imaqRemoveCustomData(Image* image, const char* key);
IMAQ_FUNC int    __stdcall imaqRemoveVisionInfo2(const Image* image, unsigned int info);
IMAQ_FUNC int    __stdcall imaqSetBitDepth(Image* image, unsigned int bitDepth);
IMAQ_FUNC int    __stdcall imaqSetImageSize(Image* image, int width, int height);
IMAQ_FUNC int    __stdcall imaqSetMaskOffset(Image* image, Point offset);
IMAQ_FUNC int    __stdcall imaqWriteCustomData(Image* image, const char* key, const void* data, unsigned int size);

//============================================================================
//  Tool Window functions
//============================================================================
IMAQ_FUNC int   __stdcall imaqCloseToolWindow(void);
IMAQ_FUNC int   __stdcall imaqGetCurrentTool(Tool* currentTool);
IMAQ_FUNC int   __stdcall imaqGetLastEvent(WindowEventType* type, int* windowNumber, Tool* tool, Rect* rect);
IMAQ_FUNC void* __stdcall imaqGetToolWindowHandle(void);
IMAQ_FUNC int   __stdcall imaqGetToolWindowPos(Point* position);
IMAQ_FUNC int   __stdcall imaqIsToolWindowVisible(int* visible);
IMAQ_FUNC int   __stdcall imaqMoveToolWindow(Point position);
IMAQ_FUNC int   __stdcall imaqSetCurrentTool(Tool currentTool);
IMAQ_FUNC int   __stdcall imaqSetEventCallback(EventCallback callback, int synchronous);
IMAQ_FUNC int   __stdcall imaqSetToolColor(const RGBValue* color);
IMAQ_FUNC int   __stdcall imaqSetupToolWindow(int showCoordinates, int maxIconsPerLine, const ToolWindowOptions* options);
IMAQ_FUNC int   __stdcall imaqShowToolWindow(int visible);

//============================================================================
//  Morphology functions
//============================================================================
IMAQ_FUNC int           __stdcall imaqConvexHull(Image* dest, Image* source, int connectivity8);
IMAQ_FUNC int           __stdcall imaqDanielssonDistance(Image* dest, Image* source);
IMAQ_FUNC int           __stdcall imaqFillHoles(Image* dest, const Image* source, int connectivity8);
IMAQ_FUNC CircleReport* __stdcall imaqFindCircles(Image* dest, Image* source, float minRadius, float maxRadius, int* numCircles);
IMAQ_FUNC int           __stdcall imaqLabel2(Image* dest, Image* source, int connectivity8, int* particleCount);
IMAQ_FUNC int           __stdcall imaqMorphology(Image* dest, Image* source, MorphologyMethod method, const StructuringElement* structuringElement);
IMAQ_FUNC int           __stdcall imaqRejectBorder(Image* dest, Image* source, int connectivity8);
IMAQ_FUNC int           __stdcall imaqSegmentation(Image* dest, Image* source);
IMAQ_FUNC int           __stdcall imaqSeparation(Image* dest, Image* source, int erosions, const StructuringElement* structuringElement);
IMAQ_FUNC int           __stdcall imaqSimpleDistance(Image* dest, Image* source, const StructuringElement* structuringElement);
IMAQ_FUNC int           __stdcall imaqSizeFilter(Image* dest, Image* source, int connectivity8, int erosions, SizeType keepSize, const StructuringElement* structuringElement);
IMAQ_FUNC int           __stdcall imaqSkeleton(Image* dest, Image* source, SkeletonMethod method);

//============================================================================
//  Logical functions
//============================================================================
IMAQ_FUNC int __stdcall imaqAnd(Image* dest, const Image* sourceA, const Image* sourceB);
IMAQ_FUNC int __stdcall imaqAndConstant(Image* dest, const Image* source, PixelValue value);
IMAQ_FUNC int __stdcall imaqCompare(Image* dest, const Image* source, const Image* compareImage, ComparisonFunction compare);
IMAQ_FUNC int __stdcall imaqCompareConstant(Image* dest, const Image* source, PixelValue value, ComparisonFunction compare);
IMAQ_FUNC int __stdcall imaqLogicalDifference(Image* dest, const Image* sourceA, const Image* sourceB);
IMAQ_FUNC int __stdcall imaqLogicalDifferenceConstant(Image* dest, const Image* source, PixelValue value);
IMAQ_FUNC int __stdcall imaqNand(Image* dest, const Image* sourceA, const Image* sourceB);
IMAQ_FUNC int __stdcall imaqNandConstant(Image* dest, const Image* source, PixelValue value);
IMAQ_FUNC int __stdcall imaqNor(Image* dest, const Image* sourceA, const Image* sourceB);
IMAQ_FUNC int __stdcall imaqNorConstant(Image* dest, const Image* source, PixelValue value);
IMAQ_FUNC int __stdcall imaqOr(Image* dest, const Image* sourceA, const Image* sourceB);
IMAQ_FUNC int __stdcall imaqOrConstant(Image* dest, const Image* source, PixelValue value);
IMAQ_FUNC int __stdcall imaqXnor(Image* dest, const Image* sourceA, const Image* sourceB);
IMAQ_FUNC int __stdcall imaqXnorConstant(Image* dest, const Image* source, PixelValue value);
IMAQ_FUNC int __stdcall imaqXor(Image* dest, const Image* sourceA, const Image* sourceB);
IMAQ_FUNC int __stdcall imaqXorConstant(Image* dest, const Image* source, PixelValue value);

//============================================================================
//  Particle Analysis functions
//============================================================================
IMAQ_FUNC int __stdcall imaqCountParticles(Image* image, int connectivity8, int* numParticles);
IMAQ_FUNC int __stdcall imaqMeasureParticle(Image* image, int particleNumber, int calibrated, MeasurementType measurement, double* value);
IMAQ_FUNC int __stdcall imaqParticleFilter2(Image* dest, Image* source, const ParticleFilterCriteria2* criteria, int criteriaCount, int rejectMatches, int connectivity8, int* numParticles);

//============================================================================
//  Analytic Geometry functions
//============================================================================
IMAQ_FUNC int           __stdcall imaqBuildCoordinateSystem(const Point* points, ReferenceMode mode, AxisOrientation orientation, CoordinateSystem* system);
IMAQ_FUNC BestCircle2*  __stdcall imaqFitCircle2(const PointFloat* points, int numPoints, const FitCircleOptions* options);
IMAQ_FUNC BestEllipse2* __stdcall imaqFitEllipse2(const PointFloat* points, int numPoints, const FitEllipseOptions* options);
IMAQ_FUNC BestLine*     __stdcall imaqFitLine(const PointFloat* points, int numPoints, const FitLineOptions* options);
IMAQ_FUNC int           __stdcall imaqGetAngle(PointFloat start1, PointFloat end1, PointFloat start2, PointFloat end2, float* angle);
IMAQ_FUNC int           __stdcall imaqGetBisectingLine(PointFloat start1, PointFloat end1, PointFloat start2, PointFloat end2, PointFloat* bisectStart, PointFloat* bisectEnd);
IMAQ_FUNC int           __stdcall imaqGetDistance(PointFloat point1, PointFloat point2, float* distance);
IMAQ_FUNC int           __stdcall imaqGetIntersection(PointFloat start1, PointFloat end1, PointFloat start2, PointFloat end2, PointFloat* intersection);
IMAQ_FUNC int           __stdcall imaqGetMidLine(PointFloat refLineStart, PointFloat refLineEnd, PointFloat point, PointFloat* midLineStart, PointFloat* midLineEnd);
IMAQ_FUNC int           __stdcall imaqGetPerpendicularLine(PointFloat refLineStart, PointFloat refLineEnd, PointFloat point, PointFloat* perpLineStart, PointFloat* perpLineEnd, double* distance);
IMAQ_FUNC SegmentInfo*  __stdcall imaqGetPointsOnContour(const Image* image, int* numSegments);
IMAQ_FUNC Point*        __stdcall imaqGetPointsOnLine(Point start, Point end, int* numPoints);
IMAQ_FUNC int           __stdcall imaqGetPolygonArea(const PointFloat* points, int numPoints, float* area);
IMAQ_FUNC float*        __stdcall imaqInterpolatePoints(const Image* image, const Point* points, int numPoints, InterpolationMethod method, int subpixel, int* interpCount);

//============================================================================
//  Clipboard functions
//============================================================================
IMAQ_FUNC int __stdcall imaqClipboardToImage(Image* dest, RGBValue* palette);
IMAQ_FUNC int __stdcall imaqImageToClipboard(const Image* image, const RGBValue* palette);

//============================================================================
//  Border functions
//============================================================================
IMAQ_FUNC int __stdcall imaqFillBorder(Image* image, BorderMethod method);
IMAQ_FUNC int __stdcall imaqGetBorderSize(const Image* image, int* borderSize);
IMAQ_FUNC int __stdcall imaqSetBorderSize(Image* image, int size);

//============================================================================
//  Image Management functions
//============================================================================
IMAQ_FUNC int    __stdcall imaqArrayToImage(Image* image, const void* array, int numCols, int numRows);
IMAQ_FUNC Image* __stdcall imaqCreateImage(ImageType type, int borderSize);
IMAQ_FUNC void*  __stdcall imaqImageToArray(const Image* image, Rect rect, int* columns, int* rows);

//============================================================================
//  Color Processing functions
//============================================================================
IMAQ_FUNC Color2                __stdcall imaqChangeColorSpace2(const Color2* sourceColor, ColorMode sourceSpace, ColorMode destSpace, double offset, const CIEXYZValue* whiteReference);
IMAQ_FUNC int                   __stdcall imaqColorBCGTransform(Image* dest, const Image* source, const BCGOptions* redOptions, const BCGOptions* greenOptions, const BCGOptions* blueOptions, const Image* mask);
IMAQ_FUNC int                   __stdcall imaqColorEqualize(Image* dest, const Image* source, int colorEqualization);
IMAQ_FUNC ColorHistogramReport* __stdcall imaqColorHistogram2(Image* image, int numClasses, ColorMode mode, const CIEXYZValue* whiteReference, Image* mask);
IMAQ_FUNC int                   __stdcall imaqColorLookup(Image* dest, const Image* source, ColorMode mode, const Image* mask, const short* plane1, const short* plane2, const short* plane3);
IMAQ_FUNC int                   __stdcall imaqColorThreshold(Image* dest, const Image* source, int replaceValue, ColorMode mode, const Range* plane1Range, const Range* plane2Range, const Range* plane3Range);

//============================================================================
//  Transform functions
//============================================================================
IMAQ_FUNC int __stdcall imaqBCGTransform(Image* dest, const Image* source, const BCGOptions* options, const Image* mask);
IMAQ_FUNC int __stdcall imaqEqualize(Image* dest, const Image* source, float min, float max, const Image* mask);
IMAQ_FUNC int __stdcall imaqInverse(Image* dest, const Image* source, const Image* mask);
IMAQ_FUNC int __stdcall imaqLookup(Image* dest, const Image* source, const short* table, const Image* mask);
IMAQ_FUNC int __stdcall imaqMathTransform(Image* dest, const Image* source, MathTransformMethod method, float rangeMin, float rangeMax, float power, const Image* mask);
IMAQ_FUNC int __stdcall imaqWatershedTransform(Image* dest, const Image* source, int connectivity8, int* zoneCount);


//============================================================================
//  Window Management functions
//============================================================================
IMAQ_FUNC int   __stdcall imaqAreScrollbarsVisible(int windowNumber, int* visible);
IMAQ_FUNC int   __stdcall imaqBringWindowToTop(int windowNumber);
IMAQ_FUNC int   __stdcall imaqGetMousePos(Point* position, int* windowNumber);
IMAQ_FUNC int   __stdcall imaqGetWindowBackground(int windowNumber, WindowBackgroundFillStyle* fillStyle, WindowBackgroundHatchStyle* hatchStyle, RGBValue* fillColor, RGBValue* backgroundColor);
IMAQ_FUNC int   __stdcall imaqGetWindowDisplayMapping(int windowNum, DisplayMapping* mapping);
IMAQ_FUNC int   __stdcall imaqGetWindowGrid(int windowNumber, int* xResolution, int* yResolution);
IMAQ_FUNC int   __stdcall imaqGetWindowHandle(int* handle);
IMAQ_FUNC int   __stdcall imaqGetWindowPos(int windowNumber, Point* position);
IMAQ_FUNC int   __stdcall imaqGetWindowSize(int windowNumber, int* width, int* height);
IMAQ_FUNC char* __stdcall imaqGetWindowTitle(int windowNumber);
IMAQ_FUNC int   __stdcall imaqGetWindowZoom(int windowNumber, int* xZoom, int* yZoom);
IMAQ_FUNC int   __stdcall imaqIsWindowNonTearing(int windowNumber, int* nonTearing);
IMAQ_FUNC int   __stdcall imaqIsWindowVisible(int windowNumber, int* visible);
IMAQ_FUNC int   __stdcall imaqMoveWindow(int windowNumber, Point position);
IMAQ_FUNC int   __stdcall imaqSetupWindow(int windowNumber, int configuration);
IMAQ_FUNC int   __stdcall imaqSetWindowBackground(int windowNumber, WindowBackgroundFillStyle fillStyle, WindowBackgroundHatchStyle hatchStyle, const RGBValue* fillColor, const RGBValue* backgroundColor);
IMAQ_FUNC int   __stdcall imaqSetWindowDisplayMapping(int windowNumber, const DisplayMapping* mapping);
IMAQ_FUNC int   __stdcall imaqSetWindowGrid(int windowNumber, int xResolution, int yResolution);
IMAQ_FUNC int   __stdcall imaqSetWindowNonTearing(int windowNumber, int nonTearing);
IMAQ_FUNC int   __stdcall imaqSetWindowMaxContourCount(int windowNumber, unsigned int maxContourCount);
IMAQ_FUNC int   __stdcall imaqSetWindowPalette(int windowNumber, PaletteType type, const RGBValue* palette, int numColors);
IMAQ_FUNC int   __stdcall imaqSetWindowSize(int windowNumber, int width, int height);
IMAQ_FUNC int   __stdcall imaqSetWindowThreadPolicy(WindowThreadPolicy policy);
IMAQ_FUNC int   __stdcall imaqSetWindowTitle(int windowNumber, const char* title);
IMAQ_FUNC int   __stdcall imaqShowScrollbars(int windowNumber, int visible);
IMAQ_FUNC int   __stdcall imaqZoomWindow(int windowNumber, int xZoom, int yZoom, Point center);

//============================================================================
//  Utilities functions
//============================================================================
IMAQ_FUNC const float* __stdcall imaqGetKernel(KernelFamily family, int size, int number);
IMAQ_FUNC Annulus      __stdcall imaqMakeAnnulus(Point center, int innerRadius, int outerRadius, double startAngle, double endAngle);
IMAQ_FUNC Point        __stdcall imaqMakePoint(int xCoordinate, int yCoordinate);
IMAQ_FUNC PointFloat   __stdcall imaqMakePointFloat(float xCoordinate, float yCoordinate);
IMAQ_FUNC Rect         __stdcall imaqMakeRect(int top, int left, int height, int width);
IMAQ_FUNC Rect         __stdcall imaqMakeRectFromRotatedRect(RotatedRect rotatedRect);
IMAQ_FUNC RotatedRect  __stdcall imaqMakeRotatedRect(int top, int left, int height, int width, double angle);
IMAQ_FUNC RotatedRect  __stdcall imaqMakeRotatedRectFromRect(Rect rect);

//============================================================================
//  Image Manipulation functions
//============================================================================
IMAQ_FUNC int   __stdcall imaqCast(Image* dest, const Image* source, ImageType type, const float* lookup, int shift);
IMAQ_FUNC int   __stdcall imaqCopyRect(Image* dest, const Image* source, Rect rect, Point destLoc);
IMAQ_FUNC int   __stdcall imaqDuplicate(Image* dest, const Image* source);
IMAQ_FUNC void* __stdcall imaqFlatten(const Image* image, FlattenType type, CompressionType compression, int quality, unsigned int* size);
IMAQ_FUNC int   __stdcall imaqFlip(Image* dest, const Image* source, FlipAxis axis);
IMAQ_FUNC int   __stdcall imaqMask(Image* dest, const Image* source, const Image* mask);
IMAQ_FUNC int   __stdcall imaqResample(Image* dest, const Image* source, int newWidth, int newHeight, InterpolationMethod method, Rect rect);
IMAQ_FUNC int   __stdcall imaqRotate2(Image* dest, const Image* source, float angle, PixelValue fill, InterpolationMethod method, int maintainSize);
IMAQ_FUNC int   __stdcall imaqScale(Image* dest, const Image* source, int xScale, int yScale, ScalingMode scaleMode, Rect rect);
IMAQ_FUNC int   __stdcall imaqShift(Image* dest, const Image* source, int shiftX, int shiftY, PixelValue fill);
IMAQ_FUNC int   __stdcall imaqTranspose(Image* dest, const Image* source);
IMAQ_FUNC int   __stdcall imaqUnflatten(Image* image, const void* data, unsigned int size);
IMAQ_FUNC int   __stdcall imaqUnwrapImage(Image* dest, const Image* source, Annulus annulus, RectOrientation orientation, InterpolationMethod method);
IMAQ_FUNC int   __stdcall imaqView3D(Image* dest, Image* source, const View3DOptions* options);

//============================================================================
//  Pattern Matching functions
//============================================================================
IMAQ_FUNC CircleMatch*              __stdcall imaqDetectCircles(const Image* image, const CircleDescriptor* circleDescriptor, const CurveOptions* curveOptions, const ShapeDetectionOptions* shapeDetectionOptions, const ROI* roi, int* numMatchesReturned);
IMAQ_FUNC EllipseMatch*             __stdcall imaqDetectEllipses(const Image* image, const EllipseDescriptor* ellipseDescriptor, const CurveOptions* curveOptions, const ShapeDetectionOptions* shapeDetectionOptions, const ROI* roi, int* numMatchesReturned);
IMAQ_FUNC LineMatch*                __stdcall imaqDetectLines(const Image* image, const LineDescriptor* lineDescriptor, const CurveOptions* curveOptions, const ShapeDetectionOptions* shapeDetectionOptions, const ROI* roi, int* numMatchesReturned);
IMAQ_FUNC RectangleMatch*           __stdcall imaqDetectRectangles(const Image* image, const RectangleDescriptor* rectangleDescriptor, const CurveOptions* curveOptions, const ShapeDetectionOptions* shapeDetectionOptions, const ROI* roi, int* numMatchesReturned);
IMAQ_FUNC FeatureData*              __stdcall imaqGetGeometricFeaturesFromCurves(const Curve* curves, unsigned int numCurves, const FeatureType* featureTypes, unsigned int numFeatureTypes, unsigned int* numFeatures);
IMAQ_FUNC FeatureData*              __stdcall imaqGetGeometricTemplateFeatureInfo(const Image* pattern, unsigned int* numFeatures);
IMAQ_FUNC int                       __stdcall imaqLearnColorPattern(Image* image, const LearnColorPatternOptions* options);
IMAQ_FUNC int                       __stdcall imaqLearnGeometricPattern(Image* image, PointFloat originOffset, const CurveOptions* curveOptions, const LearnGeometricPatternAdvancedOptions* advancedLearnOptions, const Image* mask);
IMAQ_FUNC MultipleGeometricPattern* __stdcall imaqLearnMultipleGeometricPatterns(const Image** patterns, unsigned int numberOfPatterns, const String255* labels);
IMAQ_FUNC int                       __stdcall imaqLearnPattern2(Image* image, LearningMode learningMode, LearnPatternAdvancedOptions* advancedOptions);
IMAQ_FUNC PatternMatch*             __stdcall imaqMatchColorPattern(const Image* image, Image* pattern, const MatchColorPatternOptions* options, Rect searchRect, int* numMatches);
IMAQ_FUNC GeometricPatternMatch2*   __stdcall imaqMatchGeometricPattern2(const Image* image, const Image* pattern, const CurveOptions* curveOptions, const MatchGeometricPatternOptions* matchOptions, const MatchGeometricPatternAdvancedOptions2* advancedMatchOptions, const ROI* roi, int* numMatches);
IMAQ_FUNC GeometricPatternMatch2*   __stdcall imaqMatchMultipleGeometricPatterns(const Image* image, const MultipleGeometricPattern* multiplePattern, const ROI* roi, int* numMatches);
IMAQ_FUNC PatternMatch*             __stdcall imaqMatchPattern2(const Image* image, const Image* pattern, const MatchPatternOptions* options, const MatchPatternAdvancedOptions* advancedOptions, Rect searchRect, int* numMatches);
IMAQ_FUNC MultipleGeometricPattern* __stdcall imaqReadMultipleGeometricPatternFile(const char* fileName, String255 description);
IMAQ_FUNC PatternMatch*             __stdcall imaqRefineMatches(const Image* image, const Image* pattern, const PatternMatch* candidatesIn, int numCandidatesIn, MatchPatternOptions* options, MatchPatternAdvancedOptions* advancedOptions, int* numCandidatesOut);
IMAQ_FUNC int                       __stdcall imaqSetMultipleGeometricPatternsOptions(MultipleGeometricPattern* multiplePattern, const char* label, const CurveOptions* curveOptions, const MatchGeometricPatternOptions* matchOptions, const MatchGeometricPatternAdvancedOptions2* advancedMatchOptions);
IMAQ_FUNC int                       __stdcall imaqWriteMultipleGeometricPatternFile(const MultipleGeometricPattern* multiplePattern, const char* fileName, const char* description);

//============================================================================
//  Calibration functions
//============================================================================
IMAQ_FUNC int              __stdcall imaqCopyCalibrationInfo(Image* dest, const Image* source);
IMAQ_FUNC int              __stdcall imaqCorrectCalibratedImage(Image* dest, const Image* source, PixelValue fill, InterpolationMethod method, const ROI* roi);
IMAQ_FUNC CalibrationInfo* __stdcall imaqGetCalibrationInfo2(const Image* image);
IMAQ_FUNC int              __stdcall imaqLearnCalibrationGrid(Image* image, const ROI* roi, const LearnCalibrationOptions* options, const GridDescriptor* grid, const CoordinateSystem* system, const RangeFloat* range, float* quality);
IMAQ_FUNC int              __stdcall imaqLearnCalibrationPoints(Image* image, const CalibrationPoints* points, const ROI* roi, const LearnCalibrationOptions* options, const GridDescriptor* grid, const CoordinateSystem* system, float* quality);
IMAQ_FUNC int              __stdcall imaqSetCoordinateSystem(Image* image, const CoordinateSystem* system);
IMAQ_FUNC int              __stdcall imaqSetSimpleCalibration(Image* image, ScalingMethod method, int learnTable, const GridDescriptor* grid, const CoordinateSystem* system);
IMAQ_FUNC TransformReport* __stdcall imaqTransformPixelToRealWorld(const Image* image, const PointFloat* pixelCoordinates, int numCoordinates);
IMAQ_FUNC TransformReport* __stdcall imaqTransformRealWorldToPixel(const Image* image, const PointFloat* realWorldCoordinates, int numCoordinates);

//============================================================================
//  Overlay functions
//============================================================================
IMAQ_FUNC int __stdcall imaqClearOverlay(Image* image, void* reserved);
IMAQ_FUNC int __stdcall imaqCopyOverlay(Image* dest, const Image* source, void* reserved);
IMAQ_FUNC int __stdcall imaqMergeOverlay(Image* dest, const Image* source, const RGBValue* palette, unsigned int numColors, void* reserved);
IMAQ_FUNC int __stdcall imaqOverlayArc(Image* image, const ArcInfo* arc, const RGBValue* color, DrawMode drawMode, void* reserved);
IMAQ_FUNC int __stdcall imaqOverlayBitmap(Image* image, Point destLoc, const RGBValue* bitmap, unsigned int numCols, unsigned int numRows, void* reserved);
IMAQ_FUNC int __stdcall imaqOverlayClosedContour(Image* image, const Point* points, int numPoints, const RGBValue* color, DrawMode drawMode, void* reserved);
IMAQ_FUNC int __stdcall imaqOverlayLine(Image* image, Point start, Point end, const RGBValue* color, void* reserved);
IMAQ_FUNC int __stdcall imaqOverlayMetafile(Image* image, const void* metafile, Rect rect, void* reserved);
IMAQ_FUNC int __stdcall imaqOverlayOpenContour(Image* image, const Point* points, int numPoints, const RGBValue* color, void* reserved);
IMAQ_FUNC int __stdcall imaqOverlayOval(Image* image, Rect boundingBox, const RGBValue* color, DrawMode drawMode, void* reserved);
IMAQ_FUNC int __stdcall imaqOverlayPoints(Image* image, const Point* points, int numPoints, const RGBValue* colors, int numColors, PointSymbol symbol, const UserPointSymbol* userSymbol, void* reserved);
IMAQ_FUNC int __stdcall imaqOverlayRect(Image* image, Rect rect, const RGBValue* color, DrawMode drawMode, void* reserved);
IMAQ_FUNC int __stdcall imaqOverlayROI(Image* image, const ROI* roi, PointSymbol symbol, const UserPointSymbol* userSymbol, void* reserved);
IMAQ_FUNC int __stdcall imaqOverlayText(Image* image, Point origin, const char* text, const RGBValue* color, const OverlayTextOptions* options, void* reserved);

//============================================================================
//  Color Matching functions
//============================================================================
IMAQ_FUNC ColorInformation* __stdcall imaqLearnColor(const Image* image, const ROI* roi, ColorSensitivity sensitivity, int saturation);
IMAQ_FUNC int*              __stdcall imaqMatchColor(const Image* image, const ColorInformation* info, const ROI* roi, int* numScores);

//============================================================================
//  Meter functions
//============================================================================
IMAQ_FUNC MeterArc* __stdcall imaqGetMeterArc(int lightNeedle, MeterArcMode mode, const ROI* roi, PointFloat base, PointFloat start, PointFloat end);
IMAQ_FUNC int       __stdcall imaqReadMeter(const Image* image, const MeterArc* arcInfo, double* percentage, PointFloat* endOfNeedle);

//============================================================================
//  Barcode I/O functions
//============================================================================
IMAQ_FUNC int               __stdcall imaqGradeDataMatrixBarcodeAIM(const Image* image, AIMGradeReport* report);
IMAQ_FUNC BarcodeInfo*      __stdcall imaqReadBarcode(const Image* image, BarcodeType type, const ROI* roi, int validate);
IMAQ_FUNC Barcode2DInfo*    __stdcall imaqReadPDF417Barcode(const Image* image, const ROI* roi, Barcode2DSearchMode searchMode, unsigned int* numBarcodes);
IMAQ_FUNC DataMatrixReport* __stdcall imaqReadDataMatrixBarcode2(Image* image, const ROI* roi, DataMatrixGradingMode prepareForGrading, const DataMatrixDescriptionOptions* descriptionOptions, const DataMatrixSizeOptions* sizeOptions, const DataMatrixSearchOptions* searchOptions);


//============================================================================
//  Shape Matching functions
//============================================================================
IMAQ_FUNC ShapeReport* __stdcall imaqMatchShape(Image* dest, Image* source, const Image* templateImage, int scaleInvariant, int connectivity8, double tolerance, int* numMatches);

//============================================================================
//  Contours functions
//============================================================================
IMAQ_FUNC ContourID     __stdcall imaqAddAnnulusContour(ROI* roi, Annulus annulus);
IMAQ_FUNC ContourID     __stdcall imaqAddClosedContour(ROI* roi, const Point* points, int numPoints);
IMAQ_FUNC ContourID     __stdcall imaqAddLineContour(ROI* roi, Point start, Point end);
IMAQ_FUNC ContourID     __stdcall imaqAddOpenContour(ROI* roi, const Point* points, int numPoints);
IMAQ_FUNC ContourID     __stdcall imaqAddOvalContour(ROI* roi, Rect boundingBox);
IMAQ_FUNC ContourID     __stdcall imaqAddPointContour(ROI* roi, Point point);
IMAQ_FUNC ContourID     __stdcall imaqAddRectContour(ROI* roi, Rect rect);
IMAQ_FUNC ContourID     __stdcall imaqAddRotatedRectContour2(ROI* roi, RotatedRect rect);
IMAQ_FUNC ContourID     __stdcall imaqCopyContour(ROI* destRoi, const ROI* sourceRoi, ContourID id);
IMAQ_FUNC ContourID     __stdcall imaqGetContour(const ROI* roi, unsigned int index);
IMAQ_FUNC int           __stdcall imaqGetContourColor(const ROI* roi, ContourID id, RGBValue* contourColor);
IMAQ_FUNC int           __stdcall imaqGetContourCount(const ROI* roi);
IMAQ_FUNC ContourInfo2* __stdcall imaqGetContourInfo2(const ROI* roi, ContourID id);
IMAQ_FUNC int           __stdcall imaqMoveContour(ROI* roi, ContourID id, int deltaX, int deltaY);
IMAQ_FUNC int           __stdcall imaqRemoveContour(ROI* roi, ContourID id);
IMAQ_FUNC int           __stdcall imaqSetContourColor(ROI* roi, ContourID id, const RGBValue* color);

//============================================================================
//  Regions of Interest functions
//============================================================================
IMAQ_FUNC int  __stdcall imaqConstructROI2(const Image* image, ROI* roi, Tool initialTool, const ToolWindowOptions* tools, const ConstructROIOptions2* options, int* okay);
IMAQ_FUNC ROI* __stdcall imaqCreateROI(void);
IMAQ_FUNC int  __stdcall imaqGetROIBoundingBox(const ROI* roi, Rect* boundingBox);
IMAQ_FUNC int  __stdcall imaqGetROIColor(const ROI* roi, RGBValue* roiColor);
IMAQ_FUNC ROI* __stdcall imaqGetWindowROI(int windowNumber);
IMAQ_FUNC int  __stdcall imaqSetROIColor(ROI* roi, const RGBValue* color);
IMAQ_FUNC int  __stdcall imaqSetWindowROI(int windowNumber, const ROI* roi);

//============================================================================
//  Image Analysis functions
//============================================================================
IMAQ_FUNC int              __stdcall imaqCentroid(const Image* image, PointFloat* centroid, const Image* mask);
IMAQ_FUNC Curve*           __stdcall imaqExtractCurves(const Image* image, const ROI* roi, const CurveOptions* curveOptions, unsigned int* numCurves);
IMAQ_FUNC HistogramReport* __stdcall imaqHistogram(const Image* image, int numClasses, float min, float max, const Image* mask);
IMAQ_FUNC LinearAverages*  __stdcall imaqLinearAverages2(Image* image, LinearAveragesMode mode, Rect rect);
IMAQ_FUNC LineProfile*     __stdcall imaqLineProfile(const Image* image, Point start, Point end);
IMAQ_FUNC QuantifyReport*  __stdcall imaqQuantify(const Image* image, const Image* mask);

//============================================================================
//  Error Management functions
//============================================================================
IMAQ_FUNC int         __stdcall imaqClearError(void);
IMAQ_FUNC char*       __stdcall imaqGetErrorText(int errorCode);
IMAQ_FUNC int         __stdcall imaqGetLastError(void);
IMAQ_FUNC const char* __stdcall imaqGetLastErrorFunc(void);
IMAQ_FUNC int         __stdcall imaqSetError(int errorCode, const char* function);

//============================================================================
//  Threshold functions
//============================================================================
IMAQ_FUNC ThresholdData* __stdcall imaqAutoThreshold2(Image* dest, const Image* source, int numClasses, ThresholdMethod method, const Image* mask);
IMAQ_FUNC int            __stdcall imaqLocalThreshold(Image* dest, const Image* source, unsigned int windowWidth, unsigned int windowHeight, LocalThresholdMethod method, double deviationWeight, ObjectType type, float replaceValue);
IMAQ_FUNC int            __stdcall imaqMagicWand(Image* dest, const Image* source, Point coord, float tolerance, int connectivity8, float replaceValue);
IMAQ_FUNC int            __stdcall imaqMultithreshold(Image* dest, const Image* source, const ThresholdData* ranges, int numRanges);
IMAQ_FUNC int            __stdcall imaqThreshold(Image* dest, const Image* source, float rangeMin, float rangeMax, int useNewValue, float newValue);

//============================================================================
//  Memory Management functions
//============================================================================
IMAQ_FUNC int __stdcall imaqDispose(void* object);

//============================================================================
//  File I/O functions
//============================================================================
IMAQ_FUNC int         __stdcall imaqCloseAVI(AVISession session);
IMAQ_FUNC AVISession  __stdcall imaqCreateAVI(const char* fileName, const char* compressionFilter, int quality, unsigned int framesPerSecond, unsigned int maxDataSize);
IMAQ_FUNC int         __stdcall imaqGetAVIInfo(AVISession session, AVIInfo* info);
IMAQ_FUNC int         __stdcall imaqGetFileInfo(const char* fileName, CalibrationUnit* calibrationUnit, float* calibrationX, float* calibrationY, int* width, int* height, ImageType* imageType);
IMAQ_FUNC FilterName* __stdcall imaqGetFilterNames(int* numFilters);
IMAQ_FUNC char**      __stdcall imaqLoadImagePopup(const char* defaultDirectory, const char* defaultFileSpec, const char* fileTypeList, const char* title, int allowMultiplePaths, ButtonLabel buttonLabel, int restrictDirectory, int restrictExtension, int allowCancel, int allowMakeDirectory, int* cancelled, int* numPaths);
IMAQ_FUNC AVISession  __stdcall imaqOpenAVI(const char* fileName);
IMAQ_FUNC int         __stdcall imaqReadAVIFrame(Image* image, AVISession session, unsigned int frameNum, void* data, unsigned int* dataSize);
IMAQ_FUNC int         __stdcall imaqReadFile(Image* image, const char* fileName, RGBValue* colorTable, int* numColors);
IMAQ_FUNC int         __stdcall imaqReadVisionFile(Image* image, const char* fileName, RGBValue* colorTable, int* numColors);
IMAQ_FUNC int         __stdcall imaqWriteAVIFrame(Image* image, AVISession session, const void* data, unsigned int dataLength);
IMAQ_FUNC int         __stdcall imaqWriteBMPFile(const Image* image, const char* fileName, int compress, const RGBValue* colorTable);
IMAQ_FUNC int         __stdcall imaqWriteFile(const Image* image, const char* fileName, const RGBValue* colorTable);
IMAQ_FUNC int         __stdcall imaqWriteJPEGFile(const Image* image, const char* fileName, unsigned int quality, void* colorTable);
IMAQ_FUNC int         __stdcall imaqWriteJPEG2000File(const Image* image, const char* fileName, int lossless, float compressionRatio, const JPEG2000FileAdvancedOptions* advancedOptions, const RGBValue* colorTable);
IMAQ_FUNC int         __stdcall imaqWritePNGFile2(const Image* image, const char* fileName, unsigned int compressionSpeed, const RGBValue* colorTable, int useBitDepth);
IMAQ_FUNC int         __stdcall imaqWriteTIFFFile(const Image* image, const char* fileName, const TIFFFileOptions* options, const RGBValue* colorTable);
IMAQ_FUNC int         __stdcall imaqWriteVisionFile(const Image* image, const char* fileName, const RGBValue* colorTable);

//============================================================================
//  Frequency Domain Analysis functions
//============================================================================
IMAQ_FUNC int __stdcall imaqAttenuate(Image* dest, const Image* source, AttenuateMode highlow);
IMAQ_FUNC int __stdcall imaqConjugate(Image* dest, const Image* source);
IMAQ_FUNC int __stdcall imaqFFT(Image* dest, const Image* source);
IMAQ_FUNC int __stdcall imaqFlipFrequencies(Image* dest, const Image* source);
IMAQ_FUNC int __stdcall imaqInverseFFT(Image* dest, const Image* source);
IMAQ_FUNC int __stdcall imaqTruncate(Image* dest, const Image* source, TruncateMode highlow, float ratioToKeep);

//============================================================================
//  Pixel Manipulation functions
//============================================================================
IMAQ_FUNC int    __stdcall imaqArrayToComplexPlane(Image* dest, const Image* source, const float* newPixels, ComplexPlane plane);
IMAQ_FUNC float* __stdcall imaqComplexPlaneToArray(const Image* image, ComplexPlane plane, Rect rect, int* columns, int* rows);
IMAQ_FUNC int    __stdcall imaqExtractColorPlanes(const Image* image, ColorMode mode, Image* plane1, Image* plane2, Image* plane3);
IMAQ_FUNC int    __stdcall imaqExtractComplexPlane(Image* dest, const Image* source, ComplexPlane plane);
IMAQ_FUNC int    __stdcall imaqFillImage(Image* image, PixelValue value, const Image* mask);
IMAQ_FUNC void*  __stdcall imaqGetLine(const Image* image, Point start, Point end, int* numPoints);
IMAQ_FUNC int    __stdcall imaqGetPixel(const Image* image, Point pixel, PixelValue* value);
IMAQ_FUNC int    __stdcall imaqReplaceColorPlanes(Image* dest, const Image* source, ColorMode mode, const Image* plane1, const Image* plane2, const Image* plane3);
IMAQ_FUNC int    __stdcall imaqReplaceComplexPlane(Image* dest, const Image* source, const Image* newValues, ComplexPlane plane);
IMAQ_FUNC int    __stdcall imaqSetLine(Image* image, const void* array, int arraySize, Point start, Point end);
IMAQ_FUNC int    __stdcall imaqSetPixel(Image* image, Point coord, PixelValue value);

//============================================================================
//  LCD functions
//============================================================================
IMAQ_FUNC int        __stdcall imaqFindLCDSegments(ROI* roi, const Image* image, const LCDOptions* options);
IMAQ_FUNC LCDReport* __stdcall imaqReadLCD(const Image* image, const ROI* roi, const LCDOptions* options);

//============================================================================
//  Regions of Interest Manipulation functions
//============================================================================
IMAQ_FUNC ROI*        __stdcall imaqMaskToROI(const Image* mask, int* withinLimit);
IMAQ_FUNC ROIProfile* __stdcall imaqROIProfile(const Image* image, const ROI* roi);
IMAQ_FUNC int         __stdcall imaqROIToMask(Image* mask, const ROI* roi, int fillValue, const Image* imageModel, int* inSpace);
IMAQ_FUNC int         __stdcall imaqTransformROI2(ROI* roi, const CoordinateSystem* baseSystem, const CoordinateSystem* newSystem);

//============================================================================
//  OCR functions
//============================================================================
IMAQ_FUNC CharSet*         __stdcall imaqCreateCharSet(void);
IMAQ_FUNC int              __stdcall imaqDeleteChar(CharSet* set, int index);
IMAQ_FUNC int              __stdcall imaqGetCharCount(const CharSet* set);
IMAQ_FUNC CharInfo2*       __stdcall imaqGetCharInfo2(const CharSet* set, int index);
IMAQ_FUNC int              __stdcall imaqReadOCRFile(const char* fileName, CharSet* set, String255 setDescription, ReadTextOptions* readOptions, OCRProcessingOptions* processingOptions, OCRSpacingOptions* spacingOptions);
IMAQ_FUNC ReadTextReport2* __stdcall imaqReadText2(const Image* image, const CharSet* set, const ROI* roi, const ReadTextOptions* readOptions, const OCRProcessingOptions* processingOptions, const OCRSpacingOptions* spacingOptions);
IMAQ_FUNC int              __stdcall imaqRenameChar(CharSet* set, int index, const char* newCharValue);
IMAQ_FUNC int              __stdcall imaqSetReferenceChar(const CharSet* set, int index, int isReferenceChar);
IMAQ_FUNC int              __stdcall imaqTrainChars(const Image* image, CharSet* set, int index, const char* charValue, const ROI* roi, const OCRProcessingOptions* processingOptions, const OCRSpacingOptions* spacingOptions);
IMAQ_FUNC int*             __stdcall imaqVerifyPatterns(const Image* image, const CharSet* set, const String255* expectedPatterns, int patternCount, const ROI* roi, int* numScores);
IMAQ_FUNC int*             __stdcall imaqVerifyText(const Image* image, const CharSet* set, const char* expectedString, const ROI* roi, int* numScores);
IMAQ_FUNC int              __stdcall imaqWriteOCRFile(const char* fileName, const CharSet* set, const char* setDescription, const ReadTextOptions* readOptions, const OCRProcessingOptions* processingOptions, const OCRSpacingOptions* spacingOptions);

//============================================================================
//  Classification functions
//============================================================================
IMAQ_FUNC int                            __stdcall imaqAddClassifierSample(Image* image, ClassifierSession* session, const ROI* roi, const char* sampleClass, double* featureVector, unsigned int vectorSize);
IMAQ_FUNC ClassifierReport*              __stdcall imaqClassify(Image* image, const ClassifierSession* session, const ROI* roi, double* featureVector, unsigned int vectorSize);
IMAQ_FUNC ClassifierSession*             __stdcall imaqCreateClassifier(ClassifierType type);
IMAQ_FUNC int                            __stdcall imaqDeleteClassifierSample(ClassifierSession* session, int index);
IMAQ_FUNC ClassifierAccuracyReport*      __stdcall imaqGetClassifierAccuracy(const ClassifierSession* session);
IMAQ_FUNC ClassifierSampleInfo*          __stdcall imaqGetClassifierSampleInfo(const ClassifierSession* session, int index, int* numSamples);
IMAQ_FUNC int                            __stdcall imaqGetNearestNeighborOptions(const ClassifierSession* session, NearestNeighborOptions* options);
IMAQ_FUNC int                            __stdcall imaqGetParticleClassifierOptions(const ClassifierSession* session, ParticleClassifierPreprocessingOptions* preprocessingOptions, ParticleClassifierOptions* options);
IMAQ_FUNC ClassifierSession*             __stdcall imaqReadClassifierFile(ClassifierSession* session, const char* fileName, ReadClassifierFileMode mode, ClassifierType* type, ClassifierEngineType* engine, String255 description);
IMAQ_FUNC int                            __stdcall imaqRelabelClassifierSample(ClassifierSession* session, int index, const char* newClass);
IMAQ_FUNC int                            __stdcall imaqSetParticleClassifierOptions(ClassifierSession* session, const ParticleClassifierPreprocessingOptions* preprocessingOptions, const ParticleClassifierOptions* options);
IMAQ_FUNC NearestNeighborTrainingReport* __stdcall imaqTrainNearestNeighborClassifier(ClassifierSession* session, const NearestNeighborOptions* options);
IMAQ_FUNC int                            __stdcall imaqWriteClassifierFile(const ClassifierSession* session, const char* fileName, WriteClassifierFileMode mode, const String255 description);

//============================================================================
//  Inspection functions
//============================================================================
IMAQ_FUNC int __stdcall imaqCompareGoldenTemplate(const Image* image, Image* goldenTemplate, Image* brightDefects, Image* darkDefects, const InspectionAlignment* alignment, const InspectionOptions* options);
IMAQ_FUNC int __stdcall imaqLearnGoldenTemplate(Image* goldenTemplate, PointFloat originOffset, const Image* mask);

//============================================================================
//  Morphology functions
//============================================================================
IMAQ_FUNC int __stdcall imaqGrayMorphology(Image* dest, Image* source, MorphologyMethod method, const StructuringElement* structuringElement);
//============================================================================
//  Obsolete functions
//============================================================================
IMAQ_FUNC int                    __stdcall imaqTransformROI(ROI* roi, Point originStart, float angleStart, Point originFinal, float angleFinal);
IMAQ_FUNC Color                  __stdcall imaqChangeColorSpace(const Color* sourceColor, ColorMode sourceSpace, ColorMode destSpace);
IMAQ_FUNC int                    __stdcall imaqConstructROI(const Image* image, ROI* roi, Tool initialTool, const ToolWindowOptions* tools, const ConstructROIOptions* options, int* okay);
IMAQ_FUNC int                    __stdcall imaqConvex(Image* dest, const Image* source);
IMAQ_FUNC int                    __stdcall imaqRotate(Image* dest, const Image* source, float angle, PixelValue fill, InterpolationMethod method);
IMAQ_FUNC int                    __stdcall imaqLineGaugeTool(const Image* image, Point start, Point end, LineGaugeMethod method, const EdgeOptions* edgeOptions, const CoordinateTransform* reference, float* distance);
IMAQ_FUNC int                    __stdcall imaqBestCircle(const PointFloat* points, int numPoints, PointFloat* center, double* radius);
IMAQ_FUNC int                    __stdcall imaqWritePNGFile(const Image* image, const char* fileName, unsigned int compressionSpeed, const RGBValue* colorTable);
IMAQ_FUNC int                    __stdcall imaqLoadPattern(Image* pattern, const char* fileName);
IMAQ_FUNC int                    __stdcall imaqLabel(Image* dest, Image* source, int connectivity8, int* particleCount);
IMAQ_FUNC int                    __stdcall imaqCoordinateReference(const Point* points, ReferenceMode mode, Point* origin, float* angle);
IMAQ_FUNC ContourInfo*           __stdcall imaqGetContourInfo(const ROI* roi, ContourID id);
IMAQ_FUNC int                    __stdcall imaqSetWindowOverlay(int windowNumber, const Overlay* overlay);
IMAQ_FUNC Overlay*               __stdcall imaqCreateOverlayFromROI(const ROI* roi);
IMAQ_FUNC Overlay*               __stdcall imaqCreateOverlayFromMetafile(const void* metafile);
IMAQ_FUNC int                    __stdcall imaqSetCalibrationInfo(Image* image, CalibrationUnit unit, float xDistance, float yDistance);
IMAQ_FUNC int                    __stdcall imaqGetCalibrationInfo(const Image* image, CalibrationUnit* unit, float* xDistance, float* yDistance);
IMAQ_FUNC int                    __stdcall imaqSavePattern(const Image* pattern, const char* fileName);
IMAQ_FUNC int                    __stdcall imaqLearnPattern(Image* image, LearningMode learningMode);
IMAQ_FUNC Barcode2DInfo*         __stdcall imaqReadDataMatrixBarcode(const Image* image, const ROI* roi, const DataMatrixOptions* options, unsigned int* numBarcodes);
IMAQ_FUNC LinearAverages*        __stdcall imaqLinearAverages(const Image* image, Rect rect);
IMAQ_FUNC GeometricPatternMatch* __stdcall imaqMatchGeometricPattern(const Image* image, const Image* pattern, const CurveOptions* curveOptions, const MatchGeometricPatternOptions* matchOptions, const MatchGeometricPatternAdvancedOptions* advancedMatchOptions, const ROI* roi, int* numMatches);
IMAQ_FUNC CharInfo*              __stdcall imaqGetCharInfo(const CharSet* set, int index);
IMAQ_FUNC ReadTextReport*        __stdcall imaqReadText(const Image* image, const CharSet* set, const ROI* roi, const ReadTextOptions* readOptions, const OCRProcessingOptions* processingOptions, const OCRSpacingOptions* spacingOptions);
IMAQ_FUNC ThresholdData*         __stdcall imaqAutoThreshold(Image* dest, Image* source, int numClasses, ThresholdMethod method);
IMAQ_FUNC ColorHistogramReport*  __stdcall imaqColorHistogram(Image* image, int numClasses, ColorMode mode, const Image* mask);
IMAQ_FUNC int                    __stdcall imaqFitCircle(const PointFloat* points, int numPoints, BestCircle* circle);
IMAQ_FUNC PatternMatch*          __stdcall imaqMatchPattern(const Image* image, Image* pattern, const MatchPatternOptions* options, Rect searchRect, int* numMatches);
IMAQ_FUNC int                    __stdcall imaqFitEllipse(const PointFloat* points, int numPoints, BestEllipse* ellipse);
IMAQ_FUNC ParticleReport*        __stdcall imaqSelectParticles(const Image* image, const ParticleReport* reports, int reportCount, int rejectBorder, const SelectParticleCriteria* criteria, int criteriaCount, int* selectedCount);
IMAQ_FUNC int                    __stdcall imaqParticleFilter(Image* dest, Image* source, const ParticleFilterCriteria* criteria, int criteriaCount, int rejectMatches, int connectivity8);
IMAQ_FUNC ParticleReport*        __stdcall imaqGetParticleInfo(Image* image, int connectivity8, ParticleInfoMode mode, int* reportCount);
IMAQ_FUNC int                    __stdcall imaqCalcCoeff(const Image* image, const ParticleReport* report, MeasurementValue parameter, float* coefficient);
IMAQ_FUNC EdgeReport*            __stdcall imaqEdgeTool(const Image* image, const Point* points, int numPoints, const EdgeOptions* options, int* numEdges);
IMAQ_FUNC CircleReport*          __stdcall imaqCircles(Image* dest, const Image* source, float minRadius, float maxRadius, int* numCircles);
IMAQ_FUNC ContourID              __stdcall imaqAddRotatedRectContour(ROI* roi, RotatedRect rect);
IMAQ_FUNC int                    __stdcall imaqIsVisionInfoPresent(const Image* image, VisionInfoType type, int* present);
#endif

