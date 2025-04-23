/**************************************************************************/
/*  test_test__style_box_flat.h                                           */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#pragma once
#include "scene/resources/style_box_flat.h"
#include "tests/test_macros.h"

namespace TestStyleBoxFlat {

TEST_CASE("[Test_StyleBoxFlat] Default values") {
	Ref<StyleBoxFlat> sbf;
	sbf.instantiate();
	CHECK(sbf->get_bg_color() == Color(0.6, 0.6, 0.6, 1));
	CHECK(sbf->get_border_color() == Color(0.8, 0.8, 0.8, 1));
	CHECK(sbf->get_border_blend() == false);
	CHECK(sbf->get_border_width(SIDE_LEFT) == 0);
	CHECK(sbf->get_border_width(SIDE_RIGHT) == 0);
	CHECK(sbf->get_border_width(SIDE_TOP) == 0);
	CHECK(sbf->get_border_width(SIDE_BOTTOM) == 0);
	CHECK(sbf->get_corner_detail() == 8);
	CHECK(sbf->get_corner_radius(CORNER_TOP_LEFT) == 0);
	CHECK(sbf->get_corner_radius(CORNER_TOP_RIGHT) == 0);
	CHECK(sbf->get_corner_radius(CORNER_BOTTOM_LEFT) == 0);
	CHECK(sbf->get_corner_radius(CORNER_BOTTOM_RIGHT) == 0);
	CHECK(sbf->is_draw_center_enabled() == true);
	CHECK(sbf->get_expand_margin(SIDE_LEFT) == 0.0);
	CHECK(sbf->get_expand_margin(SIDE_RIGHT) == 0.0);
	CHECK(sbf->get_expand_margin(SIDE_TOP) == 0.0);
	CHECK(sbf->get_expand_margin(SIDE_BOTTOM) == 0.0);
	CHECK(sbf->get_shadow_color() == Color(0, 0, 0, 0.6));
	CHECK(sbf->get_shadow_offset() == Vector2(0, 0));
	CHECK(sbf->get_skew() == Vector2(0, 0));
}
TEST_CASE("[Test_StyleBoxFlat] Getters and setters") {
	Ref<StyleBoxFlat> sbf;
	sbf.instantiate();
	Color color = Color(0.7, 0.6, 0.6, 1);
	sbf->set_bg_color(color);
	CHECK(sbf->get_bg_color() == color );
	sbf->set_border_color(color);
	CHECK(sbf->get_border_color() == color);
	sbf->set_border_width(SIDE_LEFT, 1);
	CHECK(sbf->get_border_width(SIDE_LEFT) == 1);
	sbf->set_border_width_all(2);
	CHECK(sbf->get_border_width(SIDE_LEFT) == 2);
	CHECK(sbf->get_border_width(SIDE_RIGHT) == 2);
	CHECK(sbf->get_border_width(SIDE_TOP) == 2);
	CHECK(sbf->get_border_width(SIDE_BOTTOM) == 2);
	sbf->set_corner_radius(CORNER_TOP_LEFT, 1);
	CHECK(sbf->get_corner_radius(CORNER_TOP_LEFT) == 1);
	sbf->set_corner_radius_all(2);
	CHECK(sbf->get_corner_radius(CORNER_TOP_LEFT) == 2);
	CHECK(sbf->get_corner_radius(CORNER_TOP_RIGHT) == 2);
	CHECK(sbf->get_corner_radius(CORNER_BOTTOM_LEFT) == 2);
	CHECK(sbf->get_corner_radius(CORNER_BOTTOM_RIGHT) == 2);
	sbf->set_expand_margin(SIDE_LEFT, 1.0);
	CHECK(sbf->get_expand_margin(SIDE_LEFT) == 1.0);
	sbf->set_expand_margin_all(2.0);
	CHECK(sbf->get_expand_margin(SIDE_LEFT) == 2.0);
	CHECK(sbf->get_expand_margin(SIDE_RIGHT) == 2.0);
	CHECK(sbf->get_expand_margin(SIDE_TOP) == 2.0);
	CHECK(sbf->get_expand_margin(SIDE_BOTTOM) == 2.0);
	sbf->set_draw_center(false);
	CHECK(sbf->is_draw_center_enabled() == false);
	sbf->set_shadow_color(color);
	CHECK(sbf->get_shadow_color() == color);
	sbf->set_shadow_offset(Vector2(1, 0));
	CHECK(sbf->get_shadow_offset() == Vector2(1, 0));
	sbf->set_skew(Vector2(1, 0));
	CHECK(sbf->get_skew() == Vector2(1, 0));
	sbf->set_border_blend(true);
	CHECK(sbf->get_border_blend() == true);
}	
} // namespace TestStyleBoxFlat
