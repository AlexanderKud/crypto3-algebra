//---------------------------------------------------------------------------//
// Copyright (c) 2020 Mikhail Komarov <nemo@nil.foundation>
// Copyright (c) 2020 Nikita Kaskov <nbering@nil.foundation>
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//---------------------------------------------------------------------------//

#ifndef CRYPTO3_ALGEBRA_FIELDS_ALT_BN128_FP12_2OVER3OVER2_EXTENSION_PARAMS_HPP
#define CRYPTO3_ALGEBRA_FIELDS_ALT_BN128_FP12_2OVER3OVER2_EXTENSION_PARAMS_HPP

#include <nil/crypto3/algebra/fields/params.hpp>
#include <nil/crypto3/algebra/fields/alt_bn128/base_field.hpp>
#include <nil/crypto3/algebra/fields/fp6_3over2.hpp>
#include <nil/crypto3/algebra/fields/fp2.hpp>

#include <nil/crypto3/algebra/detail/literals.hpp>

namespace nil {
    namespace crypto3 {
        namespace algebra {
            namespace fields {
                namespace detail {

                    using namespace nil::crypto3::algebra;

                    template<typename FieldType>
                    struct fp12_2over3over2_extension_params;

                    /************************* ALT_BN128 ***********************************/

                    template<std::size_t ModulusBits, std::size_t GeneratorBits>
                    class fp12_2over3over2_extension_params<fields::alt_bn128<ModulusBits, GeneratorBits>>
                        : public params<fields::alt_bn128<ModulusBits, GeneratorBits>> {

                        typedef fields::alt_bn128<ModulusBits, GeneratorBits> base_field_type;
                        typedef params<base_field_type> policy_type;

                    public:
                        typedef typename policy_type::number_type number_type;
                        typedef typename policy_type::modulus_type modulus_type;

                        constexpr static const modulus_type modulus = policy_type::modulus;

                        typedef fields::fp2<base_field_type> non_residue_field_type;
                        typedef typename non_residue_field_type::value_type non_residue_type;
                        typedef fields::fp6_3over2<base_field_type> underlying_field_type;
                        typedef typename underlying_field_type::value_type underlying_type;

                        /*constexpr static const std::array<non_residue_type, 12> Frobenius_coeffs_c1 =
                           {non_residue_type(0x01, 0x00),
                            non_residue_type(0x1284B71C2865A7DFE8B99FDD76E68B605C521E08292F2176D60B35DADCC9E470_cppui253,
                           0x246996F3B4FAE7E6A6327CFE12150B8E747992778EEEC7E5CA5CF05F80F362AC_cppui254),
                            non_residue_type(0x30644E72E131A0295E6DD9E7E0ACCCB0C28F069FBB966E3DE4BD44E5607CFD49_cppui254,
                           0x00),
                            non_residue_type(0x19DC81CFCC82E4BBEFE9608CD0ACAA90894CB38DBE55D24AE86F7D391ED4A67F_cppui253,
                           0xABF8B60BE77D7306CBEEE33576139D7F03A5E397D439EC7694AA2BF4C0C101_cppui248),
                            non_residue_type(0x30644E72E131A0295E6DD9E7E0ACCCB0C28F069FBB966E3DE4BD44E5607CFD48_cppui254,
                           0x00),
                            non_residue_type(0x757CAB3A41D3CDC072FC0AF59C61F302CFA95859526B0D41264475E420AC20F_cppui251,
                           0xCA6B035381E35B618E9B79BA4E2606CA20B7DFD71573C93E85845E34C4A5B9C_cppui252),
                            non_residue_type(0x30644E72E131A029B85045B68181585D97816A916871CA8D3C208C16D87CFD46_cppui254,
                           0x00),
                            non_residue_type(0x1DDF9756B8CBF849CF96A5D90A9ACCFD3B2F4C893F42A9166615563BFBB318D7_cppui253,
                           0xBFAB77F2C36B843121DC8B86F6C4CCF2307D819D98302A771C39BB757899A9B_cppui252),
                            non_residue_type(0x59E26BCEA0D48BACD4F263F1ACDB5C4F5763473177FFFFFE_cppui191, 0x00),
                            non_residue_type(0x1687CCA314AEBB6DC866E529B0D4ADCD0E34B703AA1BF84253B10EDDB9A856C8_cppui253,
                           0x2FB855BCD54A22B6B18456D34C0B44C0187DC4ADD09D90A0C58BE1EAE3BC3C46_cppui254),
                            non_residue_type(0x59E26BCEA0D48BACD4F263F1ACDB5C4F5763473177FFFFFF_cppui191, 0x00),
                            non_residue_type(0x290C83BF3D14634DB120850727BB392D6A86D50BD34B19B929BC44B896723B38_cppui254,
                           0x23BD9E3DA9136A739F668E1ADC9EF7F0F575EC93F71A8DF953C846338C32A1AB_cppui254)};*/

                        constexpr static const std::array<modulus_type, 12 * 2> Frobenius_coeffs_c1 = {
                            0x01,
                            0x00,
                            0x1284B71C2865A7DFE8B99FDD76E68B605C521E08292F2176D60B35DADCC9E470_cppui253,
                            0x246996F3B4FAE7E6A6327CFE12150B8E747992778EEEC7E5CA5CF05F80F362AC_cppui254,
                            0x30644E72E131A0295E6DD9E7E0ACCCB0C28F069FBB966E3DE4BD44E5607CFD49_cppui254,
                            0x00,
                            0x19DC81CFCC82E4BBEFE9608CD0ACAA90894CB38DBE55D24AE86F7D391ED4A67F_cppui253,
                            0xABF8B60BE77D7306CBEEE33576139D7F03A5E397D439EC7694AA2BF4C0C101_cppui248,
                            0x30644E72E131A0295E6DD9E7E0ACCCB0C28F069FBB966E3DE4BD44E5607CFD48_cppui254,
                            0x00,
                            0x757CAB3A41D3CDC072FC0AF59C61F302CFA95859526B0D41264475E420AC20F_cppui251,
                            0xCA6B035381E35B618E9B79BA4E2606CA20B7DFD71573C93E85845E34C4A5B9C_cppui252,
                            0x30644E72E131A029B85045B68181585D97816A916871CA8D3C208C16D87CFD46_cppui254,
                            0x00,
                            0x1DDF9756B8CBF849CF96A5D90A9ACCFD3B2F4C893F42A9166615563BFBB318D7_cppui253,
                            0xBFAB77F2C36B843121DC8B86F6C4CCF2307D819D98302A771C39BB757899A9B_cppui252,
                            0x59E26BCEA0D48BACD4F263F1ACDB5C4F5763473177FFFFFE_cppui191,
                            0x00,
                            0x1687CCA314AEBB6DC866E529B0D4ADCD0E34B703AA1BF84253B10EDDB9A856C8_cppui253,
                            0x2FB855BCD54A22B6B18456D34C0B44C0187DC4ADD09D90A0C58BE1EAE3BC3C46_cppui254,
                            0x59E26BCEA0D48BACD4F263F1ACDB5C4F5763473177FFFFFF_cppui191,
                            0x00,
                            0x290C83BF3D14634DB120850727BB392D6A86D50BD34B19B929BC44B896723B38_cppui254,
                            0x23BD9E3DA9136A739F668E1ADC9EF7F0F575EC93F71A8DF953C846338C32A1AB_cppui254};

                        constexpr static const std::array<modulus_type, 2> non_residue = {9, 1};
                    };

                    template<std::size_t ModulusBits, std::size_t GeneratorBits>
                    constexpr std::array<typename fp12_2over3over2_extension_params<
                                             alt_bn128_base_field<ModulusBits, GeneratorBits>>::modulus_type,
                                         2> const
                        fp12_2over3over2_extension_params<
                            alt_bn128_base_field<ModulusBits, GeneratorBits>>::non_residue;

                }    // namespace detail
            }        // namespace fields
        }            // namespace algebra
    }                // namespace crypto3
}    // namespace nil

#endif    // CRYPTO3_ALGEBRA_FIELDS_ALT_BN128_FP12_2OVER3OVER2_EXTENSION_PARAMS_HPP
