/***************************************************************************
 *   Free Heroes of Might and Magic II: https://github.com/ihhub/fheroes2  *
 *   Copyright (C) 2020                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#pragma once

#include "image.h"

namespace fheroes2
{
    class MovableSprite : public Sprite
    {
    public:
        MovableSprite();
        MovableSprite( int32_t width_, int32_t height_, int32_t x_, int32_t y_ );
        explicit MovableSprite( const Sprite & sprite );
        ~MovableSprite() override = default;

        MovableSprite & operator=( const Sprite & sprite );

        void show();
        void hide();
        void redraw(); // in case if Display has changed

        bool isHidden() const;

        void setPosition( int32_t x_, int32_t y_ ) override;

    private:
        ImageRestorer _restorer;
        bool _isHidden;
    };

    // This class is useful for cases of playing videos only
    class ScreenPaletteRestorer
    {
    public:
        ScreenPaletteRestorer();
        ScreenPaletteRestorer( const ScreenPaletteRestorer & ) = delete;

        ~ScreenPaletteRestorer();

        ScreenPaletteRestorer & operator=( const ScreenPaletteRestorer & ) = delete;

        void changePalette( const uint8_t * palette ) const;
    };

    Image CreateDeathWaveEffect( const Image & in, int32_t x, int32_t waveWidth, int32_t waveHeight );

    Image CreateRippleEffect( const Image & in, int32_t frameId, double scaleX = 0.05, double waveFrequency = 20.0 );

    void FadeDisplay( const Image & top, const Point & pos, uint8_t endAlpha, int delayMs );

    void FadeDisplayWithPalette( const Image & top, const Point & pos, uint8_t paletteId, int delayMs, int frameCount );

    void FadeDisplay( int delayMs = 500 );

    void InvertedFade( const Image & top, const Point & offset, const Image & middle, const Point & middleOffset, uint8_t endAlpha, int delayMs );

    void InvertedFadeWithPalette( const Image & top, const Point & offset, const Image & middle, const Point & middleOffset, uint8_t paletteId, int delayMs,
                                  int frameCount );

    // Display pre-render function to show screen system info
    void PreRenderSystemInfo();

    // Display post-render function to hide screen system info
    void PostRenderSystemInfo();
}
