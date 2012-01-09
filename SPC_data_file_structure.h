/* This file contains defines and structure definitions which can be useful
        in case of writing a program to analyze .set, .sdt and .spc files
        created using BH software
*/

/*

/////////////////////////////////////////////////////////////////////////
////////////         .set  and .sdt files structure   ///////////////////
/////////////////////////////////////////////////////////////////////////

The setup files ( extension .set ) consist of:
  1 - a file header containing structural data which are used 
        to find the other parts of the file
  2 - the 'file information' which was typed in when the file was saved
  3 - the system setup data for hardware and software



The data files ( extension .sdt ) consist of:
  1 - a file header containing structural data which are used 
        to find the other parts of the file
  2 - the 'file information' which was typed in when the file was saved
  3 - the system setup data for hardware and software
  4 - one or more measurement description blocks which contain 
       the system parameters corresponding to the particular data blocks
  5 - data blocks containing a set curve from one measurement each, 
       along with information to which measurement description block 
       they correspond

*/

#define BH_HEADER_CHKSUM      0x55aa
#define BH_HEADER_NOT_VALID   0x1111
#define BH_HEADER_VALID       0x5555

// all offsets are given from the beginning of the file
// all parts lengths are given in bytes
 
 //  1 - File header
typedef struct  {
   short    revision;  // software revision number  (lower 4 bits >= 10(decimal))
   long     info_offs; // offset of the info part which contains general text 
                       //   information (Title, date, time, contents etc.)
   short    info_length;  // length of the info part
   long     setup_offs;   // offset of the setup text data 
               // (system parameters, display parameters, trace parameters etc.)
   short    setup_length;  // length of the setup data
   long     data_block_offs;   // offset of the first data block 
   short    no_of_data_blocks; // no_of_data_blocks valid only when in 0 .. 0x7ffe range,
                               // if equal to 0x7fff  the  field 'reserved1' contains 
                               //     valid no_of_data_blocks
   long     data_block_length;     // length of the longest block in the file
   long     meas_desc_block_offs;  // offset to 1st. measurement description block 
                                   //   (system parameters connected to data blocks)
   short    no_of_meas_desc_blocks;  // number of measurement description blocks
   short    meas_desc_block_length;  // length of the measurement description blocks
   unsigned short    header_valid;   // valid: 0x5555, not valid: 0x1111
   unsigned long     reserved1;      // reserved1 now contains no_of_data_blocks
   unsigned short    reserved2;
   unsigned short chksum;            // checksum of file header
   }bhfile_header;


/*
  2 - File Info
This part contains the general information which has been typed in when the data was saved. 
The info part is stored in ASCII. An example is given below.

*IDENTIFICATION
  ID  : _SPC Setup & Data File_
  Title : startup
  Version : 1 810 M
  Revision    : 1
  Date  : 10-10-1997
  Time  : 12:29:01
  Author  : Bond, James
  Company : Unknown
  Contents    : Dye sample from Dr. No
*END

ID line is tested by the application to check whether the file is a valid SPC file
Possible identifiers are listed below

*/

// for .set files ( setup only )
const char setup_identifier[32] =      "SPC Setup Script File"; 

// for normal .sdt files ( setup + data )
const char  data_identifier[32] =      "SPC Setup & Data File";

// for .sdt files created automatically in Continuous Flow mode measurement 
//     ( no setup, only data )
const char  flow_data_identifier[32] = "SPC Flow Data File";

// for .sdt files created using DLL function SPC_save_data_to_sdtfile
//     ( no setup, only data )
const char  dll_data_identifier[32]  = "SPC DLL Data File";

// for .sdt files created in FIFO mode 
//     ( setup, data blocks = Decay, FCS, FIDA, FILDA & MCS curves 
//             for each used routing channel )
const char  fcs_data_identifier[32]  = "SPC FCS Data File";



/*
  3 - Setup

The setup block contains all the system parameters, display parameters, trace parameters etc 
  stored in ASCII.
From the software version 8.1  setup block contains also binary part.
  
It is used to set the SPC system (hardware and software) into the same state as 
  it was in the moment when the data file was stored. 
The values are stored together with an identifier of the particular parameter.
This method allows to maintain compatibility between different SPC versions. 
If a parameter is missing in the setup part, i.e. 
  if a file from an older software version is loaded, a default value is used 
   when the file is loaded. 
For Multi SPC Systems the system parameters section contains subsections 
   for module parameters which are separate for the individual modules.

ASCII part of the setup block starts with the line
*SETUP
and ends with the line
*END

After this  binary part of the setup follows  ( for the files created with the software
  version 8.1 and next ) 

It starts with the text BIN_PARA_BEGIN
Directly after BIN_PARA_BEGIN text comes:
  -  4-byte value which is equal to the length of binary setup 
          ( all suqsequent headers and structures up to *END text )
  -  BHBinHdr bh_bin_hdr       
  -  SPCBinHdr spc_bin_hdr       
  -  structures defined in spc_bin_hdr header

binary setup ends with the line
*END

binary setup contains mainly display parameters for different graph windows
 ( Main graph (2D, 3D), FCS and other (in future) ), 
 which are used by the main software to restore display parameters
   of the specific windows
 DI_ parameters in ASCII part of the setup are now obsolete and are present
 for compatibility reason only
*/

typedef struct {
   unsigned long     soft_rev;       // software revision
   unsigned long     para_length;    // currently set to 0 
   unsigned long     reserved1;
   unsigned short    reserved2;
   }BHBinHdr;


// all offsets are given from the beginning of the file
// all parts lengths are given in bytes

typedef struct {
  unsigned long  FCS_old_offs;    // offset of FCSParam structure for FCS parameters
  unsigned long  FCS_old_size;    //  FCSParam structure size
               //  FCSParam is obsolete - needed only for compatibility
               //  with software v. 8.1 - 8.2
               //  from v.8.3 FCS parameters are included further in HSTParam 
  unsigned long  gr1_offs;    // offset of GR_Param structure for main graph window
  unsigned long  gr1_size;    //  GR_Param structure size                       
  unsigned long  FCS_offs;    // offset of HSTParam structure for FCS parameters
  unsigned long  FCS_size;    //  HSTParam structure size
  unsigned long  FIDA_offs;   // offset of HSTParam structure for FIDA window parameters
  unsigned long  FIDA_size;   //  HSTParam structure size 
  unsigned long  FILDA_offs;  // offset of HSTParam structure for FILDA window parameters
  unsigned long  FILDA_size;  //  HSTParam structure size
  unsigned long  gr2_offs;    // offset of GR_Param structure for the 1st additional graph
  unsigned short gr_no;       // number of additional GR_Param structures, ( size = gr1_size )
  unsigned short hst_no;      // number of additional HSTParam structures, ( size = FCS_size )
  unsigned long  hst_offs;    // offset of the 1st additional HSTParam structure
  unsigned long  GVD_offs;    // offset of GVDParam structure for GVD-120 parameters 
  unsigned short GVD_size;    //  GVDParam structure size
  unsigned short FIT_offs;    // offset of FITSetup structure for FIT parameters
  unsigned short FIT_size;    //  FITSetup structure size
  unsigned short extdev_offs;  // offset of external devices setup structures
  unsigned short extdev_size;  //  size of external devices setup structures
  unsigned short reserve2;
  unsigned long  reserve3;
  }SPCBinHdr;

