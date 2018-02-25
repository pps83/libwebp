#ifdef _MSC_VER
#pragma warning(disable: 4244) // conversion from 'int' to 'uint8_t', possible loss of data
#endif

#include "src/dec/alpha_dec.c"
#include "src/dec/buffer_dec.c"
#include "src/dec/frame_dec.c"
#include "src/dec/idec_dec.c"
#include "src/dec/io_dec.c"
#include "src/dec/quant_dec.c"
#include "src/dec/tree_dec.c"
#include "src/dec/vp8l_dec.c"
#include "src/dec/vp8_dec.c"
#include "src/dec/webp_dec.c"

#include "src/demux/anim_decode.c"

#define MemBuffer MemBuffer_demux
#define RemapMemBuffer RemapMemBuffer_demux
#define InitMemBuffer InitMemBuffer_demux
#define MemDataSize MemDataSize_demux
#define ParseVP8X ParseVP8X_demux
#include "src/demux/demux.c"
#undef MemBuffer
#undef RemapMemBuffer
#undef InitMemBuffer
#undef MemDataSize
#undef ParseVP8X


#include "src/dsp/alpha_processing.c"
#include "src/dsp/alpha_processing_mips_dsp_r2.c"
#include "src/dsp/alpha_processing_neon.c"
#include "src/dsp/alpha_processing_sse2.c"
#include "src/dsp/alpha_processing_sse41.c"
#include "src/dsp/cost.c"
#include "src/dsp/cost_mips32.c"
#include "src/dsp/cost_mips_dsp_r2.c"
#include "src/dsp/cost_sse2.c"
#include "src/dsp/cpu.c"
#include "src/dsp/dec.c"
#include "src/dsp/dec_clip_tables.c"
#include "src/dsp/dec_mips32.c"
#include "src/dsp/dec_mips_dsp_r2.c"
#include "src/dsp/dec_msa.c"
#include "src/dsp/dec_neon.c"
#include "src/dsp/dec_sse2.c"
#include "src/dsp/dec_sse41.c"

#define clip_8b clip_8b_enc
#define clip1 clip1_enc
#define TrueMotion TrueMotion_enc
#define kZigzag kZigzag_enc
#define Put8x8uv_SSE2 Put8x8uv_SSE2_enc
#define Put16_SSE2 Put16_SSE2_enc
#define VE8uv_SSE2 VE8uv_SSE2_enc
#define VE16_SSE2 VE16_SSE2_enc
#define HE16_SSE2 HE16_SSE2_enc
#define TrueMotion_SSE2 TrueMotion_SSE2_enc
#define DC8uv_SSE2 DC8uv_SSE2_enc
#define DC8uvNoLeft_SSE2 DC8uvNoLeft_SSE2_enc
#define DC8uvNoTop_SSE2 DC8uvNoTop_SSE2_enc
#define DC8uvNoTopLeft_SSE2 DC8uvNoTopLeft_SSE2_enc
#define DC16_SSE2 DC16_SSE2_enc
#define DC16NoLeft_SSE2 DC16NoLeft_SSE2_enc
#define DC16NoTop_SSE2 DC16NoTop_SSE2_enc
#define DC16NoTopLeft_SSE2 DC16NoTopLeft_SSE2_enc
#define VE4_SSE2 VE4_SSE2_enc
#define LD4_SSE2 LD4_SSE2_enc
#define VR4_SSE2 VR4_SSE2_enc
#define VL4_SSE2 VL4_SSE2_enc
#define RD4_SSE2 RD4_SSE2_enc
#define TM4_SSE2 TM4_SSE2_enc
#include "src/dsp/enc.c"

