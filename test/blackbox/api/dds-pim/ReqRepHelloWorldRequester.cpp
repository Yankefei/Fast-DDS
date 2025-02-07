// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file ReqRepHelloWorldRequester.cpp
 *
 */

#include <fastdds/dds/domain/DomainParticipantFactory.hpp>

#include "ReqRepHelloWorldRequester.hpp"

using namespace eprosima::fastdds::dds;
using namespace eprosima::fastdds::rpc;
using namespace eprosima::fastdds::rtps;

ReqRepHelloWorldRequester::ReqRepHelloWorldRequester()
    : current_number_(std::numeric_limits<uint16_t>::max()),
    number_received_(std::numeric_limits<uint16_t>::max()),
    requester_(nullptr),
    service_(nullptr),
    participant_(nullptr),
    initialized_(false),
    matched_(0)
{
}

ReqRepHelloWorldRequester::~ReqRepHelloWorldRequester()
{
    if (participant_)
    {
        if (service_)
        {
            if (requester_)
            {
                service_->delete_requester(requester_);
            }
            
            participant_->delete_service(service_);
        }
        DomainParticipantFactory::get_instance()->delete_participant(participant_);
    }
}

