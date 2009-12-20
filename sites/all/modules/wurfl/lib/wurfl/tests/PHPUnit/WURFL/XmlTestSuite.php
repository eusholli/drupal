<?php

require_once 'Xml/WURFLConsistencyVerifierTest.php';

/**
 * Static test suite.
 */
class WURFL_XmlTestSuite extends PHPUnit_Framework_TestSuite {
	
	/**
	 * Constructs the test suite handler.
	 */
	public function __construct() {
		$this->setName ( 'XmlTestSuite' );		
		$this->addTestSuite ( 'WURFL_Xml_WURFLConsistencyVerifierTest' );
	
	}
	
	/**
	 * Creates the suite.
	 */
	public static function suite() {
		return new self ( );
	}
}