/*
SPCBinHdr header includes offsets of GR_Param structure for the main display window
  and HSTParam structures for FCS, FIDA and FILDA windows.
Another GR_Param structures can be included if additional 3D display windows were 
  opened
Another HSTParam structures can be included if additional histograms windows were 
  opened ( e.g. MCS (Macro Time) histogram )
GVDParam structure contains parameters of GVD-120 module which controls BH Galvano Scanner.
FITParam structure contains start values of FCS fitting parameters   
Other fields will be used in future software versions
FCS, FIDA, FILDA, MCS windows parameters are defined below in HSTParam structure
The structure contains attributes of histogram display windows,
  which can be visible in FIFO mode
*/

typedef struct {
  int   top;
  int   left;
  int   height;
  int   width;
  int   flags;  // 0x1 - visible
  }BHPanelAttr;



typedef union 
{
  int             i;
  unsigned int    u;
  int             b;
  short           h;
  unsigned short  g;
  long            l;
  unsigned long   m;
  float           f;
  double          d;
  char            c;
} DparVal;



  
  
typedef struct            
{
  DparVal maxcnt;     //  DI_MAXCNT    
  DparVal lbline;     //  DI_LBLINE  
  DparVal bline;      //  DI_BLINE     
  int  scale;         //  DI_SCALE   
  int  grid;          //  DI_GRID  X : bit1, bit3 minor/ Y : bit2, bit 4 minor/ bit0 = X+Y
  int  plot_style;    //  DI_TRACE     
  int  point_style;   //  DI_PSTYLE    
  int  line_style;    //  set to 0    
  int  point_freq;    //  DI_PFREQ   
  int  resize;        //  0 - not set, 1- Full size, 2 - Proportional, 3- other
  int   grid_color;   //  DI_GCOL_F
  int   bkg_color;    //  DI_GCOL_B
  int   d2_mode;      //  DI_2DDIS
  short reverse;      //  DI_XREV - bit 0, DI_YREV - bit 1                          
  short ascale;       //  autoscale for 2D
  DparVal xlow;          
  DparVal xhigh;          
  int  xscale;        //  Xscale log = 1
  DparVal yhilim;     // high limit for y scale  
} Disp2DAttr;




typedef struct  {    // obsolete, needed only for compatibility with software v. 8.1 - 8.2
  int      view_decay;      
  int      view_fcs;   
  float    cortime; // correlation time [ms] 
  BHPanelAttr  pnl_attr; 
  Disp2DAttr   d2para;
  }FCSParam;


// Histogram traces parameters ( FCS, FIDA, FILDA, MCS )
typedef struct  {
  short    active;         // (0)1 - (not) active   
  short    module;
  short    curve;          // routing channel no 
  short    cross_curve;    // cross correlation channel number for FCS
                      //    ( when = curve and module = cross_module -  auto FCS )
  short    cross_module;   // cross correlation module number for FCS
  int      color;          // trace color
  int      points;         // number of points in trace 
  }HSTtrace;  //



#define MAX_NO_OF_TRACES  8

typedef struct{        // structure for FCS, FIDA and FILDA histogram windows
  int              active;   // window visible, histogram is calculated
  unsigned short   hst_type; // additional histogram parameters
                    // for FCS:  0 - linear FCS with log binning ( 100 bins/log )
                              // when bit 15 = 1 ( 0x8000 ) - Multi-Tau FCS 
                              //           where bits 14-0 = ktau parameter
  short          reserve;   
  float          time;     // in [ms], correlation time for FCS, 
                           // period time for FIDA, FILDA, time per point for MT
  BHPanelAttr    pnl_attr; 
  Disp2DAttr     d2para;
  HSTtrace       htrace[MAX_NO_OF_TRACES];
  }HSTParam;



#define MAX_NO_OF_COLORS   11 // max value for DI_COL_NO

typedef struct            
{
  int   offsx;             //  DI_3DOFFX - offset X for 3D display 
  int   offsy;             //  DI_3DOFFY - offset Y for 3D display         
  int   inclination;       //  DI_3DINCX - inclination X for 3D display    
  int   body_color;        //  DI_BOD_C
  int   curve_color;       //  DI_3DCOL
  int   d3_mode;           //  DI_3DMODE
  int   ywin;              //  DI_YWIN  
  int   xwin;              //  DI_XWIN  
  int   twin;              //  DI_TWIN  
  int   sywin;             //  DI_SYWIN  
  int   sxwin;             //  DI_SXWIN  
  int   d3_style;          //  DI_3DSTYL
  int   interpolate;       //  DI_INTCOL- bit 0, DI_INTPIX - bit 1
  int   col_no;            //  DI_COL_NO
  int   color[MAX_NO_OF_COLORS];   // 0 - DI_COLMIN, 1 - DI_COLMAX, 2..5 - DI_COL2-5,
                           // 6 - 10 are stored in BIN_SETUP
  int   col_hi;            //  DI_HICOL
  int   detail;            //  DI_DETAIL  
  int   ascale;            //  DI_ASCALE  
  int   lcol_no;           //  DI_COL_NO  for log scale
} Disp3DAttr;



typedef struct _Interval {
    unsigned int    from;
    unsigned int    to;
    }Interval;



typedef struct _Trace3d {
  short    log_scale;       /*  display type 0- linear , 1- logarithmic  */
  short    offsx;           /*  display offset X  - parameter DI_3DOFFX  */
  short    offsy;           /*  display offset Y  - parameter DI_3DOFFY  */
  double   inclination;     /*  display inclination- parameter DI_3DINCX  */
  short    mode;            /*  display mode  - parameter DI_3DMODE  */
  unsigned int    page;            /*  page number in SPC memory */
  unsigned int    no_of_curves;    /*  number of curves  */
  unsigned int    no_of_disp_curves;    /*  number of displayed curves */
  unsigned int    no_of_points;    /*  number of points  */
  short    resolution; 
  Interval * win;            /*  pointer to  window interval - depending on
                                   display mode = DI_XWIN,DI_YWIN,DI_TWIN */
  Interval * win_y;          /*  pointer to Y window interval - for f(t,x,y,param) */
  unsigned short  first_disp_point; /*  number of first displayed point on curves  */
  unsigned short  last_disp_point;  /*  number of last displayed point on curves  */
  unsigned int    first_disp_curve; /*  number of first displayed curve  */
  unsigned int    last_disp_curve;  /*  number of last displayed curve  */
  short    reduction;        /*  display reduction ratio  */
  int      color;            /*  colors of curves  (DIS_3DCOL converted ) */
  int      body_color;       /*  color of the body (DIS_BOD_C converted ) */
  double   curve1_xpos;      /*  x position on the graph of the first curve */
  double   curve1_ypos;      /*  y position on the graph of the first curve */
  double   xinc;             /*  x increment */
  double   yinc;             /*  y increment */
  double   ygain;            /*  y gain */
  short    no;               /*  3d trace no */
  short    sreserve;         /*  for future use */
  unsigned long    reserve;  /*  for future use */
  long     low_offset;       /*  DI_BLINE */
  long     max_count;        /*  DI_MAXCNT */
  Interval * swin;           /*  pointer to ScanX(Y) window interval -  depending on
                                 display mode = DI_XWIN,DI_YWIN,DI_TWIN */
  Interval * swin_y;         /*  pointer to ScanY window interval  */
  long no_of_blocks;         /*  for get3Dcurve */
  } Trace3d;



