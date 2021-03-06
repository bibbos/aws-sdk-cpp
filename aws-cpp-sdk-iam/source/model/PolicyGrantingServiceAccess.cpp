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

#include <aws/iam/model/PolicyGrantingServiceAccess.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

namespace Aws
{
namespace IAM
{
namespace Model
{

PolicyGrantingServiceAccess::PolicyGrantingServiceAccess() : 
    m_policyNameHasBeenSet(false),
    m_policyType(PolicyType::NOT_SET),
    m_policyTypeHasBeenSet(false),
    m_policyArnHasBeenSet(false),
    m_entityType(PolicyOwnerEntityType::NOT_SET),
    m_entityTypeHasBeenSet(false),
    m_entityNameHasBeenSet(false)
{
}

PolicyGrantingServiceAccess::PolicyGrantingServiceAccess(const XmlNode& xmlNode) : 
    m_policyNameHasBeenSet(false),
    m_policyType(PolicyType::NOT_SET),
    m_policyTypeHasBeenSet(false),
    m_policyArnHasBeenSet(false),
    m_entityType(PolicyOwnerEntityType::NOT_SET),
    m_entityTypeHasBeenSet(false),
    m_entityNameHasBeenSet(false)
{
  *this = xmlNode;
}

PolicyGrantingServiceAccess& PolicyGrantingServiceAccess::operator =(const XmlNode& xmlNode)
{
  XmlNode resultNode = xmlNode;

  if(!resultNode.IsNull())
  {
    XmlNode policyNameNode = resultNode.FirstChild("PolicyName");
    if(!policyNameNode.IsNull())
    {
      m_policyName = StringUtils::Trim(policyNameNode.GetText().c_str());
      m_policyNameHasBeenSet = true;
    }
    XmlNode policyTypeNode = resultNode.FirstChild("PolicyType");
    if(!policyTypeNode.IsNull())
    {
      m_policyType = PolicyTypeMapper::GetPolicyTypeForName(StringUtils::Trim(policyTypeNode.GetText().c_str()).c_str());
      m_policyTypeHasBeenSet = true;
    }
    XmlNode policyArnNode = resultNode.FirstChild("PolicyArn");
    if(!policyArnNode.IsNull())
    {
      m_policyArn = StringUtils::Trim(policyArnNode.GetText().c_str());
      m_policyArnHasBeenSet = true;
    }
    XmlNode entityTypeNode = resultNode.FirstChild("EntityType");
    if(!entityTypeNode.IsNull())
    {
      m_entityType = PolicyOwnerEntityTypeMapper::GetPolicyOwnerEntityTypeForName(StringUtils::Trim(entityTypeNode.GetText().c_str()).c_str());
      m_entityTypeHasBeenSet = true;
    }
    XmlNode entityNameNode = resultNode.FirstChild("EntityName");
    if(!entityNameNode.IsNull())
    {
      m_entityName = StringUtils::Trim(entityNameNode.GetText().c_str());
      m_entityNameHasBeenSet = true;
    }
  }

  return *this;
}

void PolicyGrantingServiceAccess::OutputToStream(Aws::OStream& oStream, const char* location, unsigned index, const char* locationValue) const
{
  if(m_policyNameHasBeenSet)
  {
      oStream << location << index << locationValue << ".PolicyName=" << StringUtils::URLEncode(m_policyName.c_str()) << "&";
  }

  if(m_policyTypeHasBeenSet)
  {
      oStream << location << index << locationValue << ".PolicyType=" << PolicyTypeMapper::GetNameForPolicyType(m_policyType) << "&";
  }

  if(m_policyArnHasBeenSet)
  {
      oStream << location << index << locationValue << ".PolicyArn=" << StringUtils::URLEncode(m_policyArn.c_str()) << "&";
  }

  if(m_entityTypeHasBeenSet)
  {
      oStream << location << index << locationValue << ".EntityType=" << PolicyOwnerEntityTypeMapper::GetNameForPolicyOwnerEntityType(m_entityType) << "&";
  }

  if(m_entityNameHasBeenSet)
  {
      oStream << location << index << locationValue << ".EntityName=" << StringUtils::URLEncode(m_entityName.c_str()) << "&";
  }

}

void PolicyGrantingServiceAccess::OutputToStream(Aws::OStream& oStream, const char* location) const
{
  if(m_policyNameHasBeenSet)
  {
      oStream << location << ".PolicyName=" << StringUtils::URLEncode(m_policyName.c_str()) << "&";
  }
  if(m_policyTypeHasBeenSet)
  {
      oStream << location << ".PolicyType=" << PolicyTypeMapper::GetNameForPolicyType(m_policyType) << "&";
  }
  if(m_policyArnHasBeenSet)
  {
      oStream << location << ".PolicyArn=" << StringUtils::URLEncode(m_policyArn.c_str()) << "&";
  }
  if(m_entityTypeHasBeenSet)
  {
      oStream << location << ".EntityType=" << PolicyOwnerEntityTypeMapper::GetNameForPolicyOwnerEntityType(m_entityType) << "&";
  }
  if(m_entityNameHasBeenSet)
  {
      oStream << location << ".EntityName=" << StringUtils::URLEncode(m_entityName.c_str()) << "&";
  }
}

} // namespace Model
} // namespace IAM
} // namespace Aws
