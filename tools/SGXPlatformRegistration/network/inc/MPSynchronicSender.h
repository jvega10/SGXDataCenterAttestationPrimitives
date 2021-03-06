/*
 * Copyright (C) 2011-2020 Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of Intel Corporation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
/**
 * File: MPSynchronicSender.h 
 *   
 * Description: Definition for the class to send network requests. 
 * Implements the IMPSynchonicSender interface class. 
 */
#ifndef __MP_ASYNCRONIUS_SENDER_H
#define __MP_ASYNCRONIUS_SENDER_H

#include <stdexcept> 
#include "IMPSynchronicSender.h"

class MPSynchronicSender : public IMPSynchronicSender {
    public:
        MPSynchronicSender(const ProxyConf& proxyObject, const LogLevel logLevel) : m_proxy(proxyObject), m_logLevel(logLevel) { }
        MpResult sendBinaryRequest(const string& serverURL, const string& subscriptionKey, const uint8_t *request, const uint16_t requestSize,
            uint8_t *response, uint16_t &responseSize, HttpStatusCode& http_response_code, string& errorCodeStr);
        virtual ~MPSynchronicSender() {};
	private:
        ProxyConf m_proxy;
        LogLevel m_logLevel;
};

#endif  // __MP_ASYNCRONIUS_SENDER_H