typedef struct  {
  short               active;      
  unsigned short      tr3d_module; // mod_no for 3D trace, missing in Trace3d structure
  unsigned short      mem_bank;      
  unsigned short      reserved2;      
  double              dreserved1;
  double              dreserved2;
  BHPanelAttr         pnl_attr; 
  Disp2DAttr          d2para;    // Disp2DAttr for modes with 2D display  
  Disp3DAttr          d3para;    // additional parameters for 3D display  
  Disp2DAttr          d23para;   // Disp2DAttr for modes with 3D display  
  Trace3d             tr3d;      // 3D trace parameters structure                                      
  Disp2DAttr          d21para;   // Disp2DAttr for modes with 2D display and 32-bit range
                                 //      ( fifo modes & 2D Block Display )
  }GR_Param;                     // Main Graph window parameters



/*
  4 - Measurement Description Blocks
  
Each data block can (but need not) have its own system (hardware) parameter set 
 which can differ from the setup parameters. 
In the block header of each data block a corresponding measurement description block is specified. 
Therefore the number of measurement description blocks can vary 
 from one (if all stored data blocks originate from only one measurement) 
 to the overall number of saved data blocks 
  (if all blocks are measured with different hardware parameters). 

The number, the length and the location of the measurement description blocks is stored 
  in the file header at the beginning of the file.
The information in the measurement description blocks is used for 
 the 'Block Info' or 'Set Info' function in the Load, Save and Trace Parameters menus. 
If the button 'Use System Parameters from the Selected Block' is pressed, 
 the system parameters are replaced by the data in the measurement description block.
The measurement description blocks are stored in a binary format. 

From the software version 7.9  measurement description block contains also additional 
 information (in the structure MeasStopInfo ) collected at the end of the measurement. 
 This information can be useful when analyzing system's wrong setup or malfunction.

From the software version 8.1  measurement description block contains also additional 
 information (in the structure MeasFCSInfo ) collected at the end of the FIFO measurement
 when FCS curve were created.
 The information is valid only for data blocks of type FIFO_DATA or FIFO_DATA_FROM_FILE

From the software version 8.3  measurement description block contains also additional 
 information (in the structure MeasFIDAInfo ) collected at the end of the FIFO measurement
 when FIDA or FILDA curves were created.
 The information is valid only for data blocks of type FIFO_DATA or FIFO_DATA_FROM_FILE

From the software version 8.4  measurement description block contains instead of MeasFIDAInfo
 the structure MeasHISTInfo  collected at the end of the FIFO measurement
 when FIDA , FILDA or MCS curves were created. 
 It contains additionally information for MCS curve.
 The information is valid only for data blocks of type FIFO_DATA or FIFO_DATA_FROM_FILE

The structures are shown below.

*/


typedef struct {
  unsigned short  status;  // last SPC_test_state return value ( status )
  unsigned short  flags;   // scan clocks bits 2-0( frame, line, pixel), 
                           //  rates_read - bit 15
  float  stop_time;        // time from start to  - disarm ( simple measurement )
                           //    - or to the end of the cycle (for complex measurement )
  int    cur_step;         // current step  ( if multi-step measurement )
  int    cur_cycle;        // current cycle (accumulation cycle in FLOW mode ) -
                           //  ( if multi-cycle measurement ) 
  int    cur_page;         // current measured page
  float  min_sync_rate;    // minimum rates during the measurement
  float  min_cfd_rate;     //   ( -1.0 - not set )
  float  min_tac_rate;
  float  min_adc_rate;
  float  max_sync_rate;    // maximum rates during the measurement
  float  max_cfd_rate;     //   ( -1.0 - not set )
  float  max_tac_rate;
  float  max_adc_rate;
  int    reserved1;
  float  reserved2;
  }MeasStopInfo;           // information collected when measurement is finished
  


typedef struct {
  unsigned short  chan;               // routing channel number
  unsigned short  fcs_decay_calc;     // bit 0 = 1 - decay curve calculated
                                      // bit 1 = 1 - fcs   curve calculated
                                      // bit 2 = 1 - FIDA  curve calculated
                                      // bit 3 = 1 - FILDA curve calculated
                                      // bit 4 = 1 - MCS curve calculated
                                      // bit 5 = 1 - 3D Image calculated
  unsigned int    mt_resol;           // macro time clock in 0.1 ns units
  float           cortime;            // correlation time [ms] 
  unsigned int    calc_photons;       //  no of photons  
  int             fcs_points;         // no of FCS values
  float           end_time;           // macro time of the last photon 
  unsigned short  overruns;           // no of Fifo overruns 
                              //   when > 0  fcs curve & end_time are not valid
  unsigned short  fcs_type;   // 0 - linear FCS with log binning ( 100 bins/log )
                              // when bit 15 = 1 ( 0x8000 ) - Multi-Tau FCS 
                              //           where bits 14-0 = ktau parameter
  unsigned short  cross_chan;         // cross FCS routing channel number
                   //   when chan = cross_chan and mod == cross_mod - Auto FCS
                   //        otherwise - Cross FCS
  unsigned short  mod;                // module number
  unsigned short  cross_mod;          // cross FCS module number
  unsigned int    cross_mt_resol;     // macro time clock of cross FCS module in 0.1 ns units
  }MeasFCSInfo;   // information collected when FIFO measurement is finished


  
typedef struct {
  float           fida_time;          // interval time [ms] for FIDA histogram
  float           filda_time;         // interval time [ms] for FILDA histogram
  int             fida_points;        // no of FIDA values
                                      //    or current frame number ( fifo_image)
  int             filda_points;       // no of FILDA values
                                      //    or current line  number ( fifo_image)
  float           mcs_time;            // interval time [ms] for MCS histogram
  int             mcs_points;          // no of MCS values
                                      //    or current pixel number ( fifo_image)
  unsigned int    cross_calc_phot;    //  no of calculated photons from cross_channel 
                                      //    for Cross FCS histogram
  int             reserved1;
  double          reserved2;
  double          reserved3;
  }MeasHISTInfo;     // extension of MeasFCSInfo for other histograms ( FIDA, FILDA, MCS ) 
  

