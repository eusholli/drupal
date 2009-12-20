<?php

require_once 'Configuration/ArrayConfigTest.php';
require_once 'Configuration/XmlConfigTest.php';

/**
 * Static test suite.
 */
class WURFL_ConfigurationTestSuite extends PHPUnit_Framework_TestSuite {
	
	/**
	 * Constructs the test suite handler.
	 */
	public function __construct() {
		$this->setName ( 'ConfigurationTestSuite' );		
		$this->addTestSuite ( 'WURFL_Configuration_XmlConfigTest' );
		$this->addTestSuite ( 'WURFL_Configuration_ArrayConfigTest' );
	}
	
	/**
	 * Creates the suite.
	 */
	public static function suite() {
		return new self ( );
	}
}

