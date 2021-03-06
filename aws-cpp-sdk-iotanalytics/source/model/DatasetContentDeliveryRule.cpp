﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/iotanalytics/model/DatasetContentDeliveryRule.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace IoTAnalytics
{
namespace Model
{

DatasetContentDeliveryRule::DatasetContentDeliveryRule() : 
    m_entryNameHasBeenSet(false),
    m_destinationHasBeenSet(false)
{
}

DatasetContentDeliveryRule::DatasetContentDeliveryRule(JsonView jsonValue) : 
    m_entryNameHasBeenSet(false),
    m_destinationHasBeenSet(false)
{
  *this = jsonValue;
}

DatasetContentDeliveryRule& DatasetContentDeliveryRule::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("entryName"))
  {
    m_entryName = jsonValue.GetString("entryName");

    m_entryNameHasBeenSet = true;
  }

  if(jsonValue.ValueExists("destination"))
  {
    m_destination = jsonValue.GetObject("destination");

    m_destinationHasBeenSet = true;
  }

  return *this;
}

JsonValue DatasetContentDeliveryRule::Jsonize() const
{
  JsonValue payload;

  if(m_entryNameHasBeenSet)
  {
   payload.WithString("entryName", m_entryName);

  }

  if(m_destinationHasBeenSet)
  {
   payload.WithObject("destination", m_destination.Jsonize());

  }

  return payload;
}

} // namespace Model
} // namespace IoTAnalytics
} // namespace Aws