typedef struct _MeasureInfo {
  char     time[9];        /* time of creation */
  char     date[11];       /* date of creation */
  char     mod_ser_no[16]; /* serial number of the module */
  short    meas_mode;
  float    cfd_ll;
  float    cfd_lh;
  float    cfd_zc;
  float    cfd_hf;
  float    syn_zc;
  short    syn_fd;
  float    syn_hf;
  float    tac_r;
  short    tac_g;
  float    tac_of;
  float    tac_ll;
  float    tac_lh;
  short    adc_re;
  short    eal_de;
  short    ncx;
  short    ncy;
  unsigned short  page;
  float    col_t;
  float    rep_t;
  short    stopt;
  char     overfl;
  short    use_motor;
  unsigned short    steps;
  float    offset;
  short    dither;
  short    incr;
  short    mem_bank;
  char     mod_type[16];   /* module type */
  float    syn_th;
  short    dead_time_comp;
  short    polarity_l;   //  2 = disabled line markers
  short    polarity_f;
  short    polarity_p;
  short    linediv;      // line predivider = 2 ** ( linediv)
  short    accumulate;
  int      flbck_y; 
  int      flbck_x; 
  int      bord_u; 
  int      bord_l; 
  float    pix_time;
  short    pix_clk; 
  short    trigger; 
  int      scan_x; 
  int      scan_y; 
  int      scan_rx; 
  int      scan_ry; 
  short    fifo_typ;
  int      epx_div; 
  unsigned short  mod_type_code; 
  unsigned short  mod_fpga_ver;    // new in v.8.4
  float    overflow_corr_factor;
  int      adc_zoom; 
  int      cycles;        //  cycles ( accumulation cycles in FLOW mode ) 
  MeasStopInfo StopInfo;
  MeasFCSInfo  FCSInfo;   // valid only for FIFO meas
  int      image_x;       // 4 subsequent fields valid only for Camera mode
  int      image_y;       //     or FIFO_IMAGE mode
  int      image_rx; 
  int      image_ry; 
  short    xy_gain;       // gain for XY ADCs ( SPC930 )
  short    master_clock;  // use or not  Master Clock (SPC140 multi-module )
  short    adc_de;        // ADC sample delay ( SPC-930 )
  short    det_type;      // detector type ( SPC-930 in camera mode ) 
  short    x_axis;        // X axis representation ( SPC-930 ) 
  MeasHISTInfo  HISTInfo; // extension of FCSInfo, valid only for FIFO meas
  }MeasureInfo;



/*
   5- Data Blocks

With the software version 7.0  the data block header was changed to make possible 
  a higher number of data blocks and a variable block size.
Each data block can now contain a 'Data Set' i.e. the data of several curves 
  which were obtained in one measurement. 
The number and the location of  the data blocks is contained in the file header 
  at the beginning of the data file. 
The length of the block is contained in the block header.
The data block header contains the data block number, 
  the offset of the data block from the beginning of the file, 
  the offset to the next data block, 
  an information about the data in the block (measured block, block loaded from file, etc.), 
  and a reference to the corresponding measurement description block

The data block header structure is shown below.
*/


typedef struct {
   short          block_no;   // number of the block in the file
                         // valid only  when in 0 .. 0x7ffe range, otherwise use lblock_no field
                         // obsolete now, lblock_no contains full block no information                         
   long           data_offs;       // offset of the data block from the beginning of the file
   long           next_block_offs; // offset to the data block header of the next data block
   unsigned short block_type;      // see block_type defines below
   short          meas_desc_block_no; // Number of the measurement description block 
                                      //    corresponding to this data block
   unsigned long  lblock_no;       // long block_no - see remarks below 
   unsigned long  block_length;    // reserved2 now contains block( set ) length
   }BHFileBlockHeader;

//    ( MSB bit is 31, LSB bit is 0 )
//    The field block_no is obsolete
//    The field 'lblock_no' contains the data block / data set number in the bits 0 to 23 
//          and the module number (0 to 3) in the bits 24 to 25.
//
//    Block numbering start always from 1, so before calculating position in SPC memory 
//         ( or extracting FCS auto/cross rout. channels ) it should be at first decremented by 1
//    
//    for data set ( PAGE_BLOCK ) 
//           bits 0 - 23 represent number of the 1st block (decay curve) of the page
//
//    for FIFO_DATA 
//         bits 23 - 20   = block contents - the same as bits 4-7 in block_type
//                          ( starting from software version 8.3 )
//         for FIDA_BLOCK , FILDA_BLOCK, MCS_BLOCK and IMG_BLOCK
//             bits 7 - 0  represent routing channel number
//         for FCS_BLOCK bits 17 - 0  contain routing channel and module 
//                                      for auto and cross FCS
//             bits 17 - 16   = Cross FCS module number
//             bits 15 - 8    = rout. channel number   
//             bits  7 - 0    = Cross FCS rout. channel number   
//             when chan = cross_chan and mod == cross_mod - Auto FCS, 
//                           otherwise - Cross FCS


//////////
// defines for block type field in BHFileBlockHeader
/////////

// bits 0 - 3  in block_type define mode of creation

#define NOT_USED              0
#define MEAS_DATA             1   // normal measurement modes
#define FLOW_DATA             2   // continuos flow measurement ( BIFL )  
#define MEAS_DATA_FROM_FILE   3
#define CALC_DATA             4   // calculated data
#define SIM_DATA              5   // simulated data
#define FIFO_DATA             8   // FIFO mode data
#define FIFO_DATA_FROM_FILE   9   // FIFO mode data

// bits 4 - 7  in block_type define block contents 

#define DECAY_BLOCK    0x0     // one decay curve
#define PAGE_BLOCK     0x10    // set of decay curves = measured page
#define FCS_BLOCK      0x20    // FCS histogram curve                 
#define FIDA_BLOCK     0x30    // FIDA histogram curve                 
#define FILDA_BLOCK    0x40    // FILDA histogram curve                 
#define MCS_BLOCK      0x50    // MCS histogram curve                 
#define IMG_BLOCK      0x60    // fifo image - set of curves          


// bits 8 - 11 in block_type define data type      

#define DATA_USHORT           0x0     // 16-bit unsigned short
                                      //   (it was the only type up to 20.08.04)
#define DATA_ULONG            0x100   // 32-bit unsigned long, for FIFO decay vcurves                                 
#define DATA_DBL              0x200   // 32-bit double, for histogram data blocks 

// bits 12- 15 in block_type are not yet defined, reserved for future use
         
      // defines for page data sets
