// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  relay_gui.cpp
 * @brief ModuleDescription
 *
 */
// </rtc-template>

#include "relay_gui.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const relay_gui_spec[] =
#else
static const char* relay_gui_spec[] =
#endif
  {
    "implementation_id", "relay_gui",
    "type_name",         "relay_gui",
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
relay_gui::relay_gui(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_relay_inIn("relay_in", m_relay_in),
    m_waytorosOut("waytoros", m_waytoros)
    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
relay_gui::~relay_gui()
{
}



RTC::ReturnCode_t relay_gui::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("relay_in", m_relay_inIn);
  
  // Set OutPort buffer
  addOutPort("waytoros", m_waytorosOut);

  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>

  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t relay_gui::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t relay_gui::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t relay_gui::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t relay_gui::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t relay_gui::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t relay_gui::onExecute(RTC::UniqueId /*ec_id*/)
{


   if (m_relay_inIn.isNew())
     {
       m_relay_inIn.read();
       std::cout << "Received: " << m_relay_in.data << std::endl;
       m_waytoros.data = m_relay_in.data;
       m_waytorosOut.write();
     }
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t relay_gui::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t relay_gui::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t relay_gui::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t relay_gui::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t relay_gui::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}



extern "C"
{
 
  void relay_guiInit(RTC::Manager* manager)
  {
    coil::Properties profile(relay_gui_spec);
    manager->registerFactory(profile,
                             RTC::Create<relay_gui>,
                             RTC::Delete<relay_gui>);
  }
  
}
