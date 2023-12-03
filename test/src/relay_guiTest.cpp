// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  relay_guiTest.cpp
 * @brief ModuleDescription (test code)
 *
 */
// </rtc-template>

#include "relay_guiTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const relay_gui_spec[] =
#else
static const char* relay_gui_spec[] =
#endif
  {
    "implementation_id", "relay_guiTest",
    "type_name",         "relay_guiTest",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
relay_guiTest::relay_guiTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_relay_inOut("relay_in", m_relay_in),
    m_dp_nameIn("dp_name", m_dp_name)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
relay_guiTest::~relay_guiTest()
{
}



RTC::ReturnCode_t relay_guiTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("dp_name", m_dp_nameIn);
  
  // Set OutPort buffer
  addOutPort("relay_in", m_relay_inOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t relay_guiTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t relay_guiTest::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t relay_guiTest::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t relay_guiTest::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t relay_guiTest::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t relay_guiTest::onExecute(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t relay_guiTest::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t relay_guiTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t relay_guiTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t relay_guiTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t relay_guiTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool relay_guiTest::runTest()
{
    return true;
}


extern "C"
{
 
  void relay_guiTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(relay_gui_spec);
    manager->registerFactory(profile,
                             RTC::Create<relay_guiTest>,
                             RTC::Delete<relay_guiTest>);
  }
  
}