#define MEAS_PAGE             0x11
#define FLOW_PAGE             0x12
#define MEAS_PAGE_FROM_FILE   0x13
#define CALC_PAGE             0x14
#define SIM_PAGE              0x15



/*
 Data of the block
 for all blocks except FIFO_DATA ( FIFO_DATA_FROM_FILE ) ( bits 0 - 3  in block_type )
 
The data of the set specified by the block header is stored as shown below. 
It follows directly after the data block header:
  unsigned short  curvepoint[0][0]
  unsigned short  curvepoint[0] [1]
  . .
  . .             curvepoint[0] [adc_re -1]
  unsigned short  curvepoint[1][0]
  unsigned short  curvepoint[1] [1]
  . .
  .               curvepoint[1] [adc_re -1]
  .
  unsigned short  curvepoint[n][0]
  unsigned short  curvepoint[n] [1]
  . .
  .               curvepoint[n] [adc_re -1]


The photon numbers in each curve point are unsigned short integers, 
  i.e. values from 0 to 65,535. 
The number of curves in the data set depends on the measurement parameters, 
  e.g. measurement mode, no of routing bits etc. 
The number of curves in the block is equal to 
        'block_length' (from the block header) divided by 
        adc_resolution (from the corresponding measurement description block).
*/

/*

 Data of the block
 only for blocks FIFO_DATA ( FIFO_DATA_FROM_FILE ) ( bits 0 - 3  in block_type )
 for files created with software version > 8.2 

 Depending on bits 4 - 7  in block_type data block of type FIFO_DATA ( FIFO_DATA_FROM_FILE ) 
 can contain one decay curve or FCS, FIDA, FILDA histograms data. 
 For IMG_BLOCK it contains set of decay curves representing the image. 
 Decay curve contains adc_re points which are unsigned long integers ( 32-bit ).
 
 FCS histogram data contains results of FCS (auto or cross ) calculation for photons 
    collected in one routing channel.
    Number of FCS curve points is defined in coresponding measurement description 
    block in the field FCSInfo.fcs_points. 
    FCS calculation uses logaritmic binning therefore both time ( x ) and data ( y ) 
      values are required.
    At first FCSInfo.fcs_points values of FCS time in [µs] ( x scale ) are  given 
      and then FCSInfo.fcs_points values of FCS curve ( y scale ).
    Each FCS time and data point is a 8 byte double value.

 FIDA histogram data contains results of FIDA calculation for photons 
    collected in one routing channel.
    Number of FIDA curve points is defined in coresponding measurement description 
    block in the field HISTInfo.fida_points. 
    Each FIDA data point is a 8 byte double value.

 FILDA histogram data contains results of FILDA calculation for photons 
    collected in one routing channel.
    Number of FILDA curve points is defined in coresponding measurement description 
    block in the field HISTInfo.filda_points. 
    Each FILDA data point is a 8 byte double value.

 only for files created with software version > 8.3 
 MCS histogram data contains results of MCS calculation for photons 
    collected in one routing channel.
    Number of MCS curve points is defined in coresponding measurement description 
    block in the field HISTInfo.mcs_points. 
    Each MCS data point is a 4 byte unsigned long integer value.

 IMG_BLOCK data contains set of decay curves representing the image built from photons
    collected in one routing channel.
    Curve length is equal to adc_re from the corresponding measurement description block
    The number of curves in the block is equal to 
        'block_length' (from the block header) divided by 
         adc resolution (adc_re from the corresponding measurement description block) 
         and is normally equal to image_x * image_y
    The photon numbers in each curve point are unsigned short integers, 
      i.e. values from 0 to 65,535. 
 
  /////////////////////////////////////////////////////
 only for files created with software v. 8.1 - 8.2 
 Data of the block
 only for blocks FIFO_DATA ( FIFO_DATA_FROM_FILE ) ( bits 0 - 3  in block_type )

  Data block of type FIFO_DATA ( FIFO_DATA_FROM_FILE ) contains one decay curve
   as described above ( 16-bit unsigned short integers). 
   After the last curvepoint FCS curve is stored which contains results of 
    FCS (auto or cross ) calculation for photons collected in one routing channel.
  Number of FCS curve points is defined in coresponding measurement description 
   block in the field FCSInfo.fcs_points. 
  FCS calculation uses logaritmic binning therefore both time ( x ) and data ( y ) 
   values are required.
  At first FCSInfo.fcs_points values of FCS time in [µs] ( x scale ) are  given 
    and then FCSInfo.fcs_points values of FCS curve ( y scale ).
  Each FCS time and data point is a 8 byte double value.
  /////////////////////////////////////////////////////

*/



/////////////////////////////////////////////////////////////////////////
////////////         .spc  files structure       ////////////////////////
/////////////////////////////////////////////////////////////////////////

/*

Measurements in the FIFO mode generate one or several a photon data file files
  ( with extension .spc ) containing the micro times, the macro times, 
  and the detector channel numbers of the individual photons. 
  
  Moreover, a FIFO measurement generates a setup file ( .set) that contains 
    the hardware and software setup parameters used. Structure of the setup file 
    is described above.
*/


////////////////////////////////////////////////////////////////////////////
///    FIFO Data Files (SPC-600/630, 4096 Channel Mode, 48-bit photon frame)
////////////////////////////////////////////////////////////////////////////

/*

The information about the subsequent photons is stored one after another 
 in the measurement data file. 
 For each photon 6 bytes are used. 
 The structure of these data is shown in the table below.
 
           Bit 7   Bit 6   Bit 5   Bit 4   Bit 3   Bit 2   Bit 1   Bit 0
------------------------------------------------------------------------         
Byte 0    ADC[7]  ADC[6]  ADC[5]  ADC[4]  ADC[3]  ADC[2]  ADC[1]  ADC[0]
Byte 1    0       GAP     MTOV   INVALID  ADC[11] ADC[10] ADC[9]  ADC[8]
Byte 2    MT[23]  MT[22]  MT[21]  MT[20]  MT[19]  MT[18]  MT[17]  MT[16]
Byte 3    R[7]    R[6]    R[5]    R[4]    R[3]    R[2]    R[1]    R[0]
Byte 4    MT[7]   MT[6]   MT[5]   MT[4]   MT[3]   MT[2]   MT[1]   MT[0]
Byte 5    MT[15]  MT[14]  MT[13]  MT[12]  MT[11]  MT[10]  MT[9]   MT[8]

ADC[11:0]    ADC Data (reversed Micro Time)
             Due to reversed start-stop acquisition mode used in all SPC modules 
             real Micro Time = 4095 - ADC
R [7:0]      Routing Signals (inverted)
MT[23:0]     Macro Time [in 50ns intervals]
GAP          1 = Possible recording gap due to FIFO Full. 
             There may be (and most likely is) a gap in the re-cording preceding
               this photon.
MTOV         1 = Macro Timer Overflow. 
             Since the capacity of the macro timer is limited to 24 bit 
             it will overflow every 2**24 × 50 ns. 
             The software which processes the data file has to add these 2**24 × 50 ns 
             to its internal macro time value on each MTOV =1.
INVALID      1 = Data Invalid. All data for this photon except the MTOV bit is invalid. 
             The INVALID bit is set if the 'Count Enable' bit at the SPC routing connector was '0',
              i.e. if a router is connected and there is no valid routing information 
              for this photon.

The first photon frame (6 bytes) in the .spc file is added by the software and contains information 
about the Macro Time clock and the number of routing channels used during the measurement:
  byte 1 : bit 4 = 1 ( Invalid photon ),  bits 3-0 = number of routing bits
  byte 2 and 3  = macro time clock in 0.1 ns units ( for 50ns value 500 is set )
  byte 5 and 6  = 0
  
when programming, the most convenient way is to treat  the  photon frame as 3 16-bit words

1st data word - Byte 1 ( bits 15-8 ), Byte 0 ( bits 7-0 )
2nd data word - Byte 3 ( bits 15-8 ), Byte 2 ( bits 7-0 )
3rd data word - Byte 5 ( bits 15-8 ), Byte 5 ( bits 7-0 )

*/

 //  0x1000000 * 50e-9, macro time overflow  for SPC-6x0 in 48-bit mode
