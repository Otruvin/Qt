// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef LockOrientationCallback_h
#define LockOrientationCallback_h

#include "public/platform/WebLockOrientationCallback.h"
#include "public/platform/WebScreenOrientationType.h"
#include "wtf/Noncopyable.h"
#include "wtf/PassRefPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

class ScriptPromiseResolver;

// LockOrientationCallback is an implementation of WebLockOrientationCallback
// that will resolve the underlying promise depending on the result passed to
// the callback.
class LockOrientationCallback final : public WebLockOrientationCallback {
    WTF_MAKE_NONCOPYABLE(LockOrientationCallback);
public:
    explicit LockOrientationCallback(PassRefPtr<ScriptPromiseResolver>);
    virtual ~LockOrientationCallback();

    virtual void onSuccess() override;
    virtual void onError(WebLockOrientationError) override;

private:
    RefPtr<ScriptPromiseResolver> m_resolver;
};

} // namespace blink

#endif // LockOrientationCallback_h
