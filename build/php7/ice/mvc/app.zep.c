
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"


/**
 * This component allows to create MVC applications.
 *
 * @package     Ice/Mvc
 * @category    Application
 * @author      Ice Team
 * @copyright   (c) 2014-2016 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_App) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc, App, ice, mvc_app, ice_di_access_ce, ice_mvc_app_method_entry, 0);

	zend_declare_property_bool(ice_mvc_app_ce, SL("autoRender"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_app_ce, SL("modules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_App, getAutoRender) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "autoRender");

}

PHP_METHOD(Ice_Mvc_App, setAutoRender) {

	zval *autoRender, autoRender_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&autoRender_sub);

	zephir_fetch_params(0, 1, 0, &autoRender);



	zephir_update_property_zval(this_ptr, SL("autoRender"), autoRender);

}

PHP_METHOD(Ice_Mvc_App, getModules) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "modules");

}

PHP_METHOD(Ice_Mvc_App, setModules) {

	zval *modules, modules_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&modules_sub);

	zephir_fetch_params(0, 1, 0, &modules);



	zephir_update_property_zval(this_ptr, SL("modules"), modules);

}

/**
 * App constructor
 *
 * @param Di $di
 */
PHP_METHOD(Ice_Mvc_App, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *di = NULL, di_sub, __$null, _0, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&di_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &di);

	if (!di) {
		di = &di_sub;
		di = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("di"), di);
	zephir_read_property(&_0, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "app");
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &_1, this_ptr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Handles a MVC request.
 *
 * @param string method
 * @param string uri
 * @return ResponseInterface|boolean
 */