#define OV_TIME48      0.8388608 
   // masks for 1st word,  SPC-6x0 in 48-bit mode 
#define MTOV48        0x2000     // Macro Time overflow 
#define OVRUN48       0x4000     // Fifo overrun, recording gap
#define INVALID48     0x1000     // Invalid entry

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////
///    FIFO Data Files (SPC-600/630, 256 Channel Mode, 32-bit photon frame)
/////////////////////////////////////////////////////////////////////////

/*

The information about the subsequent photons is stored one after another 
 in the measurement data file. For each photon 4 bytes are used. 
 The structure of these data is shown in the table below.

           Bit 7    Bit 6    Bit 5    Bit 4    Bit 3    Bit 2    Bit 1    Bit 0
-------------------------------------------------------------------------------         
Byte 0     ADC[7]   ADC[6]   ADC[5]   ADC[4]   ADC[3]   ADC[2]   ADC[1]   ADC[0]
Byte 1     MT[7]    MT[6]    MT[5]    MT[4]    MT[3]    MT[2]    MT[1]    MT[0]
Byte 2     MT[15]   MT[14]   MT[13]   MT[12]   MT[11]   MT[10]   MT[9]    MT[8]
Byte 3     INVALID  MTOV     GAP      0        R[2]     R[1]     R[0]     MT[16]

ADC[7:0]     ADC Data (reversed Micro Time) 
             Due to reversed start-stop acquisition mode used in all SPC modules 
             real Micro Time = 255 - ADC
R [2:0]      Routing Signals (inverted)
MT[16:0]     Macro Time [in 50ns intervals]
GAP          1 = Possible recording gap due to FIFO Full. 
             There may be (and most likely is) a gap in the re-cording preceding
               this photon.
MTOV         1 = Macro Timer Overflow. 
             Since the capacity of the macro timer is limited to 17 bit 
             it will overflow every 2**17 × 50 ns. 
             The software which processes the data file has to add these 2**17 × 50 ns 
             to its internal macro time value on each MTOV = 1.
INVALID      1 = Data Invalid. All data for this photon except the MTOV bit is invalid. 
             The INVALID bit is set if the 'Count Enable' bit at the SPC routing connector was '0',
              i.e. if a router is connected and there is no valid routing information 
              for this photon.

The INVALID bit is used to mark photons for which no correct detector channel number, 
   micro time, or macro time could be determined. 
   This happens if several detectors in a multi-detector system detected photons within 
   the response time of the routing electronics, the sum of the TAC output and the dither signal
   was outside the conversion range of the ADC, or in the (very unlikely) case 
   that a photon appears within the generation of a macro time overflo entry (see below). 
   
The first photon frame (4 bytes) in the .spc file is added by the software and 
  contains information about the Macro Time clock and the number of routing channels 
  used during the measurement:
  byte 0,1,2    = macro time clock in 0.1 ns units ( for 50ns value 500 is set )
  byte 3 : bit 7 = 1 ( Invalid photon ),  bits 3-6 = number of routing bits, 
           bits 0-2 reserved


Macro Time Overflows
Due to the high macro time resolution and the limited number of macro time bits 
  a macro time overflow occurs every 6.5536 ms. 
  In most cases a photon will be recorded within this time. 
  The ocurrance of  a single macro time overflow is then marked by the 'MTOV' bit of the next valid photon.
  However, for low count rates it may happen that several macro time overflows occur 
  between subsequent photons. 
  In this case an entry in the FIFO file is generated that contains the number of overflows 
  since the last photon was recorded. 
  This entry is marked by 'MTOV = 1' and 'INVALID = 1'. 
  The structure of  this entry is shown below.

           Bit 7    Bit 6    Bit 5    Bit 4    Bit 3    Bit 2    Bit 1    Bit 0
-------------------------------------------------------------------------------         
Byte 0    CNT[7]   CNT[6]   CNT[5]   CNT[4]   CNT[3]   CNT[2]   CNT[1]   CNT[0]
Byte 1    CNT[15]  CNT[14]  CNT[13]  CNT[12]  CNT[11]  CNT[10]  CNT[9]   CNT[8]
Byte 2    CNT[23]  CNT[23]  CNT[21]  CNT[20]  CNT[19]  CNT[18]  CNT[17]  CNT[16]
Byte 3    INVALID  MTOV     0        0        CNT[27]  CNT[26]  CNT[25]  CNT[24]

CNT[27:0] Number of macro time overflows which occurred without recording photons

when programming, the photon frame is treated as one 32-bit word

*/

 //  0x20000 * 50e-9, macro time overflow  for SPC-6x0 in 32-bit mode
#define OV_TIME6_32    0.0065536 

  // masks for different parts of the frame
#define INVALID6_32        0x80000000   // Invalid
#define MTOV6_32           0x40000000   // Macro time overflow
#define INVALID_MTOV6_32   0xc0000000   // Invalid + Macro time overflow
#define OVRUN6_32          0x20000000   // Fifo overrun, recording gap
#define ROUT6_32           0x07000000   // Routing signals( inverted )
#define MT6_32             0x01ffff00   // Macro time
#define ADC6_32            0xff         // ADC value 

  // masks for the 1st frame in .spc file
#define RB_NO6_32          0x78000000   // routing bits number used during measurement  
#define MT_CLK6_32         0x00ffffff   // macro time clock in 0.1 ns units
#define R_FILE6_32         0x04000000   // file with raw data ( diagnostic mode only )


////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////
///    FIFO Data Files (SPC-130, SPC140, SPC830 )
//////////////////////////////////////////////////////////////

