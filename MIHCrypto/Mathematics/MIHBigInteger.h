//
// Copyright (C) 2014 Michael Hohl <http://www.michaelhohl.net/>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
// documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
// Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
// OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#import "MIHNumber.h"
#import <openssl/bn.h>

/**
 *  Class which wraps the functionallity of OpenSSL BIGNUM data type.
 *  BIGNUM is a integer data type which can store numbers of unlimted size without loosing precision.
 *
 *  MIHNumber is designed to be an immutable. All calculation return a new instance.
 *
 *  @author <a href="http://www.michaelhohl.net/">Michael Hohl</a>
 */
@interface MIHBigInteger : NSObject<MIHNumber, NSCoding> {
    BIGNUM *_representedBn;
}

/**
 *  Initialises MIHBigInteger with the passed NSUInteger value.
 *
 *  @param value The value of to get assigned to the BigNum.
 *
 *  @return The newly-created MIHBigInteger instance.
 */
- (id)initWithUnsignedInteger:(unsigned int)value;

/**
 *  Initialises MIHBigInteger with the passed NSString which contains a decimal number as string.
 *
 *  @param decimalString NSString which contains a decimal number represented by chars.
 *
 *  @return The newly-create MIHBigInteger instance.
 */
- (id)initWithDecimalStringValue:(NSString *)decimalString;

/**
 *  Creates a NSString of this hex value of this MIHBigInteger.
 *
 *  @return NSString which represents the MIHBigInteger.
 */
- (NSString *)hexStringValue;

/**
 *  Compares this MIHBigInteger with the passed MIHBigInteger.
 *
 *  @param other MIHBigInteger to compare with.
 *
 *  @return `YES` if the other MIHBigInteger is equal to this one.
 */
- (BOOL)isEqualToBigInteger:(MIHBigInteger *)other;

/**
 *  Compares this MIHBigInteger with the passed MIHBigInteger.
 *
 *  @param other MIHBigInteger to compare with.
 *
 *  @return `YES` if the other MIHBigInteger is less than this one.
 */
- (BOOL)isGreaterThanBigInteger:(MIHBigInteger *)other;

/**
 *  Compares this MIHBigInteger with the passed MIHBigInteger.
 *
 *  @param other MIHBigInteger to compare with.
 *
 *  @return `YES` if the other MIHBigInteger is greater than this one.
 */
- (BOOL)isLessThanBigInteger:(MIHBigInteger *)other;

@end
