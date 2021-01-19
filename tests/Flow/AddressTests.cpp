// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "HexCoding.h"
#include "Flow/Address.h"
#include "PublicKey.h"
#include "PrivateKey.h"
#include <gtest/gtest.h>
#include <vector>

using namespace TW;
using namespace TW::Flow;

TEST(FlowAddress, Valid) {
    ASSERT_TRUE(Address::isValid("__ADD_VALID_ADDRESS_HERE__"));

    // TODO: Add more tests
}

TEST(FlowAddress, Invalid) {
    ASSERT_FALSE(Address::isValid("__ADD_INVALID_ADDRESS_HERE__"));

    // TODO: Add more tests
}

TEST(FlowAddress, FromPrivateKey) {
    auto privateKey = PrivateKey(parse_hex("ccf430b9cb836779fe1cbe5c7bd278b136c717b635743f38b91fc02f56157894"));
    auto address = Address("0x3bf5d7407caaeb32", privateKey.getPublicKey(TWPublicKeyTypeSECP256k1));
    ASSERT_EQ(address.string(), "0x3bf5d7407caaeb32");
}

TEST(FlowAddress, FromPublicKey) {
    auto publicKey = PublicKey(parse_hex("025106abc3869d1be94c99e8b4d3d5b62da07d828bf91668269dbe071df8c0d995"), TWPublicKeyTypeSECP256k1);
    auto address = Address("0x3bf5d7407caaeb32", publicKey);
    ASSERT_EQ(address.string(), "0x3bf5d7407caaeb32");
}

TEST(FlowAddress, FromString) {
    auto address = Address("__ADD_VALID_ADDRESS_HERE__");
    ASSERT_EQ(address.string(), "__ADD_SAME_VALID_ADDRESS_HERE__");
}