/*

The information about the subsequent photons is stored one after another 
 in the measurement data file. For each photon 4 bytes are used. 
 The structure of these data is shown in the table below.

           Bit 7    Bit 6    Bit 5    Bit 4    Bit 3    Bit 2    Bit 1    Bit 0
-------------------------------------------------------------------------------         
Byte 0     MT[7]    MT[6]    MT[5]    MT[4]    MT[3]    MT[2]    MT[1]    MT[0]
Byte 1     R[3]     R[2]     R[1]     R[0]     MT[11]   MT[10]   MT[9]    MT[8]
Byte 2     ADC[7]   ADC[6]   ADC[5]   ADC[4]   ADC[3]   ADC[2]   ADC[1]   ADC[0]
Byte 3     INVALID  MTOV     GAP      0        ADC[11]  ADC[10]  ADC[9]   ADC[8]

ADC[11:0]  ADC Data (reversed Micro Time) 
           Due to reversed start-stop acquisition mode used in all SPC modules 
             real Micro Time = 4095 - ADC
R [3:0]    Routing Signals (inverted). 
           Bit 3 is not available for early SPC-130/134 modules
MT[16:0]   Macro Time (50 ns intervals for internal Macro time oscillator, 
                        for Sync clock see below)
GAP        1 = Possible recording gap due to FIFO Full. 
           There may be (and most likely is) a gap in the re-cording preceding
             this photon.
MTOV       1 = Macro Timer Overflow. 
           Since the capacity of the macro timer is limited to 12 bit 
           it will overflow every 2**12th macro time period. 
           For the internal macro time clock of 50 ns overflows occur every 204.8 µs. 
           For synchronisation of the macro-time clock with the SYNC signal 
             this interval may even be shorter. 
           Therefore there may even be multiple overflows without any photons detected (see below).
           The software which processes the data file has to add the times 
             between overflows to its internal macro time value on each MTOV =1
INVALID    1 = Data Invalid. All data for this photon except the MTOV bit is invalid. 
           The INVALID bit is set if the 'Count Enable' bit at the SPC routing connector was '0',
            i.e. if a router is connected and there is no valid routing information 
            for this photon.

The INVALID bit is used to mark photons for which no correct detector channel number, 
   micro time, or macro time could be determined. 
   This happens if several detectors in a multi-detector system detected photons within 
   the response time of the routing electronics, the sum of the TAC output and the dither signal
   was outside the conversion range of the ADC, or in the (very unlikely) case 
   that a photon appears within the generation of a macro time overflo entry (see below). 
   
The first photon frame (4 bytes) in the .spc file is added by the software and contains information 
about the Macro Time clock and the number of routing channels used during the measurement:
  byte 0,1,2    = macro time clock in 0.1 ns units ( for 50ns value 500 is set )
  byte 3 : bit 7 = 1 ( Invalid photon ),  bits 3-6 = number of routing bits, 
           bit 2 = 1 file with raw data ( for diagnostic mode only, 
                     such file contains pure data read from FIFO without special meaning 
                       of the entries with 'MTOV = 1' and 'INVALID = 1' described below )
           bit 1 = 1 file with markers ( new SPC-140, SPC-150, see below)
           bit 0 reserved  

Internal Macro Time Clock is equal 50ns for all modules.
The only exception is the newest SPC-140 ( FPGA v. > B0 ) and SPC-150, where it is equal 25 ns.

Macro Time Overflows
  Since the capacity of the macro timer is limited to 12 bit it will overflow 
   at each 2**12-th macro time period. 
  In most cases the overflow is marked by the 'MTOV' bit of the next valid photon. 
  However, the internal macro time clock of 50 ns overflows occur every 204.8 µs.
  For synchronisation of the macro-time clock with the SYNC signal this interval may 
    even be shorter. 
  Therefore, it can happen that no valid photon is recorded between two subsequent 
    macro time overflows. 
  To enable the processing software to maintain a correct macro time for 
    the rest of the measurement an entry in the measurement data file is written 
    if several overflows occurred between two subsequent photons. 
  This entry is marked by 'MTOV = 1' and 'INVALID = 1' and contains 
   the number of macro time overflows which occurred since the last photon was recorded.

  The structure of  this entry is shown below.

           Bit 7    Bit 6    Bit 5    Bit 4    Bit 3    Bit 2    Bit 1    Bit 0
-------------------------------------------------------------------------------         
Byte 0    CNT[7]   CNT[6]   CNT[5]   CNT[4]   CNT[3]   CNT[2]   CNT[1]   CNT[0]
Byte 1    CNT[15]  CNT[14]  CNT[13]  CNT[12]  CNT[11]  CNT[10]  CNT[9]   CNT[8]
Byte 2    CNT[23]  CNT[23]  CNT[21]  CNT[20]  CNT[19]  CNT[18]  CNT[17]  CNT[16]
Byte 3    INVALID  MTOV     0        0        CNT[27]  CNT[26]  CNT[25]  CNT[24]

CNT[27:0] Number of macro time overflows which occurred without recording photons

when programming, the photon frame is treated as one 32-bit word

*/

 //  0x1000 * 50e-9, macro time overflow with internal macro time clock
#define OV_TIME32      0.0002048 

  // masks for different parts of the frame
#define INVALID32        0x80000000   // Invalid
#define MTOV32           0x40000000   // Macro time overflow
#define INVALID_MTOV32   0xc0000000   // Invalid + Macro time overflow
#define OVRUN32          0x20000000   // Fifo overrun, recording gap
#define ROUT32           0xf000       // Routing signals( inverted )
#define MT32             0xfff        // Macro time
#define ADC32            0x0fff0000   // ADC value 


  // masks for the 1st frame in .spc file
#define RB_NO32          0x78000000   // routing bits number used during measurement  
#define MT_CLK32         0x00ffffff   // macro time clock in 0.1 ns units
#define M_FILE32         0x02000000   // file with markers
#define R_FILE32         0x04000000   // file with raw data ( diagnostic mode only )


/////////////////////////////////////////////////////////////////////////
///  additional information for  FIFO Data Files with markers
/////////////////////////////////////////////////////////////////////////

