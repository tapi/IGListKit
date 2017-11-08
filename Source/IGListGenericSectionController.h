/**
 * Copyright (c) 2016-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <IGListKit/IGListSectionController.h>

NS_ASSUME_NONNULL_BEGIN

/**
 This class adds a helper layer to `IGListSectionController` to automatically store a generic object in
 `didUpdateToObject:`.
 */
NS_SWIFT_NAME(ListGenericSectionController)
@interface IGListGenericSectionController<__covariant ObjectType : id<IGListDiffable>> : IGListSectionController

/**
 The object mapped to this section controller. Matches the object provided in
 `[IGListAdapterDataSource listAdapter:sectionControllerForObject:]` when this section controller was created and
 returned.

 @note This object is briefly `nil` between initialization and the first call to `didUpdateToObject:`. After that, it is
 safe to assume that this is non-`nil`.
 */
@property (nonatomic, strong, nullable, readonly) ObjectType object;

/**
 Updates the section controller to a new object.

 @param object The object mapped to this section controller.

 @note This `IGListSectionController` subclass sets its object in this method, so any overrides **must call super**.
 */
- (void)didUpdateToObject:(id<IGListDiffable>)object NS_REQUIRES_SUPER;

@end

NS_ASSUME_NONNULL_END