PHP_METHOD(Ice_Mvc_App, handle) {

	zval _9, _36, _18$$7;
	zend_bool _3, _10, _4$$5, _16$$7, _20$$7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL, method_sub, *uri = NULL, uri_sub, _SERVER, __$null, argv, router, request, response, dispatcher, returned, controller, view, _0, _1, _5, _6, _7, _8, _35, _2$$4, _11$$7, _12$$7, _13$$7, _14$$7, _15$$7, _17$$7, _19$$7, _21$$9, _22$$9, _23$$9, _24$$10, _33$$10, _34$$10, _25$$11, _30$$11, _32$$11, _26$$12, _27$$12, _28$$12, _29$$12, _31$$13;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&argv);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&dispatcher);
	ZVAL_UNDEF(&returned);
	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&view);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_33$$10);
	ZVAL_UNDEF(&_34$$10);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_30$$11);
	ZVAL_UNDEF(&_32$$11);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_18$$7);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 0, 2, &method, &uri);

	if (!method) {
		method = &method_sub;
		ZEPHIR_CPY_WRT(method, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(method);
	}
	if (!uri) {
		uri = &uri_sub;
		ZEPHIR_CPY_WRT(uri, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(uri);
	}


	zephir_read_property(&_0, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "request");
	ZEPHIR_CALL_METHOD(&request, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(method) == IS_NULL) {
		ZEPHIR_CALL_METHOD(method, &request, "getmethod", NULL, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(uri) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "_url");
		ZEPHIR_CALL_METHOD(uri, &request, "get", NULL, 0, &_2$$4);
		zephir_check_call_status();
	}
	_3 = !zephir_is_true(method);
	if (_3) {
		ZEPHIR_INIT_NVAR(&_1);
		ZEPHIR_GET_CONSTANT(&_1, "PHP_SAPI");
		_3 = ZEPHIR_IS_STRING_IDENTICAL(&_1, "cli");
	}
	if (_3) {
		ZEPHIR_INIT_NVAR(method);
		ZVAL_STRING(method, "GET");
		ZEPHIR_OBS_VAR(&argv);
		zephir_array_fetch_string(&argv, &_SERVER, SL("argv"), PH_NOISY, "ice/mvc/app.zep", 60 TSRMLS_CC);
		_4$$5 = !zephir_is_true(uri);
		if (_4$$5) {
			_4$$5 = zephir_array_isset_long(&argv, 1);
		}
		if (_4$$5) {
			ZEPHIR_OBS_NVAR(uri);
			zephir_array_fetch_long(uri, &argv, 1, PH_NOISY, "ice/mvc/app.zep", 63 TSRMLS_CC);
		}
	}
	zephir_read_property(&_5, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "router");
	ZEPHIR_CALL_METHOD(&router, &_5, "get", NULL, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &router, "handle", NULL, 0, method, uri);
	zephir_check_call_status();
	zephir_read_property(&_7, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "dispatcher");
	ZEPHIR_CALL_METHOD(&dispatcher, &_7, "get", NULL, 0, &_6);
	zephir_check_call_status();
	zephir_read_property(&_8, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_9);
	zephir_create_array(&_9, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_9, &response);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "app.after.router.handle");
	ZEPHIR_CALL_METHOD(NULL, &_8, "applyhook", NULL, 0, &_6, &_9);
	zephir_check_call_status();
	_10 = Z_TYPE_P(&response) == IS_OBJECT;
	if (_10) {
		_10 = (zephir_instance_of_ev(&response, ice_http_response_responseinterface_ce TSRMLS_CC));
	}
	if (!(_10)) {
		zephir_read_property(&_11$$7, this_ptr, SL("modules"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setmodules", NULL, 0, &_11$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setmethod", NULL, 0, method);
		zephir_check_call_status();
		zephir_array_fetch_string(&_12$$7, &response, SL("module"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 76 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setmodule", NULL, 0, &_12$$7);
		zephir_check_call_status();
		zephir_array_fetch_string(&_13$$7, &response, SL("handler"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 77 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &dispatcher, "sethandler", NULL, 0, &_13$$7);
		zephir_check_call_status();
		zephir_array_fetch_string(&_14$$7, &response, SL("action"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 78 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setaction", NULL, 0, &_14$$7);
		zephir_check_call_status();
		zephir_array_fetch_string(&_15$$7, &response, SL("params"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 79 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setparams", NULL, 0, &_15$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&response, &dispatcher, "dispatch", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&returned, &dispatcher, "getreturnedvalue", NULL, 0);
		zephir_check_call_status();
		_16$$7 = Z_TYPE_P(&returned) == IS_OBJECT;
		if (_16$$7) {
			_16$$7 = (zephir_instance_of_ev(&returned, ice_http_response_responseinterface_ce TSRMLS_CC));
		}
		if (_16$$7) {
			ZEPHIR_CPY_WRT(&response, &returned);
		}
		zephir_read_property(&_17$$7, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_18$$7);
		zephir_create_array(&_18$$7, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_18$$7, &response);
		ZEPHIR_INIT_VAR(&_19$$7);
		ZVAL_STRING(&_19$$7, "app.after.dispatcher.dispatch");
		ZEPHIR_CALL_METHOD(NULL, &_17$$7, "applyhook", NULL, 0, &_19$$7, &_18$$7);
		zephir_check_call_status();
		_20$$7 = Z_TYPE_P(&response) == IS_OBJECT;
		if (_20$$7) {
			_20$$7 = (zephir_instance_of_ev(&response, ice_http_response_responseinterface_ce TSRMLS_CC));
		}
		if (!(_20$$7)) {
			ZEPHIR_CPY_WRT(&controller, &response);
			zephir_read_property(&_21$$9, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_22$$9);
			ZVAL_STRING(&_22$$9, "response");
			ZEPHIR_CALL_METHOD(&response, &_21$$9, "get", NULL, 0, &_22$$9);
			zephir_check_call_status();
			zephir_read_property(&_23$$9, &controller, SL("view"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&view, &_23$$9);
			zephir_read_property(&_23$$9, this_ptr, SL("autoRender"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_23$$9)) {
				ZEPHIR_CALL_METHOD(&_24$$10, &view, "getcontent", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&_24$$10) == IS_NULL) {
					ZEPHIR_CALL_METHOD(&_25$$11, &view, "getfile", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_is_true(&_25$$11))) {
						ZVAL_BOOL(&_26$$12, 1);
						ZEPHIR_CALL_METHOD(NULL, &view, "setsilent", NULL, 0, &_26$$12);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_27$$12, &dispatcher, "gethandler", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_28$$12, &dispatcher, "getaction", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_VAR(&_29$$12);
						ZEPHIR_CONCAT_VSV(&_29$$12, &_27$$12, "/", &_28$$12);
						ZEPHIR_CALL_METHOD(NULL, &view, "setfile", NULL, 0, &_29$$12);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_30$$11, &view, "count", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_is_true(&_30$$11))) {
						ZEPHIR_CALL_METHOD(&_31$$13, &dispatcher, "getparams", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &view, "replace", NULL, 0, &_31$$13);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_32$$11, &view, "render", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &view, "setcontent", NULL, 0, &_32$$11);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_34$$10, &view, "getmainview", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_33$$10, &view, "layout", NULL, 0, &_34$$10);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "setbody", NULL, 0, &_33$$10);
				zephir_check_call_status();
			}
		}
	}
	zephir_read_property(&_35, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_36);
	zephir_create_array(&_36, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_36, &response);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "app.after.handle");
	ZEPHIR_CALL_METHOD(NULL, &_35, "applyhook", NULL, 0, &_6, &_36);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&response, "send", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