#include "src/dsp/enc_avx2.c"
#include "src/dsp/enc_mips32.c"
#include "src/dsp/enc_mips_dsp_r2.c"
#include "src/dsp/enc_msa.c"
#define kC1 kC1_enc_neon
#define kC2 kC2_enc_neon
#define ConvertU8ToS16_NEON ConvertU8ToS16_NEON_enc_neon
#define SaturateAndStore4x4_NEON SaturateAndStore4x4_NEON_enc_neon
#define Add4x4_NEON Add4x4_NEON_enc_neon
#define Transpose8x2_NEON Transpose8x2_NEON_enc_neon
#define TransformPass_NEON TransformPass_NEON_enc_neon
#include "src/dsp/enc_neon.c"
#undef kC1
#undef nC2
#undef ConvertU8ToS16_NEON
#undef SaturateAndStore4x4_NEON
#undef Add4x4_NEON
#undef Transpose8x2_NEON
#undef TransformPass_NEON
#include "src/dsp/enc_sse2.c"
#include "src/dsp/enc_sse41.c"
#include "src/dsp/filters.c"
#include "src/dsp/filters_mips_dsp_r2.c"
#include "src/dsp/filters_msa.c"
#define GradientPredictor_C GradientPredictor_C_filters_neon
#include "src/dsp/filters_neon.c"
#undef GradientPredictor_C
#include "src/dsp/filters_sse2.c"
#include "src/dsp/lossless.c"
#define ColorTransformDelta ColorTransformDelta_lossless_enc
#define Average2 Average2_lossless_enc
#define Average3 Average3_lossless_enc
#define Average4 Average4_lossless_enc
#define Clip255 Clip255_lossless_enc
#define AddSubtractComponentFull AddSubtractComponentFull_lossless_enc
#define ClampedAddSubtractFull ClampedAddSubtractFull_lossless_enc
#define AddSubtractComponentHalf AddSubtractComponentHalf_lossless_enc
#define ClampedAddSubtractHalf ClampedAddSubtractHalf_lossless_enc
#define Sub3 Sub3_lossless_enc
#define Select Select_lossless_enc
#define Average2_m128i Average2_m128i_lossless_enc
#include "src/dsp/lossless_enc.c"
#include "src/dsp/lossless_enc_mips32.c"
#include "src/dsp/lossless_enc_mips_dsp_r2.c"
#include "src/dsp/lossless_enc_msa.c"
#include "src/dsp/lossless_enc_neon.c"
#undef Average2_m128i
#define Average2_m128i Average2_m128i_lossless_enc_sse2
#include "src/dsp/lossless_enc_sse2.c"
#include "src/dsp/lossless_enc_sse41.c"
#include "src/dsp/lossless_mips_dsp_r2.c"
#include "src/dsp/lossless_msa.c"
#define kGreenShuffle kGreenShuffle_lossless_neon
#define DoGreenShuffle_NEON DoGreenShuffle_NEON_lossless_neon
#include "src/dsp/lossless_neon.c"
#undef kGreenShuffle
#undef DoGreenShuffle_NEON
#undef Average2_m128i
#define Average2_m128i Average2_m128i_lossless_sse2
#include "src/dsp/lossless_sse2.c"
#include "src/dsp/rescaler.c"
#include "src/dsp/rescaler_mips32.c"
#include "src/dsp/rescaler_mips_dsp_r2.c"
#include "src/dsp/rescaler_msa.c"
#include "src/dsp/rescaler_neon.c"
#include "src/dsp/rescaler_sse2.c"
#include "src/dsp/ssim.c"
#define kWeight kWeight_ssim_sse2
#include "src/dsp/ssim_sse2.c"
#include "src/dsp/upsampling.c"
#include "src/dsp/upsampling_mips_dsp_r2.c"
#include "src/dsp/upsampling_msa.c"
#include "src/dsp/upsampling_neon.c"
#include "src/dsp/upsampling_sse2.c"
#include "src/dsp/upsampling_sse41.c"
#include "src/dsp/yuv.c"
#include "src/dsp/yuv_mips32.c"
#include "src/dsp/yuv_mips_dsp_r2.c"
#include "src/dsp/yuv_neon.c"
#define clip_y clip_y_yuv_sse2
#include "src/dsp/yuv_sse2.c"
#include "src/dsp/yuv_sse41.c"


#define clip clip_enc
#define DoFilter DoFilter_enc
#define clip_y_yuv_sse2 clip_y_yuv_sse2_enc
#include "src/enc/alpha_enc.c"
#include "src/enc/analysis_enc.c"
#include "src/enc/backward_references_cost_enc.c"
#include "src/enc/backward_references_enc.c"
#include "src/enc/config_enc.c"
#include "src/enc/cost_enc.c"
#include "src/enc/filter_enc.c"
#include "src/enc/frame_enc.c"
#include "src/enc/histogram_enc.c"
#include "src/enc/iterator_enc.c"
#include "src/enc/near_lossless_enc.c"
#undef clip_8b
#define clip_8b clip_8b_picture_csp_enc
#include "src/enc/picture_csp_enc.c"
#include "src/enc/picture_enc.c"
#define GetPSNR GetPSNR_picture_psnr_enc
#include "src/enc/picture_psnr_enc.c"
#include "src/enc/picture_rescale_enc.c"
#define MakeARGB32 MakeARGB32_picture_tools_enc
#include "src/enc/picture_tools_enc.c"
#define NearLossless NearLossless_predictor_enc
#define ColorCodeToMultipliers ColorCodeToMultipliers_predictor_enc
#include "src/enc/predictor_enc.c"

#undef clip
#undef kZigzag
#undef MAX_ALPHA
#define clip clip_quant_enc
#define kZigzag kZigzag_quant_enc
#define kDcTable kDcTable_quant_enc
#define kAcTable kAcTable_quant_enc
#include "src/enc/quant_enc.c"
#include "src/enc/syntax_enc.c"
#include "src/enc/token_enc.c"
#define kBModesProba kBModesProba_tree_enc
#include "src/enc/tree_enc.c"
#include "src/enc/vp8l_enc.c"
#undef GetPSNR
#define ResetSegmentHeader ResetSegmentHeader_webp_enc
#define GetPSNR GetPSNR_webp_enc
#include "src/enc/webp_enc.c"

#undef clip
#define GetFrame GetFrame_anim_encode
#define clip clip_anim_encode
#define SetFrame SetFrame_anim_encode
#include "src/mux/anim_encode.c"
#include "src/mux/muxedit.c"
#include "src/mux/muxinternal.c"
#include "src/mux/muxread.c"


#include "src/utils/bit_reader_utils.c"
#include "src/utils/bit_writer_utils.c"
#include "src/utils/color_cache_utils.c"
#include "src/utils/filters_utils.c"
#include "src/utils/huffman_encode_utils.c"
#include "src/utils/huffman_utils.c"
#undef clip_8b
#define clip_8b clip_8b_quant_levels_utils
#include "src/utils/quant_levels_dec_utils.c"
#include "src/utils/quant_levels_utils.c"
#include "src/utils/random_utils.c"
#include "src/utils/rescaler_utils.c"
#include "src/utils/thread_utils.c"
#include "src/utils/utils.c"