/*

The newest SPC-140 ( FPGA v. > B0 ) and SPC-150 can work in FIFO_IMAGE mode.
Internal macro time clock for this module is equal 25 ns.

In this mode  not only photons are collected in the module's FIFO, 
  but also markers entries. 
 Marker entries are created from external Frame, Line and Pixel clocks pulses.
 Marker entries contain valid macro time information. 
  ADC[11:0] is currently set to 0xfff, R0-3 bits contain marker's type

Markers can be used also in normal FIFO mode ( newest SPC-140 ( FPGA v. > B0 ) and SPC-150 )
Up to four user defined events can be recorded in this way together with normal photons.

To record markers in FIFO mode enable used markers' inputs in 
   System Parameters->MoreParameters window when FIFO mode is chosen


.spc files with markers are recognized by flag M_FILE32 set in the 1st file frame.

The structure of the marker frame is shown in the table below.

           Bit 7    Bit 6    Bit 5    Bit 4    Bit 3    Bit 2    Bit 1    Bit 0
-------------------------------------------------------------------------------         
Byte 0     MT[7]    MT[6]    MT[5]    MT[4]    MT[3]    MT[2]    MT[1]    MT[0]
Byte 1     M[3]     M[2]     M[1]     M[0]     MT[11]   MT[10]   MT[9]    MT[8]
Byte 2     1        1        1        1        1        1        1        1     
Byte 3     1        MTOV     GAP      1        1        1        1        1     

M [3:0]   Marker's type:
          M[0] = 1   Marker0 = Pixel Clock Marker
          M[1] = 1   Marker1 = Line  Clock Marker
          M[2] = 1   Marker2 = Frame Clock Marker
          M[3] = 1   Marker3, not used in FIFO_IMAGE mode, user defined

It can happen that in the same frame more than 1 marker M[] bits are set.
It would mean that different external clock pulses appeared in the current
  macro time period
*/

  // masks for markers frames

#define MARKER0       0x90001000      
#define MARKER1       0x90002000    
#define MARKER2       0x90004000    
#define MARKER3       0x90008000   

#define P_MARK32      MARKER0   // pixel marker 
#define L_MARK32      MARKER1   // line  marker 
#define F_MARK32      MARKER2   // frame marker 






//////////////////////////////////////////////////////////////
///    FIFO Data Files (DPC-230 )
//////////////////////////////////////////////////////////////
/*
           DPC-230 file format
A DPC-230 .spc file created by Becker & Hickl SPCM software consists of a sequence 
  of 32 bit records. 
The byte order shown is the byte order in the file.
-------------------------------------------------------------------------------
  Byte 0  1. Record = Descriptor  Bits [7:0]
  Byte 1                          Bits [15:8]
  Byte 2                          Bits [23:16]
  Byte 3                          Bits [31:24]
-------------------------------------------------------------------------------
  Byte 0  2. Record               Bits [7:0]
  Byte 1                          Bits [15:8]
  Byte 2                          Bits [23:16]
  Byte 3                          Bits [31:24]
-------------------------------------------------------------------------------

The first record is a descriptor which identifies DPC-230 files and defines the time unit. 

Descriptor

  Bit 31  Bit 30  Bit 29  Bit 28  Bit 27  Bit 26  Bit 25  Bit 24
     1       1       0       0       0     RAW       0       1

  Bit 23  Bit 22  Bit 21  Bit 20  Bit 19  Bit 18  Bit 17  Bit 16
  TPB[23] TPB[22] TPB[21] TPB[20] TPB[19] TPB[18] TPB[17] TPB[16]

  Bit 15  Bit 14  Bit 13  Bit 12  Bit 11  Bit 10  Bit 9 Bit 8
  TPB[15] TPB[14] TPB[13] TPB[12] TPB[11] TPB[10] TPB[9]  TPB[8]

  Bit 7   Bit 6   Bit 5   Bit 4   Bit 3   Bit 2   Bit 1   Bit 0
  TPB[7]  TPB[6]  TPB[5]  TPB[4]  TPB[3]  TPB[2]  TPB[1]  TPB[0]

RAW = 1 This file contains raw (=not processed) data - used for hardware debugging only. 
    = 0  processed data - only this file format is described here.

TPB[23:0] Time per bin. 
    This is the time unit for this file. All times are expressed in multiples of this unit.
    TPB is expressed in femto seconds (1 fs = 10-15 s)  
    
    
All events are recorded with their channel number and a 54 bit integer time stamp. 
The time stamp reflects the absolute time from the start of the measurement. 
The time unit is the TPB entry in the descriptor (see above). 
To save disk space an event is stored with the lower 24 bit of the time stamp only. 
To be able to reconstruct the complete time stamp another type of records 
  is defined: TIME[53:24]. This record does not decribe events. 
  It is a command to set the high part of the event time.  
Both parts TIME[53:24] and TIME[23:0] (contained in the Event Record) 
    together are the complete time stamp of an event. 

-------------------------------------------------------------------------------
Record Types
-------------------------------------------------------------------------------
  Bit 31  Bit 30  Type         Description
     0       0    Event        Low Part of Time [TPB] incl. channel number
     0       1    TIME[53:24]  Set middle part of Time to TIME[53:24]
     1       0    reserved     reserved
     1       1    Special      Currently only Descriptor at start of file

-------------------------------------------------------------------------------
Event Record
-------------------------------------------------------------------------------
  Bit 31  Bit 30  Bit 29  Bit 28  Bit 27  Bit 26  Bit 25  Bit 24
     0       0      GAP    Ch[4]   CH[3]   CH[2]   CH[1]   CH[0]

  Bit 23    Bit 22    Bit 21    Bit 20    Bit 19    Bit 18    Bit 17    Bit 16
  TIME[23]  TIME[22]  TIME[21]  TIME[20]  TIME[19]  TIME[18]  TIME[17]  TIME[16]

  Bit 15    Bit 14    Bit 13    Bit 12    Bit 11    Bit 10    Bit 9     Bit 8
  TIME[15]  TIME[14]  TIME[13]  TIME[12]  TIME[11]  TIME[10]  TIME[9]   TIME[8]

  Bit 7     Bit 6     Bit 5     Bit 4     Bit 3     Bit 2     Bit 1     Bit 0
  TIME[7]   TIME[6]   TIME[5]   TIME[4]   TIME[3]   TIME[2]   TIME[1]   TIME[0]

  GAP         - Data lost before this entry due to full FIFO (1) / no gap occurred (0)
  CH[4:0]     - Channel Number
  TIME[23:0]  - Event Time [TPB] - low part


-------------------------------------------------------------------------------
TIME[53:24] Record
-------------------------------------------------------------------------------
  Bit 31    Bit 30    Bit 29    Bit 28    Bit 27    Bit 26    Bit 25    Bit 24
     0         1      TIME[53]  TIME[52]  TIME[51]  TIME[50]  TIME[49]  TIME[48]

  Bit 23    Bit 22    Bit 21    Bit 20    Bit 19    Bit 18    Bit 17    Bit 16
  TIME[47]  TIME[46]  TIME[45]  TIME[44]  TIME[43]  TIME[42]  TIME[41]  TIME[40]

  Bit 15    Bit 14    Bit 13    Bit 12    Bit 11    Bit 10    Bit 9     Bit 8
  TIME[39]  TIME[38]  TIME[37]  TIME[36]  TIME[35]  TIME[34]  TIME[33]  TIME[32]

  Bit 7     Bit 6     Bit 5     Bit 4     Bit 3     Bit 2     Bit 1     Bit 0
  TIME[31]  TIME[30]  TIME[29]  TIME[28]  TIME[27]  TIME[26]  TIME[25]  TIME[24]

TIME[53:24] Set Event Time [TPB] - high part

*/
