// -*- C++ -*-
/*!
 * @file  Multiplyer.cpp
 * @brief Multiplyer RTC
 * @date $Date$
 *
 * $Id$
 */

#include "Multiplyer.h"

// Module specification
// <rtc-template block="module_spec">
static const char* multiplyer_spec[] =
  {
    "implementation_id", "Multiplyer",
    "type_name",         "Multiplyer",
    "description",       "Multiplyer RTC",
    "version",           "1.0.0",
    "vendor",            "Sugar Sweet Robotics",
    "category",          "Experimental",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.factor", "2.0",
    // Widget
    "conf.__widget__.factor", "text",
    // Constraints
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
Multiplyer::Multiplyer(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_inIn("in", m_in),
    m_outOut("out", m_out)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
Multiplyer::~Multiplyer()
{
}



RTC::ReturnCode_t Multiplyer::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("in", m_inIn);
  
  // Set OutPort buffer
  addOutPort("out", m_outOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("factor", m_factor, "2.0");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Multiplyer::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Multiplyer::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Multiplyer::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Multiplyer::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Multiplyer::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t Multiplyer::onExecute(RTC::UniqueId ec_id)
{
  if(m_inIn.isNew()) {
    m_inIn.read();
    m_out.data = m_factor * m_in.data;
    m_outOut.write();
  }
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Multiplyer::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Multiplyer::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Multiplyer::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Multiplyer::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Multiplyer::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void MultiplyerInit(RTC::Manager* manager)
  {
    coil::Properties profile(multiplyer_spec);
    manager->registerFactory(profile,
                             RTC::Create<Multiplyer>,
                             RTC::Delete<Multiplyer>);
  }
  
};


