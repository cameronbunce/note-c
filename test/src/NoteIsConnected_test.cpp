/*!
 * @file NoteIsConnected_test.cpp
 *
 * Written by the Blues Inc. team.
 *
 * Copyright (c) 2023 Blues Inc. MIT License. Use of this source code is
 * governed by licenses granted by the copyright holder including that found in
 * the
 * <a href="https://github.com/blues/note-c/blob/master/LICENSE">LICENSE</a>
 * file.
 *
 */

#ifdef NOTE_C_TEST

#include <catch2/catch_test_macros.hpp>
#include "fff.h"

#include "n_lib.h"

DEFINE_FFF_GLOBALS
FAKE_VALUE_FUNC(J *, NoteNewRequest, const char *)
FAKE_VALUE_FUNC(J *, NoteRequestResponse, J *)

namespace
{

TEST_CASE("NoteIsConnected")
{
    NoteSetFnDefault(malloc, free, NULL, NULL);

    RESET_FAKE(NoteNewRequest);
    RESET_FAKE(NoteRequestResponse);

    SECTION("No response") {
        NoteRequestResponse_fake.return_val = NULL;

        CHECK(!NoteIsConnected());
    }

    SECTION("Response") {
        J* resp = JCreateObject();
        REQUIRE(resp != NULL);
        NoteRequestResponse_fake.return_val = resp;

        SECTION("Error in response") {
            const char errMsg[] = "an error";
            JAddStringToObject(resp, "err", errMsg);

            CHECK(!NoteIsConnected());
        }

        SECTION("Not connected") {
            JAddBoolToObject(resp, "connected", false);

            CHECK(!NoteIsConnected());
        }

        SECTION("Connected") {
            JAddBoolToObject(resp, "connected", true);

            CHECK(NoteIsConnected());
        }
    }
}

}

#endif // NOTE_C_TEST
