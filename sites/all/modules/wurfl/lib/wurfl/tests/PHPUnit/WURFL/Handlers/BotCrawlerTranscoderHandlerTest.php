<?php

/**
 *  test case.
 */
class WURFL_Hanlders_BotCrawlerTranscoderHandlerTest extends PHPUnit_Framework_TestCase {
	
	const BOT_CRAWLER_TRANSCODER_FILE_PATH = "bot_crawler_transcoder.txt";
	
	private $handler;
	
	
	function setUp() {
		$normalizer = new WURFL_Request_UserAgentNormalizer_Null();
		$this->handler = new WURFL_Handlers_BotCrawlerTranscoderHandler($normalizer);
	}
	
	/**
	 * @dataProvider botCrawlerTranscoderUserAgentsProvider
	 *
	 * @param string $userAgent
	 */
	function testShoudHandleKnownBots($userAgent) {
		$found = $this->handler->canHandle($userAgent);	
		$this->assertTrue($found);
	}
	
	
	function botCrawlerTranscoderUserAgentsProvider() {
		return array(
			array("Mozilla/5.0 (compatible; BecomeBot/3.0; +http://www.become.com/site_owners.html)"),
			array("Mozilla/5.0 (compatible; DBLBot/1.0; +http://www.dontbuylists.com/)")
		);
		
	}
	
	
}

